#include "c_logger.h"

CLogger::CLogger()
{

}

CLogger::~CLogger()
{
	
}

void CLogger::NewRiga(wxString ws)
{
	wxDateTime time = wxDateTime::Now();
	wxString vv=time.FormatTime();
	out->AppendText("\n"+vv+" - "+ws);

}
void CLogger::Append(wxString ws)
{
	out->AppendText(ws);
}