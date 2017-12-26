#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "Semafaro.h"
#include "StringO.h"

typedef struct semafaro0{
  double x, y;
  char *id;
  char *corP, *corB;
  double tempo;
}semafaro0;


Semafaro criaSemafaro(double x, double y, char *id, char *corP, char* corB){
   semafaro0 *newElement;
   newElement = (semafaro0*) malloc(sizeof(semafaro0));
   newElement->x = x;
   newElement->y = y;
   newElement->tempo = 0;

   newElement->id = criarString(id);

   newElement->corP = criarString(corP);

   newElement->corB = criarString(corB);

   return newElement;
}

double getXS(Semafaro element){
   semafaro0 *newElement = (semafaro0*) element;
   return newElement->x;
}

double getYS(Semafaro element){
  semafaro0 *newElement = (semafaro0*) element;
  return newElement->y;
}

char *getIdS(Semafaro element){
  semafaro0 *newElement = (semafaro0*) element;
  return newElement->id;
}

char *getCorpS(Semafaro element){
  semafaro0 *newElement = (semafaro0*) element;
  return newElement->corP;
}

char *getCorbS(Semafaro element){
  semafaro0 *newElement = (semafaro0*) element;
  return newElement->corB;
}

double getTempo(Semafaro element){
  semafaro0 *newElement = (semafaro0*) element;
  return newElement->tempo;
}

void setTempo(Semafaro element, double tempo){
  semafaro0 *newElement = (semafaro0*) element;
  newElement->tempo = tempo;
}

void removeS(Semafaro element){
  semafaro0 *newElement = (semafaro0*) element;
  if(newElement != NULL){
    free(newElement->id);
    free(newElement->corP);
    free(newElement->corB);
    free(newElement);
  }
}

int compareS(Semafaro element, void *item){
  semafaro0 *newElement = (semafaro0*) element;
  char *id = (char*) item;
  if(strcmp(newElement->id, id) == 0){
    return 1;
  }
  return 0;
}
