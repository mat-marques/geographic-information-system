#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "List.h"

typedef void* HashTable;
typedef void* itemHT;

/*
   Autor: Matheus Augusto Marques.
   Tad HashTable:
   Uma tabela de espalhamento associa (mapeia) chaves de busca a valores.
   Uma tabela de espalhamento não contém chaves duplicadas. Cada chave
   pode ser mapeada a um único valor. O valor é um registro contendo, pelo
   menos, um campo ch – a chave do registro. Uma tabela de espalhamento
   possui uma capacidade inicial de armazenamento, definida no momento de
   sua criação.
 */


/*
   Cria e retorna uma tabela de espalhamento com n posições.
 */
HashTable createHT(unsigned int n);

/*
   A função aumenta o tamanho da hash.
   n deve ser maior que o tamanho atual da hash.
   Retorna 1 caso a operação foi realizada com sucesso ou retorna 0 se a operação falhou.
 */
int increaseHT(HashTable hash, unsigned int n);

/*
   A função retorna o tamanho atual da hash.
 */
unsigned int lenghtHT(HashTable hash);

/*
   A função insere um dado do tipo Item na chave configurada como key na hash.
   Retorna 1 caso a operação foi realizada com sucesso ou retorna 0 se a operação falhou.
 */
int insertHT(HashTable hash, char *key, itemHT item);

/*
   A função remove um Item contido na chave key. A função de nome function é utilizada para encontrar o Item dentro da hash.
   Se o Item existe na hash, então ele será removido da hash e retornado ao usuário.
 */
itemHT removeHT(HashTable hash, char *key, itemHT item, compareToL function);

/*
   A função remove um Item contido na hash. A função de nome function é utilizada para encontrar o Item dentro da hash.
   Se o Item existe na hash, então ele será removido da hash e retornado ao usuário.
 */
itemHT removeHT2(HashTable hash, itemHT item, compareToL function);

/*
 A função verifica se item existe na chave de nome key dentro de hash. A função de nome function é utilizada para comparar os item dentro da hash.
 Caso o elemento exista, então o mesmo e retornado ao usuário. Caso não exista é retornado null.
 */
itemHT itemIsInsideHT(HashTable hash, char *key, itemHT item, compareToL function);

/*
  A função retorna uma lista existente na posição da chave key. A lista é utilizada para armazenar os possíveis conflitos na inserção de um Item com uma dada chave (key).
  Retorna null caso a chave (Key) não exista na hash.
 */
List getHtList(HashTable hash, char *key);

/*
  A função remove uma lista existente na chave key. A lista é utilizada para armazenar os possíveis conflitos na inserção de um Item com uma dada chave (key).
  Retorna uma List. Retorna null caso a chave (Key) não exista na hash.
 */
List removeHtList(HashTable hash, char *key);

/*
  O procedimento apaga todos os dados dentro da hash. A funçao nomeada como function é utilizada para remover os dados armazenados na hash.
 */
void eraseHT(HashTable hash, eraseItemL function);

#endif
