#ifndef ESTABELECIMENTOCOMERCIAL_H
#define ESTABELECIMENTOCOMERCIAL_H

#include "Endereco.h"

typedef void* EstabC;
/*
   Autor: Matheus Augusto Marques.
   Tad Estabelecimento Comercial:
   Um estabelecimento comercial é definido por tipo, endereço, cnpj e nome.
   O dado tipo define o tipo do estabelecimento comercial.
   O dado endereço define onde no espaço o estabelecimento comercial se encontra.
   O dado cnpj é um registro único e exclusivo para cada estabelecimento comercial.
   O dado nome define o nome do estabelecimento comercial.
 */

/*
  Cria e retorna um estabelecimento comercial com as configurações de tipo, cep, face, num, cnpj e nome.
 */
EstabC criaEstabC(char *codt, char *cep, char face, int num, char *cnpj, char *nome);

/*
   A função retorna o tipo do estabelecimento comercial.
 */
char *getCodt(EstabC estabC);

/*
   O procedimento define o tipo do estabelecimento comercial.
 */
void setCodt(EstabC estabC, char *codt);

/*
   A função retorna a descrição do estabelecimento comercial.
 */
char *getDescription(EstabC estabC);

/*
   O procedimento define uma descrição para um estabelecimento comercial.
 */
void setDescription(EstabC estabC, char *description);

/*
   A função retorna o cnpj do estabelecimento comercial.
 */
char *getCnpj(EstabC estabC);

/*
   O procedimento define um novo cnpj para um estabelecimento comercial.
 */
void setCnpj(EstabC estabC, char *cnpj);

/*
   A função retorna o nome do estabelecimento comercial.
 */
char *getNomeEstabC(EstabC estabC);

/*
   O procedimento define um novo nome para um estabelecimento comercial.
 */
void setNomeEstabC(EstabC estabC, char *nome);

/*
   A função retorna o endereço do estabelecimento comercial.
 */
Endereco getEnderecoEstabC(EstabC estabC);

/*
   O procedimento define um novo endereço para um estabelecimento comercial.
 */
void setEnderecoEstabC(EstabC estabC, Endereco endereco);

/*
   A função verifica se o cnpj de um estabelecimento comercial é igual ao cnpj contido na variável cnpj.
   Retorna 1 se forem iguais e 0 se forem diferentes.
 */
int compareEstabC(EstabC estabC1, void* cnpj);

/*
   Apaga todos os dados de um estabelecimento comercial.
 */
void removeEstabC(EstabC estabC);

#endif
