#ifndef CSTATUSBAR_H
#define CSTATUSBAR_H
#include "wxcrafter.h"

class CStatusbar
{
public:
	CStatusbar();
	~CStatusbar();
	
	int InitStatusbar();
	
	void SetStatusbar(wxStatusBar* _statusbar){
		statusbar = _statusbar;
	}
	void SetStatusText(wxString value,int campo) {
		statusbar->SetStatusText(value,campo);
	}
protected:
	wxStatusBar* statusbar;

};

#endif // CSTATUSBAR_H
