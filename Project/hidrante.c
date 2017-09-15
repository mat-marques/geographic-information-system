#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "hidrante.h"

typedef struct hidrante0{
  double x, y;
  char *id;
}hidrante0;

Hidrante criaHidrante(double x, double y, char *id){
   hidrante0 *newElement;
   int i;
   newElement = (hidrante0*) malloc(sizeof(hidrante0));
   newElement->x = x;
   newElement->y = y;
   i = strlen(id);
   newElement->id = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->id, id);
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
