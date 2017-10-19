#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Circulo.h"
#include "Cor.h"
/**
  Define as propriedades de um círculo.
*/
typedef struct Circle{
  int i;
  double r, x, y;
  char cor[30];
}Circle;
/**
  Cria um círculo.
*/
Circulo createCircle(int i, double r, double x, double y, char cor[30]){

<<<<<<< Updated upstream
    Circle *new = (Circle*) malloc(sizeof(Circle));
    new->i = i;
    new->r = r;
    new->x = x;
    new->y = y;

    strcpy(new->cor,cor);
    return new;
=======
    Circle *newC = (Circle*) malloc(sizeof(Circle));
    newC->i = i;
    newC->r = r;
    newC->x = x;
    newC->y = y;
    newC->cor[0] = '\0';
    strcpy(newC->cor, cor);
    return newC;
>>>>>>> Stashed changes
}
/**
 Retorna o número de identificação do círculo.
*/
int getCi(Circulo element){
  Circle *element2 = (Circle *) element;
  return element2->i;
}

/**
 Retorna o raio do círculo.
*/
double getCr(Circulo element){
  Circle *element2 = (Circle *) element;
  return element2->r;
}

/**
 Retorna a coordenada x do centro do círculo.
*/
double getCx(Circulo element){
  Circle *element2 = (Circle *) element;
  return element2->x;
}

/**
  Retorna a coordenada y do centro do círculo.
*/
double getCy(Circulo element){
  Circle *element2 = (Circle *) element;
  return element2->y;
}

/**
  Retorna a cor do círculo.
*/
char* getCcor(Circulo element){
  Circle *element2 = (Circle *) element;
  return element2->cor;
}

void removeCirculo(Circulo element){
  Circle *element2 = (Circle *) element;
  if(element2 != NULL){
    free(element2);
  }
}

int compareC(Circulo element, void* item){
  Circle *element2 = (Circle *) element;
  int *item2 = (int *) item;
  if(element2->i == *item2){
    return 1;
  }
  return 0;
}
