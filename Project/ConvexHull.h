#ifndef CONVEXHULL_H
#define CONVEXHULL_H
#include "Stack.h"


void *listQ_To_Vector(Stack stack);

void *listH_To_Vector(Stack stack);

void *listS_To_Vector(Stack stack);

void *listT_To_Vector(Stack stack);

void *listR_To_Vector(Stack stack);

void *listC_To_Vector(Stack stack);

Stack convexHull(void *vetor, int n);


#endif
