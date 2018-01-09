#ifndef PONTO_H
#define PONTO_H

typedef void* Point;
/*
  Autor: Matheus Augusto Marques
  Tad Ponto.
  Definição:
  Um ponto é definido por dois números reais x e y. Esses números representam a coordenada geografica do ponto em um plano cartesiano.
*/

Point createPoint(int id, double x, double y);


int getIdPoint(Point point);


void setIdPoint(Point point, int id);


double getXPoint(Point point);


void setXPoint(Point point, double x);


double getYPoint(Point point);


void setYPoint(Point point, double y);


int comparePoints(Point point, void *id);


void removePoint(Point point);

#endif
