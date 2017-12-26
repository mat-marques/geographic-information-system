#ifndef MORADOR_H
#define MORADOR_H

#include "Endereco.h"
typedef void* Morador;

/*
   Autor: Matheus Augusto Marques.
   Tad Morador:
   Um morador é um dado que representa um morador de uma cidade. Um morador é defino por um cpf e um endereco.
 */

/*
   Cria e retorna um morador definido por cpf e endereco.
 */
Morador criaMorador(char *cpf, Endereco endereco);

/*
   A função retorna o cpf de um morador.
 */
char *getCpfM(Morador morador);

/*
   O procedimento define um novo cpf para um morador.
 */
void setCpfM(Morador morador, char *cpf);

/*
   A função retorna o endereco de um morador.
 */
Endereco getEndereco(Morador morador);

/*
   O procedimento define um novo endereco para um morador.
 */
void setEndereco(Morador morador, Endereco endereco);

/*
   A função verifica se um morador tem o valor de seu cpf igual ao valor na variável cpf.
   Retorna 1 se forem iguais e 0 se forem diferentes.
 */
int compareMorador(Morador morador, void *cpf);

/*
   O procedimento apaga todos os dados de um morador.
 */
void removeMorador(Morador morador);

#endif
