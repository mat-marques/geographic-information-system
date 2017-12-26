#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Poligono.h"
#include "StringO.h"

typedef struct myPolygon{
  double *points;
  int nPoints, id, qtdPoints;
  char *colour;
} newPolygon;


Polygon createPolygon(int id, int nPoints){
  newPolygon *myPolygon = NULL;
  int i;
  myPolygon = (newPolygon *)malloc(sizeof(newPolygon));
  if (myPolygon  != NULL) {
    myPolygon->id = id;

    myPolygon->points = (double*) malloc((2 * nPoints) * sizeof(double));
    for(i = 0; i < nPoints; i++){
      *(myPolygon->points + i) = 0;
    }

    myPolygon->nPoints = nPoints;
    myPolygon->qtdPoints = 0;
    myPolygon->colour = NULL;
  }
  return myPolygon;
}


int getIdPolygon(Polygon polygon){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->id;
  }
  return 0;
}


void setIdPolygon(Polygon polygon, int id){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    myPolygon->id = id;
  }
}


int insertPointsPolygon(Polygon polygon, double x, double y){
  newPolygon *myPolygon = (newPolygon *)polygon;
  int i = 0;
  if(polygon != NULL){
    if(myPolygon->qtdPoints < myPolygon->nPoints){
      i = 2 * myPolygon->qtdPoints;
      *(myPolygon->points + i) = x;
      *(myPolygon->points + (i + 1)) = y;
      myPolygon->qtdPoints = myPolygon->qtdPoints + 1;
      return 1;
    }
  }
  return 0;
}


double *getPoints(Polygon polygon){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->points;
  }
  return 0;
}


void setPoints(Polygon polygon, double *points, int nPoints){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    myPolygon->nPoints = nPoints;
    myPolygon->points = points;
  }
}


int getnPoints(Polygon polygon){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->nPoints;
  }
  return 0;
}


int getqtdPointsPolygon(Polygon polygon){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->qtdPoints;
  }
  return 0;
}


double getXPolygon(Polygon polygon, int position){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    if((position >= 0) && (position <= myPolygon->nPoints))
    return *(myPolygon->points + position);
  }
  return 0;
}


void setXPolygon(Polygon polygon, int position, double x){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    if((position >= 0) && (position <= myPolygon->nPoints))
    *(myPolygon->points + position) = x;
  }
}


double getYPolygon(Polygon polygon, int position){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    if((position >= 0) && (position <= myPolygon->nPoints))
    return *(myPolygon->points + position);
  }
  return 0;
}


void setYPolygon(Polygon polygon, int position, double y){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    if((position >= 0) && (position <= myPolygon->nPoints))
    *(myPolygon->points + position) = y;
  }
}


char *getColourPolygon(Polygon polygon){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->colour;
  }
  return NULL;
}


void setColourPolygon(Polygon polygon, char *colour) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    if (myPolygon->colour != NULL) {
      free(myPolygon->colour);
    }
    myPolygon->colour = criarString(colour);
  }
}


int comparePolygon(Polygon polygon, void *id){
  newPolygon *myPolygon = (newPolygon *)polygon;
  int *myId = (int *)id;
  if (myPolygon->id == *myId) {
    return 1;
  }
  return 0;
}


void erasePolygon(Polygon polygon){
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    if (myPolygon->colour != NULL) {
      free(myPolygon->colour);
    }
    free(myPolygon->points);
    free(myPolygon);
  }
}
