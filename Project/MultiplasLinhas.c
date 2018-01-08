#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MultiplasLinhas.h"
#include "StringO.h"

typedef struct myCoorf{
  double x, y;
}Coord;

typedef struct myPolyLine {
  Coord **points;
  int id, nPoints, qtdPoints, lineSize;
  char *colourLine, *colourFill;
} newPolyLine;

PolyLine createPolyLine(int id, int nPoints) {
  newPolyLine *myPolyLine = NULL;
  char colour1[] = "red", colour2[] = "black";
  int i;
  myPolyLine = (newPolyLine *)malloc(sizeof(newPolyLine));
  if (myPolyLine != NULL) {
    myPolyLine->id = id;

    myPolyLine->points = (Coord**) malloc(nPoints * sizeof(Coord));
    for(i = 0; i < nPoints; i++){
      *(myPolyLine->points + i) = NULL;
    }

    myPolyLine->qtdPoints = 0;
    myPolyLine->nPoints = nPoints;
    myPolyLine->lineSize = 2;
    myPolyLine->colourLine = criarString(colour1);
    myPolyLine->colourFill = criarString(colour2);
  }
  return myPolyLine;
}


int getIdPolyLine(PolyLine polyLine) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    return myPolyLine->id;
  }
  return 0;
}


void setIdPolyLine(PolyLine polyLine, int id) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    myPolyLine->id = id;
  }
}


int insertPointsPolyLine(PolyLine polyLine, double x, double y){
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  int i = 0;
  Coord *newCoord = NULL;
  if(polyLine!= NULL){
    if(myPolyLine->qtdPoints < myPolyLine->nPoints){
      i = myPolyLine->qtdPoints;
      newCoord = *(myPolyLine->points + i);
      newCoord->x = x;
      newCoord->y = y;
      myPolyLine->qtdPoints = myPolyLine->qtdPoints + 1;
      return 1;
    }
  }
  return 0;
}


double *getPointsPolyLine(PolyLine polyLine){
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  Coord *newCoord = NULL;
  double *vector = NULL;
  int i = 0;
  if (polyLine != NULL) {
    vector = (double*) malloc((myPolyLine->qtdPoints * 2) * sizeof(double));
    for(i=0; i<myPolyLine->qtdPoints; i++){
      newCoord = *(myPolyLine->points + i);
      *(vector + (i * 2)) = newCoord->x;
      *(vector + (i * 2) + 1) = newCoord->y;
    }
  }
  return vector;
}



int getnPointsPolyLine(PolyLine polyLine) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    return myPolyLine->nPoints;
  }
  return 0;
}


int getqtdPointsPolyLine(PolyLine polyLine){
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    return myPolyLine->qtdPoints;
  }
  return 0;
}


double getXPolyLine(PolyLine polyLine, int point) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  Coord *newCoord = NULL;
  if (polyLine != NULL) {
    if ((point > 0) && (point <= myPolyLine->nPoints)) {
      newCoord = *(myPolyLine->points + (point-1));
      return newCoord->x;
    }
  }
  return 0;
}


void setXPolyLine(PolyLine polyLine, int point, double x) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  Coord *newCoord = NULL;
  if (polyLine != NULL) {
    if ((point > 0) && (point <= myPolyLine->nPoints)) {
      newCoord = *(myPolyLine->points + (point-1));
      newCoord->x = x;
    }
  }
}


double getYPolyLine(PolyLine polyLine, int point) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  Coord *newCoord = NULL;
  if (polyLine != NULL) {
    if ((point > 0) && (point <= myPolyLine->nPoints)) {
      newCoord = *(myPolyLine->points + (point-1));
      return newCoord->y;
    }
  }
  return 0;
}


void setYPolyLine(PolyLine polyLine, int point, double y) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  Coord *newCoord = NULL;
  if (polyLine != NULL) {
    if ((point > 0) && (point <= myPolyLine->nPoints)) {
      newCoord = *(myPolyLine->points + (point-1));
      newCoord->y = y;
    }
  }
}


int getLineSizePolyLine(PolyLine polyLine) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    return myPolyLine->lineSize;
  }
  return 0;
}


void setLineSizePolyLine(PolyLine polyLine, int lineSize) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    myPolyLine->lineSize = lineSize;
  }
}


char *getColourLinePolyLine(PolyLine polyLine) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    return myPolyLine->colourLine;
  }
  return NULL;
}


void setColourLinePolyLine(PolyLine polyLine, char *colour) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    if (myPolyLine->colourLine != NULL) {
      free(myPolyLine->colourLine);
    }
    myPolyLine->colourLine = criarString(colour);
  }
}


char *getColourFillPolyLine(PolyLine polyLine) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    return myPolyLine->colourFill;
  }
  return NULL;
}


void setColourFillPolyLine(PolyLine polyLine, char *colour) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    if (myPolyLine->colourFill != NULL) {
      free(myPolyLine->colourFill);
    }
    myPolyLine->colourFill = criarString(colour);
  }
}


int comparePolyLine(PolyLine polyLine, void *id) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  int *myId = (int *)id;
  if (myPolyLine->id == *myId) {
    return 1;
  }
  return 0;
}


void erasePolyLine(PolyLine polyLine) {
  int i;
  Coord *newCoord = NULL;
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    if (myPolyLine->colourLine != NULL) {
      free(myPolyLine->colourLine);
    }
    if (myPolyLine->colourFill != NULL) {
      free(myPolyLine->colourFill);
    }
    for(i=0; i<myPolyLine->qtdPoints; i++){
      newCoord = *(myPolyLine->points + i);
      free(newCoord);
    }
    free(myPolyLine->points);
    free(myPolyLine);
  }
}
