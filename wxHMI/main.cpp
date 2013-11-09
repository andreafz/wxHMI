/* DA FARE */
// attenzione alle 10 righe di distinta in + ... non c'e' l'oggetto relativo!
// salvare e ricaricare distinta in lavoro
// x lavorare offline
// x indirizzo ip su ini
// trasmettere ascii
// x timer!
// barra di stato
// dialogo di avvio
// colonne da non trasmettere
// funzioni add_linea cop_riga del_riga ....





#include <wx/app.h>
#include <wx/event.h>
#include "MainFrame.h"
#include "c_distinta.h"
#include <wx/image.h>

// Define the MainApp
class MainApp : public wxApp
{
public:
	MainApp() {}
	virtual ~MainApp() {}
	
	virtual bool OnInit() {
		// Add the common image handlers
		wxImage::AddHandler( new wxPNGHandler );
		wxImage::AddHandler( new wxJPEGHandler );
		
		MainFrame *mainFrame = new MainFrame(NULL);
		
		SetTopWindow(mainFrame);
		return GetTopWindow()->Show();
	}
};

DECLARE_APP(MainApp)
IMPLEMENT_APP(MainApp)
