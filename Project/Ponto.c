#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ponto.h"

typedef struct myPoint{
  int id;
  double x, y;
}newPoint;


Point createPoint(int id, double x, double y){
  newPoint *point = NULL;

  point = (newPoint*) malloc(sizeof(newPoint));
  if(point != NULL){
      point->id = id;
      point->x = x;
      point->y = y;
  }

  return point;
}


int getIdPoint(Point point){
  newPoint *myNewPoint = (newPoint*) point;
  return myNewPoint->id;
}


void setIdPoint(Point point, int id){
  newPoint *myNewPoint = (newPoint*) point;
  myNewPoint->id = id;
}


double getXPoint(Point point){
  newPoint *myNewPoint = (newPoint*) point;
  return myNewPoint->x;
}


void setXPoint(Point point, double x){
  newPoint *myNewPoint = (newPoint*) point;
  myNewPoint->x = x;
}


double getYPoint(Point point){
  newPoint *myNewPoint = (newPoint*) point;
  return myNewPoint->y;
}


void setYPoint(Point point, double y){
  newPoint *myNewPoint = (newPoint*) point;
  myNewPoint->y = y;
}


int comparePoints(Point point, void *id){
  newPoint *myNewPoint = (newPoint*) point;
  int *myId = (int*) id;
  if(myNewPoint->id == *myId){
    return 1;
  }
  return 0;
}


void removePoint(Point point){
  newPoint *myNewPoint = (newPoint*) point;
  if(myNewPoint != NULL){
    free(myNewPoint);
  }
}
