//Algoritmo 3 --> Shell
//Caso 2-->Peor caso(Orden Inverso):10,9,8,7,6,5,4,3,2,1
#include <stdio.h>
#include "shell.h"

#define NUM_MAX 10010//Tamaño del arreglo
int main(){
	int arreglo[NUM_MAX] = {0};
	int i,j,k,n,num,comparacion,cambio,verificar,promedio;
	for(n=10;n<NUM_MAX;n+=10)
	{	
		
			/*Inicializar en Orden Inverso*/
			for(i=0;i<n;i++){
				//num=rand()%1000;
				arreglo[i]=n - i;//CANT_NUM - i;
			}
			//Llama a la funcion shell y verifica
			//si todo salio bien
			cambio=0;
			comparacion=0;
			if(shell(&cambio,&comparacion,arreglo,n)!=OK){
				printf("Error al ordenar\n");
			}
			//Impresion de arreglo
			//Imprime_Arr(arreglo,n);
			//Verificar que se ordenaron los datos
			verificar=0;
			for(i=0;i<n - 1;i++){
				if(arreglo[i]<=arreglo[i+1]){
					verificar++;
				}	
			}
			if(verificar!=n - 1){
				printf("Error al ordenar %d\n",verificar);
			}
			
		//printf("\n\nCambios:%d\n",cambio);
		//printf("Comparaciones:%d\n",comparacion);
		promedio= cambio + comparacion;
		printf("%d\t%d\n",n,promedio);
	}
	return 0;
}
