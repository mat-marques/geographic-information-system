#ifndef STACK_H
#define STACK_H
#include <stdio.h>

typedef void* Stack;
typedef void* ItemS;
typedef void(*eraseItemS)(ItemS);

Stack createStack();


int lengthStack(Stack stack);


int insertTop(Stack stack, ItemS item);


int removeTop(Stack stack, eraseItemS func);


ItemS removeTopI(Stack stack);


ItemS getItemTop(Stack stack);


Stack concatStacks(Stack stack1, Stack stack2);

void eraseBaseStack(Stack stack);


int eraseStackOne(Stack stack, eraseItemS func);


int eraseStackTwo(Stack stack);


#endif
