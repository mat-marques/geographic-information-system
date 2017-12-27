#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Linha.h"
#include "StringO.h"

typedef struct myLine {
  double x1, y1, x2, y2;
  char *colour;
  int sizeLine, id;
} newLine;

Line createLine(int id, double x1, double y1, double x2, double y2) {
  newLine *myLine = NULL;
  char colour1[] = "red";
  myLine = (newLine *)malloc(sizeof(newLine));
  if (myLine != NULL) {
    myLine->id = id;
    myLine->x1 = x1;
    myLine->y1 = y1;
    myLine->x2 = x2;
    myLine->y2 = y2;
    myLine->colour = criarString(colour1);
    myLine->sizeLine = 2;
  }
  return myLine;
}


int getIdLine(Line line) {
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    return myLine->id;
  }
  return 0;
}


void setIdLine(Line line, int id) {
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    myLine->id = id;
  }
}


double getX1Line(Line line) {
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    return myLine->x1;
  }
  return 0;
}


void setX1Line(Line line, double x1){
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    myLine->x1 = x1;
  }
}


double getY1Line(Line line) {
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    return myLine->y1;
  }
  return 0;
}


void setY1Line(Line line, double y1){
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    myLine->y1 = y1;
  }
}


double getX2Line(Line line) {
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    return myLine->x2;
  }
  return 0;
}


void setX2Line(Line line, double x2){
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    myLine->x2 = x2;
  }
}


double getY2Line(Line line) {
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    return myLine->y2;
  }
  return 0;
}


void setY2Line(Line line, double y2){
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    myLine->y2 = y2;
  }
}


int getSizeLine(Line line) {
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    return myLine->sizeLine;
  }
  return 0;
}


void setSizeLine(Line line, int sizeLine){
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    myLine->sizeLine = sizeLine;
  }
}


char *getColourLine(Line line) {
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    return myLine->colour;
  }
  return 0;
}


void setColourLine(Line line, char *colourLine){
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    if(myLine->colour != NULL){
      free(myLine->colour);
    }
    myLine->colour = criarString(colourLine);
  }
}


int compareLines(Line line, void *id){
  newLine *myLine = (newLine *)line;
  int *myId = (int*) id;
  if(myLine->id == *myId){
    return 1;
  }
  return 0;
}


void eraseLine(Line line){
  newLine *myLine = (newLine *)line;
  if (line != NULL) {
    if(myLine->colour != NULL){
      free(myLine->colour);
    }
    free(myLine);
  }
}
