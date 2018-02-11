#ifndef PONTO_H
#define PONTO_H

typedef void* Point;
/*
  Autor: Matheus Augusto Marques
  Tad Ponto.
  Definição:
  Um ponto é definido por dois números reais x e y.
  Esses números representam a coordenada geografica do ponto em um plano cartesiano.
*/

/*
  Cria e retorna um ponto com um id e coordenadas x e y.
*/
Point createPoint(int id, double x, double y);


/*
  Retorna o id de point.
*/
int getIdPoint(Point point);


/*
  Define um novo id para point.
*/
void setIdPoint(Point point, int id);


/*
  Retorna a coordenada x de point.
*/
double getXPoint(Point point);


/*
  Define uma nova coordenada x para point.
*/
void setXPoint(Point point, double x);


/*
  Retorna a coordenada y de point.
*/
double getYPoint(Point point);


/*
  Define uma nova coordenada y para point.
*/
void setYPoint(Point point, double y);


/*
 Compara um ponto (point) por ids.
 Se os ids forem iguais retorna 1. Caso contrário retorna 0.
*/
int comparePoints(Point point, void *id);


/*
  Remove os dados de point.
*/
void removePoint(Point point);

#endif
