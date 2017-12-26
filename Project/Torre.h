#ifndef TORRE_H
#define TORRE_H

typedef void* Torre;

/***
   Autor: Matheus Augusto Marques.
   TAD: Torre
   Definição:
   Uma torre de celular, basicamente, é composta por um par ordenado x, y(ambos pertecem aos números reais), um valor inteiro para identificar a torre no plano e uma cor nos padrões do svg.
 */

/**
   Cria um torre de celular e retorna essa torre.
   A torre é configurada com os parâmetro x, y e id.
   Onde x e y representam a posição da torre no plano e id se refere ao número de
   identificação da torre no plano.
 */
Torre criaTorre(double x, double y, char *id, char *corP, char *corB);


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
   Retorna uma string.
 */
char *getIdT(Torre element);


/**
   Retorna a cor de preenchimento da Torre element.
   Retorna uma string.
 */
char *getCorpT(Torre element);


/**
   Retorna a cor de borda da Torre element.
   Retorna uma string.
 */
char *getCorbT(Torre element);


/**
   Retorna o raio de alcance da Torre element.
   Retorna uma string.
 */
double getRaio(Torre element);


/**
   Modifica o raio de alcance da Torre element pelo valor em raio.
 */
void setRaio(Torre element, double raio);

/*A funcao retorna a operadora que a torre pertence */
char *getOperadora(Torre element);

/*O procedimento define a operadora da torre */
void setOperadora(Torre element, char *operadora);


/**
   Remove uma torre da memória.
 */
void removeT(Torre element);

/*
   A função verifica se uma torre é igual ao tipo de dado item.
   item é um tipo de dado genérico.
 */
int compareT(Torre element, void *item);

#endif
