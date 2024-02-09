#include "nodo.h"

int nsetd (ptrnod n, datogen d){
  if(!VAL_AP(n))
    return ERR_APUINV;
  n->d = d;
  return OK;
}

int ngetd (ptrnod n, datogen* d){
  if(!VAL_AP(n))
    return ERR_APUINV;
  *d = n->d;
  return OK;
}

int nsets (ptrnod n, ptrnod d){
  if(!VAL_AP(n))
    return ERR_APUINV;
  n->sig = d;
  return OK;
}

int ngets (ptrnod n, ptrnod* d){
  if(!VAL_AP(n))
    return ERR_APUINV;
  *d = n->sig;
  return OK;
}
