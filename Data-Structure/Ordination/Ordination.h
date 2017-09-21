#ifndef ORDINATION_H
#define ORDINATION_H
#include <stdio.h>

/**
Autor: Matheus Augusto Marques.
Módulo Ordination(Ordenação).
Definição:
*/

typedef int(*compareTo)(void*, int, void*, int);
typedef void*(*allocateData)(int);
typedef void(*deallocateData)(void*);
typedef void(*attribution)(void*, int, void*, int);

void mergeSort(void *vector, int begin, int end, allocateData func1, deallocateData func2, compareTo func3, attribution func4);

void quickSort(void *vector, int begin, int end, allocateData  func1, deallocateData  func2, compareTo func3, attribution func4);

void heapSort(void *vector, int N, allocateData  func1, deallocateData  func2,
compareTo func3, attribution func4);

#endif
