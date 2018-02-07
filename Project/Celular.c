#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Celular.h"
#include "Pessoa.h"
#include "StringO.h"

typedef struct novoCelular {
  char *num, *idT, *operadora;
  Pessoa pessoa;
  double x, y;
} NovoCelular;

Celular criaCelular(char *num) {
  NovoCelular *novoC = (NovoCelular *)malloc(sizeof(NovoCelular));

  novoC->idT = NULL;
  novoC->operadora = NULL;
  novoC->pessoa = NULL;
  novoC->num = criarString(num);
  novoC->x = 0;
  novoC->y = 0;
  return novoC;
}

char *getNumCelular(Celular celular) {
  NovoCelular *novoC = (NovoCelular *)celular;
  return novoC->num;
}

void setNumCelular(Celular celular, char *num) {
  NovoCelular *novoC = (NovoCelular *)celular;
  if (novoC->num != NULL) {
    free(novoC->num);
    novoC->num = NULL;
  }
  novoC->num = criarString(num);
}

double getXCelular(Celular celular){
  NovoCelular *novoC = (NovoCelular *)celular;
  return novoC->x;
}

void setXCelular(Celular celular, double x){
  NovoCelular *novoC = (NovoCelular *)celular;
  novoC->x = x;
}

double getYCelular(Celular celular){
  NovoCelular *novoC = (NovoCelular *)celular;
  return novoC->y;
}

void setYCelular(Celular celular, double y){
  NovoCelular *novoC = (NovoCelular *)celular;
  novoC->y = y;
}

char *getNomeOperadora(Celular celular) {
  NovoCelular *novoC = (NovoCelular *)celular;
  return novoC->operadora;
}

void setNomeOperadora(Celular celular, char *nomeOperadora) {
  NovoCelular *novoC = (NovoCelular *)celular;
  if (novoC->operadora != NULL) {
    free(novoC->operadora);
    novoC->operadora = NULL;
  }
  novoC->operadora = criarString(nomeOperadora);
}

void *getDonoCelular(Celular celular) {
  NovoCelular *novoC = (NovoCelular *)celular;
  return novoC->pessoa;
}

void *setDonoCelular(Celular celular, void *pessoa) {
  NovoCelular *novoC = (NovoCelular *)celular;
  Pessoa nPessoa = NULL;
  if (novoC->pessoa != NULL) {
    nPessoa = novoC->pessoa;
    novoC->pessoa = NULL;
  }
  novoC->pessoa = pessoa;
  return nPessoa;
}

char *getIdTorreConexao(Celular celular) {
  NovoCelular *novoC = (NovoCelular *)celular;
  return novoC->idT;
}

void setIdTorreConexao(Celular celular, char *id) {
  NovoCelular *novoC = (NovoCelular *)celular;
  if (novoC->idT != NULL) {
    free(novoC->idT);
    novoC->idT = NULL;
  }
  if (id != NULL) {
    novoC->idT = criarString(id);
  } else {
    novoC->idT = NULL;
  }
}

int compareCelulares(Celular celular, void *num) {
  NovoCelular *novoC = (NovoCelular *)celular;
  char *cNum = (char *)num;
  if (strcmp(novoC->num, cNum) == 0) {
    return 1;
  }
  return 0;
}

void removeCelular(Celular celular) {
  NovoCelular *novoC = (NovoCelular *)celular;
  if (novoC != NULL) {
    free(novoC->idT);
    free(novoC->num);
    free(novoC->operadora);
    novoC->pessoa = NULL;
  }
  free(novoC);
}
