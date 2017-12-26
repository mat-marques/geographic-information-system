#include "List.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
  Item info;
  struct Element *next;
  struct Element *previous;
} Element;

typedef struct Base {
  Element *first;
  Element *last;
  int size;
} Base;

List createL() {
  Base *base = NULL;
  base = (Base *)malloc(sizeof(Base));
  if (base != NULL) {
    base->first = NULL;
    base->last = NULL;
    base->size = 0;
  } else {
    printf("Error in alocation memory.\n");
  }
  return (List)base;
}

int lengthL(List list) {
  Base *base = (Base *)list;
  if(list != NULL)
    return base->size;

  return 0;
}

int isEmpty(List list){
    Base *L1 = (Base *) list;
    if(L1->first==NULL){
        return 1;
    }
    return 0;
}

Posic insertL(List list, Item info){
    Element *No=NULL;
    Base *L1;
    if(isEmpty(list)==1){
        L1 = (Base *) list;
        No = (Element*) malloc(sizeof(Element));
        No->info = info;
        No->next = NULL;
        No->previous = NULL;
        L1->first = No;
        L1->last = No;
        L1->size++;
        return No;
    }else{
        L1 = (Base *) list;
        No = (Element*) malloc(sizeof(Element));
        No->info = info;
        No->next = NULL;
        No->previous = L1->last;
        L1->last->next = No;
        L1->last = No;
        L1->size++;
        return No;
    }
    return NULL;
}

void removeItemL(List list, Posic p){
    Base *L1 = (Base*) list;
    Element *No = (Element*) p;
    Element *aux, *aux2;
    if(isEmpty(list)==0){
        if(No->previous==NULL){
            aux = No->next;
            L1->first = aux;
            if(L1->first!=NULL) {
                L1->first->previous = NULL;
            }
        }else if(No->next==NULL){
            aux = No->previous;
            L1->last = aux;
            if(L1->last!=NULL) {
                L1->last->next = NULL;
            }
        }else {
            aux = No->previous;
            aux2 = No->next;
            aux->next = aux2;
            aux2->previous = aux;
        }

        if(No!=NULL){
            free(No);
        }
        L1->size--;
    }
}

Item get(List list, Posic p){
    Element *No = (Element*) p;
    if(isEmpty(list)==0){
        if(No->info!=NULL) {
            return No->info;
        }
    }
    return NULL;
}

Posic insertBefore(List list, Posic p, Item info){
    Base *L1 = (Base*) list;
    Element *No = (Element*) p;
    Element *aux, *aux2;
    aux = (Element*) malloc(sizeof(Element));
    if(isEmpty(list)==0){
        if(No->previous==NULL){
            aux->info = info;
            aux->next = No;
            No->previous = aux;
            aux->previous = NULL;
            L1->size++;
            L1->first = aux;
        } else {
            aux->info = info;
            aux2 = No->previous;
            aux2->next = aux;
            aux->previous = aux2;
            aux->next = No;
            No->previous = aux;
            L1->size++;
        }
    } else {
        insertL(list, info);
        L1->size++;
    }
    return aux;
}

Posic insertAfter(List list, Posic p, Item info){
    Base *L1 = (Base*) list;
    Element *No = (Element*) p;
    Element *aux;
    aux = (Element*) malloc(sizeof(Element));
    if(isEmpty(list)==0){
        if(No->next==NULL){
            aux->info = info;
            aux->next = NULL;
            aux->previous = No;
            No->next = aux;
            L1->size++;
            L1->last = aux;
        } else {
            aux->info = info;
            aux->next = No->next;
            aux->previous = No;
            No->next = aux;
            L1->size++;
        }
    } else {
        insertL(list, info);
        L1->size++;
    }
    return aux;
}

Posic getFirst(List list){
    Base *L1 = (Base *) list;
    return L1->first;
}

Posic getNext(List list, Posic p){
    Element *No = (Element *) p;
    return No->next;
}

Posic getLast(List list){
    Base *L1 = (Base *) list;
    return L1->last;
}

Posic getPrevious(List list, Posic p){
    Element *No = (Element *) p;
    return No->previous;
}

int insertBeginL(List list, Item item) {
  Base *base = (Base *)list;
  Element *element = NULL;
  if (base != NULL) {
    element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
      return 0;
    }
    element->info = item;
    if (base->first != NULL) {
      element->previous = NULL;
      element->next = base->first;
      base->first->previous = element;
      base->first = element;
    } else {
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

int insertEndL(List list, Item item) {
  Base *base = (Base *)list;
  Element *element = NULL;
  if (base != NULL) {
    element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
      return 0;
    }
    element->info = item;
    if (base->first != NULL) {
      element->next = NULL;
      element->previous = base->last;
      base->last->next = element;
      base->last = element;
    } else {
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

int insertMiddleL(List list, int p, Item item) {
  Base *base = (Base *)list;
  Element *element = NULL;
  Element *aux = NULL;
  int i, j;
  if (p <= 0) {
    return 0;
  }
  j = lengthL(list);
  if (base != NULL) {
    if (p == 1) {
      insertBeginL(list, item);
    } else if (p >= j) {
      insertEndL(list, item);
    } else {
      element = (Element *)malloc(sizeof(Element));
      if (element == NULL) {
        return 0;
      }
      element->info = item;
      if (base->first != NULL) {
        aux = base->first;
        for (i = 1; i <= j; i++) {
          if (i == (p - 1)) {
            break;
          }
          aux = aux->next;
        }
        element->next = aux->next;
        aux->next->previous = element;
        element->previous = aux;
        aux->next = element;
      } else {
        base->first = element;
        base->last = element;
        element->next = NULL;
        element->previous = NULL;
      }
      base->size = base->size + 1;
    }
    return 1;
  }
  return 0;
}

void showL(List list, showLI func){
  Base *base = (Base *)list;
  Element *aux = NULL;
  int i=0, j=0;
  if (base != NULL) {
    if (base->first != NULL) {
      j = base->size;
      aux = base->first;
      for (i = 1; i <= j; i++) {
        func(aux->info);
        aux = aux->next;
      }
    }
  }
}

Item searchItemL(List list, Item item, compareToL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  Item info = NULL;
  int i=0, j=0;
  if (base != NULL) {
    if (base->first != NULL) {
      j = base->size;
      aux = base->first;
      for (i = 1; i <= j; i++) {
        if (func(aux->info, item) == 1){
          info = aux->info;
          break;
        }
        aux = aux->next;
      }
    }
  }
  return info;
}

Item removeItemL2(List list, Item item, compareToL func){
  Base *base = (Base *)list;
  Element *aux = NULL;
  Item info = NULL;
  int i=0, j=0;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      for (i = 1; i <= j; i++) {
        if (func(aux->info, item) == 1){
          info = aux->info;
          aux->previous->next = aux->next;
          aux->next->previous = aux->previous;
          free(aux);
          base->size = base->size - 1;
          break;
        }
        aux = aux->next;
      }
    }
  }
  return info;
}

int removeBeginL(List list, eraseItemL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first->next;
      aux->previous = NULL;
      if(func != NULL)
        func(base->first->info);
      free(base->first);
      base->first = aux;
      base->size = base->size - 1;
      return 1;
    }else{
      if (base->first != NULL && base->size == 1) {
          if(func != NULL)
            func(base->last->info);
          free(base->last);
          base->last = NULL;
          base->first = NULL;
          base->size = base->size - 1;
          return 1;
      }
    }
  }
  return 0;
}

int removeEndL(List list, eraseItemL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  if (base != NULL) {
    if (base->first != NULL && base->size > 1) {
      aux = base->last->previous;
      aux->next = NULL;
      if(func != NULL)
        func(base->last->info);
      free(base->last);
      base->last = aux;
      base->size = base->size - 1;
      return 1;
    } else {
       if (base->first != NULL && base->size == 1) {
          if(func != NULL)
            func(base->last->info);
          free(base->last);
          base->last = NULL;
          base->first = NULL;
          base->size = base->size - 1;
          return 1;
        }
      }
  }
  return 0;
}

int removeMiddleL(List list, int p, eraseItemL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  int i, j;
  if (p <= 0) {
    return 0;
  }
  j = lengthL(list);
  if (p == 1) {
    removeBeginL(list, func);
    return 1;
  } else if (p >= j) {
    removeEndL(list, func);
    return 1;
  } else {
    if (base != NULL) {
      if (base->first != NULL) {
        base->size = base->size - 1;
        aux = base->first;
        for (i = 1; i <= j; i++) {
          if (i == p) {
            if(func != NULL)
              func(aux->info);
            aux->previous->next = aux->next;
            aux->next->previous = aux->previous;
            free(aux);
            break;
          }
          aux = aux->next;
        }
        return 1;
      }
    }
  }
  return 0;
}

Item getBeginItemL(List list) {
  Base *base = (Base *)list;
  if (base != NULL) {
    if (base->first != NULL) {
      return (Item)base->first->info;
    }
  }
  return NULL;
}

Item getEndItemL(List list) {
  Base *base = (Base *)list;
  if (base != NULL) {
    if (base->first != NULL) {
      return (Item)base->last->info;
    }
  }
  return NULL;
}

Item getItemL(List list, int p) {
  Base *base = (Base *)list;
  int i, j;
  Element *aux = NULL;
  Item item = NULL;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      j = lengthL(list);
      if (p <= 0 || p > j) {
        return NULL;
      }
      for (i = 1; i <= j; i++) {
        if (i == p) {
          item = aux->info;
          return item;
        }
        aux = aux->next;
      }
    }
  }
  return NULL;
}

void concatL(List listOne, List listTwo){
  if(listOne!=NULL && listTwo!=NULL){
    Base *base1 = (Base *)listOne;
    Base *base2 = (Base *)listTwo;
    if(base1->first != NULL && base2->first != NULL){
      base1->last->next = base2->first;
      base2->first->previous = base1->last;
      base1->last = base2->last;
      base1->size = base1->size + base2->size;
    }else {
      if(base1->first == NULL && base2->first != NULL) {
        base1->first = base2->first;
        base1->last = base2->last;
        base1->size = base2->size;
      }
    }
  }
}

int eraseListL(List list, eraseItemL func) {
  Base *base = (Base *)list;
  Element *aux, *aux2;
  int i, j;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      j = lengthL(list);
      for (i = 1; i <= j; i++) {
        aux2 = aux;
        aux = aux->next;
        if(func != NULL)
          func(aux2->info);
        free(aux2);
      }
        base->first = NULL;
        base->last = NULL;
      base->size = 0;
      return 1;
    }
  }
  return 0;
}

void eraseBase(List list){
  Base *base = (Base *)list;
  if(base!=NULL){
    free(base);
  }
}
