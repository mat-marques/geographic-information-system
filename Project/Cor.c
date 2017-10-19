#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Cor.h"

typedef struct cores{
  char *corP;
  char *corC;
  int id;
}cores;

Cor criaCor(char *corPreenchimento, char *corContorno, int id){
    int i;
    cores *cor = NULL;
    cor = (cores*) malloc(sizeof(cores));
    i = strlen(corPreenchimento) + 1;
    cor->corP = (char *) malloc(i * sizeof(char));
    cor->corP[0] = '\0';
    strcpy(cor->corP, corPreenchimento);

    i = strlen(corContorno) + 1;
    cor->corC = (char *) malloc(i * sizeof(char));
    cor->corC[0] = '\0';
    strcpy(cor->corC, corContorno);
    cor->id = id;
    return cor;
}
int getCorId(Cor cor){
    cores *corAux = (cores*) cor;
    return corAux->id;
}

char *getCorP(Cor cor){
    cores *corAux = (cores*) cor;
    return corAux->corP;
}

void setCorP(Cor cor, char *corPreenchimento){
  int i;
  cores *corAux = (cores*) cor;
  if(corAux->corP!=NULL){
    free(corAux->corP);
    corAux->corP = NULL;
  }
  i = strlen(corPreenchimento) + 1;
  corAux->corP = (char*) malloc(i * sizeof(char));
  corAux->corP[0]='\0';
  strcpy(corAux->corP, corPreenchimento);
}

char *getCorC(Cor cor){
    cores *corAux = (cores*) cor;
    return corAux->corC;
}

void setCorC(Cor cor, char *corContorno){
  int i;
  cores *corAux = (cores*) cor;
  if(corAux->corC!=NULL){
    free(corAux->corC);
    corAux->corC = NULL;
  }
  i = strlen(corContorno) + 1;
  corAux->corC = (char*) malloc(i * sizeof(char));
  corAux->corC[0]='\0';
  strcpy(corAux->corC, corContorno);
}

void resetarCores(Cor cor){
  cores *corAux = (cores*) cor;
  if(corAux->corC!=NULL){
    free(corAux->corC);
    corAux->corC = NULL;
  }
  if(corAux->corP!=NULL){
    free(corAux->corP);
    corAux->corP = NULL;
  }
}

void removeCor(Cor cor){
  cores *corAux = (cores*) cor;
  if(corAux != NULL){
    free(corAux->corC);
    free(corAux->corP);
    free(corAux);
    free(cor);
  }
}
