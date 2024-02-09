#ifndef EVALEXP_H
#define EVALEXP_H
/**********************************************************
Evaluacion de espresiones desde un archivo, 
usando redireccionamieno, y se escribe cada 
expresion con el valor que resulta de evaluarla
Fecha: Diciembre 2020
**********************************************************/
#include "err.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>//ES POSIBLE QUE NO SE USE

#include <ctype.h>
/**********************************************************
                       C O N S T A N T E S
**********************************************************/
#define  MAXCAD  300 //tamanio maximo de una cadena
#define  MAXSIM  100 //tamanio maximo de simbolos en una expresion
#define maxP  100    //tamanio maximo de una pila

/*simbolos aritmeticos*/
#define SUMA     -1
#define RESTA    -2
#define MULT     -3
#define DIV      -4
#define PAR_IZQ  -5
#define PAR_DER  -6

#define TAMMAX    100   /*Tamaño inicial del arreglo*/
#define TAMCRE    10    /*Tamaño que se agrega cada vez
                          que crece el arreglo*/
#define TAMDAT    20    /*Tamaño de cadena para convertir
                          cada dato almacenado en char* */
/* De error */
#define OVERFLOW  20    /*Insertar en pila llena*/
#define UNDERFLOW 30    /*Extraer de pila vacía*/

#define DATO      int   /*Tipo de dato almacenado*/
#define FORMATO " %3d " /*Formato para converir dato a 
                          cadena*/
/**********************************************************
                       M A C R O S
**********************************************************/
/*Si tiene datos la pila*/
#define TIE_DAT(p)  ((p)->tope>0)
/*Si la pila está vacía*/
#define VAC_PIL(p)  ((p)->tope==0)
/*Si tiene espacio el arreglo de la pila*/
#define TIE_ESP(p)  (AP_VAL(p->dato)&&(p)->tope<(p)->tam)
/*Si la pila está llena*/
#define LLE_PIL(p)  ((p)->tope==(p)->tam)
/**********************************************************
                       T I P O S
**********************************************************/
typedef struct{
	DATO *dato;
	int tope;
	int tam;
}pila;

#define MAX 100

/**********************************************************
                       F U N C I O N E S
**********************************************************/
int inic_pil(pila* p);
int crea_pil(pila* p);
int elim_pil(pila* p);
int pop_pil(pila* p);
int push_pil(pila* p,DATO d);
char* str_pil(char * s, const pila* p);

int prioridad(char simbolo);
void ToPostfix(char, char);
#endif
