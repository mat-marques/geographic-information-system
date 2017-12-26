#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "Hidrante.h"
#include "StringO.h"

typedef struct hidrante0{
  double x, y;
  char *id;
  double vazao;
  char *corP, *corB;
}hidrante0;

Hidrante criaHidrante(double x, double y, char *id, char *corP, char *corB){
   hidrante0 *newElement;
   newElement = (hidrante0*) malloc(sizeof(hidrante0));
   newElement->x = x;
   newElement->y = y;
   newElement->vazao = 0;

   newElement->id = criarString(id);

   newElement->corP = criarString(corP);

   newElement->corB = criarString(corB);

   return (Hidrante) newElement;
}

double getXH(Hidrante element){
   hidrante0 *newElement = (hidrante0*) element;
   return newElement->x;
}

double getYH(Hidrante element){
  hidrante0 *newElement = (hidrante0*) element;
  return newElement->y;
}

char *getIdH(Hidrante element){
  hidrante0 *newElement = (hidrante0*) element;
  return newElement->id;
}

char *getCorpH(Hidrante element){
  hidrante0 *newElement = (hidrante0*) element;
  return newElement->corP;
}

char *getCorbH(Hidrante element){
  hidrante0 *newElement = (hidrante0*) element;
  return newElement->corB;
}

double getVazao(Hidrante element){
  hidrante0 *newElement = (hidrante0*) element;
  return newElement->vazao;
}

void setVazao(Hidrante element, double vazao){
  hidrante0 *newElement = (hidrante0*) element;
  newElement->vazao = vazao;
}


void removeH(Hidrante element){
  hidrante0 *newElement = (hidrante0*) element;
  if(newElement != NULL){
    free(newElement->id);
    free(newElement->corP);
    free(newElement->corB);
    free(newElement);
  }
}

int compareH(Hidrante element, void *item){
  hidrante0 *newElement = (hidrante0*) element;
  char *item2 = (char *) item;
  if(strcmp(newElement->id, item2) == 0){
    return 1;
  }
  return 0;
}
