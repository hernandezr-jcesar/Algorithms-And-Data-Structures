#include <stdio.h>
#include <string.h>

#define SIZE 100

struct stack {
    int index;
    char array[SIZE];
};

typedef struct stack Stack;

void initialize_stack(Stack*);
int push(Stack*, char);
int pop(Stack*, char*);
int is_full(Stack*);
int is_empty(Stack*);
void to_posfix(Stack* s, char* postfix, char* infix);
int priority(char);
int is_operator(char);
char top(Stack*);

int main(int argc, char* argv[])
{
    Stack my_stack;
    char my_postfix[100];
    char my_infix[100];
    initialize_stack(&my_stack);
        
    to_posfix(&my_stack, my_postfix, argv[1]);

    printf("%s", my_postfix);

    return 0;
}

void initialize_stack(Stack* s)
{
    s->index = 0;
}

int push(Stack* s, char pushable)
{
    if(s->index < SIZE){
        s->array[s->index] = pushable;
        (s->index)++;
        return 1;
    }
    else 
        return 0;
} 

int pop(Stack* s, char* poppable)
{
    if(s->index >= 0){
        (s->index)--;
        *poppable = s->array[s->index];
        return 1;
    }
    else
        return 0;
}

int is_full(Stack* s)
{
    if (s->index == SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(Stack* s)
{
    if (s->index == 0)
        return 1;
    else
        return 0;
}

void to_posfix(Stack* s, char* postfix, char* infix)
{
    char leftParenthesis;
    unsigned int i = 0, j = 0;
    push(s,'(');
    strcat (infix,")");
    while((!is_empty(s)))
    {
        if(infix[i] > 47 && infix[i] < 58)
        {
            postfix[j] = infix[i];
            j++;
        }    
        else if(infix[i] == '(')
            push(s, infix[i]);
        else if(is_operator(infix[i]))
        {
            while(priority(infix[i]) >= priority(top(s)))
            {
                pop(s, &postfix[j]);
                j++;
            }
            push(s, infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(top(s) != '(')
                if(is_operator(top(s)))
                {
                    pop(s, &postfix[j]);
                    j++;
                }
            pop(s,&leftParenthesis); //removes parenthesis
        }
        i++;
    }
    postfix[j] = '\0';
}

int priority(char operator)
{
    if(operator == '+' || operator == '-')
        return 1;
    else if(operator == '*' || operator == '/')
        return 2;
    else if(operator == '%' || operator == '^')
        return 3;
    else
        return 4;
}

int is_operator(char operator)
{
    if(operator == '+' || operator == '-' || operator == '*' || 
    operator == '/' || operator == '^' || operator == '%')
        return 1;
    else
        return 0;
}

char top(Stack* s)
{
    return s->array[(s->index)-1];
}
