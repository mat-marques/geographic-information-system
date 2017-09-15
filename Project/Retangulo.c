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
    Rectangle *new;
    new = (Rectangle*) malloc(sizeof(Rectangle));
    new->i = i;
    new->w = w;
    new->h = h;
    new->x = x;
    new->y = y;

    strcpy(new->cor,cor);
    return new;
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
