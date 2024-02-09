#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
#include<time.h>

int main(){
  queue q;
  char salida[100];
  srand(time(NULL));
  int num,i,conta;
  for(conta=0;conta<500;conta++){
    crea_que(&q);
    for(i=0;i<(rand() % 100);i++){
      inse_que(&q,num=rand() % 100);
    }
    printf("%s\n",str_que(salida,&q));
	printf("\n");
    elim_que(&q);
  }
  return 0;
}
