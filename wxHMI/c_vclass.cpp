#include "c_vclass.h"

RigaDist::RigaDist()
{
	//precarico l'array di stringhe
	for (int i=0; i<20; i++) {
		dati.s.Add("",1);  //TODO vedere se si può mettere al posto dell'1
		dati.d[i]=0.0;
		dati.i[i]=0;
	}
	for (int i=0; i<5; i++)
		dati.fatti[i]=0;

}

RigaDist::~RigaDist()
{
//for (int i=0; i<20; i++)
	//dati.s[i]->Delete();
}
//TODO int MainFrame::GetDati(int processo, int* dati)
//TODO {
//TODO
//TODO 	ListaRighe::Node* nrd;
//TODO 	RigaDist* rd;
//TODO
//TODO 	int riga = m_grid53->GetRows();
//TODO 	nrd = Distinta->Item(riga);
//TODO 	rd = nrd->GetData();
//TODO
//TODO 	for(int ii=0;ii<10;ii++) {
//TODO 		*dati=rd->dati.d[ii];
//TODO 		dati++;
//TODO 	}
//TODO
//TODO 	return 0;
//TODO }
