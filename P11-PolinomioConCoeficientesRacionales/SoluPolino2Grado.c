#include <stdio.h>
#include "racional.h"
#include "pol2rac.h"
int main(){
  racional a,b,c,r;
  racional cero;
  ini_rac(&cero,0,1);
  int i,j,err;
  ecseg e;
  char s1[1000];
  
   for(i=-10;i<5;i++){
    for(j=1;j<10;j++){
		ini_rac(&a,i,j);//a 
		ini_rac(&b,i+1,j);//b 
		ini_rac(&c,i,j+1);//c 
		
		ini_ec2r(&e,&a,&b,&c); 
		sol_ecseg(&e,&a,&b,&c);
    }  
  }
   for(i=-5;i<5;i++){
    for(j=1;j<10;j++){
		ini_rac(&a,i,j);//a 
		ini_rac(&b,2*i,j);//b 
		ini_rac(&c,i,j);//c 
		
		ini_ec2r(&e,&a,&b,&c); 
		sol_ecseg(&e,&a,&b,&c);
    }  
  }
   for(i=1;i<20;i++){
    for(j=1;j<20;j++){
		ini_rac(&a,i,j);//a 
		ini_rac(&b,i,j);//b 
		ini_rac(&c,i,j+1);//c 
		
		ini_ec2r(&e,&a,&b,&c); 
		sol_ecseg(&e,&a,&b,&c);
    }  
  }
  return 0;
}
