#ifndef CONVEXHULL_H
#define CONVEXHULL_H
#include "Stack.h"
#include "List.h"
typedef void* Vector;

/*
   Autor: Matheus Augusto Marques.
   Módulo ConvexHull(Envoltória convexa).
   Definição: O módulo tem a finalidade de manipular um conjunto de pontos e através dos pontos calcular a área de um polígono a envoltoria convexa.
 */


/*
   Função exclusiva utilizada na criação de envoltórias convexas dos objetos referentes ao projeto desenvolvido. São eles quadras , torres, semafáros, hidrantes, círculos e retângulos.
   Retorna uma pilha que contém os elementos que compõem a envoltória convexa.
   A pilha contém todos os elementos da variável list. Essa função calcula todas as sub-envoltorias de um conjunto de pontos. Desde a maior envoltória até a menor.
   A lista deve ser não vazia.
   O argumento type pode receber um dos seguintes valores:
   O argumento type pode receber um dos seguintes valores:
   1 : Quadra.
   2 : Hidrante.
   3 : Semáfaro.
   4 : Torre.
   5 : Retângulo.
   6 : Círculo;
 */
Stack convexHullOfAll(List list, int type);


/*
   O procedimento manipula um conjunto de torres presentes na variável list.
   Através das propriedades das torres é calculado um polígono de cobertura das torres. Esse polígono é desenhado em um arquivo svg contido na variável file.
   list deve ser não vazia.
   file deve já estar aberto para escrita.
 */
void generateConvexHullT(List list, FILE *file);


/*
   A função calcula e retorna a área de um polígono convexo. A variável list contém um conjunto de pontos que devem formam um polígono convexo.
   list deve ser não vazia.
 */
double areaConvexHull(List list);

#endif
