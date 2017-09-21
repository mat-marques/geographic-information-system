#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
typedef void* List;
typedef void* Item;
typedef void(*eraseItem)(Item);
/**
Autor: Matheus Augusto Marques.
TAD: Simple List.
Definition:

*/

List createListLL();

int insertEndLL(List list, int id, Item item);

int insertBeginLL(List list, int id, Item item);

int insertMiddleLL(List list, int id, int p, Item item);

int removeBeginLL(List list, eraseItem func);

int removeEndLL(List list, eraseItem func);

int removeMiddleLL(List list, int p, eraseItem func);

Item searchIdLL(List list, int id);

Item getBeginItem(List list);

Item getEndItem(List list);

Item getLL(List list, int p);

int lenghtLL(List list);

int eraseListLL(List list, eraseItem func);


#endif
