#ifndef POL2RAC_H
#define POL2RAC_H
/***********************************************************
Declaraci�n de polinomio de segundo grado con coeficientes
  racionales para calcular las raices.
Objetivo: Utilizar los n�meros racionales como coeficientes
  de un polinomio de segundo grado. El polinomio tiene la 
  forma: ax^2+bx+c=0
  con a,b y c como n�meros racionales
Autor:
  Juan Jes�s Guti�rrez Garc�a
Fecha:
  Septiembre 2020
Observaciones:
  Se define un tipo de dato nuevo que es ecseg, abreviaci�n
  de ecuaci�n de segundo grado. 
  No todos los polinomios de segundo grado con coeficientes
  racionales tienen raices racionales por tanto en todos los
  casos se hace una aproximaci�n que s�lo ser� exacta en caso
  de que las raices del polinomio sean racionales
Limitantes:
  Hay cadenas temporales de tama�o TAMCADAUX que se utili-
  zan para la conversi�n de n�meros enteros a cadenas de
  caracters.
  El menejo de memoria es completamente est�tico y no se 
  verifica que los arreglos no rebasen el tama�o permitido.
***********************************************************/

#include "racional.h"
/************- Constantes de Operaci�n-********************/
/*Define el tama�o de las cadenas auxiliares*/
/*Utiliza la constante de racional*/

/*ERRORES. Utiliza los definidos en racional.h*/
/*#define OK           0 /*Sin Error*/
/*#define DENCER       1 /*Denominador cero*/
/*#define APINV        2 /*Si se recibe un apuntador nulo*/
/*#define IMAG         3 /*Error en caso de obtener ra�z de
                         n�meros negativos*/
						 
/**********************************************************/
/*****************- Estado de la ecuaci�n-*****************/
/**********************************************************/

#define DOSSOL          1   /*Dos soluciones racionales*/
#define UNASOL          2   /*Una soluci�n �nica*/
#define IMGSOL          3   /*Soluciones imaginarias*/
#define NOEC2           4   /*No hay ecuaci�n, a==0*/

/**********************************************************/
/****- Definici�n del tipo ecuaci�n de segundo grado-******/
typedef struct{
  /*Coeficientes*/
  racional a;      /*Variable al cuadrado*/
  racional b;      /*Variable l�neal */
  racional c;      /*Constante*/
  /*Raices de la ecuaci�n*/
  racional x1;
  racional x2;
  /*Estado*/
  int estado; /*Entero que define el estado de la ecuaci�n*/
} ecseg;

/**********************************************************/
/*                      Funciones                         */
/**********************************************************/
/**************- Inicializa una ecuaci�n -*****************/
/* Inicializa una ecuaci�n
Recibe un apuntador de tipo ecseg y tres coeficientes racio-
  nales.
Regresa:
  OK, en caso de inicializar la ecuaci�n.
  APINV, si recibe un apuntador nulo
  DENCER, en casode recibir un cero como el tercer par�metro
Observaciones:
  Siempre debe utilizar esta funci�n para inicializar las
  ecuaciones con coeficientes racionales. No modificar 
  directamente los campos de la estructura.
*/
int ini_ec2r(ecseg*, const racional*, const racional*, const racional*);

/**************- Convierte racional a cadena **************/
/* Convierte una ecuaci�n a cadena
Recibe Un apuntador a cadena de caracteres que debe tener 
  espacio suficiente para almacerna la ecuaci�n.
Regresa:
  Un apuntador a la misma cadena que recibe. En caso de te-
  ner un error regresa alguna de las siguientes cadenas:
  "NULL":   Recibe un apuntador nulo
  En caso contrario regresa una cadena que represetnta la 
  ecuaci�n de segundo grado. Por ejemplo
  (-3/4)x^2+(-5/3)x+(3)=0
*/
char* tostr_ec2r(char*,const ecseg*);

/* Saca las raices del polinomio ingesado pero como no pude 
reducir mucho las raices hay uno que otro fallo en los resultados 
pues de repente en unps casos se aleja mucho del cero. 
*/
void sol_ecseg(ecseg* e, const racional* a, const racional* b, const racional* c);
#endif
