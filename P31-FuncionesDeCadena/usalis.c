#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#define TIPO char

int main(){
  lista l;
  int i;
  TIPO *p,*s,x;
  int res;
  char sal[5000];
  datogen midat;
  time_t t;

  sal[0]='\0';
  srand((unsigned) time(&t));
  lis_crea(&l);

  for(i=1;i<15;i++){
    p = (TIPO*)malloc(sizeof(TIPO));
    *p='A'+rand()%20;
    lis_insi(&l,(datogen)p);
  }
  printf("Lista original %s\n",lis_mue(&l,sal));
  lis_inve(&l);
  printf("Lista invertida %s\n",lis_mue(&l,sal));
  for(i=0;i<25000;i++)
    if (rand()>RAND_MAX/2){
      res = lis_elii(&l,&midat);
      if (res==OK){
        s = (TIPO*)midat;
        printf("%d Se elimino(%d) el %c y quedo %s\n",
               i,res,*s,lis_mue(&l,sal));
        free(s);
      } else
        printf("%d No se elimino(%d)\n",i,res);
    }else{
      p = (TIPO*)malloc(sizeof(TIPO));
      *p = rand()%100;
      res = lis_insi(&l,(datogen)p);
      printf("%d Se inserto(%d) el %c y quedo %s\n",
         i,res,*p,lis_mue(&l,sal));
    }
  lis_elim(&l);
  printf("Lista al final %s\n",lis_mue(&l,sal));
  return 0;
}
