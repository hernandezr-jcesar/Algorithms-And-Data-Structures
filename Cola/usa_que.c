#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(){
  queue q;
  char salida[100];
  
  crea_que(&q);
  inse_que(&q,123);
  inse_que(&q,13);
  inse_que(&q,132);
  inse_que(&q,523);
  avan_que(&q);
  inse_que(&q,2020);
  inse_que(&q,2021);
  printf("%s\n",str_que(salida,&q));
  elim_que(&q);
  return 0;
}
