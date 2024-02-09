#include <stdio.h>
#include "alumno.h"
#include "inicializar.h"
#include "buscar.h"

int cmp_edad_alu(const alumno* a1, const alumno* a2){
  int res=0;
  if(a1->edad < a2->edad)
    res =-1;
  else if(a1->edad > a2->edad)
    res = 1;
  return res;
}

int cmp_noms_alu(const alumno* a1, const alumno* a2){
  return strcmp(a1->noms_c,a2->noms_c);
}


int main(){
  alumno ar_alumno[100];
  alumno alu_bus;
  char salida[100];
  int i,pos,n = 50;
  
  inicializar(ar_alumno,&n);
  set_noms(&alu_bus, "Rafael");
  
  buscar(&pos,&alu_bus, ar_alumno,n,cmp_noms_alu);
  if(pos!=-1)
      printf("El dato es %d) %s\n",pos,get_nomc(salida,ar_alumno+pos));

  return 0;
}