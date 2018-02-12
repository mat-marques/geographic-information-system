#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Endereco.h"
#include "StringO.h"

typedef struct NovoEndereco {
  char *cep, face;
  int num;
  char *comp;
  double x, y;
} NovoEndereco;

Endereco criaEndereco(char *cep, char face, int num, char *comp) {
  NovoEndereco *novoE;

  novoE = (NovoEndereco *)malloc(sizeof(NovoEndereco));

  novoE->cep = criarString(cep);
  novoE->comp = criarString(comp);
  novoE->face = face;
  novoE->num = num;
  novoE->x = -1;
  novoE->y = -1;
  return novoE;
}

char *getCep(Endereco endereco) {
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  return novoE->cep;
}

void setCep(Endereco endereco, char *cep) {
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  if (novoE->cep != NULL) {
    free(novoE->cep);
    novoE->cep = NULL;
  }
  novoE->cep = criarString(cep);
}

char getFace(Endereco endereco) {
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  return novoE->face;
}

void setFace(Endereco endereco, char face) {
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  novoE->face = face;
}

int getNum(Endereco endereco) {
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  return novoE->num;
}

void setNum(Endereco endereco, double num) {
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  novoE->num = num;
}


double getXEndereco(Endereco endereco){
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  return novoE->x;
}

void setXEndereco(Endereco endereco, double x){
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  novoE->x = x;
}

double getYEndereco(Endereco endereco){
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  return novoE->y;
}

void setYEndereco(Endereco endereco, double y){
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  novoE->y = y;
}

char *getComp(Endereco endereco) {
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  return novoE->comp;
}

void setComp(Endereco endereco, char *comp) {
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  if (novoE->comp != NULL) {
    free(novoE->comp);
    novoE->comp = NULL;
  }
  novoE->comp = criarString(comp);
}

int compareEnderecos(Endereco endereco1, Endereco endereco2) {
  NovoEndereco *novoE1 = (NovoEndereco *)endereco1;
  NovoEndereco *novoE2 = (NovoEndereco *)endereco2;
  if ((strcmp(novoE1->cep, novoE2->cep) == 0) && (novoE1->num == novoE2->num) &&
      (novoE1->face == novoE2->face) &&
      (strcmp(novoE1->comp, novoE2->comp) == 0)) {

    return 1;
  }

  return 0;
}

void removeEndereco(Endereco endereco) {
  NovoEndereco *novoE = (NovoEndereco *)endereco;
  if (novoE != NULL) {
    if (novoE->cep != NULL) {
      free(novoE->cep);
      novoE->cep = NULL;
    }
    if (novoE->comp != NULL) {
      free(novoE->comp);
      novoE->comp = NULL;
    }
    free(novoE);
  }
}
