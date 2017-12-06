#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "List.h"

typedef void* HashTable;
typedef void* itemHT;

HashTable createHT(unsigned int n);


int increaseHT(HashTable hash, unsigned int n);


unsigned int lenghtHT(HashTable hash);


int insertHT(HashTable hash, char *key, itemHT item);


itemHT removeHT(HashTable hash, char *key, itemHT item, compareToL function);


itemHT itemIsInsideHT(HashTable hash, char *key, itemHT item, compareToL function);


List getHtList(HashTable hash, char *key);


List removeHtList(HashTable hash, char *key);


void eraseHT(HashTable hash, eraseItemL function);

#endif
