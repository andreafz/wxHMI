
#include "c_toolbar.h"

#include "wx/config.h"
#include "wx/fileconf.h"

CToolbar::CToolbar()
{
	toolbar = 0;
	lastbutton = 0;
}

CToolbar::~CToolbar()
{
}

int CToolbar::InitToolbar()
{

	if(!toolbar)
		return -1;
	
	logger->NewRiga("toolbar.ini reading .....");
	
	wxString ws;
	wxString ws1;
	wxString chiave;
	
	//wxBitmap bmp1;
	wxIcon bmp1;
	//wxBitmap bmp2;
	wxIcon bmp2;
	
	wxImage ima1;
	wxImage ima2;
	
	int id,u;
	unsigned int mask;

	
	wxFileConfig *FilIni = new wxFileConfig("", "", "toolbar.ini","toolbar.ini",
							wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_RELATIVE_PATH);

	if (!FilIni) {
		logger->Append(" FAIL!");
		return -2;
	}
		
	


	FilIni->Read("TOOLBAR/max_but",&max_but);
	

	if(max_but<1 || max_but>20)
		return -12;
		
	toolbar->ClearTools();

	num_bottoni=0;
		
	for (int i=0; i<max_but; i++) {
		//compongo indice colonna
		chiave = "BUTTON";
		chiave << (i+1);
		FilIni->Read((chiave+"/id"),&id);
		if(id==0) {
			toolbar->AddSeparator();
			toolbar->AddSeparator();
		}
		if(id>0) {
			FilIni->Read((chiave+"/toggle"),&(toggle[num_bottoni]));
			FilIni->Read((chiave+"/abil"),&(abil[num_bottoni]));
			FilIni->Read((chiave+"/icona1"),&ws);						
			ws1=".\\icon\\"+ws;			
			ima1.LoadFile(ws1, wxBITMAP_TYPE_PNG);
			ima1.SetMaskColour(0,0,0);
			FilIni->Read((chiave+"/icona2"),&ws);
			ws1=".\\icon\\"+ws;
			ima2.LoadFile(ws1, wxBITMAP_TYPE_PNG);
			ima2.SetMaskColour(0,0,0);
			if(toggle[num_bottoni]==true)
				toolbar->AddTool(id, _("Tool Label"), ima1, ima2, wxITEM_CHECK, wxT(""), wxT(""), NULL);
			else
				toolbar->AddTool(id, _("Tool Label"), ima1, ima2, wxITEM_NORMAL, wxT(""), wxT(""), NULL);
			
			//toolbar->SetToggle(id,true);
			//wxITEM_NORMAL
			idtasti[num_bottoni]=id;
			
			
			u=id-8000;
			mask=0x00000001;
			mask=mask<<u;
			abimask[num_bottoni]=mask;
			
			num_bottoni++;
		}
	}
	toolbar->Realize();
	
/////		
/////
/////
/////	FilIni->Read("BUTTON1/id",&id);
/////	FilIni->Read("BUTTON1/icona",ws);
/////	
/////	//wxBitmap tt(".\\icon\\media_pause.PNG");
/////	//wxBitmap::wxBitmap(ws);
/////	
/////	//tt.LoadFile(".\\icon\\media_pause.PNG");
/////	
///////	wxBitmap bitmap(wxT(“print.xpm”), wxBITMAP_TYPE_XPM);
/////	wxBitmap tt;
/////	tt.LoadFile(wxT(".\\icon\\media_pause.PNG"), wxBITMAP_TYPE_PNG);
/////	
/////	//tt.
/////	
/////	//if(id>0) {
/////		bottone[0] = new wxBitmapButton(toolbar, 8000, tt, wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
/////	tt.LoadFile(wxT(".\\icon\\media_play_green.PNG"), wxBITMAP_TYPE_PNG);
/////		bottone[1] = new wxBitmapButton(toolbar, 8001, tt, wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
/////tt.LoadFile(wxT(".\\icon\\media_pause.PNG"), wxBITMAP_TYPE_PNG);
/////		bottone[2] = new wxBitmapButton(toolbar, 8002, tt, wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
/////	tt.LoadFile(wxT(".\\icon\\media_play_green.PNG"), wxBITMAP_TYPE_PNG);
/////		bottone[3] = new wxBitmapButton(toolbar, 8003, tt, wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
/////tt.LoadFile(wxT(".\\icon\\media_pause.PNG"), wxBITMAP_TYPE_PNG);
/////		bottone[4] = new wxBitmapButton(toolbar, 8004, tt, wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
/////	tt.LoadFile(wxT(".\\icon\\media_play_green.PNG"), wxBITMAP_TYPE_PNG);
/////		bottone[5] = new wxBitmapButton(toolbar, 8005, tt, wxDefaultPosition, wxSize(-1,-1), wxBU_AUTODRAW);
/////		toolbar->AddControl(bottone[0]);
/////		toolbar->AddSeparator();
/////		toolbar->AddControl(bottone[1]);
/////		toolbar->AddSeparator();
/////		toolbar->AddControl(bottone[2]);
/////		toolbar->AddSeparator();
/////		toolbar->AddControl(bottone[3]);
/////		toolbar->AddSeparator();
/////		toolbar->AddControl(bottone[4]);
/////		toolbar->AddSeparator();
/////		toolbar->AddControl(bottone[5]);
/////		
/////		bottone[3]->SetBitmapDisabled()
/////		toolbar->Realize();
/////		
/////
	
	
	//}
  
	
//	tb->AddTool(id,"label",tt);
	//tb->AddTool()
	
	delete FilIni;

	logger->Append(" done.\n");

	return 0;
}


void CToolbar::Comando(wxCommandEvent& event)
{
	int id = event.GetId();
	
	for (int i=0; i<num_bottoni; i++) {
		if(idtasti[i] == id)
			lastbutton = abimask[i];
	}

}

void CToolbar::refresh() 
{
	for (int i=0; i<num_bottoni; i++) {
		if (toggle[i]== true)
			toolbar->ToggleTool(idtasti[i],(togtasti & abimask[i]));
		if (abil[i]== true)
			toolbar->EnableTool(idtasti[i],(abitasti & abimask[i]));
	}
	
}

unsigned short int CToolbar::GetTasti(int* _lastbutton) 
{
	unsigned short int tasti=0;
	for (int i=0; i<num_bottoni; i++) {
		if(toolbar->GetToolState(idtasti[i]) == true)
			tasti=tasti | abimask[i];
			//toolbar->gettool
	}
	*_lastbutton = lastbutton;
	lastbutton = 0;
	return tasti;
}