#ifndef DICIONARIO_H
#define DICIONARIO_H

#include "HashTable.h"
#include "List.h"

typedef void* Dicionario;

Dicionario criaDicionario(int tamanho);


void insertSecaoDicionario(Dicionario dicionario, char *nome, int tamanhoS);


int qtdSecoes(Dicionario dicionario);


HashTable getSecaoDicionario(Dicionario dicionario, char *nome);


HashTable removeSecaoDicionario(Dicionario dicionario, char *nome);


void removeDicionario(Dicionario dicionario);

#endif
