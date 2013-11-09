
#pragma GCC system_header
#include <windef.h>
#include "CndexLinkUser.h"
#include "wxcrafter.h"
#include "c_logger.h"
#include "my_defines.h"
#include "c_statusbar.h"

#ifndef OPEN_H
#define OPEN_H

//#ifndef CDISTINTA_H
//#include "c_distinta.h"
//#endif

class CDistinta;
class CToolbar;
class CStatusbar;



//--------------------------------------
// tick 1 - Lettura M processi - Lettura M tasti - Scrittura M processi - Scrittura M tasti
// tick 2 - Lettura errori e messaggi
// tick 3 - libero
// tick 4 - 


class COpen
{
public:
	COpen();
	~COpen();
	
	int Refresh1(void); //ritorna 0=nulla da fare 1,2,3,4,5=aggiorna master 1,2,3,4,5 11,12,13,14,15=incrementa contatori master 1,2,3,4,5
	int Refresh2(void);
	int Refresh3(void);
	int Connetti(void);
	int Stacca(void);
	double GetE(int nr);
	void SetE(int nr, double val);
	void LeggiErrori(wxString ws);

	wxString GetSC(int nr);
	void SetSC(int nr, wxString ws);
	void StartProgram(void);
	void StopProgram(void);
	int InitOpen(void);
	
	WORD ID_Sessione;
	DWORD ClasseErr;
	DWORD NumeroErr;	
	double varE[100];
	wxString varSC[10];
	wxString warning;
	WORD MIsync[MAX_PROC_MASTER];
	DWORD Tasti;
	WORD AbTasti[2];
	WORD ToTasti[2];
	unsigned int abitasti;
	unsigned int togtasti;
	
	unsigned int comtasti;
	int lastcommand;
	
	
	int inizio_E;
	int numero_E;
	int inizio_SC;
	int numero_SC;
	
	int mtasti;
	int mabtasti;
	int TTick;

	
	
	int processo[(MAX_PROC_SLAVE+1)*MAX_PROC_MASTER];  //[0]Primo master[1...9]Slave primo master [10]Secondo master ...
	
	int stato_m[MAX_PROC_MASTER]; //0=nessuna richiesta
	                //1=richiesta dati
					//2=attesa spedizione dati
					//3=richiesta conteggio
					//4=conteggio eseguito
	
	
	void set_distinta (CDistinta* _distinta) {
		distinta = _distinta;
	}
	void set_logger (CLogger* _logger) {
		logger = _logger;
	}
	void set_statusbar (CStatusbar* _statusbar) {
		statusbar = _statusbar;
	}	
	void set_toolbar (CToolbar* _toolbar) {
		toolbar = _toolbar;
	}	
	void SetStatusbar (CStatusbar* _statusbar) {
		statusbar = _statusbar;
	}
	

MSG_ERROR_C4 pError;
MSG_ANOMALY_C4 pAnomaly;
	
protected:
	wxString AddrIP;
	bool on_line;
	int simula; //schema di simulazione
	int p_tot; //numero totale processi x cicli for
	CDistinta* distinta;
	CLogger* logger;
	CStatusbar* statusbar;
	CToolbar* toolbar;
	wxString program[5];

};

#endif // OPEN_H
