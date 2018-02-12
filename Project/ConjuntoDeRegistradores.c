#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ConjuntoDeRegistradores.h"
#include "StringO.h"

typedef struct mySetOfRegisters{
  char *name;
  void **myRegisters;
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
    sor->myRegisters = (void **) malloc(qtdRegisters * sizeof(void*));
    /* Percorre o vetor insidindo null */
    for(i=0; i<qtdRegisters; i++){
      sor->myRegisters[i] = NULL;
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
      *(sor->myRegisters) = registerN;
      sor->qtdRegistersC = sor->qtdRegistersC + 1;
    } else if(sor->qtdRegistersC < sor->qtdRegistersT){
      *(sor->myRegisters + (sor->qtdRegistersC + 1)) = registerN;
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
      if(compareRegister(*(sor->myRegisters + i), name) == 1){
        registerN = *(sor->myRegisters + i);
      }
    }
  }
  return registerN;
}


void removeSetOfRegisters(SetOfRegisters setOfRegisters,  void (removeRegInfo)(void *)){
  int i;
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;
  if(sor != NULL){
    for(i=0; i<sor->qtdRegistersC; i++){
      if(sor->myRegisters[i] != NULL){
        if(removeRegInfo != NULL){
          removeRegister(sor->myRegisters[i], removeRegInfo);
        } else {
          removeRegister(sor->myRegisters[i], NULL);
        }
      }
    }
    free(sor->name);
    free(sor->myRegisters);
    free(sor);
  }
}
