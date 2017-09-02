#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"


typedef struct no{
    Item item;
    struct no *next,*previous;
}no;

typedef struct Base{
    no *first;
    no *last;
    int len;
}Base;


Lista createLista(){
    Base *base=NULL;
    base = (Base *) malloc(sizeof(Base));
    base->first = NULL;
    base->last = NULL;
    base->len = 0;
    return (Lista) base;
}

int lenght(Lista L){
    Base *L1 = (Base *) L;
    return L1->len;
}

int isEmpty(Lista L){
    Base *L1 = (Base *) L;
    if(L1->first==NULL){
        return 1;
    }
    return 0;
}

Posic insert(Lista L, Item info){
    no *No=NULL;
    Base *L1;
    if(isEmpty(L)==1){
        L1 = (Base *) L;
        No = (no*) malloc(sizeof(no));
        No->item = info;
        No->next = NULL;
        No->previous = NULL;
        L1->first = No;
        L1->last = No;
        L1->len++;
        return No;
    }else{
        L1 = (Base *) L;
        No = (no*) malloc(sizeof(no));
        No->item = info;
        No->next = NULL;
        No->previous = L1->last;
        L1->last->next = No;
        L1->last = No;
        L1->len++;
        return No;
    }
    return NULL;
}

void removeItem(Lista L, Posic p){
    Base *L1 = (Base*) L;
    no *No = (no*) p;
    no *aux, *aux2;
    if(isEmpty(L)==0){
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
        L1->len--;
    }
}

Item get(Lista L, Posic p){
    no *No = (no*) p;
    if(isEmpty(L)==0){
        if(No->item!=NULL) {
            return No->item;
        }
    }
    return NULL;
}

Posic insertBefore(Lista L, Posic p, Item info){
    Base *L1 = (Base*) L;
    no *No = (no*) p;
    no *aux, *aux2;
    aux = (no*) malloc(sizeof(no));
    if(isEmpty(L)==0){
        if(No->previous==NULL){
            aux->item = info;
            aux->next = No;
            No->previous = aux;
            aux->previous = NULL;
            L1->len++;
            L1->first = aux;
        } else {
            aux->item = info;
            aux2 = No->previous;
            aux2->next = aux;
            aux->previous = aux2;
            aux->next = No;
            No->previous = aux;
            L1->len++;
        }
    } else {
        insert(L, info);
        L1->len++;
    }
    return aux;
}

Posic insertAfter(Lista L, Posic p, Item info){
    Base *L1 = (Base*) L;
    no *No = (no*) p;
    no *aux;
    aux = (no*) malloc(sizeof(no));
    if(isEmpty(L)==0){
        if(No->next==NULL){
            aux->item = info;
            aux->next = NULL;
            aux->previous = No;
            No->next = aux;
            L1->len++;
            L1->last = aux;
        } else {
            aux->item = info;
            aux->next = No->next;
            aux->previous = No;
            No->next = aux;
            L1->len++;
        }
    } else {
        insert(L, info);
        L1->len++;
    }
    return aux;
}

Posic getFirst(Lista L){
    Base *L1 = (Base *) L;
    return L1->first;
}

Posic getNext(Lista L, Posic p){
    no *No = (no *) p;
    return No->next;
}

Posic getLast(Lista L){
    Base *L1 = (Base *) L;
    return L1->last;
}

Posic getPrevious(Lista L, Posic p){
    no *No = (no *) p;
    return No->previous;
}
