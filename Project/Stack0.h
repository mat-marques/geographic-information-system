#ifndef STACK_H
#define STACK_H
#include <stdio.h>

typedef void* Stack;
typedef void* Item;
typedef void(*eraseItemS)(Item);

Stack createStack();


int lengthStack(Stack stack);


int insertTop(Stack stack, Item item);


int removeTop(Stack stack, eraseItemS func);


Item removeTopI(Stack stack);


Item getItemTop(Stack stack);


Stack concatStacks(Stack stack1, Stack stack2);


int eraseStackOne(Stack stack, eraseItemS func);


int eraseStackTwo(Stack stack);


#endif
