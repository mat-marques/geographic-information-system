#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Rua.h"
#include "StringO.h"

typedef struct myStreet{
  char  *name, *cepRight, *cepLeft;
   double cmp, vm;
}newStreet;


Street createStreet(char *name, char *cepRight, char *cepLeft, double cmp, double vm){
  newStreet *myNewStreet = NULL;
  myNewStreet = (newStreet*) malloc(sizeof(newStreet));
  if(myNewStreet != NULL){
    myNewStreet->cepLeft = criarString(cepLeft);
    myNewStreet->cepRight = criarString(cepRight);
    myNewStreet->name = criarString(name);
    myNewStreet->cmp = cmp;
    myNewStreet->vm = vm;
  }
  return myNewStreet;
}


char *getNameStreet(Street street){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
        return myNewStreet->name;
    }
    return NULL;
}


void setNameStreet(Street street, char *name){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
      if(myNewStreet->name != NULL){
        free(myNewStreet->name);
        myNewStreet->name = NULL;
      }
      myNewStreet->name = criarString(name);
    }
}


char *getCepRight(Street street){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
        return myNewStreet->cepRight;
    }
    return NULL;
}


void setCepRight(Street street, char *cepRight){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
      if(myNewStreet->cepRight != NULL){
        free(myNewStreet->cepRight);
        myNewStreet->cepRight = NULL;
      }
      myNewStreet->cepRight = criarString(cepRight);
    }
}


char *getCepLeft(Street street){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
        return myNewStreet->cepLeft;
    }
    return NULL;
}


void setCepLeft(Street street, char *cepLeft){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
      if(myNewStreet->cepLeft != NULL){
        free(myNewStreet->cepLeft);
        myNewStreet->cepLeft = NULL;
      }
      myNewStreet->cepLeft = criarString(cepLeft);
    }
}


double getCmp(Street street){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
        return myNewStreet->cmp;
    }
    return 0;
}


void setCmp(Street street, double cmp){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
      myNewStreet->cmp = cmp;
    }
}


double getVm(Street street){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
        return myNewStreet->vm;
    }
    return 0;
}


void setVm(Street street, double vm){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
      myNewStreet->vm = vm;
    }
}


int compareStreet(Street street, void *name){
  newStreet *myNewStreet = (newStreet*) street;
  char *myName = (char*) name;
  if(strcmp(myNewStreet->name, myName) == 0){
    return 1;
  }
  return 0;
}


void removeStreet(Street street){
    newStreet *myNewStreet = (newStreet*) street;
    if(myNewStreet != NULL){
      if(myNewStreet->cepLeft != NULL)
        free(myNewStreet->cepLeft);

      if(myNewStreet->cepRight != NULL)
        free(myNewStreet->cepRight);

      if(myNewStreet->name != NULL)
        free(myNewStreet->name);

      free(myNewStreet);
    }
}
