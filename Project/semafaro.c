#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "semafaro.h"

typedef struct semafaro0{
  double x, y;
  char *id;
}semafaro0;


Semafaro criaSemafaro(double x, double y, char *id){
   semafaro0 *newElement;
   int i;
   newElement = (semafaro0*) malloc(sizeof(semafaro0));
   newElement->x = x;
   newElement->y = y;
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
