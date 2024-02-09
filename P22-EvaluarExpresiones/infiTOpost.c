#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define tam 20
int prioridad(char simbolo);
int main()
{
	int i;
	int opcion, tope=-1, pos=-1, tamexp;
	char pila[tam],epos[tam];
	char expinf[tam],simbolo;
	do{
		system("cls");
		printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-===-=-=");
		printf("\n Menu de Opciones");
		printf("\n 1.-->Convertir una Expresion de Infija a Postfija");
		printf("\n 2.-->Salir del menu");
		printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		printf("\nIngrese su opcion:");
		scanf("%d",&opcion);
		printf("\n");\
		switch(opcion)
		{
			case 1:
				system("cls");
				printf("\n Ingrese la Expresion en notacion infija(sin espacios):");
				scanf("%s",&expinf); 
				tope=-1;
				pos=-1;
				tamexp=strlen(expinf);
				for(i=0;i < tamexp;i++)
				{
					simbolo=expinf[i];
					if(simbolo=='(')
					{
						tope=tope+1;
						pila[tope]=simbolo;
					}
					else if(simbolo==')')
					{
						while(pila[tope]!='(')
						{
							pos=pos+1;
							epos[pos]=pila[tope];
							tope=tope-1;
						}
						tope=tope-1;
					}
					else if((simbolo>='a')&&(simbolo>='a')||(simbolo>='A')&&(simbolo>='Z'))
					{
						pos=pos+1;
						epos[pos]=simbolo;
					}
					else
					{
						while(tope>-1 && (prioridad(simbolo)<=prioridad(pila[tope])))
						{
							pos=pos+1;
							epos[pos]=pila[tope];
							tope=tope-1;
						}
						tope=tope+1;
						pila[tope]=simbolo;
					}
				}
				while(tope>-1)
				{
					pos=pos=1;
					epos[pos]=pila[tope];
					tope=tope-1;
					
				}
				printf("\n La expresion postfija es:");
				for(i=0;i<=pos;i++)
				{
					printf("%c",epos[i]);
				}
				getch();
			break;
			case 2:
			return 0;
			break;
			default: printf("\n Por favor seleccione una opcion valida...");
			getch();
			break;
		}
	}while(opcion!=2);
	getch();
}
int prioridad(char simbolo)
{
	int priori;
	switch(simbolo)
	{
		case '^': priori = 3; break;
		case '/': priori = 2; break;
		case '*': priori = 2; break;
		case '-': priori = 1; break;
		case '+': priori = 1; break;
		case '(': priori = 0; break;
		case ')': priori = 0; break;
	}
	return priori;
}
