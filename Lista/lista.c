#include "lista.h"

int lis_crea(lista* l){
  /*validar¿?*/
  *l = NULL;
  return OK;
}

int lis_elim(lista* l){
  datogen d;

  while(!lis_vac(l))
    lis_elii(l,&d);
  return OK;
}


int lis_vac(const lista* l){
  return *l==NULL;
}

int lis_insi(lista* l ,datogen d){
  lista x;

  x = (lista) malloc(sizeof(nodo));
  if(!x)
    return ERR_INSMEM;
  nsetd((ptrnod)x,d);
  nsets((ptrnod)x,(ptrnod)*l);
  *l = x;
  return OK;
}

int lis_elii(lista* l ,datogen *d){
  lista x;

  if(lis_vac(l))
    return ERR_LISVAC;
  x = *l;
  ngetd((ptrnod)x,d);
  ngets((ptrnod)x,(ptrnod*)l);
  free(x);
  return OK;
}

int lis_inve(lista* l){
  lista ant2,ant1,aux;
  if(!lis_vac(l)){
    ant2 = NULL;
    ant1 = NULL;
    aux = *l;
    while(aux){
      ant2=ant1;
      ant1=aux;
      aux=aux->sig;
      ant1->sig=ant2;
    }
    *l = ant1;
  }
  return OK;
}

char* lis_mue (const lista* l,char* sal){
  lista x;
  char tmp[TAMCAD];
  datogen dato;
  int *ls;

  sal[0]='\0';
  sprintf(sal,"[");
  x = *l;
  while (!lis_vac(&x)){
    ngetd((ptrnod)x,&dato);
    ls = (int*)dato;
    sprintf(tmp," %c ",*ls);
    ngets((ptrnod)x,(ptrnod*)&x);
    strcat(sal,tmp);
  }
  strcat(sal, "]");
  return sal;
}
