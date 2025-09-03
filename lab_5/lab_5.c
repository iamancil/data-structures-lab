//Evaluate a postfix algebraic expression with the help of stack.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define max_size 100

//stack here is implemented  using arrays

typedef struct {
	int arr[max_size];
	int top;
} Stack;

void initialize(Stack *stack);
bool isFull(Stack *stack);
bool empty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int topStack(Stack *stack);

void initialize(Stack *stack){
	stack->top = -1;
}

void push(Stack *stack, int value){
  if(isFull(stack)){
    printf("Stack overflow");
    return;
  }
  else{
    stack->top++;
    stack->arr[stack->top] = value;
  }
}

bool isFull(Stack *stack){
  if(stack->top == max_size-1){
    return true;
  }
  else{
    return false;
  }
}
int pop(Stack *stack){
  if(empty(stack)){
    printf("Stack underflow");
    return 0;
  }
  else{
    int popped = stack->arr[stack->top];
    stack->top--;
    return popped;
  }
}

int topStack(Stack *stack){
  if(empty(stack)){
    printf("Stack is empty");
    return 0;
  }
  else{
    int topElement=stack->arr[stack->top];
    return topElement;
  }
}

bool empty(Stack *stack){
	//returns true or false
  if(stack->top == -1){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  Stack stack;
  initialize(&stack);
  char *expression;
  int size = 100;
  expression = (char *)malloc(size * sizeof(char));
  printf("Enter a postfix expression: ");
  scanf("%99s", expression);
  for(int i=0;expression[i]!=')';i++){
    int curr_char = expression[i];
    if (isdigit(curr_char)){
      push(&stack, curr_char-'0');
    }
    else if(curr_char == '+' || curr_char == '-' || curr_char == '*' || curr_char == '/'){
      int n2 = pop(&stack);
      int n1 = pop(&stack);
      int result;

      switch (curr_char) {
        case '+':
          result = n1+n2;
          break;
        case '-':
          result = n1-n2;
          break;
        case '*':
          result = n1*n2;
          break;
        case '/':
          result = n1/n2;
          break;
      }
      push(&stack,result);
    }
  }
  printf("Result: %d\n", pop(&stack));
  free(expression);
  return 0;
}
