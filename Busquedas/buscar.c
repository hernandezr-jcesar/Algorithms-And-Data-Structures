#include "buscar.h"

int buscar(int* pos, const alumno* f, alumno* a, int n, fun_cpm f_cmp){
  int i,esta;
  if(!AP_VAL(a))
    return AP_INV;
  if(!AP_VAL(pos))
    return AP_INV;
  if(!(n>0))
    return DI_INV;
  *pos=-1;
  esta=0;
  while(!esta && *pos<n)
    esta = f_cmp(&a[++(*pos)],f)==0;
  *pos=*pos==n?-1:*pos;
  return OK;
}