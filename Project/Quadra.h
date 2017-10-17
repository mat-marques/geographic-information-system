#ifndef QUADRA_H
#define QUADRA_H

typedef void* Quadra;

/***
Autor: Matheus Augusto Marques.
Tad: Quadra
Definição:
Uma quadra é composta por um cep, um par ordenado x e y, uma largura e uma altura. O cep diferencia uma quadra de outras quadras no plano. O cep é único para cada quadra. O par ordenado representa a posição no plano cartesiano onde a quadra esta. A largura e altura representa a largura e a altura da quadra.
*/

Quadra criaQuadra(double x, double y, double larg, double alt, char *cep, char *corP, char *corB);


/**
Retorna o cep de Quadra element.
*/
char *getCepQ(Quadra element);

/**
Exclui o cep de Quadra element.
*/
void excluirCep(Quadra element);

/**
Retorna a coordenada x do par ordenado de Quadra element.
*/
double getXQ(Quadra element);

/**
Retorna a coordenada y do par ordenado de Quadra element.
*/
double getYQ(Quadra element);

double getCorpQ(Quadra element);

double getCorbQ(Quadra element);

/**
Retorna a largura de Quadra element.
*/
double getLargQ(Quadra element);

/**
Retorna a altura de Quadra element.
*/
double getAltQ(Quadra element);

void removeQ(Quadra element);

int compareQ(Quadra element, void *item);

#endif
