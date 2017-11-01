#ifndef DOUBLLELINKEDLIST_H
#define DOUBLLELINKEDLIST_H
#include <stdio.h>
typedef void* List;
typedef void* Item;
typedef void(*eraseItemDLL)(Item);
typedef void(*showDLLI)(Item);
typedef int(*compareToDLL)(Item, Item);


/**
Autor: Matheus Augusto Marques.
 Tad: Lista duplamente encadeada(Double Linked List).
Definição:
Uma lista é uma coleção ordenada de itens em que seus elementos podem
ser acessados através de uma posição. A única diferença de uma lista duplamente encadeada  para uma lista normal esta na forma como ocorre sua implementação. Uma lista sem nenhum elemento (comprimento 0) é denominada lista vazia.
*/

/*
A função cria uma lista vazia.
Possui comprimento zero.
*/
List createDLL();


/*
A função retorna um inteiro. Esse inteiro representa a quantidade de elemento de uma lista.
*/
int lengthDLL(List list);


/*
A função insere um item no inicio de uma lista.
Retorna 1 se a inserção ocorreu corretamente e 0 caso contrário.
*/
int insertBeginDLL(List list, Item item);


/*
A função insere um item no final de uma lista.
Retorna 1 se a inserção ocorreu corretamente e 0 caso contrário.
*/
int insertEndDLL(List list, Item item);


/*
A função insere um item na posição p de uma lista.
p deve ser maior que zero.
Retorna 1 se a inserção ocorreu corretamente e 0 caso contrário.
*/
int insertMiddleDLL(List list, int p, Item item);


/*
A função selecionada cada elemento da lista por vez e aplica esse elemento na
função func.
A função func deve ser implementada pelo usúario. Seu objetivo é , primordialmente, mostrar na tela um determinado item da lista.
*/
void showDLL(List list, showDLLI func);


/*
A função procura e retorna um Item contido em list. A função de comparação de Itens deve ser implementada pelo usuário. Retorna NULL caso Item não exista em list.
func != NULL.
*/
Item searchItemDLL(List list, Item item, compareToDLL func);

/*
A função remove um nó de list. A função de comparação de Itens deve ser implementada pelo usuário. Retorna NULL caso o Item não exista em list e retorna o Item caso contrário.
func != NULL.
*/
Item removeItemDLL(List list, Item item, compareToDLL func);

/*
A função remove um nó de list na primeira posição. A função de remoção (func) deve ser implementada pelo usuário. func = NULL caso não se queira eliminar o Item no nó removido.
Retorna 1 caso a remoção foi realizada com sucesso e 0 caso contrário.
*/
int removeBeginDLL(List list, eraseItemDLL func);

/*
A função remove um nó de list na última posição. A função de remoção (func) deve ser implementada pelo usuário. func = NULL caso não se queira eliminar o Item no nó removido.
Retorna 1 caso a remoção foi realizada com sucesso e 0 caso contrário.
*/
int removeEndDLL(List list, eraseItemDLL func);

/*
A função remove um nó de list na posição p (p>0). A função de remoção (func) deve ser implementada pelo usuário. func = NULL caso não se queira eliminar o Item no nó removido.
Retorna 1 caso a remoção foi realizada com sucesso e 0 caso contrário.
*/
int removeMiddleDLL(List list, int p, eraseItemDLL func);


/*
A função retorna um Item contido em list. Esse Item está , precisamente, no inicio de list.
Retorna null caso list for vazia.
*/
Item getBeginItemDLL(List list);


/*
A função retorna um Item contido em list. Esse Item está , precisamente, no final de list.
Retorna null caso list for vazia.
*/
Item getEndItemDLL(List list);


/*
A função retorna um Item contido em list na posição p.
Retorna NULL caso p seja inválido.
p > 0.
*/
Item getItemDLL(List list, int p);


/*
A função concatena duas listas.
listTwo será inserida no final de listOne.
*/
void concatDLL(List listOne, List listTwo);


/*
O procedimento apaga a base da lista.
*/
void eraseBase(List list);


/*
O procedimento apaga todos os nós da lista. A função utilizada para apagar os Itens de list deve ser implementada pelo usuário. Caso não se queira apagar os Itens func deve receber NULL.
*/
int eraseListDLL(List list, eraseItemDLL func);


#endif
