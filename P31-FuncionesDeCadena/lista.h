#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "err.h"
#include "nodo.h"

#define ERR_LISVAC  1  /*Lista Vacía*/
#define TAMCAD      20

typedef nodo* lista;

//Vaciar lista
int lis_vac(const lista*);
//Crear nueva lista
int lis_crea(lista*);
//Eliminar lista
int lis_elim(lista*);
//Insertar dato en la lista
int lis_insi(lista*,datogen);
//Eliminar dato de la lista
int lis_elii(lista*,datogen*);
//Invertir lista
int lis_inve(lista*);
char* lis_mue (const lista*,char*);
//Corta una lista en un rango determinado
//int lis_cort(lista* l, inicio, final);
int insert(lista*, lista* ,int );

#endif
