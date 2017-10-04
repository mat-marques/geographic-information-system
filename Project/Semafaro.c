#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "Semafaro.h"

typedef struct semafaro0{
  double x, y;
  char *id;
  double tempo;
}semafaro0;


Semafaro criaSemafaro(double x, double y, char *id){
   semafaro0 *newElement;
   int i;
   newElement = (semafaro0*) malloc(sizeof(semafaro0));
   newElement->x = x;
   newElement->y = y;
   newElement->tempo = 0;
   i = strlen(id);
   newElement->id = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->id, id);
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
    free(newElement);
  }
}