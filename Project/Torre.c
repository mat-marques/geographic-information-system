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
}torre0;


Torre criaTorre(double x, double y, char *id){
   torre0 *newElement;
   int i;
   newElement = (torre0*) malloc(sizeof(torre0));
   newElement->x = x;
   newElement->y = y;
   i = strlen(id);
   newElement->id = (char*) malloc((i+1)*sizeof(char));
   strcpy(newElement->id, id);
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
