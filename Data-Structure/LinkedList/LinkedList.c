#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct Element{
  Item info;
  int id;
  struct Element *next;
}Element;

typedef struct Base{
  Element *first;
  Element *last;
  int size;
}Base;

List createListLL(){
  Base *list = NULL;
  list = (Base *) malloc(sizeof(Base));
  if(list!=NULL){
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
  }else{
    printf("Error in alocation of memory.\n");
  }
  return (List) list;
}


int insertEndLL(List list, int id, Item item){
  Base *base = (Base *) list;
  Element *element = NULL;
  if(base!=NULL){
    element = (Element*) malloc(sizeof(Element));
    if(element==NULL){
      printf("Error in alocation of memory.\n");
      return 0;
    }
    if(base->first!=NULL){
      element->id = id;
      element->info = item;
      element->next = NULL;
      base->last->next = element;
      base->last = element;
      base->size = base->size + 1;
    }else{
      element->id = id;
      element->info = item;
      element->next = NULL;
      base->first = element;
      base->last = element;
      base->size = base->size + 1;
    }
    return 1;
  }
  return 0;
}


int insertBeginLL(List list, int id, Item item){
  Base *base = (Base *) list;
  Element *element = NULL;
  if(base!=NULL){
    element = (Element*) malloc(sizeof(Element));
    if(element==NULL){
      printf("Error in alocation of memory.\n");
      return 0;
    }
    if(base->first!=NULL){
      element->id = id;
      element->info = item;
      element->next = base->first;
      base->first = element;
      base->size = base->size + 1;
    }else{
      element->id = id;
      element->info = item;
      element->next = NULL;
      base->first = element;
      base->last = element;
      base->size = base->size + 1;
    }
    return 1;
  }
  return 0;
}


int insertMiddleLL(List list, int id, int p, Item item){
  Base *base = (Base *) list;
  Element *element = NULL, *aux=NULL;
  int i=0, j=0;
  if(base!=NULL||p<=0){
    j = base->size;
    if(p==1){
      insertBeginLL(list, id, item);
    } else
    if(p==j||p>j){
      insertEndLL(list, id, item);
    }else
    if(p<j&&p>0){
      element = (Element*) malloc(sizeof(Element));
      if(element==NULL){
        printf("Error in alocation of memory.\n");
        return 0;
      }
      if(base->first!=NULL){
        element->id = id;
        element->info = item;
        aux = base->first;
        for(i=1; i<=j; i++){
          if(i==(p-1)){
            element->next = aux->next;
            aux->next = element;
            base->size = base->size + 1;
            break;
          }
          aux = aux->next;
        }
      }else{
        element->id = id;
        element->info = item;
        element->next = NULL;
        base->first = element;
        base->last = element;
        base->size = base->size + 1;
      }
    }else{
      return 0;
    }
    return 1;
  }
  return 0;
}


int removeBeginLL(List list, eraseItem func){
  Base *base = (Base *) list;
  Element *aux = NULL;
  if(base!=NULL){
    if(base->first!=NULL){
      aux = base->first->next;
      func(base->first->info);
      free(base->first);
      base->first = aux;
      base->size = base->size - 1;
      return 1;
    }
  }

  return 0;
}


int removeEndLL(List list, eraseItem func){
  Base *base = (Base *) list;
  Element *aux = NULL;
  int i, j;
  if(base!=NULL){
    if(base->first!=NULL){
      aux = base->first;
      j = lenghtLL(list);
      for(i=1; i<j-1; i++){
        aux = aux->next;
      }
      func(base->last->info);
      free(base->last);
      aux->next = NULL;
      base->last = aux;
      base->size = base->size - 1;
      return 1;
    }
  }

  return 0;
}


int removeMiddleLL(List list, int p, eraseItem func){
  Base *base = (Base *) list;
  Element *aux = NULL, *aux2=NULL;
  int i, j;
  if(base!=NULL){
    if(base->first!=NULL){
      aux = base->first;
      j = lenghtLL(list);
      if(p<=0||p>j){
        return 0;
      }
      for(i=1; i<=j; i++){
        if(i==p){
          aux2->next = aux->next;
          func(aux->info);
          free(aux);
          break;
        }
        aux2 = aux;
        aux = aux->next;
      }
      base->size = base->size - 1;
      return 1;
    }
  }

  return 0;
}


Item searchIdLL(List list, int id){
  Base *base = (Base *) list;
  Element *aux = NULL;
  Item item=NULL;
  int i, j;
  if(base!=NULL){
    if(base->first!=NULL){
      aux = base->first;
      j = lenghtLL(list);
      for(i=0; i<j; i++){
        if(aux->id == id){
          item = aux->info;
          break;
        }
        aux = aux->next;
      }
      return item;
    }
  }

  return NULL;
}


Item getBeginItem(List list){
  Base *base = (Base *) list;
  Item item=NULL;
  if(base!=NULL){
    if(base->first!=NULL){
      item = base->first->info;
      return item;
    }
  }
  return NULL;
}


Item getEndItem(List list){
  Base *base = (Base *) list;
  Item item=NULL;
  if(base!=NULL){
    if(base->first!=NULL){
      item = base->last->info;
      return item;
    }
  }
  return NULL;
}


Item getLL(List list, int p){
  Base *base = (Base *) list;
  Element *aux = NULL;
  Item item=NULL;
  int i, j;
  if(base!=NULL){
    if(base->first!=NULL){
      aux = base->first;
      j = lenghtLL(list);
      if(p<=0 || p > j){
        return NULL;
      }
      for(i=1; i<=j; i++){
        if(i == p){
          item = aux->info;
          break;
        }
        aux = aux->next;
      }
      return item;
    }
  }

  return NULL;
}


int lenghtLs(List list){
    Base *base = (Base *) list;
    return base->size;
}

int eraseListLs(List list, eraseItem func){
  Base *base = (Base *) list;
  Element *aux = NULL, *aux2=NULL;

  int i, j;
  if(base!=NULL){
    if(base->first!=NULL){
      aux = base->first;
      j = lenghtLs(list);
      for(i=0; i<j; i++){
        aux2  = aux;
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
