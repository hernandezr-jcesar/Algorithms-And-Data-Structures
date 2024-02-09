
typedef int Toperador;
typedef float Toperando;
/*Tipo de datos para pila de operadores*/
typedef struct{
	Toperador v[maxP];
	int tope;
} TPila_es;
/*Tipo de dato para la pila de operandos*/
typedef struct{
	Toperando v[maxP];
	int tope;
}  TPila_os;

void tokenize(char *cadena, int *expresion_infija, int *num_sim);
int precedencia(Toperador op);
void transforma_postfija(int *exp_infija, int *exp_postfija, int *num_sim);

void tokenize(char *cadena, int *expresion_infija, int *num_sim)
{
	int i,j;
	char sim[MAXCAD];
	*num_sim = 0;
	i = 0;
	while(i<strlen(cadena))
	{
		switch(cadena[1])
		{
			case '+': expresion_infija[*num_sim]=SUMA;break;
			case '-': expresion_infija[*num_sim]=RESTA;break;
			case '*': expresion_infija[*num_sim]=MULT;break;
			case '/': expresion_infija[*num_sim]=DIV;break;
			case '(': expresion_infija[*num_sim]=PAR_IZQ;break;
			case ')': expresion_infija[*num_sim]=PAR_DER;break;
			default: j=i;
				strcpy(sim, "");
				while((j<strlen(cadena))&&(cadena[j]>='0')&&(cadena[j]<='9')){
					sim[j-i]=cadena[j];
					j++;
				}
				sim[j-i]='\0';
				i=j-1;
				expresion_infija[*num_sim]=atoi(sim);
			
		}
		(*num_sim)++;
		i++;
	}
	
}

/*Funcion para devolver el grado de precedencia de un operador*/
int precedencia(Toperador op){
	int p;
	switch(op){
		case SUMA: p=1; break;
		case RESTA: p=1; break;
		case MULT: p=2; break;
		case DIV: p=2; break;
		case PAR_IZQ: p=0; break;
		case PAR_DER: p=0; break;
	}
	return (p);
}
//C:\Users\cesar\OneDrive\Documentos\AlgoEstrucDat\SegundoParcial\P22\SRC\version_0>


/*Funcion para transformar la secuencia de entrada en forma infija a postfija*/
void transforma_postfija(int *exp_infija, int *exp_postfija, int *num_sim)
{
	TPila_es *pila_es;/*Pila de operadores*/
	int i;
	int op;
	int num_sim_out;/*Numero de simbolos que quedaran en la salida*/
	pila_es = crea_pil();
	//pila_es = crearp_es();
	num_sim_out = 0;
	for (i=0;i<*num_sim;i++) 
	{
		switch (exp_infija[i]) {
		case SUMA:
		case RESTA:
		case MULT:
		case DIV: op=tope_pil(pila_es)/*op=tope_es(pila_es)*/;
			while ((precedencia(op)>=precedencia(exp_infija[i])) && (!elim_pil(pila_es)/*vaciap_es(pila_es)*/)) {
				pila_es=pop_pil(pila_es);
				//pila_es=desapilar_es(pila_es);
				exp_postfija[num_sim_out]=op;
				num_sim_out++;
				op=tope_pil(pila_es);
				//op=tope_es(pila_es);
			}
			pila_es=push_pil(pila_es, exp_infija[i]);
			//pila_es=apilar_es(pila_es, exp_infija[i]);
		break;
		case PAR_IZQ: pila_es=push_pil(pila_es,  PAR_IZQ);/*pila_es=apilar_es(pila_es, PAR_IZQ)*/;break;
		case PAR_DER: op=tope_pil(pila_es)/*op=tope_es(pila_es)*/;
			pila_es=pop_pil(pila_es);
			//pila_es=desapilar_es(pila_es);
			if (op!=PAR_IZQ) {
				exp_postfija[num_sim_out]=op;
				num_sim_out++;
			}	
			while (op!=PAR_IZQ) {
				op=tope_pil(pila_es);
				//op=tope_es(pila_es);
				pila_es=pop_pil(pila_es);
				//pila_es=desapilar_es(pila_es);
				if (op!=PAR_IZQ) {
					exp_postfija[num_sim_out]=op;
					num_sim_out++;
				}
			}
			break;
		default: /* Es un operando. */
			exp_postfija[num_sim_out] = exp_infija[i];
			num_sim_out++;
		}
	}
	/*Vaciamos los posibles operadores que queden en la pila */
	while(!elim_pil(pila_es)/*vaciap_es(pila_es)*/){
		op=tope_pil(pila_es);
		//op=tope_es(pila_es);
		pila_es=pop_pil(pila_es);
		//pila_es=desapilar_es(pila_es);
		exp_postfija[num_sim_out]=op;
		num_sim_out++;
	}
	*num_sim = num_sim_out;
	int x;
	printf("\n La expresion postfija es:");
				for(x=0;x<=*num_sim;x++)
				{
					printf("%c",exp_infija[x]);
				}
}
/*Funcion [ara evaluar una expresion postfija
Toperando evalua_postfija(int *exp_postfija, int num_sim){
	TPila_os *pila_os;
	int i;
	Toperando op1,op2;
	//Inserta codigo para evaluar la expresion postfija
}*/