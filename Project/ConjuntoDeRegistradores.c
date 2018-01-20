#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ConjuntoDeRegistradores.h"
#include "StringO.h"

struct reg{
  void *r;
};

typedef struct mySetOfRegisters{
  char *name;
  struct reg *myRegisters;
  int qtdRegistersT, qtdRegistersC;
}newSetOfRegisters;

SetOfRegisters createSetOfRegisters(char *name, int qtdRegisters){
  newSetOfRegisters *sor = NULL;
  int i;
  sor = (newSetOfRegisters*) malloc(sizeof(newSetOfRegisters));
  if(sor != NULL){
    sor->name = criarString(name);
    sor->qtdRegistersC = 0;
    sor->qtdRegistersT = qtdRegisters;
    sor->myRegisters = (struct reg*) malloc(qtdRegisters * sizeof(struct reg));
    /* Percorre o vetor insidindo null */
    for(i=0; i<qtdRegisters; i++){
      (sor->myRegisters + i)->r = NULL;
    }
  }
  return sor;
}


char *getNamesetOfRegisters(SetOfRegisters setOfRegisters){
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;
  return sor->name;
}



void setNameSetOfRegisters(SetOfRegisters setOfRegisters, char *name){
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;
  if(sor->name != NULL){
    free(sor->name);
  }
  sor->name = criarString(name);
}



int getQtdRegistersTSetOfRegisters(SetOfRegisters setOfRegisters){
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;
  return sor->qtdRegistersT;
}



int getQtdRegistersCSetOfRegisters(SetOfRegisters setOfRegisters){
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;

  return sor->qtdRegistersC;
}


void insertRegister(SetOfRegisters setOfRegisters, Register registerN){
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;
  if(sor != NULL){
    if(sor->qtdRegistersC == 0){
      sor->myRegisters->r = registerN;
      sor->qtdRegistersC = sor->qtdRegistersC + 1;
    } else if(sor->qtdRegistersC < sor->qtdRegistersT){
      (sor->myRegisters + (sor->qtdRegistersC + 1))->r = registerN;
      sor->qtdRegistersC = sor->qtdRegistersC + 1;
    }
  }
}


Register getRegister(SetOfRegisters setOfRegisters, char *name){
  int i;
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;
  Register registerN = NULL;
  if(sor != NULL){
    for(i=0; i<sor->qtdRegistersC; i++){
      if(compareRegister((sor->myRegisters + i)->r, name) == 1){
        registerN = (sor->myRegisters + i)->r;
      }
    }
  }
  return registerN;
}


void removeSetOfRegisters(SetOfRegisters setOfRegisters,  void (removeReg)(void *)){
  int i;
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;
  if(sor != NULL){
    for(i=0; i<sor->qtdRegistersC; i++){
      if((sor->myRegisters + i)->r != NULL){
        removeRegister((sor->myRegisters + i)->r, removeReg);
      }
    }
    free(sor->name);
    free(sor);
  }
}
