/*

Per compilare con libreria CndexLink 
 * 
 * ricavare il .def con impdef
 * impdef CndexLink.lib > Cndex.def
 * 
 * il file def è incompleto, mancano la @nn su quasi tutte le funzioni.
 * Quando il linker da errore indica quale @nn mettere a mano...
 * 
 * poi si ricava la import library con dlltool
 * dlltool -k --dllname CndexLink.dll --def Cndex.def --output-lib libcndex.a
 * 
 * la libreria che si ottiene si aggiunge al linker in Libraries delle opzioni linker
 * 


*/

#include "wx/app.h"
#include <windef.h>

#include "wx/config.h"
#include "wx/fileconf.h"
#include "wxcrafter.h"

#include "c_open.h"
#include "CndexLinkUser.h"
#include "c_distinta.h"
#include "c_toolbar.h"
#include "c_statusbar.h"



COpen::COpen()
{
	p_tot = (MAX_PROC_SLAVE+1) * MAX_PROC_MASTER;
	
	simula = 0;
	for (int i=0; i<=p_tot; i++) {
		processo[i]=0;
	}
	for (int i=0; i<MAX_PROC_MASTER; i++) {
		program[i] = "";
	}
	
}

COpen::~COpen()
{
	CloseSession_C(ID_Sessione,&ClasseErr,&NumeroErr);
}

int COpen::InitOpen()
{

	wxASSERT(logger != 0);
	wxASSERT(distinta != 0);
	wxASSERT(toolbar != 0);

	if(!logger || !distinta || !toolbar)
		return -1;
	
	logger->NewRiga("cnc.ini reading .....");
	
	wxString ws;

	
	wxFileConfig *FilIni = new wxFileConfig("", "", "cnc.ini","cnc.ini",
							wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_RELATIVE_PATH);


	FilIni->Read("CNC_OPEN/Ip",&AddrIP);
	

	FilIni->Read("CNC_OPEN/OnLine",&on_line);
	FilIni->Read("CNC_OPEN/Simula",&simula);
	
	FilIni->Read("CNC_OPEN/IniE",&inizio_E);
	FilIni->Read("CNC_OPEN/NumE",&numero_E);
	FilIni->Read("CNC_OPEN/IniSC",&inizio_SC);
	FilIni->Read("CNC_OPEN/NumSC",&numero_SC);
	FilIni->Read("CNC_OPEN/NumSC",&TTick);
	
	
	//lettura processi
	for (int nr_proc=1,npro=0; nr_proc<=MAX_PROC_MASTER; nr_proc++, npro+=10) {
		
		//compongo indice colonna
		ws = "MPROC_";
		ws << (nr_proc);
		FilIni->Read((ws+"/Master"),&(processo[npro]));
		if(processo[npro]>0) {
			FilIni->Read((ws+"/Slave1"),&(processo[npro+1]));
			FilIni->Read((ws+"/Slave2"),&(processo[npro+2]));
			FilIni->Read((ws+"/Slave3"),&(processo[npro+3]));
			FilIni->Read((ws+"/Slave4"),&(processo[npro+4]));
			FilIni->Read((ws+"/Slave5"),&(processo[npro+5]));
			FilIni->Read((ws+"/Slave6"),&(processo[npro+6]));
			FilIni->Read((ws+"/Slave7"),&(processo[npro+7]));
			FilIni->Read((ws+"/Slave8"),&(processo[npro+8]));
			FilIni->Read((ws+"/Slave9"),&(processo[npro+9]));

			FilIni->Read((ws+"/Program"),&(program[nr_proc-1]));
		}
	}
	

	
	delete FilIni;
	
	
	logger->Append(" done.");
	statusbar->SetStatusText(AddrIP,3);
	
	return 0;
	
	
}

void COpen::StartProgram()
{
	char temp[50];
	LPSTR tt;	

	if(simula ==1 ) {
		//set riga di partenza
		if(distinta->SetStartRow() < 0)
			return;  //se riga non valida abortisco sequneza di avvio
		logger->NewRiga("PArtito!");
		return;
	}

	if (on_line==true) {
		//Attivazione programmi
		for(int i=0; i<MAX_PROC_MASTER; i++) {
			if(processo[i*10] > 0) {
				if(program[i] != "") {
					strcpy( temp, (const char*)program[i].mb_str(wxConvUTF8) );
					tt=temp;
					SelectPartProgram_C(ID_Sessione,processo[i*10],tt,&ClasseErr,&NumeroErr);

					//inserire controllo errore
				}
			}
		}
		
		//set riga di partenza
		if(distinta->SetStartRow() < 0)
			return;  //se riga non valida abortisco sequneza di avvio

		//Start programmi
		for(int i=0; i<MAX_PROC_MASTER; i++) {
			if(processo[i*10] > 0) {
				if(program[i] != "") {
					Cycle_C (ID_Sessione,processo[i*10],1,&ClasseErr,&NumeroErr);
					
					//inserire controllo errore
				}
			}
		}
	}
	
}

void COpen::StopProgram()
{
	

		for (int i=0; i<=p_tot; i++) { 
			if (processo[i]> 0)
				Reset_C (ID_Sessione,processo[i],&ClasseErr,&NumeroErr);
				
				//inserire controllo errori
			
		}

	
}


int COpen::Connetti()
{
	WORD is=0;
	//LPSTR tt="IP.192.168.1.201"; //AddrIP.to();
	char temp[50];
	strcpy( temp, (const char*)AddrIP.mb_str(wxConvUTF8) );
	LPSTR tt=temp;
	if(simula == 0) {
		if (on_line) {
			is=OpenSession_C(tt,&ID_Sessione,&ClasseErr,&NumeroErr);
			statusbar->SetStatusText("Connected...",2);
		}
		else
			statusbar->SetStatusText("Offline",2);
	}
	else
		statusbar->SetStatusText("Simulazione",2);
		
	return is;
	
}


int COpen::Stacca()
{
	WORD is=0;
	if (on_line)
		is=CloseSession_C(ID_Sessione,&ClasseErr,&NumeroErr);
	return is;
	
}

double COpen::GetE(int nr)
{
	return varE[nr];
	
}

void COpen::SetE(int nr,double val)
{
	varE[nr]=val;
	
}

wxString COpen::GetSC(int nr)
{
	return varSC[nr];
	
}

int COpen::Refresh1()
{
	//WORD is=0;
	//char temp[50];
	//LPSTR tt=&(temp[0]);
	int ret;

	
	if (on_line) {
		ReadCurrentAnomalyMsg_C (ID_Sessione, &pAnomaly, &ClasseErr,&NumeroErr);
		
		ReadCurrentErrorMsg_C (ID_Sessione, 1, &pError, &ClasseErr,&NumeroErr);
		
		//lettura abilitazione tasti
		//ReadVarWord_C(ID_Sessione,MW_CODE,1,310,2,AbTasti,&ClasseErr,&NumeroErr);
		ReadVarWord_C(ID_Sessione,MW_CODE,1,310,2,(WORD*)&abitasti,&ClasseErr,&NumeroErr);
		//abitasti=AbTasti;
		
		//lettura azionamento tasti
		ReadVarWord_C(ID_Sessione,MW_CODE,1,312,2,(WORD*)&togtasti,&ClasseErr,&NumeroErr);
		//togtasti=ToTasti;
		toolbar->SetTasti(abitasti,togtasti);
		
		
		toolbar->refresh();
		
		//lettura stato processi master
		ReadVarWord_C(ID_Sessione,MW_CODE,1,300,5,MIsync,&ClasseErr,&NumeroErr);
		for(int i=0; i<MAX_PROC_MASTER; i++) {
			stato_m[i]=MIsync[i];
		}
		//lettura dati da distinta
		for(int i=0; i<MAX_PROC_MASTER; i++) {
			if(stato_m[i]==1) {
				ret = distinta->MandaDati(i);
				if (ret==0) {
					stato_m[i]=2;
					break;
				}
			}
		}
		
		//controllo richieste conteggio di ogni processo master
		for (int i=0; i<MAX_PROC_MASTER; i++) {
			if(stato_m[i]==3) {
				ret = distinta->Conteggio(i);
				stato_m[i]=0;
			}			
		}

	}
	
	return 0;
}


int COpen::Refresh2()
{

	if (on_line) {
	
		for(int i=0; i<MAX_PROC_MASTER; i++) {
		
			if(stato_m[i]==2) {
				for(int ii=0;ii<10;ii++) {
					if(processo[i*10+ii]>0) {
						WriteVarDouble_C(ID_Sessione,E_CODE,processo[i*10+ii],inizio_E,numero_E,varE,&ClasseErr,&NumeroErr);
						//logger->NewRiga("Invio dati main 0");
					}
				}
	//			stato_m[0]=3;
			}
		}
		
		

		for(int i=0; i<MAX_PROC_MASTER; i++) {
			if(MIsync[i] != stato_m[i]) {
				MIsync[i] = stato_m[i];
				WriteVarWord_C(ID_Sessione,MW_CODE,1,300+i,1,&(MIsync[i]),&ClasseErr,&NumeroErr); 
				
			}
		}
		comtasti = toolbar->GetTasti(&lastcommand);
		if(lastcommand==0x0008)
			StartProgram();
		if(lastcommand==0x0020)
			StopProgram();
			
		WriteVarWord_C(ID_Sessione,MW_CODE,1,314,1,(WORD*)&comtasti,&ClasseErr,&NumeroErr); //TODO separare processo x processo!!
		WriteVarWord_C(ID_Sessione,MW_CODE,1,315,1,(WORD*)&lastcommand,&ClasseErr,&NumeroErr); //TODO separare processo x processo!!
	}
	
	
	
	
	
	
//da togliere!	
		comtasti = toolbar->GetTasti(&lastcommand);
			if(lastcommand==0x0008)
			StartProgram();

	
	
	return 0;
}

int COpen::Refresh3()
{
	return 0;
}
	
//		//ReadWarningMsg_C(ID_Sessione,tt,&ClasseErr,&NumeroErr);
//		//warning.FromAscii(temp);
//		
//		if(MIsync[0]==1) {
//		//wxGetApp().Close();
//		//wxApp::GetInstance()->mainFrame->GetDati(1,&(varE[0]));
//		    WriteVarDouble_C(ID_Sessione,E_CODE,1,inizio_E,numero_E,varE,&ClasseErr,&NumeroErr);
////mainFrame->GetDati(1,&(varE[0]));
//
//			//wxTheApp->CallAfter()
//			MIsync[0]=2;
//		
//		}
//		if(MIsync[0]==3)
//			MIsync[0]=0;
//			
//		WriteVarWord_C(ID_Sessione,MW_CODE,1,300,5,MIsync,&ClasseErr,&NumeroErr);
//			
//	}	
	
	
	

//WORD ReadVarWord_C (
//WORD  UserSession,
//WORD  Code,
//WORD  Process,
//WORD  Index,
//WORD  NumVar,
//WORD *  pValue
//DWORD * pErrClass,
//DWORD * pErrNum
//);	
//	
//	
//	WORD ReadWarningMsg_C (
//WORD  UserSession,
//LPSTR  pWarningMsg,
//DWORD * pErrClass,
//DWORD * pErrNum
//);
//}


void COpen::LeggiErrori(wxString ws)
{
//	ERR_MSG_C4 err_msg;
//	ReadErrMsg_C(ID_Sessione,1,&err_msg,&ClasseErr,&NumeroErr);

//	err_msg.Msg1[39]='\0';
//	err_msg.Msg2[39]='\0';
//	ws=err_msg.Msg1;
//	ws+=err_msg.Msg2;
	
}

//ReadErrMsg_C Legge i messaggi di errore di processo o di sistema 4x 40 caratteri
//Legge il testo relativo ai messaggi da part program (istruzione DIS)ReadPartProgramMsg_C 130 caratteri

//	void COpen::set_distinta (CDistinta* _distinta) {
//		distinta = _distinta;
//	}
//	void COpen::set_logger (CLogger* _logger) {
//		logger = _logger;
//	}

