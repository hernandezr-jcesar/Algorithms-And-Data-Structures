#ifndef NODO_H
#define NODO_H

#include "err.h"

typedef void* datogen;
typedef struct nodo{
  datogen   d;
  struct nodo* sig;
}nodo;

typedef nodo* ptrnod;

int nsetd (ptrnod, datogen);
int ngetd (ptrnod, datogen*);
int nsets (ptrnod, ptrnod);
int ngets (ptrnod, ptrnod*);
#endif
