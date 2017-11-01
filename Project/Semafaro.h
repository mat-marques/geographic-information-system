#ifndef SEMAFARO_H
#define SEMAFARO_H

typedef void* Semafaro;

/***
Autor: Matheus Augusto Marques.
Tad: Semafaro
Definição:
Um semáfaro é representado por um ponto em um plano. O semáfaro possui como parâmetros de configuração uma coordenada x , y e uma string que representa sua identificação no espaço. O semafáro também possui um valor númerico real que representa o tempo de ocilação entre as cores do semafáro. Além disso, o semafáro possui uma cor de preenchimento e uma cor de borda.
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

/**
Retorna a cor de preenchimento de Semafaro element.
Retorna uma string.
*/
char *getCorpS(Semafaro element);

/**
Retorna a cor de borda de Semafaro element.
Retorna uma string.
*/
char *getCorbS(Semafaro element);

/**
Retorna o tempo de Semafaro element.
Retorna uma número real.
*/
double getTempo(Semafaro element);

/*
Modifica o tempo do Semafaro element pelo valor em tempo.
*/
void setTempo(Semafaro element, double tempo);

/*
Remove um Semafáro da memória.
*/
void removeS(Semafaro element);

/*
A função verifica se um semafáro é igual ao tipo de dado item.
item é um tipo de dado genérico.
*/
int compareS(Semafaro element, void *item);

#endif
