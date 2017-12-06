#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringO.h"
#include "Cliente.h"

typedef struct novoCliente{
  char *nome, *cpf, *numCelular;
}NovoCliente;

Cliente criaCliente(char *cpf, char *numCelular){
  NovoCliente *novoCliente;
  novoCliente = (NovoCliente*) malloc(sizeof(NovoCliente));

  novoCliente->cpf = criarString(cpf);
  novoCliente->numCelular = criarString(numCelular);
  novoCliente->nome = NULL;

  return novoCliente;
}


char *getCpfC(Cliente cliente){
  NovoCliente *novoCliente = (NovoCliente*) cliente;
  return novoCliente->cpf;
}


void setCpfC(Cliente cliente, char *cpf){
  NovoCliente *novoCliente = (NovoCliente*) cliente;
  if(novoCliente->cpf != NULL){
    free(novoCliente->cpf);
    novoCliente->cpf = NULL;
  }
  novoCliente->cpf = criarString(cpf);
}


char *getNumCelularC(Cliente cliente){
  NovoCliente *novoCliente = (NovoCliente*) cliente;
  return novoCliente->numCelular;
}


void getNumCelularC(Cliente cliente, char *numCelular){
  NovoCliente *novoCliente = (NovoCliente*) cliente;
  if(novoCliente->numCelular != NULL){
    free(novoCliente->numCelular);
    novoCliente->numCelular = NULL;
  }
  novoCliente->numCelular = criarString(numCelular);
}



char *getNomeC(Cliente cliente){
  NovoCliente *novoCliente = (NovoCliente*) cliente;
  return novoCliente->nome;
}


void setNomeC(Cliente cliente, char *nome){
  NovoCliente *novoCliente = (NovoCliente*) cliente;
  if(novoCliente->nome != NULL){
    free(novoCliente->nome);
    novoCliente->nome = NULL;
  }
  novoCliente->nome= criarString(nome);
}


int compareClientes(Cliente cliente1, Cliente cliente2){
  NovoCliente *novoCliente1 = (NovoCliente*) cliente1;
  char *cpf = (char*) cliente2;
  if(strcmp(novoCliente1->cpf, cpf)==0){
    return 1;
  }
  return 0;
}


void removeClienteC(Cliente cliente){
  NovoCliente *novoCliente = (NovoCliente*) cliente;
  if(novoCliente != NULL){
    free(novoCliente->cpf);
    free(novoCliente->nome);
    free(novoCliente->numCelular);
    free(novoCliente);
  }
}
