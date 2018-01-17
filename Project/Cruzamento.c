#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cruzamento.h"
#include "StringO.h"

typedef struct myCrossRoad{
  char* id;
  double x, y;
}newCrossRoad;


CrossRoad createCrossRoad(char* id, double x, double y){
  newCrossRoad *CrossRoad = NULL;

  CrossRoad = (newCrossRoad*) malloc(sizeof(newCrossRoad));
  if(CrossRoad != NULL){
      CrossRoad->id = id;
      CrossRoad->x = x;
      CrossRoad->y = y;
  }

  return CrossRoad;
}


char *getIdCrossRoad(CrossRoad crossRoad){
  newCrossRoad *myNewCrossRoad = (newCrossRoad*) crossRoad;
  return myNewCrossRoad->id;
}


void setIdCrossRoad(CrossRoad crossRoad, char* id){
  newCrossRoad *myNewCrossRoad = (newCrossRoad*) crossRoad;
  if(myNewCrossRoad != NULL){
    myNewCrossRoad->id = id;
  }
}


double getXCrossRoad(CrossRoad crossRoad){
  newCrossRoad *myNewCrossRoad = (newCrossRoad*) crossRoad;
  return myNewCrossRoad->x;
}


void setXCrossRoad(CrossRoad crossRoad, double x){
  newCrossRoad *myNewCrossRoad = (newCrossRoad*) crossRoad;
  if(myNewCrossRoad != NULL){
    myNewCrossRoad->x = x;
  }
}


double getYCrossRoad(CrossRoad crossRoad){
  newCrossRoad *myNewCrossRoad = (newCrossRoad*) crossRoad;
  return myNewCrossRoad->y;
}


void setYCrossRoad(CrossRoad crossRoad, double y){
  newCrossRoad *myNewCrossRoad = (newCrossRoad*) crossRoad;
  if(myNewCrossRoad != NULL){
    myNewCrossRoad->y = y;
  }
}


int compareCrossRoad(CrossRoad crossRoad, void *id){
  newCrossRoad *myNewCrossRoad = (newCrossRoad*) crossRoad;
  char *myId = (char*) id;
  if(strcmp(myNewCrossRoad->id, myId) == 0){
    return 1;
  }
  return 0;
}


void removeCrossRoad(CrossRoad crossRoad){
  newCrossRoad *myNewCrossRoad = (newCrossRoad*) crossRoad;
  if(myNewCrossRoad != NULL){
    free(myNewCrossRoad->id);
    free(myNewCrossRoad);
  }
}
