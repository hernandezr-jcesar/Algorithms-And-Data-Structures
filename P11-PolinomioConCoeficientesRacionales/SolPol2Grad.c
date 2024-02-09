#include <stdio.h>
#include <math.h>
//Idea general para la solucion de polinomios pero con numeros enteros y decimales no contando con los racionales
float comprobacion(float a,float b,float c,float sol);
int main(){
	float a,b,c,D;
	float sol,sol1,sol2;
	printf("\nEcuaciones de segundo Grado\n");
	printf("\nax^2 + bx + c = 0\n");
	printf("Introduce el valor de a:");
	scanf("%f",&a);
	printf("Introduce el valor de b:");
	scanf("%f",&b);
	printf("Introduce el valor de c:");
	scanf("%f",&c);
	
	D=b*b-(4*a*c);
	if(D==0){
		sol=-b/(2*a);
		printf("Solucion: %.2f\n",sol);
		comprobacion(a,b,c,sol);
		
	}else if(D>0){
		sol1=(-b+sqrt(D))/(2*a);
		sol2=(-b-sqrt(D))/(2*a);
		printf("Solucion 1: %.2f\n",sol1);
		printf("Solucion 2: %.2f\n",sol2);
		
		comprobacion(a,b,c,sol1);
		
		comprobacion(a,b,c,sol2);
	
	}else{	/* D<0 */
		printf("No tiene solucion.\n");
		/*
		printf("Sol. 1: %.2f + %.2f i\n",-b/(2*a),(sqrt(-D))/(2*a));
		printf("Sol. 2: %.2f - %.2f i\n",-b/(2*a),(sqrt(-D))/(2*a));
		*/
	}
	
	return 0;
}

float comprobacion(float a,float b,float c,float sol){
		float comprobacion;
		comprobacion=a*(sol*sol)+b*(sol)+c;
		comprobacion=fabs(comprobacion); //valor absoluto de la comprobacion
		printf("\nComprobacion de que la solucion es correcta cuando:\n");
		printf("x=%.2f\n",sol);
		printf("ax^2 + bx + c = 0\n");
		printf("%.2f(%.2f)^2 + %.2f(%.2f) + %.2f = %.2f\n",a,sol,b,sol,c,comprobacion);
		printf("%.2f(%.2f) + (%.2f) + (%.2f) = %.2f\n",a,sol*sol,b*sol,c,comprobacion);
		printf("%.2f + (%.2f) = %.2f\n",a*sol*sol,(b*sol)+c,comprobacion);
		printf("%.2f=%.2f\n",fabs((a*sol*sol)+(b*sol)+c),comprobacion);
}
