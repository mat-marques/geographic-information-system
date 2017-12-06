#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstabelecimentoComercial.h"
#include "StringO.h"

typedef struct Ecomercial {
  char *codt, *cnpj, *nome, *description;
  Endereco endereco;
} Ecomercial;



EstabC criaEstabC(char *codt, char *cep, char *face, char *num, char *cnpj,
                   char *nome) {
  char comp[] = "none";
  Ecomercial *ecomercial = NULL;
  ecomercial = (Ecomercial *)malloc(sizeof(Ecomercial));

  ecomercial->nome = criarString(nome);

  ecomercial->codt = criarString(codt);

  ecomercial->description = NULL;

  ecomercial->endereco = criaEndereco(cep, face, num, comp);

  return ecomercial;
}


char *getCodt(EstabC estabC){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  return ecomercial->codt;
}


void setCodt(EstabC estabC, char *codt){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  if(ecomercial->codt != NULL){
    free(ecomercial->codt);
    ecomercial->codt = NULL;
  }
  ecomercial->codt = criarString(codt);
}


char *getDescription(EstabC estabC){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  return ecomercial->description;
}


void setDescription(EstabC estabC, char *description){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  if(ecomercial->description != NULL){
    free(ecomercial->description);
    ecomercial->description = NULL;
  }
  ecomercial->description = criarString(description);
}


char *getCnpj(EstabC estabC){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  return ecomercial->cnpj;
}


void setCnpj(EstabC estabC, char *cnpj){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  if(ecomercial->cnpj != NULL){
    free(ecomercial->cnpj);
    ecomercial->cnpj = NULL;
  }
  ecomercial->cnpj = criarString(cnpj);
}


char *getNomeEstabC(EstabC estabC){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  return ecomercial->nome;
}


void setNomeEstabC(EstabC estabC, char *nome){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  if(ecomercial->nome != NULL){
    free(ecomercial->nome);
    ecomercial->nome = NULL;
  }
  ecomercial->nome = criarString(nome);
}


Endereco getEnderecoEstabC(EstabC estabC){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  return ecomercial->endereco;
}

void setEnderecoEstabC(EstabC estabC, Endereco endereco){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  if(ecomercial->endereco != NULL){
    removeEndereco(ecomercial->endereco);
    ecomercial->endereco = NULL;
  }
  ecomercial->endereco = endereco;
}


int compareEstabC(EstabC estabC1, EstabC estabC2){
  Ecomercial *ecomercial = (Ecomercial*) estabC1;
  char *codt = (char*) estabC2;
  if(strcmp(ecomercial->codt, codt) == 0){
    return 1;
  }
  return 0;
}


void removeEstabC(EstabC estabC){
  Ecomercial *ecomercial = (Ecomercial*) estabC;
  free(ecomercial->cnpj);
  free(ecomercial->codt);
  free(ecomercial->description);
  free(ecomercial->nome);
  removeEndereco(ecomercial->endereco);
  free(ecomercial);
}
