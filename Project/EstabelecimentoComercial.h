#ifndef ESTABELECIMENTOCOMERCIAL_H
#define ESTABELECIMENTOCOMERCIAL_H

#include "Endereco.h"

typedef void* EstabC;
/*
Autor: Matheus Augusto Marques.

*/


EstabC criaEstabC(char *codt, char *cep, char face, int num, char *cnpj, char *nome);


char *getCodt(EstabC estabC);


void setCodt(EstabC estabC, char *codt);


char *getDescription(EstabC estabC);


void setDescription(EstabC estabC, char *description);


char *getCnpj(EstabC estabC);


void setCnpj(EstabC estabC, char *cnpj);


char *getNomeEstabC(EstabC estabC);


void setNomeEstabC(EstabC estabC, char *nome);


Endereco getEnderecoEstabC(EstabC estabC);


void setEnderecoEstabC(EstabC estabC, Endereco endereco);


int compareEstabC(EstabC estabC1, void* cnpj);


void removeEstabC(EstabC estabC);

#endif
