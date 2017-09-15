#ifndef LISTA_H
#define LISTA_H

typedef void* Lista;
typedef void* Posic;
typedef void* Item;

/**
Autor: Matheus Augusto Marques.
TAD: Lista.
Definição:
Uma lista é uma coleção ordenada de itens em que seus elementos podem
ser acessados através de sua posição (tipo Posic). Uma lista sem nenhum
elemento (comprimento 0) é denominada lista vazia.
O tipo Posic indica a posição de um item dentro da lista. Este tipo possui um valor inválido para qualquer lista. Tal valor inválido é denotado por NULL.
*/

/*
Retorna uma lista vazia.
*/
Lista createLista();

/*
retorna o número de elementos da lista.
*/
int lenght(Lista L);

/*
Retorna 1 se a lista estiver vazia e 0 caso a lista não seja vazia.
*/
int isEmpty(Lista L);

/*
insere o item info no final da lista L. O comprimento da
lista é acrescido de 1 elemento. Retorna um indicador para o elemento
acrescentado.
*/
Posic insert(Lista L, Item info);

/*

Remove o elemento da lista indicado por p. O
comprimento da lista é diminuído em 1 elemento. O indicador p deixa de
indicar um elemento válido de L.
O indicador p deve indicar um elemento existente na lista.
*/
void removeItem(Lista L, Posic p);

/*
Retorna o valor do item da lista indicado por p.
O indicador p deve indicar um elemento existente na lista.
*/
Item get(Lista L, Posic p);

/*
insere o item info na posição imediatamente anterior ao
item indicado por p. O comprimento da lista é acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado.
O indicador p deve indicar um elemento existente na lista.
*/
Posic insertBefore(Lista L, Posic p, Item info);

/*
Insere o item info na posição imediatamente posterior ao
item indicado por p. O comprimento da lista é acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado.
O indicador p deve indicar um elemento existente na lista.
*/
Posic insertAfter(Lista L, Posic p, Item info);

/*
Retorna o indicador do primeiro elemento de L. Se
length(L)=0, retorna NULL.
*/
Posic getFirst(Lista L);

/*
Retorna o indicador do elemento de L seguinte ao elemento
indicado por p. Se p for o último elemento da lista, retorna NULL.
O indicador p deve indicar um elemento existente na lista.
*/
Posic getNext(Lista L, Posic p);

/*
Retorna o indicador do último elemento de L. Se
length(L)=0, retorna NULL.
*/
Posic getLast(Lista L);

/*
Retorna o indicador do elemento de L anterior ao elemento
indicado por p. Se p for o primeiro elemento da lista, retorna NULL.
O indicador p deve indicar um elemento existente na lista.
*/
Posic getPrevious(Lista L, Posic p);

#endif
