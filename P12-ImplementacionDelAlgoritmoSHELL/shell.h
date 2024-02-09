#ifndef _SHELL_H
#define _SHELL_H
/*****************************/
/*			Constantes 		 */
/*****************************/
/*No hay error*/
#define OK 0 
/*Apuntador nulo*/
#define AP_INV 1
/*Tamaño de arreglo invalido*/
#define TA_INV 2
/*Tamaño Maximo del arreglo*/
#define TAM_MAX 10000

/****************************/
/*			Macros			*/
/****************************/
/*Apuntador valido, No nulo */
#define AP_VAL(a)	((a)!=NULL)
/*Tamaño de arreglo valido*/
#define TA_VAL(a)	(a)>0&&(a<TAM_MAX)
/****************************/
/*		Ordena los datos	*/
/*************************+**/
/*Recibe:
	arr: Arreglo con los datos
	tam: número de datos a ordenar
Regresa:
	Costante de error*/
int shell(int* camb, int* comp, int* arr, int tam);
/****************************/
/*		Cambia dos datos	*/
/*************************+**/
/*Recibe:
	a*:Primer valor del arreglo
	b*:segundo valor del arreglo
Regresa:
	Costante de error*/
int swap(int* c, int*a, int* b);
//Compara dos datos del arreglo y le suma 
//uno al contador de comparaciones
int comp_c(int* c, int a, int b);
//Imprime el arreglo en pantalla
void Imprime_Arr(int* arr, int tam);
#endif

