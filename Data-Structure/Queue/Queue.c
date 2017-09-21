#include <stdlib.h>
#include "Queue.h"

typedef struct Element{
  Item info;
  int id;
  struct Element *next, *previous;
}Element;

typedef struct Base{
  Element *first, *last;
  int size;
}Base;


Queue createQueue(){
  Base *base = (Base*) malloc(sizeof(Base));
  if(base!=NULL){
    base->first = NULL;
    base->last = NULL;
    base->size = 0;
    return (Queue) base;
  }
  return NULL;
}


int lengthQueue(Queue queue){
  Base *base = (Base*) queue;
  if(base!=NULL){
    return base->size;
  }
  return 0;
}


int insertItemQ(Queue queue, int id, Item item){
  Base *base = (Base*) queue;
  Element *element;
  if(base!=NULL){
    element = (Element*) malloc(sizeof(Element));
    if(element==NULL){
      return 0;
    }
    element->id = id;
    element->info = item;
    if(base->first!=NULL){
      base->last->next = element;
      element->next = NULL;
      element->previous = base->last;
      base->last = element;
    }else {
      base->first = element;
      base->last = element;
      element->next = NULL;
      element->previous = NULL;
    }
    base->size = base->size + 1;
    return 1;
  }
  return 0;
}


int insertPriorityItemQ(Queue queue, int id, Item item){
  Base *base = (Base*) queue;
  Element *element;
  if(base!=NULL){
    element = (Element*) malloc(sizeof(Element));
    if(element==NULL){
      return 0;
    }
    element->id = id;
    element->info = item;
    if(base->first!=NULL){
      element->previous = NULL;
      element->next = base->first;
      base->first->previous = element;
      base->first = element;
    }else {
      base->first = element;
      base->last = element;
      element->next = NULL;
      element->previous = NULL;
    }
    base->size = base->size + 1;
    return 1;
  }
  return 0;
}


int removeFirstItemQ(Queue queue, eraseItemQ func){
  Base *base = (Base*) queue;
  Element *element;
  if(base!=NULL){
    if(base->first!=NULL && base->first!=base->last){
        func(base->first->info);
        element = base->first->next;
        free(base->first);
        base->first = element;
        element->previous = NULL;
        base->size = base->size - 1;
        return 1;
    }
    if(base->first != NULL && base->first == base->last){
        func(base->first->info);
        free(base->first);
        base->last = NULL;
        base->first = NULL;
        base->size = base->size - 1;
    }
  }
  return 0;
}


int removeItemQ(Queue queue, int p, eraseItemQ func){
  Base *base = (Base*) queue;
  Element *aux;
  int i,j;
  if(base!=NULL){
    if(base->first!=NULL){
      j = lengthQueue(queue);
      if(p<=0||p>j){
        return 0;
      }
      if(p==1){
        removeFirstItemQ(queue, func);
        return 1;
      }
      aux = base->first;
      for(i=0; i<j; i++){
        if(i==p){
          func(aux->info);
          aux->next->previous = aux->previous;
          aux->previous->next = aux->next;
          free(aux);
          base->size = base->size - 1;
          return 1;
        }
        aux = aux->next;
      }
      return 1;
    }
  }
  return 0;
}


Item getFirstItemQ(Queue queue){
  Base *base = (Base*) queue;
  if(base!=NULL){
    if(base->first!=NULL){
      return base->first->info;
    }
  }
  return NULL;
}


Item compareFirstItemIdQ(Queue queue, int id){
  Base *base = (Base*) queue;
  if(base!=NULL){
    if(base->first!=NULL){
      if(base->first->id == id){
        return base->first->info;
      }
    }
  }
  return NULL;
}


int eraseQueue(Queue queue, eraseItemQ func){
  Base *base = (Base*) queue;
  int i, j;
  Element *aux, *aux2;
  if(base!=NULL){
    if(base->first!=NULL){
      aux = base->first;
      j = lengthQueue(queue);
      for(i=0; i<j; i++){
        aux2 = aux;
        aux = aux->next;
        func(aux2->info);
        free(aux2);
      }
      free(base);
      return 1;
    }
  }
  return 0;
}
