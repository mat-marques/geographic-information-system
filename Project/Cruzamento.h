#ifndef CRUZAMENTO_H
#define CRUZAMENTO_H

typedef void* CrossRoad;

/*
  Autor: Matheus Augusto Marques
  Tad: cruzamento
  Definição: Um cruzamento é definido por um id e um coordenada x, y. Sua definição abstrata, seria um ponto de se encontra no meio do cruzamento de duas ruas.
*/


/*
  A função cria e retorna um cruzamento definido por id, x e y.
*/
CrossRoad createCrossRoad(char* id, double x, double y);


/*
  A função retorna o id do cruzamento.
*/
char *getIdCrossRoad(CrossRoad crossRoad);


/*
  O procedimento define um novo id para o cruzamento.
*/
void setIdCrossRoad(CrossRoad crossRoad, char* id);


/*
  A função retorna a coordenada x do cruzamento.
*/
double getXCrossRoad(CrossRoad crossRoad);


/*
  O procedimento define uma nova coordenada x para o cruzamento.
*/
void setXCrossRoad(CrossRoad crossRoad, double x);


/*
  A função retorna a coordenada y do cruzamento.
*/
double getYCrossRoad(CrossRoad crossRoad);


/*
  O procedimento define uma nova coordenada y para o cruzamento.
*/
void setYCrossRoad(CrossRoad crossRoad, double y);


/*
  Compara um cruzamento pelo id.
  Se o cruzamento possuir mesmo id será retornado 1. 0 caso contrário.
*/
int compareCrossRoad(CrossRoad crossRoad, void *id);


/*
  Apaga os dados do cruzamento
*/
void removeCrossRoad(CrossRoad crossRoad);


#endif
