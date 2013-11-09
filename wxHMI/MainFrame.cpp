#include "MainFrame.h"
#include <wx/aboutdlg.h>
#include <wx/generic/grid.h>
//#extern MainFrame::InitDistinta();



MainFrame::MainFrame(wxWindow* parent)
	: MainFrameBaseClass(parent)
{
	int ret = 0;
	wxString err;
	tick = 0;

	toolbar = new CToolbar;
	statusbar = new CStatusbar;
	logger = new CLogger();
	open20 = new COpen();
	distinta = new CDistinta();

	statusbar->SetStatusbar(m_statusBar11);
	
	logger->SetTextCtrl(m_textCtrl238);
	distinta->SetGrid(m_grid53);
	distinta->SetCnc(open20);
	distinta->SetLogger(logger);
	distinta->SetStatusbar(statusbar);
	open20->set_distinta(distinta);
	open20->set_logger(logger);
	open20->set_toolbar(toolbar);
	open20->SetStatusbar(statusbar);
	toolbar->SetToolbar(m_mainToolbar);
	toolbar->set_logger(logger);

	ret = distinta->InitDistinta();
	if (ret < 0) wxLog::OnLog(wxLOG_Error,err.Format("Function InitDistinta return error code:%i",ret));
	
	ret = toolbar->InitToolbar();
	if (ret < 0) wxLog::OnLog(wxLOG_Error,err.Format("Function InitToolbar return error code:%i",ret));
	
	ret = statusbar->InitStatusbar();
	if (ret < 0) wxLog::OnLog(wxLOG_Error,err.Format("Function InitStatusbar return error code:%i",ret));
	
	ret = open20->InitOpen();
	if (ret < 0) wxLog::OnLog(wxLOG_Error,err.Format("Function InitOpen return error code:%i",ret));
	
	open20->Connetti();
	
	TTick = open20->TTick;  //la temporizzazione del tick è stata letta dal cnc.ini

	m_timer142->Start(1000,true);

//	m_statusBar11->SetStatusText("campo1",0);
//	m_statusBar11->SetStatusText("campo2",1);
//	m_statusBar11->SetStatusText("campo3",2);
//
}

MainFrame::~MainFrame()
{
	open20->Stacca();
	delete logger;
	delete open20;
	delete distinta;
	delete toolbar;
	delete statusbar;

}

void MainFrame::OnExit(wxCommandEvent& event)
{
	wxUnusedVar(event);
	Close();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxUnusedVar(event);
	wxAboutDialogInfo info;
	info.SetCopyright(_("My MainFrame"));
	info.SetLicence(_("GPL v2 or later"));
	info.SetDescription(_("Short description goes here"));
	::wxAboutBox(info);
}


void MainFrame::OnTimer(wxTimerEvent& event)
{
	if((titask==0) || (titask==2)) {
		open20->Refresh1();  //controllo richieste
		open20->Refresh2(); //assservimento richieste
	}
	if(titask==1) {
		open20->Refresh3();  //aggiornamento messaggi/allarmi ecc.
	}
	if(titask==3) {
		//libero
	}
	
	tick=tick+1;
	if(titask<3)
		titask++;
	else
		titask=0;
		
	m_timer142->Start(TTick,true);

}


void MainFrame::edit_distinta(wxGridEvent& event)
{
	distinta->EditRiga(event);
}

void MainFrame::comando_toolbar(wxCommandEvent& event)
{
	toolbar->Comando(event);
}
void MainFrame::comando_distinta(wxCommandEvent& event)
{
	int id=event.GetId();
	if(id==ID_INSRDIS)
		distinta->InsRiga(event);
	if(id==ID_DELRDIS)
		distinta->DelRiga(event);
	if(id==ID_VUOTDIS) {
		distinta->CancellaDistinta();
		distinta->SalvaDistinta(false);
	}		
	if(id==ID_LOADDIS) {
		distinta->CaricaDistinta(true);
		distinta->SalvaDistinta(false);		
	}
	if(id==ID_SAVEDIS)
		distinta->SalvaDistinta(false);
	if(id==ID_SAVADIS) {
		distinta->SalvaDistinta(true);		
		distinta->SalvaDistinta(false);		
	}
}

