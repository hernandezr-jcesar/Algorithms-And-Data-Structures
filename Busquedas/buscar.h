#ifndef _BUSCAR_H
#define _BUSCAR_H

#include "alumno.h"

#define DI_INV     60

typedef int (*fun_cpm)(const alumno*, const alumno*);


int buscar(int* pos, const alumno* f, alumno* a, int n, fun_cpm);

#endif