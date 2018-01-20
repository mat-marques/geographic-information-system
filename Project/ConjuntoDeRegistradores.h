#ifndef CONJUNTODEREGISTRADOR_H
#define CONJUNTODEREGISTRADOR_H

#include "Registrador.h"

typedef void* SetOfRegisters;

/*
Autor: Matheus Augusto Marques
Tad: Conjunto de registradores
Definição: Um Conjunto de registradores de registradores é definido por um nome e um conjunto de registradores. A quantidade de registradores é definido por qtdRegisters.
*/

/*
  Cria e retorna um conjunto de registradores definido por name e que possuirá um total de qtdRegisters.
*/
SetOfRegisters createSetOfRegisters(char *name, int qtdRegisters);


/*
  Retorna o nome do conjunto de registradores.
*/
char *getNameSetOfRegisters(SetOfRegisters setOfRegisters);


/*
  Define um novo nome para o conjunto de registradores.
*/
void setNameSetOfRegisters(SetOfRegisters setOfRegisters, char *name);


/*
  Retorna a quantidade que o conjunto de registradores pode armazenar.
*/
int getQtdRegistersTSetOfRegisters(SetOfRegisters setOfRegisters);


/*
  Retorna a quantidade que o conjunto de registradores esta armazenando no momento.
*/
int getQtdRegistersCSetOfRegisters(SetOfRegisters setOfRegisters);


/*
  Insere um novo registrador no conjunto de registradores.
*/
void insertRegister(SetOfRegisters setOfRegisters, Register registerN);


/*
  Busca e retorna um registrador no conjunto de registradores pelo nome.
  Caso o registrador não exista é retornado null.
*/
Register getRegister(SetOfRegisters setOfRegisters, char *name);


/*
  Apaga todos os registradores armazenados no conjunto de registradores.
*/
void removeSetOfRegisters(SetOfRegisters setOfRegisters,  void (removeReg)(void *));

#endif
