#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MultiplasLinhas.h"
#include "StringO.h"

typedef struct myPolyLine {
  double *points;
  int id, nPoints, qtdPoints;
  char *colourLine, *colourPoint;
} newPolyLine;

PolyLine createPolyLine(int id, int nPoints) {
  newPolyLine *myPolyLine = NULL;
  int i;
  myPolyLine = (newPolyLine *)malloc(sizeof(newPolyLine));
  if (myPolyLine != NULL) {
    myPolyLine->id = id;

    myPolyLine->points = (double*) malloc((2 * nPoints) * sizeof(double));
    for(i = 0; i < nPoints; i++){
      *(myPolyLine->points + i) = 0;
    }

    myPolyLine->qtdPoints = 0;
    myPolyLine->nPoints = nPoints;
    myPolyLine->colourLine = NULL;
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
  if(polyLine!= NULL){
    if(myPolyLine->qtdPoints < myPolyLine->nPoints){
      i = 2 * myPolyLine->qtdPoints;
      *(myPolyLine->points + i) = x;
      *(myPolyLine->points + (i + 1)) = y;
      myPolyLine->qtdPoints = myPolyLine->qtdPoints + 1;
      return 1;
    }
  }
  return 0;
}


double *getPoints(PolyLine polyLine) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    return myPolyLine->points;
  }
  return 0;
}


void setPoints(PolyLine polyLine, double *points, int nPoints) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    free(myPolyLine->points);
    myPolyLine->nPoints = nPoints;
    myPolyLine->points = points;
  }
}


int getnPoints(PolyLine polyLine) {
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


double getXPolyLine(PolyLine polyLine, int position) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    if ((position >= 0) && (position <= myPolyLine->nPoints)) {
      return *(myPolyLine->points + position);
    }
  }
  return 0;
}


void setXPolyLine(PolyLine polyLine, int position, double x) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    if ((position >= 0) && (position <= myPolyLine->nPoints)) {
      *(myPolyLine->points + position) = x;
    }
  }
}


double getYPolyLine(PolyLine polyLine, int position) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    if ((position >= 0) && (position <= myPolyLine->nPoints)) {
      return *(myPolyLine->points + position);
    }
  }
  return 0;
}


void setYPolyLine(PolyLine polyLine, int position, double y) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    if ((position >= 0) && (position <= myPolyLine->nPoints)) {
      *(myPolyLine->points + position) = y;
    }
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


char *getColourPointPolyLine(PolyLine polyLine) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    return myPolyLine->colourPoint;
  }
  return NULL;
}


void setColourPointPolyLine(PolyLine polyLine, char *colour) {
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    if (myPolyLine->colourPoint != NULL) {
      free(myPolyLine->colourPoint);
    }
    myPolyLine->colourPoint = criarString(colour);
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
  newPolyLine *myPolyLine = (newPolyLine *)polyLine;
  if (polyLine != NULL) {
    if (myPolyLine->colourLine != NULL) {
      free(myPolyLine->colourLine);
    }
    if (myPolyLine->colourPoint != NULL) {
      free(myPolyLine->colourPoint);
    }
    free(myPolyLine->points);
    free(myPolyLine);
  }
}
