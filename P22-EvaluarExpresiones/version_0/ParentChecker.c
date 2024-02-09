#include <stdio.h>
#include "EvalExp.h"
int main(){
	char stk[TAMMAX];
	int top=-1;
	
	char frase[TAMMAX];
	frase[TAMMAX]="(A+(B-C))";
	printf("Enter an expresion : ");
	gets(frase);
	ParentChecker(frase);
	printf("\n\n");
	
	return 0;
}
#include "EvalExp.h"

void ParentChecker(char const *frase){
	char exp[TAMMAX],temp;
	int i, flag=1;
	strcpy(exp,frase);
	for(i=0;i<strlen(exp);i++){
	  if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
	    push(exp[i]);
	  if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
	    if(top == -1)
		  flag=0;
	    else
		{
		  temp=pop();
		  if(exp[i]==')' && (temp=='{' || temp=='['))
		    flag=0;
		  if(exp[i]=='}' && (temp=='(' || temp=='['))
		    flag=0;
		  if(exp[i]==']' && (temp=='(' || temp=='{'))
		    flag=0;
		}
	}
	if(top>=0)
	  flag=0;
	if(flag==1)
	  printf("\nValid expression");
	else
	  printf("\nInvalid expression");

}
void push(char c){
	if(top == (TAMMAX-1))
	  printf("Stack Overflow\n");
	else{ 
	  top = top+1;
	  stk[top] = c;
	} 
}
char pop(){
	if(top == -1)
	  printf("\n Stack Underflow");
	else
	  return (stk[top--]);
}


