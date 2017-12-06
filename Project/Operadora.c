#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringO.h"
#include "Operadora.h"

typedef struct operadora{
  char *nome;
  int qtdClientes;
  HashTable clientes;
}NovaOperadora;


Operadora criaOperadora(char *nome){
  NovaOperadora *novaOperadora = NULL;
  novaOperadora = (NovaOperadora*) malloc(sizeof(NovaOperadora));

  novaOperadora->nome = criarString(nome);
  novaOperadora->qtdClientes = 0;
  novaOperadora->clientes = createHT(50);

  return novaOperadora;
}


char *getNomeO(Operadora operadora){
  NovaOperadora *novaOperadora = (NovaOperadora*) operadora;
  return novaOperadora->nome;
}


void setNomeO(Operadora operadora, char *nome){
  NovaOperadora *novaOperadora = (NovaOperadora*) operadora;
  if(novaOperadora->nome != NULL){
    free(novaOperadora->nome);
    novaOperadora->nome = NULL;
  }
  novaOperadora->nome = criarString(nome);
}


int qtdClientes(Operadora operadora){
  NovaOperadora *novaOperadora = (NovaOperadora*) operadora;
  return novaOperadora->qtdClientes;
}


int insereCliente(Operadora operadora, Cliente cliente){
  NovaOperadora *novaOperadora = (NovaOperadora*) operadora;
  novaOperadora->qtdClientes = novaOperadora->qtdClientes + 1;
  return insertHT(novaOperadora->clientes, getCpfC(cliente), cliente);
}


Cliente removeCliente(Operadora operadora, Cliente cliente){
  NovaOperadora *novaOperadora = (NovaOperadora*) operadora;
  novaOperadora->qtdClientes = novaOperadora->qtdClientes - 1;
  return removeHT(novaOperadora->clientes, getCpfC(cliente), cliente, compareClientes);
}



HashTable getClientes(Operadora operadora){
  NovaOperadora *novaOperadora = (NovaOperadora*) operadora;
  return novaOperadora->clientes;
}

Cliente getCliente(Operadora operadora, char *cpf){
  NovaOperadora *novaOperadora = (NovaOperadora*) operadora;
  return itemIsInsideHT(novaOperadora->clientes, cpf, cpf, compareClientes);
}

int compareOperadoras(Operadora operadora1, Operadora operadora2){
  NovaOperadora *novaOperadora = (NovaOperadora*) operadora1;
  char *nome = (char*) operadora2;
  if(strcmp(novaOperadora->nome, nome) == 0){
    return 1;
  }
  return 0;
}

void removeOperadora(Operadora operadora){
  NovaOperadora *novaOperadora = (NovaOperadora*) operadora;
  free(novaOperadora->nome);
  eraseHT(novaOperadora->clientes, NULL);
}
