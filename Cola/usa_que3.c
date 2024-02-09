#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
#include<time.h>

int main(){
  queue q;
  char salida[100];
  srand(time(NULL));
  int num,i,conta,funcion=0;
  for(conta=0;conta<500;conta++){
    crea_que(&q);
    for(i=0;i<(rand() % 100);i++){
      inse_que(&q,num=rand() % 100);
    }
    printf("%s\t",str_que(salida,&q));
	funcion=rand()% 3;
	if (funcion==0){
	  tam_que(&q);
	  printf("\n");
	}else if(funcion==1){
	  capac_que(&q);
	  printf("\n");
	}else if(funcion==2){
	  ulti_que(&q);
	  printf("\n");
	}else{
	  printf("\n");
	}
    elim_que(&q);
  }
  return 0;
}
