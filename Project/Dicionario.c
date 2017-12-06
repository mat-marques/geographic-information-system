#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Dicionario.h"
#include "StringO.h"

typedef struct secao{
  char *nome;
  HashTable hash;
}Secao;

typedef struct novoDicionario{
  int qtd, Max;
  Secao *secoes;
}NovoDicionario;


Dicionario criaDicionario(int tamanho){
  int i;
  Secao *secoes;
  NovoDicionario *novoD = (NovoDicionario*) malloc(sizeof(NovoDicionario));
  novoD->qtd = 0;
  novoD->Max = tamanho;
  novoD->secoes = (Secao*) malloc(tamanho * sizeof(Secao));
  secoes = novoD->secoes;
  for(i=0; i< tamanho; i++){
    (secoes+i)->nome = NULL;
    (secoes+i)->hash = NULL;
  }
  return novoD;
}


void insertSecaoDicionario(Dicionario dicionario, char *nome, int tamanhoS){
  Secao *secoes;
  NovoDicionario *novoD = (NovoDicionario*) dicionario;
  if(novoD != NULL){
    secoes = novoD->secoes;
    if(novoD->qtd < novoD->Max){
      (secoes + novoD->qtd)->nome = criarString(nome);
      (secoes + novoD->qtd)->hash = createHT(tamanhoS);
      novoD->qtd = novoD->qtd + 1;
    } else {
      printf("Capacidade maxima do dicionario alcancada.\n");
    }
  }
}


int qtdSecoes(Dicionario dicionario){
  NovoDicionario *novoD = (NovoDicionario*) dicionario;
  return novoD->qtd;
}


HashTable getSecaoDicionario(Dicionario dicionario, char *nome){
  int i;
  NovoDicionario *novoD = (NovoDicionario*) dicionario;
  HashTable hash = NULL;
  Secao *secoes;
  if(novoD != NULL){
    secoes = novoD->secoes;
    for(i=0; i< novoD->qtd; i++){
      if(strcmp((secoes + i)->nome, nome) == 0){
        return (secoes + i)->hash;
      }
    }
  }
  return hash;
}


HashTable removeSecaoDicionario(Dicionario dicionario, char *nome){
  int i;
  NovoDicionario *novoD = (NovoDicionario*) dicionario;
  HashTable hash = NULL;
  Secao *secoes;
  if(novoD != NULL){
    secoes = novoD->secoes;
    for(i=0; i< novoD->qtd; i++){
      if(strcmp((secoes + i)->nome, nome) == 0){
        free((secoes + i)->nome);
        hash = (secoes + i)->hash;
        (secoes + i)->hash = NULL;
        return hash;
      }
    }
  }
  return hash;
}


void removeDicionario(Dicionario dicionario){
  int i;
  NovoDicionario *novoD = (NovoDicionario*) dicionario;
  Secao *secoes;
  if(novoD != NULL){
    secoes = novoD->secoes;
    for(i=0; i< novoD->qtd; i++){
      if((secoes + i)->nome != NULL)
        free((secoes + i)->nome);
    }
    free(novoD->secoes);
    free(novoD);
  }
}
