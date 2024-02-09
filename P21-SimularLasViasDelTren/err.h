#ifndef ERR_H
#define ERR_H
/**********************************************************
Definir errores comunes a programas
Por: Juan Jesús Gutiérrez García
Para: Ejemplos de programación
Fecha: Nov-2020
**********************************************************/
#include <stdlib.h>    /* Para definir NULL */

/**********************************************************
                C O N S T A N T E S
**********************************************************/
#define OK          0   /* No hay errores */
#define AP_INV      1   /* Recibe un apuntador nulo */
#define NO_MEM      2   /* malloc regresa NULL*/
/**********************************************************
                    M A C R O S
**********************************************************/

/* Verifica que un apuntador no tenga dirección nula*/
#define AP_VAL(p)   ((p)!=NULL)

#endif
