#ifndef _STACK
#define _STACK

#define t_elem void*

typedef struct _stack {
  t_elem* s;
  int top;
  int maxsize;
} stack;

stack* stack_new(int maxsize);

void stack_free(stack* s);

int stack_getsize(stack* s);

int stack_getmaxsize(stack* s);

void push(stack* s, void* elem);

void* pop(stack* s);

void* top(stack* s);

int stack_isempty(stack* s);

int stack_isfull(stack* s);

void stack_destroy(stack* s, void elem_free(void*));


#include "stack_static.c"
#endif