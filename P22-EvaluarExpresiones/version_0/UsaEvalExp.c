#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EvalExp.h"
/*Programa pirncipal*/
int main(){
/*	
/*	char cadena[MAXCAD]; /* Para leer la expresion. */
/*	int num_sim; /* Numero de simbolos en la expresion. */
/*	int expresion_infija[MAXSIM]; /* Guarda los simbolos de la expresion infija.*/
/*	int expresion_postfija[MAXSIM]; /* Guarda los simbolos de la expresion postfija.*/
/*	Toperando resultado;
	//clrscr();
	//system("");
	printf("Introduce la expresion aritmetica: ");
	gets(cadena);
	tokenize(cadena, expresion_infija, &num_sim);
	printf("Impresion de la cadena ingresada");
	//transforma_postfija(expresion_infija, expresion_postfija, &num_sim);
	
	//resultado = evalua_postfija(expresion_postfija, num_sim);
	//printf("\n\nRESULTADO: %f\n",resultado);
	printf("Pulsa Intro para acabar\n");
	*/
	char infix[100], postfix[100];
	printf("\nEnter any infix expression:");
	gets(infix);
	strcpy(postfix, "");
	ToPostfix(infix, postfix);
	printf("\n The corresponding postfix expression is:");
	puts(postfix);
	getch();
	return 0;
}
	gets(cadena);
	return(0);
}
