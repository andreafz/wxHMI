#ifndef CTOOLBAR_H
#define CTOOLBAR_H

#include <wx/button.h>
#include <wx/toolbar.h>
#include <wx/bmpbuttn.h>
#include "c_logger.h"


class CToolbar
{
public:
	CToolbar();
	~CToolbar();
	
	int InitToolbar();

	
	void SetToolbar(wxToolBar* _toolbar){
		toolbar = _toolbar;
	}
	void set_logger (CLogger* _logger) {
		logger = _logger;
	}

	void Comando(wxCommandEvent& event);
	
	void SetTasti(unsigned short int _abitasti, unsigned short int _togtasti) {
		abitasti = _abitasti;
		togtasti = _togtasti;
	}
	unsigned short int GetTasti(int* lastbutton);
	
	void refresh();
	
protected:
	wxToolBar* toolbar;
	CLogger* logger;
	
	int max_but;
	unsigned short int abitasti;  //abilitazione tasti
	unsigned short int togtasti;  //azionamento tasti
	unsigned short int abimask[32];
	int idtasti[32];
	bool abil[32];
	bool toggle[32];
	
	int num_bottoni;
	int lastbutton;

};

#endif // CTOOLBAR_H
