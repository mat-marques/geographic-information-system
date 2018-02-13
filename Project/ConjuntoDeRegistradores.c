#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ConjuntoDeRegistradores.h"
#include "StringO.h"

typedef struct reg{
    void *myRegister;
} myReg;

typedef struct mySetOfRegisters{
  char *name;
  myReg *myRegisters;
  int qtdRegistersT, qtdRegistersC;
}newSetOfRegisters;

SetOfRegisters createSetOfRegisters(char *name, int qtdRegisters){
  newSetOfRegisters *sor = NULL;
  myReg *r;
  int i;
  sor = (newSetOfRegisters*) malloc(sizeof(newSetOfRegisters));
  if(sor != NULL){
    sor->name = criarString(name);
    sor->qtdRegistersC = 0;
    sor->qtdRegistersT = qtdRegisters;
    r = ( myReg *) malloc(qtdRegisters * sizeof(myReg));
    sor->myRegisters = NULL;
    if(r != NULL){
      sor->myRegisters = r;
      r = sor->myRegisters;
      /* Percorre o vetor insidindo null */
      for(i=0; i<qtdRegisters; i++){
        (r + i)->myRegister = NULL;
      }
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
  myReg *r;
  if(sor != NULL){
    r = sor->myRegisters;
    if(sor->qtdRegistersC == 0){
      r->myRegister = registerN;
      sor->qtdRegistersC = sor->qtdRegistersC + 1;
    } else if(sor->qtdRegistersC < sor->qtdRegistersT){
      (r + sor->qtdRegistersC)->myRegister = registerN;
      sor->qtdRegistersC = sor->qtdRegistersC + 1;
    }
  }
}


Register getRegister(SetOfRegisters setOfRegisters, char *name){
  int i;
  myReg *r;
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;
  Register registerN = NULL;
  if(sor != NULL){
    r = sor->myRegisters;
    for(i=0; i<sor->qtdRegistersC; i++){
      if(compareRegister((r + i)->myRegister, name) == 1){
        registerN = (r + i)->myRegister;
        break;
      }
    }
  }
  return registerN;
}


void removeSetOfRegisters(SetOfRegisters setOfRegisters,  void (removeRegInfo)(void *)){
  int i;
  myReg *r;
  newSetOfRegisters *sor = (newSetOfRegisters*) setOfRegisters;
  if(sor != NULL){
    r = sor->myRegisters;
    for(i=0; i<sor->qtdRegistersC; i++){
      if((r + i)->myRegister != NULL){
        if(removeRegInfo != NULL){
          removeRegister((r + i)->myRegister, removeRegInfo);
        } else {
          removeRegister((r + i)->myRegister, NULL);
        }
      }
    }
    free(sor->name);
    free(sor->myRegisters);
    free(sor);
  }
}
