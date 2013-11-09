#ifndef MAINFRAME_H
#define MAINFRAME_H
//#include <wx/listimpl.cpp>
#include "wxcrafter.h"
#include <wx/log.h>
#include "c_distinta.h"
#include "c_open.h"
#include "c_logger.h"
#include "c_toolbar.h"
#include "c_statusbar.h"




class MainFrame : public MainFrameBaseClass
{
public:
	MainFrame(wxWindow* parent);
	virtual ~MainFrame();

	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnTimer(wxTimerEvent& event);

	int GetDati(int processo, int* dati);
	int MandaDati(int master);
	int Conteggio(int master);
	int Evoluzione(int master);

	CLogger* logger;
	CDistinta* distinta;
	CToolbar* toolbar;
	CStatusbar* statusbar;
	COpen* open20;
	
	long int tick;
	int titask;	//tick-task
	int TTick;

	//CMessaggi* areamessaggi;

protected:
	virtual void comando_distinta(wxCommandEvent& event);
	virtual void comando_toolbar(wxCommandEvent& event);
	virtual void edit_distinta(wxGridEvent& event);



	wxString ws_err;





};
#endif // MAINFRAME_H
