#ifndef CONVEXHULL_H
#define CONVEXHULL_H
#include "Stack.h"
#include "DoubleLinkedList.h"
typedef void* Vector;

Vector listToVector(List list, int typeOfList);

Stack convexHullOfAll(List list, int typeOfList) ;

void convexHull(void *vetor, int n, List listConvex, List listPi);

List createListPoints(double x, double y, double r);

void generateConvexHullT(List list, FILE *file);

double areaConvexHull(List list);

#endif
