#ifndef PESSOA_H
#define PESSOA_H

#include "Endereco.h"
#include "Celular.h"

typedef void* Pessoa;
/*
   Autor: Matheus Augusto Marques.
   Tad Pessoa:
   O Tad modela uma pessoa. Uma pessoa é definida por um cpf, nome, sobrenome, sexo e data de nascimento. Pode ter opcionalmente um celular e um endereço.
 */

/*
   A função cria uma pessoa.
   Todos os parametros da função devem ter significado.
 */
Pessoa criaPessoa(char *cpf, char *nome, char *sobrenome, char *sexo, char *nasc);

/*
   A função retorna o cpf da pessoa.
 */
char *getCpf(Pessoa pessoa);

/*
   O procedimento define o cpf de uma pessoa.
 */
void setCpf(Pessoa pessoa, char *cpf);

/*
   A função retorna o primeiro nome de uma pessoa.
 */
char *getNomeP(Pessoa pessoa);

/*
   O procedimento define o primeiro nome de uma pessoa.
 */
void setNomeP(Pessoa pessoa, char *nome);

/*
   A função retorna o sobrenome de uma pessoa.
 */
char *getSobrenome(Pessoa pessoa);

/*
   O procedimento define o sobrenome de uma pessoa.
 */
void setSobrenome(Pessoa pessoa, char *sobrenome);

/*
   A função retorna o sexo de uma pessoa.
 */
char *getSexo(Pessoa pessoa);

/*
   O procedimento define o sexo de uma pessoa.
 */
void setSexo(Pessoa pessoa, char *sexo);

/*
   A função retorna a data de nascimento de uma pessoa.
 */
char *getNasc(Pessoa pessoa);

/*
   O procedimento define a data de nascimento de uma pessoa.
 */
void setNasc(Pessoa pessoa, char *nasc);

/*
   A função retorna o endereço de onde a pessoa mora.
   Retorna Null caso a pessoa não tenha endereço
 */
Endereco getEnderecoP(Pessoa pessoa);

/*
   O procedimento define o endereço de uma pessoa.
 */
void setEnderecoP(Pessoa pessoa, Endereco endereco);

/*
   A função retorna o celular de uma pessoa.
   Retorna Null caso a pessoa não tenha celular.
 */
Celular getCelular(Pessoa pessoa);

/*
   O procedimento define o celular de uma pessoa.
 */
void setCelular(Pessoa pessoa, Celular celular);

/*
   A função verifica se pessoa1 tem o mesmo valor do dado cpf em relação a variável cpf.
   Retorna 1 se forem igauis ou 0 se forem diferentes.
 */
int comparePessoas(Pessoa pessoa1, void* cpf);

/*
   O procedimento apaga os dados de uma pessoa.
 */
void removePessoa(Pessoa pessoa);

#endif
