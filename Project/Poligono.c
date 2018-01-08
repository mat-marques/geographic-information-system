#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Poligono.h"
#include "StringO.h"

typedef struct myCoord{
  double x, y;
}Coord;

typedef struct myPolygon {
  Coord **points;
  int nPoints, id, qtdPoints, lineSize;
  char *colourFill, *colourLine;
} newPolygon;


Polygon createPolygon(int id, int nPoints) {
  newPolygon *myPolygon = NULL;
  char colour1[] = "white", colour2[] = "black";
  int i;
  myPolygon = (newPolygon *)malloc(sizeof(newPolygon));
  if (myPolygon != NULL) {
    myPolygon->id = id;

    myPolygon->points = (Coord **)malloc(nPoints * sizeof(Coord));
    for (i = 0; i < nPoints; i++) {
      *(myPolygon->points + i) = NULL;
    }

    myPolygon->nPoints = nPoints;
    myPolygon->qtdPoints = 0;
    myPolygon->lineSize = 1;
    myPolygon->colourLine = criarString(colour1);
    myPolygon->colourFill = criarString(colour2);
  }
  return myPolygon;
}


int getIdPolygon(Polygon polygon) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->id;
  }
  return 0;
}


void setIdPolygon(Polygon polygon, int id) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    myPolygon->id = id;
  }
}


int insertPointsPolygon(Polygon polygon, double x, double y) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  Coord *newCoord = NULL;
  int i = 0;
  if (polygon != NULL) {
    if (myPolygon->qtdPoints < myPolygon->nPoints) {
      i = myPolygon->qtdPoints;
      newCoord = (Coord*) malloc(sizeof(Coord));
      newCoord->x = x;
      newCoord->y = y;
      *(myPolygon->points + i) = newCoord;
      myPolygon->qtdPoints = myPolygon->qtdPoints + 1;
      return 1;
    }
  }
  return 0;
}


double *getPointsPolygon(Polygon polygon){
  newPolygon *myPolygon = (newPolygon *)polygon;
  Coord *newCoord = NULL;
  double *vector = NULL;
  int i = 0;
  if (polygon != NULL) {
    vector = (double*) malloc((myPolygon->qtdPoints * 2) * sizeof(double));
    for(i=0; i<myPolygon->qtdPoints; i++){
      newCoord = *(myPolygon->points + i);
      *(vector + (i * 2)) = newCoord->x;
      *(vector + (i * 2) + 1) = newCoord->y;
    }
  }
  return vector;
}



int getnPointsPolygon(Polygon polygon) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->nPoints;
  }
  return 0;
}


int getQtdPointsPolygon(Polygon polygon) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->qtdPoints;
  }
  return 0;
}


double getXPolygon(Polygon polygon, int point) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  Coord *newCoord = NULL;
  if (polygon != NULL) {
    if ((point > 0) && (point <= myPolygon->nPoints)){
      newCoord = *(myPolygon->points + (point-1));
      return newCoord->x;
    }
  }
  return 0;
}


void setXPolygon(Polygon polygon, int point, double x) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  Coord *newCoord = NULL;
  if (polygon != NULL) {
    if ((point >= 0) && (point <= myPolygon->nPoints)){
      newCoord = *(myPolygon->points + (point-1));
       newCoord->x = x;
    }
  }
}


double getYPolygon(Polygon polygon, int point) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  Coord *newCoord = NULL;
  if (polygon != NULL) {
    if ((point > 0) && (point <= myPolygon->nPoints)){
      newCoord = *(myPolygon->points + (point-1));
      return newCoord->y;
    }
  }
  return 0;
}


void setYPolygon(Polygon polygon, int point, double y) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  Coord *newCoord = NULL;
  if (polygon != NULL) {
    if ((point >= 0) && (point <= myPolygon->nPoints)){
      newCoord = *(myPolygon->points + (point-1));
       newCoord->y = y;
    }
  }
}


int getLineSizePolygon(Polygon polygon) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->lineSize;
  }
  return 0;
}


void setLineSizePolygon(Polygon polygon, int lineSize) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    myPolygon->lineSize = lineSize;
  }
}


char *getColourFillPolygon(Polygon polygon) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->colourFill;
  }
  return NULL;
}


void setColourFillPolygon(Polygon polygon, char *colourFill) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    if (myPolygon->colourFill != NULL) {
      free(myPolygon->colourFill);
    }
    myPolygon->colourFill = criarString(colourFill);
  }
}


char *getColourLinePolygon(Polygon polygon) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    return myPolygon->colourLine;
  }
  return NULL;
}


void setColourLinePolygon(Polygon polygon, char *colourLine) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    if (myPolygon->colourLine != NULL) {
      free(myPolygon->colourLine);
    }
    myPolygon->colourLine = criarString(colourLine);
  }
}


int comparePolygon(Polygon polygon, void *id) {
  newPolygon *myPolygon = (newPolygon *)polygon;
  int *myId = (int *)id;
  if (myPolygon->id == *myId) {
    return 1;
  }
  return 0;
}


void erasePolygon(Polygon polygon) {
  int i;
  Coord *newCoord = NULL;
  newPolygon *myPolygon = (newPolygon *)polygon;
  if (polygon != NULL) {
    if (myPolygon->colourFill != NULL) {
      free(myPolygon->colourFill);
    }
    if (myPolygon->colourLine != NULL) {
      free(myPolygon->colourLine);
    }
    for(i=0; i<myPolygon->qtdPoints; i++){
      newCoord = *(myPolygon->points + i);
      free(newCoord);
    }
    free(myPolygon->points);
    free(myPolygon);
  }
}
