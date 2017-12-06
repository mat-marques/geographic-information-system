#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
  char *key;
  List list;
} Element;

typedef struct hash {
  unsigned int hashLenght, HASHSIZE;
  Element *array;
} Hash;

HashTable createHT(unsigned int n) {
  Hash *hBase;
  Element *vector;
  unsigned int i = 0;
  hBase = (Hash *)malloc(sizeof(Hash));
  if (hBase != NULL) {
    hBase->hashLenght = 0;
    hBase->HASHSIZE = n;
    vector = (Element *)malloc(n * sizeof(Element));
    if (vector != NULL) {
      hBase->array = vector;
      for (i = 0; i < n; i++) {
        vector[i].key = NULL;
        vector[i].list = NULL;
      }
    }
  }
  return hBase;
}


unsigned int hashingFunction(char *p, unsigned int hSize) {
  /* Função interna para calcular o espalhamento da hashTable. */
  unsigned int i = 0, l = 0, h = *(p + i);
  l = strlen(p);
  for (i = 0; i < l; i++) {
    h = ((h * 251) + *(p + i)) % hSize;
  }
  return h;
}


int increaseHT(HashTable hash, unsigned int n) {
  Hash *hBase = (Hash *)hash;
  Element *vector;
  Element *aux;
  unsigned int i, h;
  if (n > hBase->HASHSIZE) {

    vector = (Element *)malloc(n * sizeof(Element));

    for (i = 0; i < n; i++) {
      vector[i].key = NULL;
      vector[i].list = NULL;
    }

    aux = hBase->array;
    for (i = 0; i < hBase->HASHSIZE; i++) {
      if (aux[i].key != NULL) {
        h = hashingFunction(aux[i].key, n);
        vector[h].key = aux[i].key;
        vector[h].list = aux[i].list;
      }
    }

    free(hBase->array);
    hBase->array = vector;
    hBase->HASHSIZE = n;
    return 1;
  }
  return 0;
}


unsigned int lenghtHT(HashTable hash) {
  Hash *hBase = (Hash *)hash;
  if (hBase != NULL) {
    return hBase->hashLenght;
  }
  return 0;
}


int insertHT(HashTable hash, char *key, itemHT item) {
  Hash *hBase = (Hash *)hash;
  unsigned int h;
  int l;
  Element *aux = hBase->array;
  h = hashingFunction(key, hBase->HASHSIZE);

  if (aux[h].key != NULL) {
    insertEndL(aux[h].list, item);
  } else {
    l = strlen(key) + 1;
    aux[h].key = (char *)malloc(l * sizeof(char));
    aux[h].key[0] = '\0';
    strcat(aux[h].key, key);
    aux[h].list = createL();
    insertEndL(aux[h].list, item);
  }

  return 0;
}


itemHT removeHT(HashTable hash, char *key, itemHT item, compareToL function) {
  Hash *hBase = (Hash *)hash;
  itemHT itemS = NULL;
  Element *aux = hBase->array;
  unsigned int h;

  h = hashingFunction(key, hBase->HASHSIZE);

  if (aux[h].key != NULL) {
    itemS = removeItemL2(aux[h].list, item, function);
  }

  return itemS;
}


itemHT itemIsInsideHT(HashTable hash, char *key, itemHT item,
                      compareToL function) {
  Hash *hBase = (Hash *)hash;
  itemHT itemS = NULL;
  Element *aux = hBase->array;
  unsigned int h;

  h = hashingFunction(key, hBase->HASHSIZE);

  if (aux[h].key != NULL) {
    itemS = searchItemL(aux[h].list, item, function);
  }

  return itemS;
}


List getHtList(HashTable hash, char *key) {
  Hash *hBase = (Hash *)hash;
  Element *aux = hBase->array;
  unsigned int h;

  h = hashingFunction(key, hBase->HASHSIZE);

  if (aux[h].key != NULL) {
    return aux[h].list;
  }

  return NULL;
}


List removeHtList(HashTable hash, char *key) {
  Hash *hBase = (Hash *)hash;
  Element *aux = hBase->array;
  List list;
  unsigned int h;

  h = hashingFunction(key, hBase->HASHSIZE);

  if (aux[h].key != NULL) {
    list = aux[h].list;
    free(aux[h].key);
    aux[h].key = NULL;
    aux[h].list = NULL;
    return list;
  }
  return NULL;
}


void eraseHT(HashTable hash, eraseItemL function) {
  Hash *hBase = (Hash *)hash;
  unsigned int i;
  Element *aux = hBase->array;
  for (i = 0; i < hBase->HASHSIZE; i++) {
    if(aux[i].key != NULL){
      free(aux[i].key);
      eraseListL(aux[i].list, function);
      eraseBase(aux[i].list);
    }
  }
  free(aux);
  free(hBase);
  hash = NULL;
}
