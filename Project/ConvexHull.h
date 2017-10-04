#ifndef CONVEXHULL_H
#define CONVEXHULL_H
#include "Stack.h"
#include "DoubleLinkedList.h"
typedef void* Vector;
typedef void (*eraseElement)(void*);

Vector listToVector(List list, int typeOfList);

Stack convexHullOfElements(List list, int typeOfList) ;

void convexHull(void *vetor, int n, List listConvex, List listPi);

#endif
