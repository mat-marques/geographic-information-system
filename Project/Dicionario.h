#ifndef DICIONARIO_H
#define DICIONARIO_H

#include "HashTable.h"
#include "List.h"

typedef void* Dicionario;

/*
   Autor: Matheus Augusto Marques.
   Tad Dicionario:
   Um dicionário é um tipo de dado que tem a função de abrigar um conjunto de tabelas de espalhamento. Um dicionário é definido pela quantidade de tabelas de espalhamento que terão em seu interior. Cada tabela de espelhamento do dicionário representa uma seção do mesmo. Cada seção posui um nome e uma quantidade de páginas.
 */

/*
   Cria e retorna um dicionário de tamanho especificado pela variável tamanho.
 */
Dicionario criaDicionario(int tamanho);

/*
   O procedimento insere no dicionario uma nova seção. Uma seção possui um nome e também uma quantidade de páginas.
 */
void insertSecaoDicionario(Dicionario dicionario, char *nome, int tamanhoS);

/*
   A função retorna a quantidade de seções dentro do dicionário.
 */
int qtdSecoes(Dicionario dicionario);

/*
   A função retorna uma seção identificada pelo nome dentro do dicionário.
   Se o nome da seção não existir no dicionário será retornado Null.
 */
HashTable getSecaoDicionario(Dicionario dicionario, char *nome);

/*
   A função remove uma seção identificada pelo nome de dentro do dicionário.
   Se o nome da seção não existir no dicionário será retornado Null.
 */
HashTable removeSecaoDicionario(Dicionario dicionario, char *nome);

/*
   O procedimento apaga todos os dados de um dicionário.
 */
void removeDicionario(Dicionario dicionario);

#endif
