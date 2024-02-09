#include "pol2rac.h"
/***********************************************************
*                   Funcines locales                       *
***********************************************************/

/*Resuelve el polinomio de segundo grado con coeficientes
  racionales. En caso de no tener solución se coloca la
  variable estado con el valor correspondiente*/
void resuelve(ecseg* e){	
  return;
}
/**********************************************************/
/*                      Funciones                         */
/**********************************************************/

/**************- Inicializa una ecuación -*****************/
/* Inicializa una ecuación
Recibe un apuntador de tipo ecseg y tres coeficientes racio-
  nales.
Regresa:
  OK, en caso de inicializar la ecuación.
  APINV, si recibe un apuntador nulo
  DENCER, en casode recibir un cero como el tercer parámetro
Observaciones:
  Siempre debe utilizar esta función para inicializar las
  ecuaciones con coeficientes racionales. No modificar 
  directamente los campos de la estructura.
*/
int ini_ec2r(ecseg* e, const racional* a, const racional* b, const racional* c){
  if(!(APVAL(e)&&APVAL(a)&&APVAL(b)&&APVAL(c)))
    return APINV;
  copia_rac(&(e->a),a);
  copia_rac(&(e->b),b);
  copia_rac(&(e->c),c);
  resuelve(e);
  return OK;
}

/* Convierte una ecuación a cadena
Recibe Un apuntador a cadena de caracteres que debe tener 
  espacio suficiente para almacerna la ecuación.
Regresa:
  Un apuntador a la misma cadena que recibe. En caso de te-
  ner un error regresa alguna de las siguientes cadenas:
  "NULL":   Recibe un apuntador nulo
  En caso contrario regresa una cadena que represetnta la 
  ecuación de segundo grado. Por ejemplo
  (-3/4)x^2+(-5/3)x+(3)=0
Observaciones:
  Imprime la ecuación tal y como está no hace verificaciones
  No verifica que el tamaño del arreglo destino ni el auxi-
  liar, que utiliza de racional.h
*/
char* tostr_ec2r(char* sal ,const ecseg* e){
   char aux[TAMCADAUX];
   if(!(APVAL(sal) && APVAL(e)))
     strcpy(sal,"NULL");
   else{
     strcpy(sal,"");
	 tostr_rac(aux,&(e->a));
	 strcat(sal,aux);
	 strcat(sal,"x^2+");
	 tostr_rac(aux,&(e->b));
	 strcat(sal,aux);
	 strcat(sal,"x+");
	 tostr_rac(aux,&(e->c));
	 strcat(sal,aux);
	 strcat(sal,"=0");
   }
   return sal;
}
/* Esta funcion es la que se encarga de obtener las raices de los polinomios proporcionados por el main
	Dependiendo de las condiciones de cada polinomio se hacen diferentes cosas para obtener las raices
	En esta funcion solo saca las raices cuando a es 0, cuando la raiz de la formula es mayor a cero, 
	y cuando la raiz de la formula es igual a cero.
	No se tomo en cuanta la cituacion en la que la raiz es negativa pues el resultado seria soluciones imaginarias.
*/

void sol_ecseg(ecseg* e, const racional* a, const racional* b, const racional* c){
	//declaracion de todas las variables racionales que se usaran en el calculo de las raices
	racional D,p,q,r,m1,m2,m3,m4,m5,m6,div1,divi2,divi3,divi4,raiz1,suma1,rest1,rest2,minusone,two,four,x1,x2;
	//se igualan los numeros racionales dados por p,q y r para poder trabajar con ellos en esta funcion
	p=*a;
	q=*b;
	r=*c;
	//se declaran estos enteros para despues hacer comparaciones 
	//entre racionales y dependiendo que se hace u na cosa u otra
	int dif,dif1,azero;
	char s1[1000];//variable para guardar los valores y luego comvertirlos a cadena.
	racional cero;//racional cero para hacer comparaciones de racionales
	ini_rac(&cero,0,1);
	ini_rac(&minusone,-1,1);//racional -1 que sera el que hara negativos a los racionales que se necesiten
	ini_rac(&two,2,1);//valor de 2a en la ecuacion de la raices de los polinomios
	ini_rac(&four,4,1);//valor de 4b en la ecuacion de las raices de los polinomios
	//Obtencion de D que seria lo que esta dentro de la raiz de la formula
	mult_rac(&m1,&q,&q);
	mult_rac(&m2,&p,&r);
	mult_rac(&m3,&four,&m2);
	rest_rac(&rest1,&m1,&m3);
	D=rest1;// resultado de D --> -b+4ac
	dif=comp_rac(&D,&cero);//comparacion de lo que esta en la raiz y el racional cero 1-->iguales 0--diferentes
	dif1=mayq_rac(&D,&cero);//compara si lo que esta en la raiz es mayor a cero
	azero=comp_rac(&p,&cero);//verifica si el valor a del polinomio es cero
	if(azero==0){//lo que se hace si el valor a del polinomio no es 0
	if(dif==1){//lo que se hace si D es igual a cero
	//ipresion de la formula
		printf("\n\n%sx^2",tostr_rac(s1,&p));
		printf("+%sx",tostr_rac(s1,&q));
		printf("+%s=0\n",tostr_rac(s1,&r));
		
		printf("El polinomio tiene una sola solucion:\n");
		mult_rac(&m5,&minusone,&q);//calculo de -b
		mult_rac(&m4,&two,&p);//calculo de 2a
		divi_rac(&div1,&m5,&m4);//Calculo de -b/2a
		x1=div1;//igualacion del resultado a x1
		printf("%s\n",tostr_rac(s1,&div1));//impresion de la raiz
		
		//comprobacion;
		printf("Comprobacion de soluciones:\n");
		racional ax_2,x_2,bx,cx,sumaparte,sumacompleta;
		mult_rac(&x_2,&x1,&x1);
		mult_rac(&ax_2,&p,&x_2);
		mult_rac(&bx,&q,&x1);
		mult_rac(&cx,&r,&x1);
		suma_rac(&sumaparte,&ax_2,&bx);
		suma_rac(&sumacompleta,&sumaparte,&cx);
		
		printf("siendo x=%s\n",tostr_rac(s1,&x1));
		printf("%s",tostr_rac(s1,&p));
		printf("%s^2",tostr_rac(s1,&x1));
		printf("+%s",tostr_rac(s1,&q));
		printf("%s",tostr_rac(s1,&x1));
		printf("+%s",tostr_rac(s1,&r));
		printf("%s=0\n",tostr_rac(s1,&x1));
		
		printf("%s",tostr_rac(s1,&p));
		printf("%s",tostr_rac(s1,&x_2));
		printf("+%s",tostr_rac(s1,&bx));
		printf("+%s=0\n",tostr_rac(s1,&cx));
		
		printf("%s",tostr_rac(s1,&ax_2));
		printf("+%s",tostr_rac(s1,&bx));
		printf("+%s=0\n",tostr_rac(s1,&cx));
		
		printf("%s",tostr_rac(s1,&sumaparte));
		printf("+%s=0\n",tostr_rac(s1,&cx));
		
		printf("%s=0\n",tostr_rac(s1,&sumacompleta));
		//Se guarda el valor de x1 en la ecuacion e
		e->x1=x1;
		
		
	}else if(dif1==1){//lo que se hace si D es mayor a cero
		//Impresion de la formula
		printf("\n\n%sx^2",tostr_rac(s1,&p));
		printf("+%sx",tostr_rac(s1,&q));
		printf("+%s=0\n",tostr_rac(s1,&r));
		
		printf("El polinomio tiene dos soluciones:\n");
		mult_rac(&m5,&minusone,&q);//-b
		raiz_rac(&raiz1,&D);//raiz de D 
		suma_rac(&suma1,&m5,&raiz1);//-b+Raiz(D)
		mult_rac(&m4,&two,&p);//calculo de 2a
		divi_rac(&divi2,&suma1,&m4);//calculo de (-b+Raiz(D))/2a
		x1=divi2;//igualacion del resultado a x1
		printf("Solucion 1:%s\n",tostr_rac(s1,&x1));//impresion de la raiz 1
		
		rest_rac(&rest2,&m5,&raiz1);//-b+Raiz(D)
		divi_rac(&divi3,&rest2,&m4);//calculo de (-b-Raiz(D))/2a
		x2=divi3;//igualacion del resultado de x2
		printf("Solucion 2:%s\n",tostr_rac(s1,&x2));
		//comprobacion de soluciones
		printf("Comprobacion de soluciones:\n");
		racional ax_2,x_2,bx,cx,sumaparte,sumacompleta;
		mult_rac(&x_2,&x1,&x1);
		mult_rac(&ax_2,&p,&x_2);
		mult_rac(&bx,&q,&x1);
		mult_rac(&cx,&r,&x1);
		suma_rac(&sumaparte,&ax_2,&bx);
		suma_rac(&sumacompleta,&sumaparte,&cx);
	
		//comprobacion para la raiz 1
		printf("siendo x1=%s\n",tostr_rac(s1,&x1));
		printf("%s",tostr_rac(s1,&p));
		printf("%s^2",tostr_rac(s1,&x1));
		printf("+%s",tostr_rac(s1,&q));
		printf("%s",tostr_rac(s1,&x1));
		printf("+%s",tostr_rac(s1,&r));
		printf("%s=0\n",tostr_rac(s1,&x1));
		
		printf("%s",tostr_rac(s1,&p));
		printf("%s",tostr_rac(s1,&x_2));
		printf("+%s",tostr_rac(s1,&bx));
		printf("+%s=0\n",tostr_rac(s1,&cx));
		
		printf("%s",tostr_rac(s1,&ax_2));
		printf("+%s",tostr_rac(s1,&bx));
		printf("+%s=0\n",tostr_rac(s1,&cx));
		
		printf("%s",tostr_rac(s1,&sumaparte));
		printf("+%s=0\n",tostr_rac(s1,&cx));
		
		printf("%s=0\n",tostr_rac(s1,&sumacompleta));
		
		//comprobacion para la raiz 2
		racional ax_2_2,x_2_2,bx_2,cx_2,sumaparte_2,sumacompleta_2;
		mult_rac(&x_2_2,&x2,&x2);
		mult_rac(&ax_2_2,&p,&x_2);
		mult_rac(&bx_2,&q,&x2);
		mult_rac(&cx_2,&r,&x2);
		suma_rac(&sumaparte_2,&ax_2_2,&bx_2);
		suma_rac(&sumacompleta_2,&sumaparte_2,&cx_2);
		
		printf("siendo x2=%s\n",tostr_rac(s1,&x2));
		printf("%s",tostr_rac(s1,&p));
		printf("%s^2",tostr_rac(s1,&x2));
		printf("+%s",tostr_rac(s1,&q));
		printf("%s",tostr_rac(s1,&x2));
		printf("+%s",tostr_rac(s1,&r));
		printf("%s=0\n",tostr_rac(s1,&x2));
		
		printf("%s",tostr_rac(s1,&p));
		printf("%s",tostr_rac(s1,&x_2_2));
		printf("+%s",tostr_rac(s1,&bx_2));
		printf("+%s=0\n",tostr_rac(s1,&cx_2));
		
		printf("%s",tostr_rac(s1,&ax_2_2));
		printf("+%s",tostr_rac(s1,&bx_2));
		printf("+%s=0\n",tostr_rac(s1,&cx_2));
		
		printf("%s",tostr_rac(s1,&sumaparte_2));
		printf("+%s=0\n",tostr_rac(s1,&cx_2));
		
		printf("%s=0\n",tostr_rac(s1,&sumacompleta_2));
		e->x1=x1;
		e->x2=x2;
	}	
	
	}else if(azero==1){//Lo que se hace si a es igual a cero
		printf("\n\n%sx^2",tostr_rac(s1,&p));
		printf("+%sx",tostr_rac(s1,&q));
		printf("+%s=0\n",tostr_rac(s1,&r));
		
		mult_rac(&m6,&minusone,&r);
		divi_rac(&divi4,&m6,&q);
		printf("\nSolo tien una raiz: %s\n",tostr_rac(s1,&divi4));
		e->x1=divi4;
		
	}
}