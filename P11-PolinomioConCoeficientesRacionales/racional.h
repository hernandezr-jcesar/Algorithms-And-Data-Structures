#ifndef RACIONAL_H
#define RACIONAL_H
/***********************************************************
Implementación de números Racionales.
Objetivo: Crear un tipo de dato y las funciones necesarias
  para realizar el manejo de números racionales.
Autor:
  Juan Jesús Gutiérrez García
Fecha:
  Septiembre 2020
Observaciones:
  Todo número racional se representa con dos números enteros
  y un entero que se utiliza como signo. Se define una cons-
  tante para el POSITIVO y una para NEGATIVO
  El número se almacena en su forma reducida, es decir, si
  al crearlo se proporciona un 4/8 se calcula el Máximo 
  común divisor y se almacena el 1/4
Limitantes:
  Hay cadenas temporales de tamaño TAMCADAUX que se utili-
  zan para la conversión de números enteros a cadenas de
  caracters.
  El menejo de memoria es completamente estático y no se 
  verifica que los arreglos no rebasen el tamaño permitido.
***********************************************************/

#include <math.h>      /* Sólo para usar abs*/
#include <string.h>    /* Funciones de cadena*/
#include <stdlib.h>    /* Para usar la constante NULL*/
#include <stdio.h>     /* Para usar funció sprintf*/

/************- Constantes de Operación-********************/
/*Define el tamaño de las cadenas auxiliares*/
#define TAMCADAUX    50

/*ERRORES. Constantes que regresa cada función para el 
    control de errores*/
#define OK           0 /*Sin Error*/
#define DENCER       1 /*Denominador cero*/
#define APINV        2 /*Si se recibe un apuntador nulo*/
#define IMAG         3 /*Error en caso de obtener raíz de
                         números negativos*/

/************- Constantes del problema-********************/
#define POSITIVO     1 /*Signo positivo*/
#define NEGATIVO     0 /*Signo negativo*/
/************- Valida Apuntadores-*************************/
#define APVAL(p)     ((p)!=NULL)

/************- Macros Auxiliares-**************************/
/*Calcula minimo y máximo entre dos parámetros*/
#define MAX(a,b)    (abs(a)>abs(b)?abs(a):abs(b))
#define MIN(a,b)    (abs(a)<abs(b)?abs(a):abs(b))

/************- Macros del tipo Racional-*******************/
/*Verifica si el racional representa al número cero*/
#define ESCERO(q)      ( (q)->num==0)   
/*Si número racional es entero*/
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
/************- Definición del tipo racional-***************/
typedef struct{
  int num;  /*númerador, siempre positivo*/
  int den;  /*denominador, siempre positivo */
  int sig;  /* 0 negativo 1 positivo*/
} racional;
/**********************************************************/
/*                      Funciones                         */
/**********************************************************/

/*Realiza el cálculo recursivo del máximo común divisor   */
/*
Recibe:
  Dos enteros, que ya están en orden, el primero es el 
  menor y el segundo el mayor.
Regresa:
  El entero que es el máximo común divisor.
*/
int mcd_r(int max, int min);

/**************- Inicializa un racional -******************/
/* Inicializa el número racional
Recibe un apuntador a Racional que hace referencia a la va-
  riable que será inicializada. También recibe dos enteros. 
  El primero represetna el númerador y el segundo el deno-
  minador del número racional con el que se inicializa.
Regresa:
  OK, en caso de inicializar el racional
  APINV, si recibe un apuntador nulo
  DENCER, en casode recibir un cero como el tercer parámetro
Observaciones:
  Siempre debe utilizar esta función para inicializar los
  números racionales. No modificar directamente el númerador
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
  número racional encerrado entre paréntesis
  por ejemplo (-3/4) o (5/3)
*/
char* tostr_rac(char*,const racional*);


/**********************************************************/
/****            Operaciones básicas                   ****/
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
/*Compara dos números racionales
Recibe: Dos parámetros
  Apuntador a los elementos a comparar
Regresa:
  APINV:  Cero en caso de recibir parámetros invalidos
  1    :  En caso de ser número iguales
  0    :  En caso de ser números diferentes
*/
int comp_rac(const racional*, const racional*);

/*Compara dos números racionales
Recibe: Dos parámetros
  Apuntador a los elementos a comparar
Regresa:
  APINV:  Cero en caso de recibir parámetros invalidos
  1    :  En caso de ser número diferentes
  0    :  En caso de ser números iguales
*/
int dist_rac(const racional*, const racional*);

/*Compara si es| mayor o menor
Recibe: Dos parámetros
  Apuntador a los elementos a comparar
Regresa:
  APINV:  Cero en caso de recibir parámetros invalidos
  1    :  1 si el primer parametro es mayor que el segundo
  0    :  En caso contrario
*/
int mayq_rac(const racional*, const racional*);

/**************** Operaciones unarias  ********************/
/*Invierte un número
Recibe: Dos parámetros racionales.
  Apuntador a el resultado de invertir el número
  Apuntador a el número que será invertido
Regresa:
  APINV:  Si recibe un apuntador nulo.
  DENCER: Si el segundo parámetro es cero.
  OK:     Si se realiza la operación sin problemas
*/
int inve_rac(racional*, const racional*);

/*Raíz cuadrada
Recibe: Dos parámetros racionales.
  Apuntador a el resultado raíz del número
  Apuntador a el número que del que se obtendrá la
    raíz
Regresa:
  APINV:  Si recibe un apuntador nulo.
  IMAG:   Si recibe un número racional negativo
  OK:     Si se realiza la operación sin problemas
*/
int raiz_rac(racional*, const racional*);

/**************** Operaciones binarias ********************/
/*Suma dos números racionales
Recibe: Tres parámetros
  Apuntador a un rarcional que almacenará el resultado
  Apuntador a el primer racional para sumar
  Apuntador a el segundo racional para sumar
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int suma_rac(racional*, const racional*, const racional*);

/*Resta dos números racionales
Recibe: Tres parámetros
  Apuntador a un rarcional que almacenará el resultado
  Apuntador a el primer racional para restado
  Apuntador a el segundo racional para restado
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int rest_rac(racional*, const racional*, const racional*);

/*Multiplicacion de dos números racionales
Recibe: Tres parámetros
  Apuntador a un rarcional que almacenará el resultado
  Apuntador a el primer racional para multiplpicar
  Apuntador a el segundo racional para multiplpicar
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int mult_rac(racional*, const racional*, const racional*);

/*Division de dos números racionales
Recibe: Tres parámetros
  Apuntador a un rarcional que almacenará el resultado
  Apuntador a el primer racional para ser el dividendo
  Apuntador a el segundo racional para ser el divisor
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int divi_rac(racional*, const racional*, const racional*);

#endif
