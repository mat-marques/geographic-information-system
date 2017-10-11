#include <stdlib.h>
#include "Stack.h"

typedef struct Element{
  Item info;
  struct Element *up, *down;
}Element;

typedef struct Base{
  Element *top;
  int size;
}Base;

Stack createStack(){
  Base *base = NULL;
  base = (Base*) malloc(sizeof(Element));
  if(base!=NULL){
    base->size = 0;
    base->top = NULL;
  }
  return (Stack) base;
}


int lengthStack(Stack stack){
  Base *base = (Base*) stack;
  if(base!=NULL){
    return base->size;
  }
  return 0;
}


int insertTop(Stack stack, Item item){
  Base *base = (Base*) stack;
  Element *element = NULL;
  if(base!=NULL){
    element = (Element*) malloc(sizeof(Element));
    if(element==NULL){
      return 0;
    }
    element->info = item;
    if(base->top!=NULL){
      element->down = base->top;
      element->up = NULL;
      base->top->up = element;
      base->top = element;
    }else{
      element->down = NULL;
      element->up = NULL;
      base->top = element;
    }
    base->size = base->size + 1;
    return 1;
  }
  return 0;
}


int removeTop(Stack stack, eraseItemS func){
  Base *base = (Base*) stack;
  Element *aux = NULL;
  if(base!=NULL){
    if(base->top!=NULL && base->top->down!=NULL){
        aux = base->top->down;
        func(base->top->info);
        free(base->top);
        base->top = aux;
        aux->up = NULL;
        base->size = base->size - 1;
        return 1;
    }
    if(base->top!=NULL && base->top->down==NULL){
        func(base->top->info);
        free(base->top);
        base->top = NULL;
        base->size = base->size - 1;
    }
  }
  return 0;
}


Item removeTopI(Stack stack){
  Base *base = (Base*) stack;
  Element *aux = NULL;
  Item info = NULL;
  if(base!=NULL){
    if(base->top!=NULL && base->top->down!=NULL){
        aux = base->top->down;
        info = base->top->info;
        free(base->top);
        base->top = aux;
        aux->up = NULL;
        base->size = base->size - 1;
    }
    if(base->top!=NULL && base->top->down==NULL){
        info = base->top->info;
        free(base->top);
        base->top = NULL;
        base->size = base->size - 1;
    }
  }
  return info;
}


Item getItemTop(Stack stack){
  Base *base = (Base*) stack;
  return (Item) base->top->info;
}


int eraseStackOne(Stack stack, eraseItemS func){
  Base *base = (Base*) stack;
  int i, j;
  if(base!=NULL){
    j = lengthStack(stack);
    for(i=0; i<j; i++){
      removeTop(stack, func);
    }
    free(base);
    return 1;
 }
 return 0;
}


int eraseStackTwo(Stack stack){
  Base *base = (Base*) stack;
  int i, j;
  if(base!=NULL){
    j = lengthStack(stack);
    for(i=0; i<j; i++){
      removeTopI(stack);
    }
    free(base);
    return 1;
 }
 return 0;
}
