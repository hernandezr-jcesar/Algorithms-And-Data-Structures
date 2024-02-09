#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Objetivo:
  Verificar el funcionamiento de la pila de enteros 
  invocando de forma aleatoria a todas las funciones
  que se implementan.
*/

int main(){
  char salida[10000];
  
  DATO eltope;
  pila p;
  int i,err,opc;
  
  inic_pil(&p);
  
  /*Ciclo para todas las pruebas*/
  for(i=0;i<500;i++){
    opc = rand()%6;
    printf("La pila es:%s",tostr_pil(salida,&p));
    switch(opc){
      case 0: 
        printf("Crea pila\n");
        err = crea_pil(&p);
        break;
      case 1: 
        printf("Elimina toda la pila\n");
        err = elim_pil(&p);
        break;
      case 2:
      case 3:
        printf("Inserta %d en pila\n",eltope=rand());
        err = push_pil(&p,eltope);
        break;
      case 4: 
        printf("Elimina dato de la pila\n");
        err = pop_pil(&p);
        break;
      case 5: 
        err = tope_pil(&eltope, &p);
        printf("El tope de la pila es %d\n", eltope);
        break;
    }
    printf("Regresa: %d %s\n",err,tostr_pil(salida,&p));
  }
  elim_pil(&p);
  return 0;
}
