#ifndef DOUBLLELINKEDLIST_H
#define DOUBLLELINKEDLIST_H
#include <stdio.h>
typedef void* List;
typedef void* Item;
typedef void(*eraseItemDLL)(Item);
typedef void(*showDLLI)(Item);
typedef int(*compareToDLL)(Item, Item);

List createDLL();


int lengthDLL(List list);


int insertBeginDLL(List list, Item item);


int insertEndDLL(List list, Item item);

void showDLL(List list, showDLLI func);

int insertMiddleDLL(List list, int p, Item item);


Item searchItemDLL(List list, Item item, compareToDLL func);


Item removeItemDLL(List list, Item item, compareToDLL func);


int removeBeginDLLOne(List list, eraseItemDLL func);


int removeEndDLLOne(List list, eraseItemDLL func);


int removeMiddleDLLOne(List list, int p, eraseItemDLL func);


Item removeBeginDLLTwo(List list);


Item removeEndDLLTwo(List list);


Item removeMiddleDLLTwo(List list, int p);


Item getBeginItemDLL(List list);


Item getEndItemDLL(List list);


Item getItemDLL(List list, int p);


int eraseListDLLOne(List list, eraseItemDLL func);


int eraseListDLLTwo(List list);

#endif
