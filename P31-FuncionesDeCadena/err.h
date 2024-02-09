#ifndef ERR_H
#define ERR_H
#include <stdlib.h>

/*Constantes que definen el valor de retorno de cada
  función. Se utilizan en diferentes programas*/
#define OK     0     /* No hay error */
#define ERR_APUINV 1 /* Se recibio un apuntador nulo */
#define ERR_DIMINV 2 /* El tamaño del arreglo es invalido */
#define ERR_INSMEM 3 /* No hay memoria dinámica*/
#define ERR_INDINV 4 /* Se recibio un indice fuera del rango*/

/*Macros para Validar*/
/* Valida que el apuntador no sea nulo*/
#define VAL_AP(x)     ((x)!=NULL)

#endif
