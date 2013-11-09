#include "c_distinta.h"
#include "c_open.h"

#include "wx/config.h"
#include "wx/fileconf.h"
#include <wx/listimpl.cpp>


WX_DEFINE_LIST(ListaRighe);

CDistinta::CDistinta()
{
	grid=0;
	logger=0;
	cnc=0;
		
	num_var=0;
	num_col=0;
	master_c=-1;
	p_fare=0;
	p_fatti=0;
	
	nome_dist="";

	for (int i=0; i<MAX_PROC_MASTER; i++) {
		p_master[i]=0; 
	}
	
	for (int i=0; i<MAX_COL_DIS; i++) {
		tip_colonna[i]=0; 
		car_colonna[i]=0;
		dec_colonna[i]=0;
		offs_var[i]=0; 
	}
	
}

CDistinta::~CDistinta()
{
}

int CDistinta::InitDistinta()
{

	//lettura file distinta.ini
	wxString ws,st_col;
	long wl;
	int nr_col = 0;
	int dec;
	int car;
	int var;
	
	wxASSERT(logger != 0);
	wxASSERT(grid != 0);
	wxASSERT(cnc != 0);
		
	logger->NewRiga("worklist.ini reading ......");

	lista = new ListaRighe();	
		
	grid->DisableDragColMove();
	grid->DisableDragColSize();
	grid->DisableDragGridSize();
	grid->DisableDragRowSize();

	
	wxFileConfig *FilIni = new wxFileConfig("", "", INI_DISTINTA,INI_DISTINTA,
							wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_RELATIVE_PATH);

	if (!FilIni)
		return -11;

	FilIni->Read("DIST/Distpath",&dist_path);
	FilIni->Read("DIST/Maxcol",&num_col);
	
	FilIni->Read("DIST/MasterC",&master_c);

	if(num_col<1 || num_col>MAX_COL_DIS)
		return -12;
		
	for (int i=1; i<=num_col; i++) {
		wl=0;
		//compongo indice colonna
		st_col = "DIST_COL";
		st_col << (nr_col+1);
		FilIni->Read((st_col+"/Abil"),&wl);
		if(wl==1) {
			grid->AppendCols();
			FilIni->Read((st_col+"/Desc"),&ws);
			grid->SetColLabelValue(nr_col,ws);	

			FilIni->Read((st_col+"/Larg"),&wl);
			grid->SetColSize(nr_col,wl);
	
			FilIni->Read((st_col+"/Tipo"),&ws);
			if(ws=="A") {
				FilIni->Read((st_col+"/Cara"),&car);
				tip_colonna[num_var]=0;
				car_colonna[num_var]=car;
				dec_colonna[num_var]=0;
				FilIni->Read((st_col+"/Vare"),&var);
				offs_var[num_var]=var;
				num_var++;
			}
			if(ws=="D") {
				FilIni->Read((st_col+"/Cara"),&car);
				FilIni->Read((st_col+"/Deci"),&dec);
				grid->SetColFormatFloat(nr_col,car,dec);
				tip_colonna[num_var]=1;
				car_colonna[num_var]=car;
				dec_colonna[num_var]=dec;
				FilIni->Read((st_col+"/Vare"),&var);
				offs_var[num_var]=var;
				num_var++;
			}
			if((ws=="I") || (ws=='P') || (ws=='C')) {
				FilIni->Read((st_col+"/Cara"),&car);
				grid->SetColFormatFloat(nr_col,car,0);
				tip_colonna[num_var]=2;
				car_colonna[num_var]=car;
				dec_colonna[num_var]=0;
				FilIni->Read((st_col+"/Vare"),&var);
				offs_var[num_var]=var;
				if(ws=="P")
					p_fare=num_var;
				if(ws=="C")
					p_fatti=num_var;
				num_var++;
			}
			if(ws=="B") {
				FilIni->Read((st_col+"/Cara"),&car);
				grid->SetColFormatFloat(nr_col,car,0);
				tip_colonna[num_var]=3;
				car_colonna[num_var]=car;
				dec_colonna[num_var]=0;
				FilIni->Read((st_col+"/Vare"),&var);
				offs_var[num_var]=var;
				num_var++;
			}
	    
			nr_col = nr_col+1;
		}
	}
	
	// il campo preset è sempre necessario
	if(!p_fare)
		return -13;
	
	delete FilIni;

	logger->Append(" done.");

	//carico distinta in lavoro
	grid->AppendRows();
	CaricaDistinta(false);
	return 0;
}

void CDistinta::EditRiga(wxGridEvent& event)
{
	int col,rig;
	col=event.GetCol();
	rig=event.GetRow();

	wxArrayInt ar;
	RigaDist* rd;
	ListaRighe::Node* nrd;

	wxString ws;
	double val;
	long lon;


	nrd = lista->Item(rig);
	rd = nrd->GetData();

	if(tip_colonna[col]==3)	{
		ws = grid->GetCellValue(rig,col);
		ws.ToLong(&lon);
		rd->dati.i[col]=(int)lon;
	} 
	if(tip_colonna[col]==2)	{
		ws = grid->GetCellValue(rig,col);
		ws.ToLong(&lon);
		rd->dati.i[col]=(int)lon;
	} 
	if(tip_colonna[col]==1)	{
		ws = grid->GetCellValue(rig,col);
		ws.ToDouble(&val);
		rd->dati.d[col]=val;
	} 
	if(tip_colonna[col]==0) {
		ws=grid->GetCellValue(rig,col);
		rd->dati.s[col]=ws;
	}

}


void CDistinta::SalvaDistinta(bool saveas)
{
	wxFile ff;
	wxString nome_file;
	int uu;
	RigaDist* rd;
	ListaRighe::Node* nrd;


	if (saveas) {
		fd = new wxFileDialog(NULL, "Save As...",dist_path,nome_dist,"*.dat", wxFD_SAVE);

		 if (fd->ShowModal() == wxID_CANCEL) {
		   delete fd;
			return; // the user changed idea...
		}
		
		nome_dist = fd->GetFilename();
	
		nome_file = dist_path+nome_dist;
	}
	else
		nome_file = ".\\DISTINTA.DAT";

	ff.Open(nome_file,wxFile::write);
	
	//se salvataggio distinta attuale
	//come prima cosa salvo il nome della distinta...
	if(saveas==false) {
		uu=wxStrlen(nome_dist);
		ff.Write(&uu,sizeof(int));
		if (uu>0)
			ff.Write(nome_dist,wxMBConvUTF8());
	}
	//... e poi tutte le righe...
	nrd=lista->GetFirst();

	while (nrd) {
		rd = nrd->GetData();

		for(int ii=0; ii<num_var; ii++) {
			ff.Write(&rd->dati.d[ii],sizeof(double));
			ff.Write(&rd->dati.i[ii],sizeof(int));
		}
		for(int ii=0; ii<num_var; ii++) {
			uu=wxStrlen(rd->dati.s[ii]);
			ff.Write(&uu,sizeof(int));
			if (uu>0)
				ff.Write(rd->dati.s[ii],wxMBConvUTF8());
		} //TODO vedere se passare all'ascii 8 bit

		nrd = nrd->GetNext();
	}

	ff.Close();

	statusbar->SetStatusText(nome_dist,0);


}

void CDistinta::CancellaDistinta()
{

	RigaDist* rd;
	ListaRighe::Node* nrd;
	nrd=lista->GetFirst();
	//cancello tutta la wxList 
	while (nrd) {
		lista->DeleteNode(nrd);
		nrd = nrd->GetNext();
	}
	//cancello la griglia
	grid->DeleteRows(0,(grid->GetNumberRows()-1));

	//inserisco una riga vuota
	rd=new RigaDist();
	lista->Append(rd);
	
}

void CDistinta::CaricaDistinta(bool loadas)
{
	wxString nome_file;
	int uu;
	char v[100];

	if (loadas) {
		fd = new wxFileDialog(NULL, "Load...",dist_path,nome_dist,"*.dat", wxFD_OPEN);
		
		 if (fd->ShowModal() == wxID_CANCEL) {
		   delete fd;
			return; // the user changed idea...
		}
		nome_dist = fd->GetFilename();
		nome_file = dist_path+nome_dist;
	}
	else
		nome_file = ".\\DISTINTA.DAT";


	logger->NewRiga("Lettura distinta");
	
	CancellaDistinta();
	wxFile ff;

	ff.Open(nome_file,wxFile::read);

	if(loadas==false) {
		ff.Read(&uu,sizeof(int));
		if(uu>0 && uu<100) {
			ff.Read(v,uu);
			v[uu]='\0';
			nome_dist = wxString::FromUTF8(v,uu);
		}
	}
	RigaDist* rd;
	wxString ws;
	int riga=0;


	while (!ff.Eof()) {
		rd=new RigaDist();
		for(int ii=0; ii<num_var; ii++) {
			ff.Read(&rd->dati.d[ii],sizeof(double));
			ff.Read(&rd->dati.i[ii],sizeof(int));
		}


		for(int ii=0; ii<num_var; ii++) {
			ff.Read(&uu,sizeof(int));
			if(uu>0 && uu<100) {
				ff.Read(v,uu);
				v[uu]='\0';
				rd->dati.s[ii] = wxString::FromUTF8(v,uu);
			}
		}
		//inserisco la riga nel database...
		lista->Append(rd);

		//..e la inserisco anche nella distinta
		grid->AppendRows();
		for(int ii=0; ii<num_var; ii++) {
			//ascii
			if(tip_colonna[ii] == 0)
				grid->SetCellValue(riga,ii,rd->dati.s[ii]);
			//double
			if(tip_colonna[ii] == 1) {
				ws = wxString::Format(wxT("%f"),rd->dati.d[ii]);
				grid->SetCellValue(riga,ii,ws);
			}
			//int
			if(tip_colonna[ii] == 2) {
				ws = wxString::Format(wxT("%i"),rd->dati.i[ii]);
				grid->SetCellValue(riga,ii,ws);
			}
			//bool  //TODO vedere se va bene
			if(tip_colonna[ii] == 3) {
				ws = wxString::Format(wxT("%i"),rd->dati.i[ii]);
				grid->SetCellValue(riga,ii,ws);
			}

		}
		riga++;
	}

	ff.Close();
	
	//controllo se distinta ha almeno 1 riga
	int i =	grid->GetNumberRows();
	if (i<1) {
		rd=new RigaDist();
		lista->Append(rd);
		grid->AppendRows();
	}
	
	statusbar->SetStatusText(nome_dist,0);

}

///void CDistinta::PopolaDistinta()
///{
///	RigaDist* rd;
///	wxString ws;
///	
///	for(int i=0 ; i<=1000 ; i++) {
///		rd=new RigaDist();
///		for(int ii=0; ii<num_var; ii++) {
///			rd->dati.d[ii]=(i+1)*100+ii;
///			if(ii==p_fare)
///				rd->dati.i[ii]=5;
///			else
///				rd->dati.i[ii]=0;
///			rd->dati.s[ii]="ABC";
///		}
///		//inserisco la riga nel database...
///		lista->Append(rd);
///		
///		//..e la inserisco anche nella distinta
///		grid->AppendRows();
///		for(int ii=0; ii<num_var; ii++) {
///
///			if(tip_colonna[ii] == 0)
///				grid->SetCellValue(i,ii,rd->dati.s[ii]);
///			//double
///			if(tip_colonna[ii] == 1) {
///				ws = wxString::Format(wxT("%f"),rd->dati.d[ii]);
///			grid->SetCellValue(i,ii,ws);
///			}
///			//int
///			if(tip_colonna[ii] == 2) {
///				ws = wxString::Format(wxT("%i"),rd->dati.i[ii]);
///			grid->SetCellValue(i,ii,ws);
///			}
///			//bool  //TODO vedere se va bene
///			if(tip_colonna[ii] == 3) {
///				ws = wxString::Format(wxT("%f"),rd->dati.i[ii]);
///			grid->SetCellValue(i,ii,ws);
///			}
///			
///		}
///
///		
///	}
///	// + 10 righe vuote....
/////	for (int i=0; i<10; i++) {
/////		rd=new RigaDist();
/////		lista->Append(rd);
/////
/////		grid->AppendRows();
/////	}
///	
///	//grid->Show(true);
///	//grid->Refresh();
///	
///}


void CDistinta::DelRiga(wxCommandEvent& event)
{
	wxArrayInt ar;
	ar = grid->GetSelectedRows();

	ListaRighe::Node* nrd;



	int u=ar.GetCount();
	for(int i=u-1; i>=0; i--) {
		grid->DeleteRows(ar.Item(i),1,false);
		nrd = lista->Item(ar.Item(i));
		lista->DeleteContents(true);
		lista->Erase(nrd);
	}

	logger->NewRiga(wxT("Cancellazione linea"));


}
void CDistinta::InsRiga(wxCommandEvent& event)
{
	wxArrayInt ar;
	RigaDist* rd;

	ar = grid->GetSelectedRows();
	int u=ar.GetCount();
	for(int i=u-1; i>=0; i--) {
		grid->InsertRows(ar.Item(i),1,false);

		rd=new RigaDist();
		lista->Insert(ar.Item(i),rd);

	}
	
	
	logger->NewRiga(wxT("Inserimento linea"));

}


int CDistinta::MandaDati(int master)
{
	ListaRighe::Node* nrd;
	RigaDist* rd;
	
	int riga = p_master[master];
	if ((riga>=0) && (riga<=1000)) {
		nrd = lista->Item(riga);
		rd = nrd->GetData();

		for(int ii=0;ii<10;ii++) {
			if(offs_var[ii]>=0)
				if (tip_colonna[ii]==1)
					cnc->varE[offs_var[ii]]=rd->dati.d[ii];
				if (tip_colonna[ii]==2)
					cnc->varE[offs_var[ii]]=(int)rd->dati.i[ii];
					
		}
	}
	return 0;

}

int CDistinta::Conteggio(int master)
{
	wxString ws;
	ListaRighe::Node* nrd;
	RigaDist* rd;
	
	nrd = lista->Item(p_master[master]);
	rd = nrd->GetData();
	
	rd->dati.fatti[master]++;
	
	//se è il master che conta in distinta...
	if(master==(master_c-1)) {
		if(p_fatti>-1) {
			rd->dati.i[p_fatti]=rd->dati.fatti[master];
			ws = wxString::Format(wxT("%i"),rd->dati.i[p_fatti]);
			grid->SetCellValue(p_master[master],p_fatti,ws);
		}
	}

	return Evoluzione(master);
}

int CDistinta::Evoluzione(int master)
{
	ListaRighe::Node* nrd;
	RigaDist* rd;
	
	nrd = lista->Item(p_master[master]);
	rd = nrd->GetData();
	
	if(rd->dati.fatti[master]>=rd->dati.i[p_fare] )
	p_master[master]++;
	return 0;
	//TODO controllare se c'e' un altra riga!
}

int CDistinta::SetStartRow()
{

	ListaRighe::Node* nrd;
	wxArrayInt ar;
	RigaDist* rd;

	ar = grid->GetSelectedRows();
	int u=ar.GetCount();
	
	if (u != 1)
		return -1;
		
	nrd = lista->Item(ar.Item(0));
	rd = nrd->GetData();

	//guardo se il primo master deve lavorare //// da fare meglio //// normalizzare distinta? TODO
	if(rd->dati.fatti[0] < rd->dati.i[p_fare] )
		return (ar.Item(0)+1);
	else
		return 0;
	
}

