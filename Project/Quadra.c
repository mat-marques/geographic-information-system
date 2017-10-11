#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Quadra.h"

typedef struct Quadra0{
   double x, y, larg, alt;
   char *cep;
}Quadra0;

typedef void (*eraseElement)(void*);

Quadra criaQuadra(double x, double y, double larg, double alt, char* cep){
   int i;
   Quadra0 *newElement = (Quadra0*) malloc(sizeof(Quadra0));
   newElement->x = x;
   newElement->y = y;
   newElement->larg = larg;
   newElement->alt = alt;
   newElement->cep = cep;
   i = strlen(cep);
   newElement->cep = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->cep, cep);
   return (Quadra) newElement;
}

char* getCepQ(Quadra element){
   Quadra0 *newElement = (Quadra0*) element;
   return newElement->cep;
}

void excluirCep(Quadra element){
   Quadra0 *newElement = (Quadra0*) element;
   if(newElement->cep!=NULL){
      free(newElement->cep);
      newElement->cep = NULL;
   }
}

double getXQ(Quadra element){
   Quadra0 *newElement = (Quadra0*) element;
   return newElement->x;
}

double getYQ(Quadra element){
   Quadra0 *newElement = (Quadra0*) element;
   return newElement->y;
}

double getLargQ(Quadra element){
   Quadra0 *newElement = (Quadra0*) element;
   return newElement->larg;
}

double getAltQ(Quadra element){
   Quadra0 *newElement = (Quadra0*) element;
   return newElement->alt;
}

void removeQ(Quadra element){
    Quadra0 *newElement = (Quadra0*) element;
    if(newElement != NULL){
        free(newElement->cep);
        free(newElement);
    }
}

int compareQ(Quadra element, void *item){
  Quadra0 *newElement = (Quadra0*) element;
  char *item2 = (char *) item;
  if(strcmp(newElement->cep, item2) == 0){
    return 1;
  }
  return 0;
}
