#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#define TIPO char

int main(){
  lista a;
  lista b;
  lista num;
  int i;
  TIPO *p,*s,x;
  int res;
  char sal[5000];
  datogen midat;
  time_t t;

  int k = 4;
  int conta;
  sal[0]='\0';
  srand((unsigned) time(&t));
  //for(conta=0;conta<5;conta++){
  lis_crea(&a);
  lis_crea(&b);

  for(i=1;i<10;i++){
    p = (TIPO*)malloc(sizeof(TIPO));
    *p='A'+rand()%20;
    lis_insi(&a,(datogen)p);
  }
  for(i=1;i<10;i++){
    s = (TIPO*)malloc(sizeof(TIPO));
    *s='A'+rand()%20;
    lis_insi(&b,(datogen)s);
  }
   printf("Lista a %s\n",lis_mue(&a,sal));
   printf("Lista b %s\n",lis_mue(&b,sal));
   
   insert(&a, &b, k);
   printf("\n");
   printf("Lista a %s\n",lis_mue(&a,sal));
   printf("\n");
   lis_elim(&a);
   lis_elim(&b);


    //printf("Lista a %s\n",lis_mue(&a,sal));
	printf("fin");
	return 0;
	
}
   
