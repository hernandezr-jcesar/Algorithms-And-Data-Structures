#include<stdio.h>
#include "shell.h"
//intercambia dos valores del arreglo
int swap(int* camb, int* a, int* b){
	int tmp;
	(*camb)++;
	tmp= *a;
	*a = *b,
	*b = tmp;
	return OK;
}
/*Ordena los numeros usando el algoritmo shell
en el peor caso que es de forma descendente/orden inverso
Recibe: arr-->Arreglo con los datos
		tam-->Número de datos a ordenar
Regresa:	Costante de error*/
int shell(int* camb,int* comp,int* arr, int tam){
	if(!AP_VAL(arr)){
		return AP_INV;
	}
	if(!TA_VAL(tam)){
		return TA_INV;
	}
	
	int salto,pos,cambios;
	salto = tam/2;
	do{
		do{
			cambios = 0;
			for(pos = salto; pos < tam; pos++){
				if(comp_c(comp,arr[pos - salto],arr[pos])){
					swap(camb,&arr[pos],&arr[pos - salto]);
					cambios++;
				}
			}
		}while(cambios != 0);
		salto = salto/2;
	}while(salto != 0);			
	return OK;
}
//compara dos valores del arreglo
int comp_c(int* comp, int a, int b){
	(*comp)++;
	return a>b;
}
//Imprime el arreglo por pantalla
void Imprime_Arr(int* arr, int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("%d\t",arr[i]);
	}
}
