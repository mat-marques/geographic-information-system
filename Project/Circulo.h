#ifndef CIRCULO_H
#define CIRCULO_H

typedef void* Circulo;
#include "Cor.h"
/**
   Autor: Matheus Augusto Marques.
   TAD: CÍRCULO.
   Definição:
   Modela a forma geométrica de um círculo. Um círculo é defino
   por um centro com duas coordenadas x e y , um raio r e uma cor nos padrões do svg.
 */

/**
   RETORNA UM CÍRCULO COM CENTRO X E Y, RAIO R , NÚMERO DE IDENTIFICAÇÃO I E UMA COR.
 */
Circulo createCircle(int i, double r, double x, double y, char cor[30]);

/**
   RETORNA O NÚMERO DE IDENTIFICAÇÃO DE UM CÍRCULO.
 */
int getCi(Circulo element);

/**
   RETORNA O RAIO DE UM CÍRCULO.
 */
double getCr(Circulo element);

/**
   RETORNA A COORDENADA X DO CENTRO DE UM CÍRCULO.
 */
double getCx(Circulo element);

/**
   RETORNA A COORDENADA Y DO CENTRO DE UM CÍRCULO.
 */
double getCy(Circulo element);

/**
   RETORNA A COR DE PREENCHIMENTO DE UM CÍRCULO.
 */
char* getCcor(Circulo element);

/*
   Remove Circulo element da memória.
 */
void removeC(Circulo element);

/*
   A função verifica se um circulo é igual ao tipo de dado item.
   item é um tipo de dado genérico.
 */
int compareC(Circulo element, void* item);

#endif
