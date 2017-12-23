#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Morador.h"
#include "StringO.h"
#include "Endereco.h"

typedef struct novoMorador{
  char *cpf;
  Endereco endereco;
}NovoMorador;

Morador criaMorador(char *cpf, Endereco endereco){
  NovoMorador *novoM = NULL;
  novoM = (NovoMorador*) malloc(sizeof(NovoMorador));

  novoM->cpf = criarString(cpf);
  novoM->endereco = endereco;
  return novoM;
}


char *getCpfM(Morador morador){
  NovoMorador *novoM = (NovoMorador*) morador;
  return novoM->cpf;
}


void setCpfM(Morador morador, char *cpf){
  NovoMorador *novoM = (NovoMorador*) morador;
  if(novoM->cpf != NULL){
    free(novoM->cpf);
    novoM->cpf = NULL;
  }
  novoM->cpf = criarString(cpf);
}

Endereco getEndereco(Morador morador){
  NovoMorador *novoM = (NovoMorador*) morador;
  return novoM->endereco;
}


void setEndereco(Morador morador, Endereco endereco){
  NovoMorador *novoM = (NovoMorador*) morador;
  if(novoM->endereco != NULL){
    removeEndereco(novoM->endereco);
    novoM->endereco = NULL;
  }
  novoM->endereco = endereco;
}


int compareMorador(Morador morador, void *cpf){
  NovoMorador *novoM = (NovoMorador*) morador;
  char *myCpf = (char*) cpf;
  if(strcmp(novoM->cpf, myCpf) == 0){
    return 1;
  }
  return 0;
}

void removeMorador(Morador morador){
  NovoMorador *novoM = (NovoMorador*) morador;
  free(novoM->cpf);
  removeEndereco(novoM->endereco);
  free(novoM);
}
