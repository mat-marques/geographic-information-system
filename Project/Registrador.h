#ifndef REGISTRADOR_H
#define REGISTRADOR_H

typedef void* Register;

/*
Autor: Matheus Augusto Marques
Tad: Registrador
Definição: Um registrador é definido por um nome e pode armazenar dentro de si uma variável genérica. Sua funcionalidade é armazenar um dado que necessita ser preservado para futuramente ser utilizado para fazer cálculos.
*/

/*
  Cria e retorna um registrador definido por name e info.
*/
Register createRegister(char *name, void *info);


/*
  Retorna o nome do registrador.
*/
char *getNameRegister(Register registerN);


/*
  Define um novo nome para o registrador.
*/
void setNameRegister(Register registerN, char *name);


/*
  Retorna o dado armazenado no registrador.
*/
void *getInfoRegister(Register registerN);


/*
  Define um novo dado para o registrador armazenar.
*/
void setInfoRegister(Register registerN, void *info);


/*
  Compara um registrador pelo nome.
  Retorna:
  1 caso forem iguais ou
  0 caso forem diferentes
*/
int compareRegister(Register registerN, void *name);


/*
  Apaga os dados de um registrador.
*/
void removeRegister(Register registerN, void (removeRegInfo)(void *));

#endif
