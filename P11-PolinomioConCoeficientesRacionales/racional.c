#include "racional.h"

/***********************************************************
Definici�n de n�meros Racionales.
Objetivo: Definier las funciones que operan con n�meros 
  racionales.
Autor:
  Juan Jes�s Guti�rrez Garc�a
Fecha:
  Septiebre 2020
Observaciones:
  La verificaci�n de errores se realiza con logica inversa.
Limitantes:
  Se utiliza s�lo memoria est�tica.
***********************************************************/

/***********************************************************
*                   Funcines locales                       *
***********************************************************/

/*C�lculo de m�ximo c�mun divisor.
  Se divide en dos funciones. Una que verifica los 
     par�metros y otra que hace el c�lculo recursivo*/  
int mcd(int a, int b){
  int max, min, res;
  max = MAX(abs(a),abs(b));      /*Ordena los n�meros*/
  min = MIN(abs(a),abs(b));
  /*Invoca a la funci�n recursva*/
  return mcd_r(max,min);
}

int mcd_r(int max, int min){
  return max%min?mcd(min,max%min):min;
}

/**************- Inicializa un racional -******************/
/* Inicializa el n�mero racional
Recibe un apuntador a Racional que hace referencia a la va-
  riable que ser� inicializada. Tambi�n recibe dos enteros. 
  El primero represetna el n�merador y el segundo el deno-
  minador del n�mero racional con el que se inicializa.
Regresa:
  OK, en caso de inicializar el racional
  APINV, si recibe un apuntador nulo
  DENCER, en casode recibir un cero como el tercer par�metro
*/
int ini_rac(racional* q, int n, int d){
  int maxcomdiv;
  /*Validaci�n*/
  if(!(APVAL(q)))
    return APINV;
  if(!(d!=0))
     return DENCER;
  /*Representaci�n del cero*/
  if (n==0){
    q->num =0;
    q->den = 1;
    q->sig = POSITIVO;
  }else{
    /*Reduce la fracci�n*/
    maxcomdiv=mcd(abs(n),abs(d));
    q->num =abs(n)/maxcomdiv;
    q->den = abs(d)/maxcomdiv;
    /*Usa ley de los signos para calcular el signo del
      racional*/
    q->sig = n*d>0?POSITIVO:NEGATIVO;
  }
  return OK;
}

/**************- Copia un racional en otro **************/
/* Copia una racional en otro
Recibe Un apunador a racional, destino y otro origen
Regresa:
  OK       En caso de realizar la copia
  APINV    En caso de recibir un apuntador NULL
  DENCER   En caso de que el origen tenga denominador cero
*/
int copia_rac(racional* d,const racional* o){
  /*Validaci�n*/
  if(!(APVAL(d)&&APVAL(o)))
    return APINV;
  if(!(o->den!=0))
     return DENCER;
  d->num = o->num;
  d->den = o->den;
  d->sig = o->sig;
  return OK;
}

/* Convierte un racional a cadena
Recibe Un apuntador a cadena de caracteres que debe tener 
  espacio suficiente para almacerna el racional.
Regresa:
  Un apuntador a la misma cadena que recibe. En caso de te-
  ner un error regresa alguna de las siguientes cadenas:
  "NULL":   Recibe un apuntador nulo
  "DIVCER": Dedenominador cero
  En caso contrario regresa una cadena que represetnta al 
  n�mero racional encerrado entre par�ntesis
  por ejemplo (-3/4) o (5/3)
Observaciones
  Se utiliza la funci�n strcpy y strcat para facilitar el
  manejo de las cadenas.
  La conversi�n de entero a cadena se hace con sprintf
  Se consideran tres casos:
  - el cero se convierte a "0"
  - Para los enteros, con denominador 1, se usa el formato
    (n) dond� la letra n representa el valor del n�merador.
    por ejemplo (5) o (-3)
  - El formato general es (n/d) por ejemplo: (-3/4) o (7/9)
*/
char* tostr_rac(char* sal ,const racional* q){
  char aux[TAMCADAUX];
  /*Verificaci�n*/
  if(!(APVAL(sal)&&APVAL(q)))
    strcpy(sal,"NULL");
  else if(!(q->den!=0))
    strcpy(sal,"DIVCER");
  else{
    /*Conversi�n*/
    strcpy(sal,"(");
    if(ESCERO(q))                 /*Caso cero*/
      strcpy(sal,"0");
    else{
      strcat(sal,SIGNO(q));       /*Caso entero*/
      if (ESENTE(q))
        sprintf(aux,"%d",q->num);
      else                        /*Caso general*/
        sprintf(aux,"%d/%d",q->num,q->den);
      strcat(sal,aux);
      strcat(sal,")");
    }
  }
  return sal;
}

/*Compara dos n�meros racionales
Recibe: Dos par�metros
  Apuntador a los elementos a comparar
Regresa:
  APINV:  Cero en caso de recibir par�metros invalidos
  1    :  En caso de ser n�mero iguales
  0    :  En caso de ser n�meros diferentes
Observaciones
  El valor de retorno s�lo es cero o uno as� que si se 
  reciben apuntadores nulos s�lo se regresa un cero. 
*/
int comp_rac(const racional* a, const racional* b){
  if(!(APVAL(a)&&APVAL(b)))
    return OK;
  return a->num==b->num && a->den==b->den && a->sig==b->sig;
}

/*Compara dos n�meros racionales
Recibe: Dos par�metros
  Apuntador a los elementos a comparar
Regresa:
  APINV:  Cero en caso de recibir par�metros invalidos
  1    :  En caso de ser n�mero diferentes
  0    :  En caso de ser n�meros iguales
Observaciones
  El valor de retorno s�lo es cero o uno as� que si se 
  reciben apuntadores nulos s�lo se regresa un cero. 
*/
int dist_rac(const racional* a, const racional* b){
  if(!(APVAL(a)&&APVAL(b)))
    return OK;
  return a->num!=b->num || a->den!=b->den || a->sig!=b->sig;
}

/*Compara dos mayor o menor
Recibe: Dos par�metros
  Apuntador a los elementos a comparar
Regresa:
  APINV:  Cero en caso de recibir par�metros invalidos
  1    :  1 si el primer parametro es mayor que el segundo
  0    :  En caso contrario
Observaciones
  En caso de recibir apuntadores nulos se regresa falso, cero
  porque estos no deben ser comarados.
  Toma en cuenta el signo de cada entero.
  Toma en cuenta el signo de cada entero.
*/
int mayq_rac(const racional* a, const racional* b){
  if(!(APVAL(a)&&APVAL(b)))
    return OK;
  return SIGNOV(a)*a->num*b->den > SIGNOV(b)*b->num*a->den;
}

/*Invierte un n�mero
Recibe: Dos par�metros racionales.
  Apuntador a el resultado de invertir el n�mero
  Apuntador a el n�mero que ser� invertido
Regresa:
  APINV:  Si recibe un apuntador nulo.
  DENCER: Si el segundo par�metro es cero.
  OK:     Si se realiza la operaci�n sin problemas
Observaciones
  Se modifica tambi�n el signo del resultado para evitar
  que tenga un valor previo diferente al signo de el par�-
  metro.
*/
int inve_rac(racional* r, const racional* a){
  if(!(APVAL(r)&&APVAL(a)))
    return APINV;
  if(ESCERO(a))
    return DENCER;
  r->num = a->den;
  r->den = a->num;
  r->sig = a->sig;
  return OK;
}

/*Ra�z cuadrada
Recibe: Dos par�metros racionales.
  Apuntador a el resultado ra�z del n�mero
  Apuntador a el n�mero que del que se obtendr� la
    ra�z
Regresa:
  APINV:  Si recibe un apuntador nulo.
  IMAG:   Si recibe un n�mero racional negativo
  OK:     Si se realiza la operaci�n sin problemas
Observaciones
  Trunca el resultado de la ra�z. No es exacta s�lo
  se obtiene la ra�z del numerador y del denominador
  Si la ra�z del denominador es menor de 1 se truncar�a 
  a cero y para evitar esto se asigna un 1 al denominador
*/
int raiz_rac(racional* r, const racional* a){
  int num,den,err;
  if(!(APVAL(r)&&APVAL(a)))
    return APINV;
  if(!ESPOS(a))
    return IMAG;

  num = sqrt(a->num);
  den = sqrt(a->den);
  den = den==0?1:den;
  err = ini_rac(r,num,den);
  return err;
}

/*Suma dos n�meros racionales
Recibe: Tres par�metros
  Apuntador a un rarcional que almacenar� el resultado
  Apuntador a el primer racional para sumar
  Apuntador a el segundo racional para sumar
Regresa:
  APINV: en caso de recibir un apuntador invalida
  OK: Si no hay error
Observaciones
  S�lo se calcula el n�merador y denominador, para reducir
  la fracci�n se invoca ini_rac.
  Tambi�n la verificaci�n del denominador diferente de cero
  se realiza con la misma funci�n
*/
int suma_rac(racional* r, const racional* a, const racional* b){
  int num,den,err;
  /* Valida */
  if(!(APVAL(r)&&APVAL(a)&&APVAL(b)))
    return APINV;
  num = SIGNOV(a)*a->num*b->den + SIGNOV(b)*a->den*b->num;
  den = a->den*b->den;  
  err = ini_rac(r,num,den);
  return err;
}

/*Resta dos n�meros racionales
Recibe: Tres par�metros
  Apuntador a un rarcional que almacenar� el resultado
  Apuntador a el primer racional para restado
  Apuntador a el segundo racional para restado
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
Observaciones
  S�lo se calcula el n�merador y denominador, para reducir
  la fracci�n se invoca ini_rac.
  Tambi�n la verificaci�n del denominador diferente de cero
  se realiza con la misma funci�n
*/
int rest_rac(racional* r, const racional* a, const racional* b){
  int num,den,err;
  /* Valida */
  if(!(APVAL(r)&&APVAL(a)&&APVAL(b)))
    return APINV;
  num = SIGNOV(a)*a->num*b->den - SIGNOV(b)*a->den*b->num;
  den = a->den*b->den;
  err = ini_rac(r,num,den);
  return err;
}

/*Multiplica dos n�meros racionales
Recibe: Tres par�metros
  Apuntador a un rarcional que almacenar� el resultado
  Apuntador a el primer racional para multiplicarse
  Apuntador a el segundo racional para multiplicarse
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int mult_rac(racional* r, const racional* a, const racional* b){
	int num,den,err;
  /* Valida */
	if(!(APVAL(r)&&APVAL(a)&&APVAL(b)))
    return APINV;
	num = (SIGNOV(a)*a->num) * (SIGNOV(b)*b->num);
	den = (a->den)*(b->den);
	err = ini_rac(r,num,den);
  return err;
  
}

/*Division dos n�meros racionales
Recibe: Tres par�metros
  Apuntador a un rarcional que almacenar� el resultado
  Apuntador a el primer racional para ser el dividendo
  Apuntador a el segundo racional para ser el divisor
Regresa:
  APINV: en caso de recibir un apuntador invalido
  OK: Si no hay error
*/
int divi_rac(racional* r, const racional* a, const racional* b){
	int num,den,err;
  /* Valida */
	if(!(APVAL(r)&&APVAL(a)&&APVAL(b)))
    return APINV;

	num= (SIGNOV(a)*a->num) * (SIGNOV(b)*b->den);
	den= a->den * b->num;
	err = ini_rac(r,num,den);
	return err;
}





