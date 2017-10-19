#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "Semafaro.h"

typedef struct semafaro0{
  double x, y;
  char *id;
  char *corP, *corB;
  double tempo;
}semafaro0;


Semafaro criaSemafaro(double x, double y, char *id, char *corP, char* corB){
   semafaro0 *newElement;
   int i;
   newElement = (semafaro0*) malloc(sizeof(semafaro0));
   newElement->x = x;
   newElement->y = y;
   newElement->tempo = 0;
   i = strlen(id);
   newElement->id = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->id, id);

   i = strlen(corP);
   newElement->corP = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->corP, corP);

   i = strlen(corB);
   newElement->corB = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->corB, corB);
   return (Semafaro) newElement;
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
  return newElemen->tempo;
}

void setTempo(Semafaro element, double tempo){
  semafaro0 *newElement = (semafaro0*) element;
  newElement->tempo = tempo;
}

void removeSemafaro(Semafaro element){
  semafaro0 *newElement = (semafaro0*) element;
  if(newElemen != NULL){
    free(newElement->id);
    free(newElement->corP);
    free(newElement->corB);
    free(newElement);
  }
}