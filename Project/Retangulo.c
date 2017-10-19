#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Retangulo.h"

typedef struct Rectangle{
  int i;
  double w, h, x, y;
  char cor[30];
}Rectangle;

Retangulo createRectangle(int i, double w, double h, double x, double y, char cor[30]){
    Rectangle *newR;
    newR = (Rectangle*) malloc(sizeof(Rectangle));
    newR->i = i;
    newR->w = w;
    newR->h = h;
    newR->x = x;
    newR->y = y;

    strcpy(newR->cor,cor);
    return newR;
  }


int getRi(Retangulo element){
  Rectangle *element2 = (Rectangle *) element;
  return element2->i;
}

double getRw(Retangulo element){
  Rectangle *element2 = (Rectangle *) element;
  return element2->w;
}

double getRh(Retangulo element){
  Rectangle *element2 = (Rectangle *) element;
  return element2->h;
}

double getRx(Retangulo element){
  Rectangle *element2 = (Rectangle *) element;
  return element2->x;
}

double getRy(Retangulo element){
  Rectangle *element2 = (Rectangle *) element;
  return element2->y;
}

char *getRcor(Retangulo element){
  Rectangle *element2 = (Rectangle *) element;
  return element2->cor;
}

void removeR(Retangulo element){
  Rectangle *element2 = (Rectangle *) element;
  if(element2 != NULL){
    free(element2);
  }
}

int compareR(Retangulo element, void* item){
  Rectangle *element2 = (Rectangle *) element;
  int *item2 = (int *) item;
  if(element2->i == *item2){
    return 1;
  }
  return 0;
}
