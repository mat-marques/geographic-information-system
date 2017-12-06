#ifndef PESSOA_H
#define PESSOA_H

#include "Endereco.h"
#include "Celular.h"

typedef void* Pessoa;
/*
Autor: Matheus Augusto Marques.

*/

Pessoa criaPessoa(char *cpf, char *nome, char *sobrenome, char *sexo, char *nasc);

char *getCpf(Pessoa pessoa);


void setCpf(Pessoa pessoa, char *cpf);


char *getNomeP(Pessoa pessoa);


void setNomeP(Pessoa pessoa, char *nome);


char *getSobrenome(Pessoa pessoa);


void setSobrenome(Pessoa pessoa, char *sobrenome);


char *getSexo(Pessoa pessoa);


void setSexo(Pessoa pessoa, char *sexo);


char *getNasc(Pessoa pessoa);


void setNasc(Pessoa pessoa, char *nasc);


Endereco getEnderecoP(Pessoa pessoa);


void setEnderecoP(Pessoa pessoa, Endereco endereco);


Celular getCelular(Pessoa pessoa);


void setCelular(Pessoa pessoa, Celular celular);


int comparePessoas(Pessoa pessoa1, void* cpf);


void removePessoa(Pessoa pessoa);

#endif
