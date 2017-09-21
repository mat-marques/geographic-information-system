#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>

typedef void* Queue;
typedef void* Item;
typedef void(*eraseItemQ)(Item);


Queue createQueue();


int lengthQueue(Queue queue);


int insertItemQ(Queue queue, int id, Item item);


int insertPriorityItemQ(Queue queue, int id, Item item);


int removeFirstItemQ(Queue queue, eraseItemQ func);


int removeItemQ(Queue queue, int p, eraseItemQ func);


Item getFirstItemQ(Queue queue);


Item compareFirstItemIdQ(Queue queue, int id);


int eraseQueue(Queue queue, eraseItemQ func);

#endif
