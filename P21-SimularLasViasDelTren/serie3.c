/*
ORIGEN
1 2 3 4 5 6 7
DESTINO
3 5 4 6 7 2 1
*/
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define TAM_ENT    7

/*Objetivo:
  Comenzando de una cadena, simular el ejercicio de las 
  vias del tren y obtener otra utilizando una pila.
*/

int main(){
  char salida[10000];
  
  int entrada[TAM_ENT] = {1,2,3,4,5,6,7};//Coloca aqui el orden inicial
  pila p;
  int err,tope,i;
  
  inic_pil(&p);
  
  /*Ciclo para todas las pruebas*/
  crea_pil(&p);
  printf("Cadena Inicial:\n 1  2  3  4  5  6  7\nCadena Final:\n");
  for(i=0;i<TAM_ENT;i++){
	  /*Inicia aqui tu codigo*/
	switch(i){
	case 0:
		push_pil(&p,entrada[i]);
	break;
    case 1:
		push_pil(&p,entrada[i]);
	break;
	case 2:
		push_pil(&p,entrada[i]);
		tope_pil(&tope,&p);
		printf(" %d ",tope);
		pop_pil(&p);
	break;
	case 3:
		push_pil(&p,entrada[i]);
	break;
	case 4:
		push_pil(&p,entrada[i]);
		tope_pil(&tope,&p);
		printf(" %d ",tope);
		pop_pil(&p);
		tope_pil(&tope,&p);
		printf(" %d ",tope);
		pop_pil(&p);
	break;
	case 5:
		push_pil(&p,entrada[i]);
		tope_pil(&tope,&p);
		printf(" %d ",tope);
		pop_pil(&p);
	break;
	case 6:
		push_pil(&p,entrada[i]);
		tope_pil(&tope,&p);
		printf(" %d ",tope);
		pop_pil(&p);
		tope_pil(&tope,&p);
		printf(" %d ",tope);
		pop_pil(&p);
		tope_pil(&tope,&p);
		printf(" %d ",tope);
		pop_pil(&p);
	break;
	}
	/*Termina aqui tu codigo*/
  }
  printf("\n");
  elim_pil(&p);
  return 0;
}