#ifndef CVCLASS_H
#define CVCLASS_H

#include "c_logger.h"
#include "my_defines.h"

struct dati_riga_distinta {
	double   d[MAX_COL_DIS];
	int      i[MAX_COL_DIS];
	short int fatti[MAX_PROC_MASTER];
	wxArrayString s;
};


class RigaDist
{
public:
	RigaDist();
	~RigaDist();

	dati_riga_distinta dati;

};

WX_DECLARE_LIST(RigaDist, ListaRighe);

#endif