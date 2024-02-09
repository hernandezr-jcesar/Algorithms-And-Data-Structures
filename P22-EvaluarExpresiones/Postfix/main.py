import sys

class Stack:
    def __init__(self):
         self.items = []

    def isEmpty(self):
         return self.items == []
    
    def isFull(self):
        return self.items == len(self.items)-1

    def push(self, item):
         self.items.append(item)

    def pop(self):
         return self.items.pop()

    def top(self):
         return self.items[len(self.items)-1]

    def size(self):
         return len(self.items)

def toPostfix(stack, infix, postfix):
    i = 0
    stack.push('(')
    infix = infix + ')' 
    while(not stack.isEmpty()):
        if infix[i] >= '0' and infix[i] <= '9':
            postfix.append(infix[i])
        elif infix[i] == '(':
            stack.push(infix[i])
        elif isOperator(infix[i]):
            while priority(infix[i]) >= priority(stack.top()):
                postfix.append(stack.pop())
            stack.push(infix[i])
        elif infix[i] == ')':
            while stack.top() != '(':
                if isOperator(stack.top()):
                    postfix.append(stack.pop())
            stack.pop()
        i = i + 1

def isOperator(operator):
    if operator == '+' or operator == '-' or operator == '*' or operator == '/' or operator == '%' or operator == '^':
        return True
    else:
        return False

def priority(operator):
    if operator == '+' or operator == '-':
        return 1
    elif operator == '*' or operator == '/':
        return 2
    elif operator == '%' or operator == '^':
        return 3
    else:
        return 4

if(len(sys.argv) == 2):
    try:
            stack = Stack()
            mypostfix = []
            myinfix = sys.argv[1]

            stack.__init__
            toPostfix(stack, myinfix, mypostfix)
            print mypostfix
    except:
        print 'Write: main.py <expression>'
        sys.exit(2)