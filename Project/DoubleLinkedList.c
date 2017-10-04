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
    printf("Error in alocation in memory.\n");
  }
  return (List)base;
}

int lengthDLL(List list) {
  Base *base = (Base *)list;
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

Item searchItemDLL(List list, Item item, compareToDLL func) {
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
          break;
        }
        aux = aux->next;
      }
    }
  }
  return info;
}


int removeBeginDLLOne(List list, eraseItemDLL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first->next;
      aux->previous = NULL;
      func(base->first->info);
      free(base->first);
      base->first = aux;
      base->size = base->size - 1;
      return 1;
    }
  }
  return 0;
}

int removeEndDLLOne(List list, eraseItemDLL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->last->previous;
      aux->next = NULL;
      func(base->last->info);
      free(base->last);
      base->last = aux;
      base->size = base->size - 1;
      return 1;
    }
  }
  return 0;
}

int removeMiddleDLLOne(List list, int p, eraseItemDLL func) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  int i, j;
  if (p <= 0) {
    return 0;
  }
  j = lengthDLL(list);
  if (p == 1) {
    removeBeginDLLOne(list, func);
    return 1;
  } else if (p >= j) {
    removeEndDLLOne(list, func);
    return 1;
  } else {
    if (base != NULL) {
      if (base->first != NULL) {
        aux = base->first;
        for (i = 1; i <= j; i++) {
          if (i == p) {
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

Item removeBeginDLLTwo(List list) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  Item item = NULL;
  if (base != NULL) {
    if (base->first != NULL) {
      item = base->first->info;
      aux = base->first->next;
      aux->previous = NULL;
      free(base->first);
      base->first = aux;
      base->size = base->size - 1;
    }
  }
  return item;
}

Item removeEndDLLTwo(List list) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  Item item = NULL;
  if (base != NULL) {
    if (base->first != NULL) {
      item = base->last->info;
      aux = base->last->previous;
      aux->next = NULL;
      free(base->last);
      base->last = aux;
      base->size = base->size - 1;
    }
  }
  return item;
}

Item removeMiddleDLLTwo(List list, int p) {
  Base *base = (Base *)list;
  Element *aux = NULL;
  Item item = NULL;
  int i, j;
  if (p <= 0) {
    return 0;
  }
  j = lengthDLL(list);
  if (p == 1) {
    item = removeBeginDLLTwo(list);
  } else if (p >= j) {
    item = removeEndDLLTwo(list);
  } else {
    if (base != NULL) {
      if (base->first != NULL) {
        aux = base->first;
        for (i = 1; i <= j; i++) {
          if (i == p) {
            aux->previous->next = aux->next;
            aux->next->previous = aux->previous;
            item = aux->info;
            free(aux);
            break;
          }
          aux = aux->next;
        }
      }
    }
  }
  return item;
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
      for (i = 0; i < j; i++) {
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

int eraseListDLLOne(List list, eraseItemDLL func) {
  Base *base = (Base *)list;
  Element *aux, *aux2;
  int i, j;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      j = lengthDLL(list);
      for (i = 0; i < j; i++) {
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

int eraseListDLLTwo(List list) {
  Base *base = (Base *)list;
  Element *aux, *aux2;
  int i, j;
  if (base != NULL) {
    if (base->first != NULL) {
      aux = base->first;
      j = lengthDLL(list);
      for (i = 0; i < j; i++) {
        aux2 = aux;
        aux = aux->next;
        free(aux2);
      }
      free(base);
      return 1;
    }
  }
  return 0;
}
