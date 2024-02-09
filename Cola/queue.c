#include "queue.h"
/*********************************************************
              F U N C I O N E S      L O C A L E S
*********************************************************/
/*Recorre los datos del arreglo, se elimina el primer
  elemento del arreglo*/
int recorre(DATO* q,int n){
  int i;
  for(i=0;i<n-1;i++)
    q[i]=q[i+1];
  return OK;
}
/*********************************************************
              D E F I N E    L A   I N T E R F A C E
*********************************************************/

/*Inicializa una cola a cola vacía*/
int crea_que(queue* q){
  if(!AP_VAL(q))
    return AP_INV;
  q->fin = 0;
  return OK;
}
/*Inserta un elemento en la cola*/
int inse_que(queue* q,DATO d){
  if(!AP_VAL(q))
    return AP_INV;
  if(!TIE_ESP(q))
    return OVERFLOW;
  q->datos[q->fin++]=d;
  return OK;
}
/*Elimina todos los datos de la cola*/
int elim_que(queue* q){
  if(!AP_VAL(q))
    return AP_INV;
  q->fin=0;
  return OK;  
}
/*Obtener el elmento a ser atendido en la cola*/
int atie_que(const queue* q,DATO* d){
  if(!(AP_VAL(q)&&AP_VAL(d)))
    return AP_INV;
  *d = q->datos[0];
  return OK;
}

/*Elimina el primer dato insertado en la cola*/
int avan_que(queue* q){
  if(!AP_VAL(q))
    return AP_INV;
  recorre(q->datos,q->fin--);
  return OK;
}
/*Convierte una cola en cadena*/
char* str_que(char* s, const queue* q){
  char s_dato[TAMDAT];
  int i;
  if(!(AP_VAL(s)&&AP_VAL(q)))
    return s;
  strcpy(s,"<");
  for(i=0;i<q->fin;i++){
    sprintf(s_dato,FORMATO,q->datos[q->fin-i-1]);
	strcat(s,s_dato);	
  }
  strcat(s," >");
  return s;
}
/* Obtiene el tamano de la cola */
int tam_que(queue* q){
  if(!AP_VAL(q))
    return AP_INV;
  int cantidad;
  cantidad=q->fin;
  printf("Tamanio:%d",cantidad);
  return OK;
}
/* Muestra la capacidad ocupada de la cola*/
int capac_que(queue* q){
  if(!AP_VAL(q))
    return AP_INV;
  printf("Espacios ocupados %d de %d",q->fin,TAMMAX);
  return OK;
}
/* Regresa el ultimo elemento insertado en la cola*/
int ulti_que(queue* q){
  if(!AP_VAL(q))
    return AP_INV;
  int i,conta=0;
  for(i=0;i<q->fin;i++){
	  conta++;
  }
   printf("Ultimo elemento:%d",q->datos[conta-1]);
  return OK;
}
