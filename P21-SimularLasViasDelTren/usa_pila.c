#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define TAM_ENT    3

/*Objetivo:
  Comenzando de una cadena, simular el ejercicio de las 
  vias del tren y obtener otra utilizando una pila.
*/

int main(){
  char salida[10000];
  
  int entrada[TAM_ENT] = {1,2,3};//Coloca aqui el orden inicial
  pila p;
  int err,tope,i;
  
  inic_pil(&p);
  
  /*Ciclo para todas las pruebas*/
  crea_pil(&p);
  
  for(i=0;i<TAM_ENT;i++){
	  /*Inicia aqui tu codigo*/
	switch(i){
	case 0:
		push_pil(&p,entrada[i]);
	break;
    case 1:
		push_pil(&p,entrada[i]);
		tope_pil(&tope,&p);
		printf(" %d ",tope);
		pop_pil(&p);
		tope_pil(&tope,&p);
		printf(" %d ",tope);
		pop_pil(&p);
	break;
	case 2:
		push_pil(&p,entrada[i]);
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
/*
ABC-->123 SI
ACB-->132 SI
CBA-->321 SI
CAB-->312 NO
BAC-->213 SI
BCA-->231 SI
*/
/*Conclusion
Las operaciones que se tendrian 
que hacer cambian respecto a la
cantidad de numeros y a los valores dados.
No se puede automatizar todo solo el conteo.
*/
/*
1 2 3 4 5 6 7
3 2 5 6 4 1 7

1 2 3 4 5 6 7
3 4 2 1 5 7 6

1 2 3 4 5 6 7
3 5 4 6 7 2 1
*/