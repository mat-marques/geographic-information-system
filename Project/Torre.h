#ifndef TORRE_H
#define TORRE_H

typedef void* Torre;

/***
Autor: Matheus Augusto Marques.
TAD: Torre
Definição:
Uma torre de celular, basicamente, é composta por um par ordenado x, y(ambos pertecem aos números reais) e um valor inteiro para identificar a torre no plano.
*/

/**
Cria um torre de celular e retorna essa torre.
A torre é configurada com os parâmetro x, y e id.
Onde x e y representam a posição da torre no plano e id se refere ao número de
identificação da torre no plano.
*/
Torre criaTorre(double x, double y, char *id);


/**
Retorna a coordena x do par ordenado referente a posição onde a Torre element está no plano.
*/
double getXT(Torre element);


/**
Retorna a coordena y do par ordenado referente a posição onde a Torre element está no plano.
*/
double getYT(Torre element);


/**
Retorna o número de identificação da Torre element.
*/
char *getIdT(Torre element);


double getRaio(Torre element);


void setRaio(Torre element, double raio);

void removeTorr(Torre element);

#endif
