#ifndef CDISTINTA_H
#define CDISTINTA_H
#include "c_vclass.h"

#include "wxcrafter.h"
#include "c_logger.h"
#include <wx/filedlg.h>
#include "my_defines.h"
#include "c_statusbar.h"


class COpen;

class CDistinta
{
public:
	CDistinta();
	~CDistinta();
	
	int InitDistinta();
	void SalvaDistinta(bool saveas);
	void CaricaDistinta(bool loadas);
	void CancellaDistinta(void);

	void EditRiga(wxGridEvent& event);
	void InsRiga(wxCommandEvent& event);
	void DelRiga(wxCommandEvent& event);
	void CopiaRiga(wxCommandEvent& event);

	int MandaDati(int master);
	int Conteggio(int master);
	int Evoluzione(int master);
	int SetStartRow(void);

	void SetGrid(wxGrid* _grid){
		grid = _grid;
	}
	void SetCnc(COpen* _cnc){
		cnc = _cnc;
	}
	void SetLogger (CLogger* _logger) {
		logger = _logger;
	}
	void SetStatusbar (CStatusbar* _statusbar) {
		statusbar = _statusbar;
	}

	
	
	
protected:
	wxGrid* grid;
	COpen* cnc;
	CLogger* logger;
	CStatusbar* statusbar;
	wxString dist_path;
	wxString nome_dist;
	wxFileDialog* fd;

	ListaRighe* lista;
	int tip_colonna[MAX_COL_DIS];  //0=ascii 1=double 2=int 3=bool
	int car_colonna[MAX_COL_DIS];  //per ora non testato
	int dec_colonna[MAX_COL_DIS];  //numero decimali 
	int offs_var[MAX_COL_DIS];     //offset variabile destinazione da applicare al parametro della sezione OPEN
	int num_var;          			//numero variabili totali (serve per fare i cicli for)
	int num_col;		  				//numero colonne
	int p_fare;  						//puntatore alla colonna preset (var I) 
	int p_fatti;  						//puntatore alla colonna fatti (var I) 
	int master_c; 						//puntatore al master che esegue conteggio a video
	
	int p_master[MAX_PROC_MASTER];  //puntatori alla riga dei processi master
	
};

#endif // CDISTINTA_H
