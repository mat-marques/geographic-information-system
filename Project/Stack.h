#ifndef STACK_H
#define STACK_H
#include <stdio.h>

typedef void* Stack;
typedef void* Item;
typedef void(*eraseItemS)(Item);

Stack createStack();


int lengthStack(Stack stack);


int insertTop(Stack stack, int id, Item item);


int removeTop1(Stack stack, eraseItemS func);


Item removeTop2(Stack stack);


Item getItemTop(Stack stack);


Item compareIdTop(Stack stack, int id);


int eraseStack(Stack stack, eraseItemS func);


#endif
