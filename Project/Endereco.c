#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringO.h"
#include "Endereco.h"

typedef struct NovoEndereco{
  char *cep, face;
  int num;
  char* comp;
}NovoEndereco;

Endereco criaEndereco(char *cep, char face,  int num, char* comp){
  NovoEndereco *novoE;

  novoE = (NovoEndereco*) malloc(sizeof(NovoEndereco));

  novoE->cep = criarString(cep);
  novoE->comp = criarString(comp);
  novoE->face = face;
  novoE->num = num;

  return novoE;
}


char *getCep(Endereco endereco){
  NovoEndereco *novoE = (NovoEndereco*) endereco;
  return novoE->cep;
}


void setCep(Endereco endereco, char *cep){
    NovoEndereco *novoE = (NovoEndereco*) endereco;
    if(novoE->cep != NULL){
      free(novoE->cep);
      novoE->cep = NULL;
    }
    novoE->cep = criarString(cep);
}


char getFace(Endereco endereco){
  NovoEndereco *novoE = (NovoEndereco*) endereco;
  return novoE->face;
}


void setFace(Endereco endereco, char face){
    NovoEndereco *novoE = (NovoEndereco*) endereco;
    novoE->face = face;
}


int getNum(Endereco endereco){
  NovoEndereco *novoE = (NovoEndereco*) endereco;
  return novoE->num;
}


void setNum(Endereco endereco, double num){
    NovoEndereco *novoE = (NovoEndereco*) endereco;
    novoE->num = num;
}


char* getComp(Endereco endereco){
  NovoEndereco *novoE = (NovoEndereco*) endereco;
  return novoE->comp;
}


void setComp(Endereco endereco, char* comp){
    NovoEndereco *novoE = (NovoEndereco*) endereco;
    if(novoE->comp != NULL){
      free(novoE->comp);
      novoE->comp = NULL;
    }
    novoE->comp = criarString(comp);
}


int compareEnderecos(Endereco endereco, void *cep){
  NovoEndereco *novoE = (NovoEndereco*) endereco;
  char *myCep = (char*) cep;
  if(strcmp(novoE->cep, myCep) == 0){
    return 1;
  }
  return 0;
}


void removeEndereco(Endereco endereco){
    NovoEndereco *novoE = (NovoEndereco*) endereco;
    if(novoE->cep != NULL){
      free(novoE->cep);
      novoE->cep = NULL;
    }
    if(novoE->comp != NULL){
      free(novoE->comp );
      novoE->comp = NULL;
    }
    free(novoE);
}
