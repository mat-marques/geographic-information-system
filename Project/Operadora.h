#ifndef OPERADORA_H
#define OPERADORA_H
#include "Pessoa.h"
#include "HashTable.h"
#include "Cliente.h"

typedef void* Operadora;


Operadora criaOperadora(char *nome);


char *getNomeO(Operadora operadora);


void setNomeO(Operadora operadora, char *nome);


int qtdClientes(Operadora operadora);


int insereCliente(Operadora operadora, Cliente cliente);


Cliente removeCliente(Operadora operadora, Cliente cliente);


HashTable getClientes(Operadora operadora);


Cliente getCliente(Operadora operadora, char *cpf);


int compareOperadoras(Operadora operadora1, Operadora operadora2);

void removeOperadora(Operadora operadora);

#endif
