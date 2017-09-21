#ifndef DOUBLLELINKEDLIST_H
#define DOUBLLELINKEDLIST_H
#include <stdio.h>
typedef void* List;
typedef void* Item;
typedef void(*eraseItemDLL)(Item item);

List createDLL();


int lengthDLL(List list);


int insertBeginDLL(List list, int id, Item item);


int insertEndDLL(List list, int id, Item item);


int insertMiddleDLL(List list, int id, int p, Item item);


int removeBeginDLL(List list, eraseItemDLL func);


int removeEndDLL(List list, eraseItemDLL func);


int removeMiddleDLL(List list, int p, eraseItemDLL func);


Item searchItemDLL(List list, int id);


Item getBeginItemDLL(List list);


Item getEndItemDLL(List list);


Item getItemDLL(List list, int p);


int eraseListDLL(List list, eraseItemDLL func);

#endif
