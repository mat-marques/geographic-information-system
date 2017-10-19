#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "Hidrante.h"

typedef struct hidrante0{
  double x, y;
  char *id;
  double vazao;
  char *corP, *corB;
}hidrante0;

Hidrante criaHidrante(double x, double y, char *id, char *corP, char *corB){
   hidrante0 *newElement;
   int i;
   newElement = (hidrante0*) malloc(sizeof(hidrante0));
   newElement->x = x;
   newElement->y = y;
   newElement->vazao = 0;
   i = strlen(id);
   newElement->id = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->id, id);

   i = strlen(corP);
   newElement->corP = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->corP, corP);

   i = strlen(corB);
   newElement->corB = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->corB, corB);
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


void removeHidrante(Hidrante element){
  hidrante0 *newElement = (hidrante0*) element;
  if(newElement != NULL){
    free(newElement->id);
    free(newElement);
  }
}