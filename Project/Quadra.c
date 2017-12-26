#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Quadra.h"
#include "StringO.h"

typedef struct Quadra0{
   double x, y, larg, alt;
   char *cep;
   char *corP, *corB;
}Quadra0;

typedef void (*eraseElement)(void*);

Quadra criaQuadra(double x, double y, double larg, double alt, char* cep, char *corP, char* corB){
   Quadra0 *newElement = (Quadra0*) malloc(sizeof(Quadra0));
   newElement->x = x;
   newElement->y = y;
   newElement->larg = larg;
   newElement->alt = alt;

   newElement->cep = criarString(cep);

   newElement->corP = criarString(corP);

   newElement->corB = criarString(corB);
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

char *getCorpQ(Quadra element){
   Quadra0 *newElement = (Quadra0*) element;
   return newElement->corP;
}

char *getCorbQ(Quadra element){
   Quadra0 *newElement = (Quadra0*) element;
   return newElement->corB;
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
        free(newElement->corP);
        free(newElement->corB);
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
