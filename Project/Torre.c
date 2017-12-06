#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "Torre.h"

/**
  Estrutura que representa uma torre
*/
typedef struct torre0{
  double x, y;
  char *id;
  double raio;
  char *corP, *corB;
  char *operadora;
}torre0;


Torre criaTorre(double x, double y, char *id, char *corP, char *corB){
   torre0 *newElement;
   int i;
   newElement = (torre0*) malloc(sizeof(torre0));
   newElement->x = x;
   newElement->y = y;
   newElement->raio = 0;
   newElement->operadora = NULL;
   i = strlen(id);
   newElement->id = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->id, id);

   i = strlen(corP);
   newElement->corP = (char*) malloc((i+1) * sizeof(char));
   strcpy(newElement->corP, corP);

   i = strlen(corB);
   newElement->corB = (char*) malloc((i+1) * sizeof(char));
   strcpy(newElement->corB, corB);

   return (Torre) newElement;
}

double getXT(Torre element){
   torre0 *newElement = (torre0*) element;
   return newElement->x;
}

double getYT(Torre element){
  torre0 *newElement = (torre0*) element;
  return newElement->y;
}

char *getIdT(Torre element){
  torre0 *newElement = (torre0*) element;
  return newElement->id;
}

char *getCorpT(Torre element){
  torre0 *newElement = (torre0*) element;
  return newElement->corP;
}

char *getCorbT(Torre element){
  torre0 *newElement = (torre0*) element;
  return newElement->corB;
}

double getRaio(Torre element){
  torre0 *newElement = (torre0*) element;
  return newElement->raio;
}

void setRaio(Torre element, double raio){
  torre0 *newElement = (torre0*) element;
  newElement->raio = raio;
}


char *getOperadora(Torre element){
  torre0 *newElement = (torre0*) element;
  return newElement->operadora;
}


void setOperadora(Torre element, char *operadora){
  torre0 *newElement = (torre0*) element;
  if(newElement->operadora != NULL){
    free(newElement->operadora);
    newElement->operadora = NULL;
  }
  newElement->operadora = operadora;
}

void removeT(Torre element){
  torre0 *newElement = (torre0*) element;
  if(newElement != NULL){
    free(newElement->id);
    free(newElement->corP);
    free(newElement->corB);
    free(newElement);
  }
}

int compareT(Torre element, void *item){
  torre0 *newElement = (torre0*) element;
  char *id = (char*) item;
  if(strcmp(newElement->id, id) == 0){
    return 1;
  }
  return 0;
}
