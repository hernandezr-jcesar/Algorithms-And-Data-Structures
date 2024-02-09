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

int insert(lista* head1, lista* head2,int k){
	lista curr,temp,head_1,head_2;
	if(!lis_vac(head1)){
    //curr = NULL;
    //temp = NULL;
	head_1 = *head1;
	head_2 = *head2;
	//head1= *head1;
	//head2= *head2;
	//traverse the first linked list until k-the
	//point is reached
	int count = 1;
	curr = head_1;
	while(count < k-1){
		curr = curr->sig;
		count++;
	}
	// bakup next node of the k-th point
	temp = curr->sig;
	//join second linked list at the k-th point
	curr->sig = head_2;
	//traverse the second linked list till end
	while(head_2->sig != NULL)
		head_2 = head_2->sig;
	//join the second part of the linked list 
	//to the end 
	head_2->sig=temp;
	}
	return OK;
}


