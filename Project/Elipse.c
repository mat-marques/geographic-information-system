#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Elipse.h"
#include "StringO.h"

typedef struct myEllipse{
  double cx, cy, rx, ry;
  int id;
  char *colour;
}newEllipse;


Ellipse createEllipse(int id, double cx, double cy, double rx, double ry){
  newEllipse *ellipse = NULL;
  ellipse = (newEllipse*) malloc(sizeof(newEllipse));
  if(ellipse != NULL){
    ellipse->id = id;
    ellipse->cx = cx;
    ellipse->cy = cy;
    ellipse->rx = rx;
    ellipse->ry = ry;
    ellipse->colour = NULL;
  }
  return ellipse;
}


int getIdEllipse(Ellipse ellipse){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    return myEllipse->id;
  }
  return 0;
}


void setIdEllipse(Ellipse ellipse, int id){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    myEllipse->id = id;
  }
}


double getCXEllipse(Ellipse ellipse){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    return myEllipse->cx;
  }
  return 0;
}


void setCXEllipse(Ellipse ellipse, double cx){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    myEllipse->cx = cx;
  }
}


double getCYEllipse(Ellipse ellipse){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    return myEllipse->cy;
  }
  return 0;
}


void setCYEllipse(Ellipse ellipse, double cy){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    myEllipse->cy = cy;
  }
}


double getRXEllipse(Ellipse ellipse){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    return myEllipse->rx;
  }
  return 0;
}


void setRXEllipse(Ellipse ellipse, double rx){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    myEllipse->rx = rx;
  }
}


double getRYEllipse(Ellipse ellipse){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    return myEllipse->ry;
  }
  return 0;
}


void setRYEllipse(Ellipse ellipse, double ry){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    myEllipse->ry = ry;
  }
}


char *getColourEllipse(Ellipse ellipse){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    return myEllipse->colour;
  }
  return NULL;
}


void setColourEllipse(Ellipse ellipse, char *colour){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    if(myEllipse->colour != NULL){
      free(myEllipse->colour);
    }
    myEllipse->colour = criarString(colour);
  }
}


int compareEllipses(Ellipse ellipse, void *id){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  int *myId = (int*) id;
  if(myEllipse->id ==  *myId){
    return 1;
  }
  return 0;
}


void eraseEllipse(Ellipse ellipse){
  newEllipse *myEllipse = (newEllipse*) ellipse;
  if(ellipse != NULL){
    if(myEllipse->colour != NULL){
      free(myEllipse->colour);
    }
    free(myEllipse);
  }

}
