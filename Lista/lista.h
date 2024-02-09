#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "err.h"
#include "nodo.h"

#define ERR_LISVAC  1  /*Lista Vacía*/
#define TAMCAD      20

typedef nodo* lista;


int lis_vac(const lista*);
int lis_crea(lista*);
int lis_elim(lista*);
int lis_insi(lista*,datogen);
int lis_elii(lista*,datogen*);
int lis_inve(lista*);
char* lis_mue (const lista*,char*);

#endif
