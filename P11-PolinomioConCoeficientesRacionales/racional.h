#ifndef RACIONAL_H
#define RACIONAL_H
/***********************************************************
Implementaci�n de n�meros Racionales.
Objetivo: Crear un tipo de dato y las funciones necesarias
  para realizar el manejo de n�meros racionales.
Autor:
  Juan Jes�s Guti�rrez Garc�a
Fecha:
  Septiembre 2020
Observaciones:
  Todo n�mero racional se representa con dos n�meros enteros
  y un entero que se utiliza como signo. Se define una cons-
  tante para el POSITIVO y una para NEGATIVO
  El n�mero se almacena en su forma reducida, es decir, si
  al crearlo se proporciona un 4/8 se calcula el M�ximo 
  com�n divisor y se almacena el 1/4
Limitantes:
  Hay cadenas temporales de tama�o TAMCADAUX que se utili-
  zan para la conversi�n de n�meros enteros a cadenas de
  caracters.
  El menejo de memoria es completamente est�tico y no se 
  verifica que los arreglos no rebasen el tama�o permitido.
***********************************************************/

#include <math.h>      /* S�lo para usar abs*/
#include <string.h>    /* Funciones de cadena*/
#include <stdlib.h>    /* Para usar la constante NULL*/
#include <stdio.h>     /* Para usar funci� sprintf*/

/************- Constantes de Operaci�n-********************/
/*Define el tama�o de las cadenas auxiliares*/
#define TAMCADAUX    50

/*ERRORES. Constantes que regresa cada funci�n para el 
    control de errores*/
#define OK           0 /*Sin Error*/
#define DENCER       1 /*Denominador cero*/
#define APINV        2 /*Si se recibe un apuntador nulo*/
#define IMAG         3 /*Error en caso de obtener ra�z de
                         n�meros negativos*/

/************- Constantes del problema-********************/
#define POSITIVO     1 /*Signo positivo*/
#define NEGATIVO     0 /*Signo negativo*/
/************- Valida Apuntadores-*************************/
#define APVAL(p)     ((p)!=NULL)

/************- Macros Auxiliares-**************************/
/*Calcula minimo y m�ximo entre dos par�metros*/
#define MAX(a,b)    (abs(a)>abs(b)?abs(a):abs(b))
#define MIN(a,b)    (abs(a)<abs(b)?abs(a):abs(b))

/************- Macros del tipo Racional-*******************/
/*Verifica si el racional representa al n�mero cero*/
#define ESCERO(q)      ( (q)->num==0)   
/*Si n�mero racional es entero*/
#define ESENTE(q)      ( (q)->den==1)
/*Verifica que el denominador no sea cero*/
#define DENVAL(q)      ( (q)->den!=0 )
/*Regresa el caracter correspondiente al signo*/
#define SIGNO(q)       ( (q)->sig==POSITIVO?"":"-")
/*Regresa un uno que correspondiente al signo*/
#define SIGNOV(q)      ( (q)->sig==POSITIVO?1:-1)
/*Regresa verdadero en caso de ser positivo*/
#define ESPOS(q)       ( (q)->sig==POSITIVO)
/*Regresa verdadero en caso de ser negativo*/
#define ESNEG(q)       ( (q)->sig==NEGATIVO)
/**********************************************************/
/************- Definici�n del tipo racional-***************/
typedef struct{
  int num;  /*n�merador, siempre positivo*/
  int den;  /*denominador, siempre positivo */
  int sig;  /* 0 negativo 1 positivo*/
} racional;
/**********************************************************/
/*                      Funciones                         */
/**********************************************************/

/*Realiza el c�lculo recursivo del m�ximo com�n divisor   */
/*
Recibe:
  Dos enteros, que ya est�n en orden, el primero es el 
  menor y el segundo el mayor.
Regresa:
  El entero que es el m�ximo com�n divisor.
*/
int mcd_r(int max, int min);

/**************- Inicializa un racional -******************/
/* Inicializa el n�mero racional
Recibe un apuntador a Racional que hace referencia a la va-
  riable que ser� inicializada. Tambi�n recibe dos enteros. 
  El primero represetna el n�merador y el segundo el deno-
  minador del n�mero racional con el que se inicializa.
Regresa:
  OK, en caso de inicializar el racional
  APINV, si recibe un apuntador nulo
  DENCER, en casode recibir un cero como el tercer par�metro
Observaciones:
  Siempre debe utilizar esta funci�n para inicializar los
  n�meros racionales. No modificar directamente el n�merador
  o el denominador.
*/
int ini_rac(racional*, int, int);

/**************- Convierte racional a cadena **************/
/* Convierte un racional a cadena
Recibe Un apuntador a cadena de caracteres que debe tener 
  espacio suficiente para almacerna el racional.
Regresa:
  Un apuntador a la misma cadena que recibe. En caso de te-
  ner un error regresa alguna de las siguientes cadenas:
  "NULL":   Recibe un apuntador nulo
  "DIVCER": Dedenominador cero
  En caso contrario regresa una cadena que represetnta al 
  n�mero racional encerrado entre par�ntesis
  por ejemplo (-3/4) o (5/3)
*/
char* tostr_rac(char*,const racional*);


/**********************************************************/
/****            Operaciones b�sicas                   ****/
/**********************************************************/
/**************  Comparaciones de orden *******************/
/* Copia una racional en otro
Recibe Un apunador a racional, destino y otro origen
Regresa:
  OK       En caso de realizar la copia
  APINV    En caso de recibir un apuntador NULL
  DENCER   En caso de que el origen tenga denominador cero
*/
int copia_rac(racional* d,const racional* o);
/*Compara dos n�meros racionales
Recibe: Dos par�metros
  Apuntador a los elementos a comparar
Regresa:
  APINV:  Cero en caso de recibir par�metros invalidos
  1    :  En caso de ser n�mero iguales
  0    :  En caso de ser n�meros diferentes
*/
int comp_rac(const racional*, const racional*);

/*Compara dos n�meros racionales
Recibe: Dos par�metros
  Apuntador a los elementos a comparar
Regresa:
  APINV:  Cero en caso de recibir par�metros invalidos
  1    :  En caso de ser n�mero diferentes
  0    :  En caso de ser n�meros iguales
*/
int dist_rac(const racional*, const racional*);

/*Compara si es| mayor o menor
Recibe: Dos par�metros
  Apuntador a los elementos a comparar
Regresa:
  APINV:  Cero en caso de recibir par�metros invalidos
  1    :  1 si el primer parametro es mayor que el segundo
  0    :  En caso contrario
*/
int mayq_rac(const racional*, const racional*);

/**************** Operaciones unarias  ********************/
/*Invierte un n�mero
Recibe: Dos par�metros racionales.
  Apuntador a el resultado de invertir el n�mero
  Apuntador a el n�mero que ser� invertido
Regresa:
  APINV:  Si recibe un apuntador nulo.
  DENCER: Si el segundo par�metro es cero.
  OK:     Si se realiza la operaci�n sin problemas
*/
int inve_rac(racional*, const racional*);

/*Ra�z cuadrada
Recibe: Dos par�metros racionales.
  Apuntador a el resultado ra�z del n�mero
  Apuntador a el n�mero que del que se obtendr� la
    ra�z
Regresa:
  APINV:  Si recibe un apuntador nulo.
  IMAG:   Si recibe un n�mero racional negativo
  OK:     Si se realiza la operaci�n sin problemas
*/
int raiz_rac(racional*, const racional*);

/**************** Operaciones binarias ********************/
/*Suma dos n�meros racionales
Recibe: Tres par�metros
  Apuntador a un rarcional que almacenar� el resultado
  Apuntador a el primer racional para sumar
  Apuntador a el segundo racional para sumar
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int suma_rac(racional*, const racional*, const racional*);

/*Resta dos n�meros racionales
Recibe: Tres par�metros
  Apuntador a un rarcional que almacenar� el resultado
  Apuntador a el primer racional para restado
  Apuntador a el segundo racional para restado
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int rest_rac(racional*, const racional*, const racional*);

/*Multiplicacion de dos n�meros racionales
Recibe: Tres par�metros
  Apuntador a un rarcional que almacenar� el resultado
  Apuntador a el primer racional para multiplpicar
  Apuntador a el segundo racional para multiplpicar
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int mult_rac(racional*, const racional*, const racional*);

/*Division de dos n�meros racionales
Recibe: Tres par�metros
  Apuntador a un rarcional que almacenar� el resultado
  Apuntador a el primer racional para ser el dividendo
  Apuntador a el segundo racional para ser el divisor
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int divi_rac(racional*, const racional*, const racional*);

#endif
