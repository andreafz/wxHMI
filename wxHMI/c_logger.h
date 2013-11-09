#ifndef GESTLOGGER_H
#define GESTLOGGER_H

#include "wxcrafter.h"


class CLogger
{
public:
	CLogger();
	~CLogger();
	void NewRiga(wxString ws);
	void Append(wxString ws);
	
	void SetTextCtrl(wxTextCtrl* _out){
		out = _out;
	}

protected:	
	wxTextCtrl* out;
	//wxDateTime* time;

};

#endif // GESTLOGGER_H
