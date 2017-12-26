#ifndef ORDINATION_H
#define ORDINATION_H
#include <stdio.h>

/*
   Todos os .c que fação uso do módulo ordination necessitam implementar quatro funções. São elas: compareToOrd, allocateData, deallocateData e attribution.
   O nome utilizado na implementação das funções deve ser diferente dos listados acima.
 */
typedef int (*compareToOrd)(void*, int, void*, int);
typedef void*(*allocateData)(int);
typedef void (*deallocateData)(void*);
typedef void (*attribution)(void*, int, void*, int);



/*
   Autor: Matheus Augusto Marques.
   Módulo ordination(Ordenação).
   Definição: Esse módulo tem por finalidade abrigar alguns algoritmos de ordenação
   que podem eventualmente ser utilizados na resolução de algum problema real. As funções aqui declaradas podem ordenar qualquer tipo de dado. Por isso, se faz necessário o uso de funções como parâmetro.
 */


/*
   A função mergeSort é utilizada para realizar a execução do algoritmo de ordenção merge sort. O merg sort é um tipo de algoritmo de ordenação do tipo dividir-para-conquistar. Essa função ordena qualquer tipo de dados.
   Parâmetros necessários:
   1) um vetor representado por vector.
   2) o inicío do vetor representado por um inteiro.
   3) o fim do vetor representado por um inteiro.
   4) Uma função implementada pelo usúario que aloca espaço de memória do mesmo tipo do vetor.
   5) Uma função implementada pelo usúario que desaloca espaço de memória do mesmo tipo do vetor.
   6) Uma função implementada pelo usúario que compara dois elementos do vetor.
   7) Uma função implementada pelo usúario que atribui o valor de um elemento do vetor a outro elemento do vetor.
 */
void mergeSort(void *vector, int begin, int end, allocateData func1, deallocateData func2, compareToOrd
               func3, attribution func4);

/*
   A função quickSort é utilizada para realizar a execução do algoritmo de ordenção quick sort. O quick sort é um tipo de algoritmo de ordenação do tipo dividir-para-conquistar. Essa função ordena qualquer tipo de dados.
   Parâmetros necessários:
   1) um vetor representado por vector.
   2) o inicío do vetor representado por um inteiro.
   3) o fim do vetor representado por um inteiro.
   4) Uma função implementada pelo usúario que aloca espaço de memória do mesmo tipo do vetor.
   5) Uma função implementada pelo usúario que desaloca espaço de memória do mesmo tipo do vetor.
   6) Uma função implementada pelo usúario que compara dois elementos do vetor.
   7) Uma função implementada pelo usúario que atribui o valor de um elemento do vetor a outro elemento do vetor.
 */
void quickSort(void *vector, int begin, int end, allocateData func1, deallocateData func2, compareToOrd func3, attribution func4);


/*
   A função heapSort é utilizada para realizar a execução do algoritmo de ordenção heap sort. O heap sort é um tipo de algoritmo de ordenação do tipo ordenação por seleção. Essa função ordena qualquer tipo de dados.
   Parâmetros necessários:
   1) um vetor representado por vector.
   2) o tamanho do vetor.
   3) Uma função implementada pelo usúario que aloca espaço de memória do mesmo tipo do vetor.
   4) Uma função implementada pelo usúario que desaloca espaço de memória do mesmo tipo do vetor.
   5) Uma função implementada pelo usúario que compara dois elementos do vetor.
   6) Uma função implementada pelo usúario que atribui o valor de um elemento do vetor a outro elemento do vetor.
 */
void heapSort(void *vector, int N, allocateData func1, deallocateData func2,
              compareToOrd func3, attribution func4);

#endif
