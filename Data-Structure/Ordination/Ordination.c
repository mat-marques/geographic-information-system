
#include <stdlib.h>
#include <math.h>
#include "Ordination.h"

typedef int(*compareTo)(void*, int, void*, int);
typedef void*(*allocateData)(int);
typedef void(*deallocateData)(void*);
typedef void(*attribution)(void*, int, void*, int);

void merge(void *vector, int begin, int middle, int end, allocateData func1, deallocateData func2, compareTo func3, attribution func4){
    int p1, p2, sizeV, i, j, k;
    void *vectorAux;
    int end1 = 0, end2 = 0;

    sizeV = end - begin + 1;
    p1 = begin;
    p2 = middle + 1;

    vectorAux = func1(sizeV);

    if(vectorAux!=NULL){
        for(i=0; i<sizeV; i++){
            if(!end1 && !end2){
                if(func3(vector, p1, vector, p2) == -1){
                    func4(vectorAux, i,vector, p1);
                    p1++;
                } else {
                    func4(vectorAux, i, vector, p2);
                    p2++;
                }
                if(p1>middle){
                    end1 = 1;
                }
                if(p2>end){
                    end2 = 1;
                }
            } else {
                if(!end1){
                    func4(vectorAux, i, vector, p1);
                    p1++;
                } else {
                    func4(vectorAux, i, vector, p2);
                    p2++;
                }

            }

        }

        for(j=0, k=begin; j<sizeV; j++, k++){
            func4(vector, k, vectorAux, j);
        }
        func2(vectorAux);
    }

}


void mergeSort(void *vector, int begin, int end, allocateData func1, deallocateData func2, compareTo func3, attribution func4){
    int middle;
    if(begin < end){
        middle = ((begin+end)/2);
        mergeSort(vector, begin, middle, func1, func2, func3, func4);
        mergeSort(vector, middle+1, end, func1, func2, func3, func4);
        merge(vector, begin, middle, end, func1, func2, func3, func4);
    }
}


int partition(void *vector, int begin, int end, allocateData  func1, deallocateData  func2, compareTo func3, attribution func4)
{
    int right, left;
    void *pivot = NULL, *aux = NULL;
    left = begin;
    right = end;
    pivot = func1(1);
    aux = func1(1);
    func4(pivot, 0, vector, begin);

    while(left < right){

        while(func3(pivot, 0, vector, left)<=0){
            left++;
        }
        while(func3(pivot, 0, vector, right)>0){
            right--;
        }
        if(left < right){
            func4(aux, 0, vector, left);
            func4(vector, left, vector, right);
            func4(vector, right, aux, 0);
        }
    }
    func4(vector, begin, vector, right);
    func4(vector, right, pivot, 0);
    func2(pivot);
    func2(aux);
    return right;
}


void quickSort(void *vector, int begin, int end, allocateData  func1, deallocateData  func2, compareTo func3, attribution func4)
{
    int pivot;
    if(end > begin){
        pivot = partition(vector, begin, end, func1, func2, func3, func4);
        quickSort(vector, begin, pivot - 1, func1, func2, func3, func4);
        quickSort(vector, pivot + 1, end, func1, func2, func3, func4);
    }
}


void createHeap(void *vector, int begin, int end, allocateData  func1, deallocateData  func2, compareTo func3, attribution func4)
{
    void *aux = func1(1);
    func4(aux, 0, vector, begin);
    int j = begin * 2 + 1;
    while(j <= end){
        if(j < end){
            if(func3(vector, j, vector, j+1) > 0){
                j++;
            }
        }
        if(func3(aux, 0, vector, j) > 0){
            func4(vector, begin, vector, j);
            begin = j;
            j = 2 * begin + 1;
        } else {
            j = end + 1;
        }
    }
    func4(vector, begin, aux, 0);
    func2(aux);
}


void heapSort(void *vector, int N, allocateData  func1, deallocateData  func2,
compareTo func3, attribution func4){
    int i;
    void *aux;
    for(i=(N-1)/2; i>=0; i--){
        createHeap(vector, i, N-1, func1, func2, func3, func4);
    }
    aux = func1(1);
    for(i = N-1; i>= 1; i--){
        func4(aux, 0, vector, 0);
        func4(vector, 0, vector, i);
        func4(vector, i, aux, 0);
        createHeap(vector, 0, i - 1, func1, func2, func3, func4);
    }
    func2(aux);
}
