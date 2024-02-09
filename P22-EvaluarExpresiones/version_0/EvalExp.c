#include "EvalExp.h"
/*Funcion para transformar la string de entrada a una secuencia de simbolos*/
void ToPostfix(char source[],char target[])
{
	inic_pil(&postfix);
	crea_pil(&postfix);
	
	while(source[i]!='/0'){
		if(source[i]=='('){
			push_pil(&postfix, source[i]);
			i++;
		}
		else if(source[i]==')'){
			
			temp = pop(st);//remove left parentesis
			i++;
		}
	}
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

 int inic_pil(pila* p){
  if(!AP_VAL(p))
    return AP_INV;
  
  p->dato = NULL;
  p->tope = 0;
  p->tam  = 0;
  return OK;
}

int crea_pil(pila* p){
  if(!AP_VAL(p))
    return AP_INV;
  p->dato = (DATO*)malloc(sizeof(DATO)*TAMMAX);
  if(!AP_VAL(p->dato))
    return OVERFLOW;
  
  p->tope = 0;
  p->tam = TAMMAX;
  return OK;
}

int elim_pil(pila* p){
  if(!AP_VAL(p))
    return AP_INV;
  free(p->dato); 
  inic_pil(p);
  return OK;
}

int push_pil(pila* p,DATO d){
  int err;
  if(!AP_VAL(p))
    return AP_INV;
  if(!TIE_ESP(p)){
	  err = crece(p);
      if(err!= OK)
	    return err;
  }
  p->dato[p->tope++]= d;
  return OK;
}

int pop_pil(pila* p){
  if(!AP_VAL(p))
    return AP_INV;
  if(!TIE_DAT(p))
    return UNDERFLOW;
  p->tope--;
  return OK;
}

char* str_pila(char* s, const pila* p){\
	char dato[TAMDAT];
	int i;
	if(!(AP_VAL(s)&&AP_VAL(p)))
	  return s;
	strcpy(s,"");
	for(i=0;i<p->tope;i++){
		sprintf(dato,FOR_DAT,p->dato[i]);
		strcat(s,dato);
	}
	strcat(s,"\n");
	return s;
}