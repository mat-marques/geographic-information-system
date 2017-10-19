#ifndef SEMAFARO_H
#define SEMAFARO_H

typedef void* Semafaro;

/***
Autor: Matheus Augusto Marques.
Tad: Semafaro
Definição:
Um semáfaro é representado por um ponto em um plano. O semáfaro possui como parâmetros de configuração uma coordenada x , y e uma string que representa sua identificação no espaço.
*/

/**
Cria e retorna o semáfaro.
Os parâmetros x e y representam um par ordenado que posiciona o semafaro em
um plano. O parâmetro id se refere a uma string de identificação do semáfaro.
*/
Semafaro criaSemafaro(double x, double y, char *id, char *corP, char* corB);


/**
Retorna a posição x do par ordenado referente a posição  do Semáfaro element no plano.
*/
double getXS(Semafaro element);

/**
Retorna a posição y do par ordenado referente a posição  do Semáfaro element no plano.
*/
double getYS(Semafaro element);

/**
Retorna o número de identificação do Semafaro element.
*/
char *getIdS(Semafaro element);


char *getCorpS(Semafaro element);


char *getCorbS(Semafaro element);


double getTempo(Semafaro element);


void setTempo(Semafaro element, double tempo);


void removeS(Semafaro element);


int compareS(Semafaro element, void *item);


void removeS(Semafaro element);


int compareS(Semafaro element, void *item);

#endif
