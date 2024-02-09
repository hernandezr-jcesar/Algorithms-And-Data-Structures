#ifndef QUEUE_H
#define QUEUE_H
/**********************************************************
Define una estructura de cola utilizando un arreglo y
un entero que indica cuál es el último elemento en la cola.
Se incerta con los indices más grandes y se elimina del 
  inicio
Fecha: Noviembre 2020
**********************************************************/
#include "err.h"
#include <string.h>
#include <stdio.h>
/**********************************************************
                       C O N S T A N T E S
**********************************************************/
#define   OVERFLOW        10
#define   UNDERFLOW       11
#define   TAMMAX          1000

/*Sobre el dato*/
#define   DATO            int
#define   FORMATO         " %d"
#define   TAMDAT          10
/**********************************************************
                       M A C R O S
**********************************************************/
#define   TIE_ESP(q)     ((q)->fin<TAMMAX)
#define   TIE_DAT(q)     ((q)->fin>0)
#define   LENA(q)        ((q)->fin==TAMMAX)
#define   VACIA(q)       ((q)->fin==0)
/**********************************************************
                       T I P O S
**********************************************************/
typedef struct{
  DATO datos[TAMMAX];  /*Datos en la cola*/
  int fin;             /*Ultimo elemento en la cola*/
                       /*0 es el primer elemento */
}queue;
/**********************************************************
                       F U N C I O N E S
**********************************************************/
/*                    Constructores                      */
/*Crea una cola vacía
Recibe:  Apuntador a la cola a ser creada
Regresa: Códico de error
*/
int crea_que(queue*);
/*                    Inserta elemento                   */
/*Inserta un elemento en una cola
Recibe:  Apuntador a la cola a ser modificada
         Elemento a ser insertado
Regresa: Códico de error
*/
int inse_que(queue*,DATO d);
/*                    Modificadores                      */
/*Elimina la cola de forma completa
Recibe:  Apuntador a la cola a ser eliminada
Regresa: Códico de error
*/
int elim_que(queue*);
/*Retira un elemento de la cola
Recibe:  Apuntador a la cola a ser eliminada
Regresa: Códico de error
*/
int avan_que(queue*);
/*                    Observadores                      */
/*Regresa el elmento a ser atendido en la cola
Recibe: La cola con datos
        Un apuntador a dato para asignar el elemento
Regresa: Código de error
*/
int atie_que(const queue*,DATO*);
/*Convierte una cola en cadena
Recibe: Cadena de salida
        Cola a ser convertida a cadena
Regresa: La cadena que recibe
*/
char* str_que(char*, const queue*);
/* Obtiene el tamano de la cola 
Recibe:La cola con los datos
Regresa:El tamano de la cola 
*/
int tam_que(queue*);
/* Muestra la capacidad ocupada de la cola
Recibe:La cola con los datos
Regresa:La capacidad de la cola que esta ocupada
*/
int capac_que(queue*);
/* Regresa el ultimo elemento insertado en la cola
Recibe:La cola con los datos
Regresa:El ultimo elemento insertado en la cola
*/
int ulti_que(queue*);
#endif
