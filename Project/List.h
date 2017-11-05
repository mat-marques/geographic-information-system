#ifndef DOUBLLELINKEDLIST_H
#define DOUBLLELINKEDLIST_H
#include <stdio.h>
typedef void* List;
typedef void* Item;
typedef void* Posic;
typedef void(*eraseItemL)(Item);
typedef void(*showLI)(Item);
typedef int(*compareToL)(Item, Item);


/**
Autor: Matheus Augusto Marques.
 Tad: Lista duplamente encadeada(Double Linked List).
Definição:
Uma lista é uma coleção ordenada de itens em que seus elementos podem
ser acessados através de sua posição (tipo Posic). Uma lista sem nenhum
elemento (comprimento 0) é denominada lista vazia.
*/

/*
A função cria uma lista vazia.
Possui comprimento zero.
*/
List createL();

/*
A função retorna um inteiro. Esse inteiro representa a quantidade de elemento de uma lista.
*/
int lengthL(List list);

/*
Retorna 1 se a lista estiver vazia e 0 caso a lista não seja vazia.
*/
int isEmpty(List L);

/*
insere o item info no final da lista L. O comprimento da
lista é acrescido de 1 elemento. Retorna um indicador para o elemento
acrescentado.
*/
Posic insertL(List L, Item info);

/*

Remove o elemento da lista indicado por p. O
comprimento da lista é diminuído em 1 elemento. O indicador p deixa de
indicar um elemento válido de L.
O indicador p deve indicar um elemento existente na lista.
*/
void removeItemL(List L, Posic p);

/*
Retorna o valor do item da lista indicado por p.
O indicador p deve indicar um elemento existente na lista.
*/
Item get(List L, Posic p);

/*
insere o item info na posição imediatamente anterior ao
item indicado por p. O comprimento da lista é acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado.
O indicador p deve indicar um elemento existente na lista.
*/
Posic insertBefore(List L, Posic p, Item info);

/*
Insere o item info na posição imediatamente posterior ao
item indicado por p. O comprimento da lista é acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado.
O indicador p deve indicar um elemento existente na lista.
*/
Posic insertAfter(List L, Posic p, Item info);

/*
Retorna o indicador do primeiro elemento de L. Se
length(L)=0, retorna NULL.
*/
Posic getFirst(List L);

/*
Retorna o indicador do elemento de L seguinte ao elemento
indicado por p. Se p for o último elemento da lista, retorna NULL.
O indicador p deve indicar um elemento existente na lista.
*/
Posic getNext(List L, Posic p);

/*
Retorna o indicador do último elemento de L. Se
length(L)=0, retorna NULL.
*/
Posic getLast(List L);

/*
Retorna o indicador do elemento de L anterior ao elemento
indicado por p. Se p for o primeiro elemento da lista, retorna NULL.
O indicador p deve indicar um elemento existente na lista.
*/
Posic getPrevious(List L, Posic p);




/*
A função insere um item no inicio de uma lista.
Retorna 1 se a inserção ocorreu corretamente e 0 caso contrário.
*/
int insertBeginL(List list, Item item);


/*
A função insere um item no final de uma lista.
Retorna 1 se a inserção ocorreu corretamente e 0 caso contrário.
*/
int insertEndL(List list, Item item);


/*
A função insere um item na posição p de uma lista.
p deve ser maior que zero.
Retorna 1 se a inserção ocorreu corretamente e 0 caso contrário.
*/
int insertMiddleL(List list, int p, Item item);


/*
A função selecionada cada elemento da lista por vez e aplica esse elemento na
função func.
A função func deve ser implementada pelo usúario. Seu objetivo é , primordialmente, mostrar na tela um determinado item da lista.
*/
void showL(List list, showLI func);


/*
A função procura e retorna um Item contido em list. A função de comparação de Itens deve ser implementada pelo usuário. Retorna NULL caso Item não exista em list.
func != NULL.
*/
Item searchItemL(List list, Item item, compareToL func);

/*
A função remove um nó de list. A função de comparação de Itens deve ser implementada pelo usuário. Retorna NULL caso o Item não exista em list e retorna o Item caso contrário.
func != NULL.
*/
Item removeItemL2(List list, Item item, compareToL func);

/*
A função remove um nó de list na primeira posição. A função de remoção (func) deve ser implementada pelo usuário. func = NULL caso não se queira eliminar o Item no nó removido.
Retorna 1 caso a remoção foi realizada com sucesso e 0 caso contrário.
*/
int removeBeginL(List list, eraseItemL func);

/*
A função remove um nó de list na última posição. A função de remoção (func) deve ser implementada pelo usuário. func = NULL caso não se queira eliminar o Item no nó removido.
Retorna 1 caso a remoção foi realizada com sucesso e 0 caso contrário.
*/
int removeEndL(List list, eraseItemL func);

/*
A função remove um nó de list na posição p (p>0). A função de remoção (func) deve ser implementada pelo usuário. func = NULL caso não se queira eliminar o Item no nó removido.
Retorna 1 caso a remoção foi realizada com sucesso e 0 caso contrário.
*/
int removeMiddleL(List list, int p, eraseItemL func);


/*
A função retorna um Item contido em list. Esse Item está , precisamente, no inicio de list.
Retorna null caso list for vazia.
*/
Item getBeginItemL(List list);


/*
A função retorna um Item contido em list. Esse Item está , precisamente, no final de list.
Retorna null caso list for vazia.
*/
Item getEndItemL(List list);


/*
A função retorna um Item contido em list na posição p.
Retorna NULL caso p seja inválido.
p > 0.
*/
Item getItemL(List list, int p);


/*
A função concatena duas listas.
listTwo será inserida no final de listOne.
*/
void concatL(List listOne, List listTwo);


/*
O procedimento apaga a base da lista.
*/
void eraseBase(List list);


/*
O procedimento apaga todos os nós da lista. A função utilizada para apagar os Itens de list deve ser implementada pelo usuário. Caso não se queira apagar os Itens func deve receber NULL.
*/
int eraseListL(List list, eraseItemL func);


#endif
