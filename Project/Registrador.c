#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Registrador.h"
#include "StringO.h"

typedef struct myRegister{
  char *name;
  void *info;
}newRegister;

Register createRegister(char *name, void *info){
  newRegister *Register = NULL;
  Register = (newRegister*) malloc(sizeof(newRegister));
  if(Register != NULL){
    Register->name = criarString(name);
    Register->info = info;
  }
  return Register;
}


char *getNameRegister(Register registerN){
  newRegister *nRegister = (newRegister*) registerN;
  return nRegister->name;
}


void setNameRegister(Register registerN, char *name){
  newRegister *nRegister = (newRegister*) registerN;
  if(nRegister->name != NULL){
    free(nRegister->name);
  }
  nRegister->name = criarString(name);
}


void *getInfoRegister(Register registerN){
  newRegister *nRegister = (newRegister*) registerN;
  return nRegister->info;
}


void setInfoRegister(Register registerN, void *info){
  newRegister *nRegister = (newRegister*) registerN;
  if(nRegister->info != NULL){
    nRegister->info = info;
  }
}


int compareRegister(Register registerN, void *name){
  newRegister *nRegister = (newRegister*) registerN;
  char *id = (char*) name;
  if(strcmp(nRegister->name, id) == 0){
    return 1;
  }
  return 0;
}


void removeRegister(Register registerN, void (removeReg)(void *)){
  newRegister *nRegister = (newRegister*) registerN;
  if(nRegister != NULL){
    free(nRegister->name);
    if(removeReg != NULL){
      removeReg(nRegister->info);
    }
    free(nRegister);
  }
}
