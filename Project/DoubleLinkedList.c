#include "DoubleLinkedList.h"
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

List createDLL() {
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

int lengthDLL(List list) {
  Base *base = (Base *)list;
  if(base == NULL)
    return 0;
  return base->size;
}

int insertBeginDLL(List list, Item item) {
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

int insertEndDLL(List list, Item item) {
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

int insertMiddleDLL(List list, int p, Item item) {
  Base *base = (Base *)list;
  Element *element = NULL;
  Element *aux = NULL;
  int i, j;
  if (p <= 0) {
    return 0;
  }
  j = lengthDLL(list);
  if (base != NULL) {
    if (p == 1) {
      insertBeginDLL(list, item);
    } else if (p >= j) {
      insertEndDLL(list, item);
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

void showDLL(List list, showDLLI func){
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

Item searchItemDLL(List list, Item item, compareToDLL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  Item info = NULL;
  int i=0, j=0;
  if (base != NULL) {
    if (base->first != NULL) {
      j = base->size;
      aux = base->first;
      for (i = 1; i <= j; i++) {
        if (func(item ,aux->info) == 1){
          info = aux->info;
          break;
        }
        aux = aux->next;
      }
    }
  }
  return info;
}

Item removeItemDLL(List list, Item item, compareToDLL func){
  Base *base = (Base *)list;
  Element *aux = NULL;
  Item info = NULL;
  int i=0, j=0;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      for (i = 1; i <= j; i++) {
        if (func(item ,aux->info) == 1){
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

int removeBeginDLL(List list, eraseItemDLL func) {
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

int removeEndDLL(List list, eraseItemDLL func) {
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

int removeMiddleDLL(List list, int p, eraseItemDLL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  int i, j;
  if (p <= 0) {
    return 0;
  }
  j = lengthDLL(list);
  if (p == 1) {
    removeBeginDLL(list, func);
    return 1;
  } else if (p >= j) {
    removeEndDLL(list, func);
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


Item getBeginItemDLL(List list) {
  Base *base = (Base *)list;
  if (base != NULL) {
    if (base->first != NULL) {
      return (Item)base->first->info;
    }
  }
  return NULL;
}

Item getEndItemDLL(List list) {
  Base *base = (Base *)list;
  if (base != NULL) {
    if (base->first != NULL) {
      return (Item)base->last->info;
    }
  }
  return NULL;
}

Item getItemDLL(List list, int p) {
  Base *base = (Base *)list;
  int i, j;
  Element *aux = NULL;
  Item item = NULL;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      j = lengthDLL(list);
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

void concatDLL(List listOne, List listTwo){
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


int eraseListDLL(List list, eraseItemDLL func) {
  Base *base = (Base *)list;
  Element *aux, *aux2;
  int i, j;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      j = lengthDLL(list);
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
