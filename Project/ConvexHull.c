#include "Circulo.h"
#include "DoubleLinkedList.h"
#include "Hidrante.h"
#include "Ordination.h"
#include "Quadra.h"
#include "Retangulo.h"
#include "Semafaro.h"
#include "Stack.h"
#include "Torre.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct S {
  void *info;
  double x, y;
} S;

S *p0;

/*Aloca um vetor ou variavel do tipo S. Função necessária para a pilha.*/
void *alocar(int qtd) {
  S *s1 = (S *)malloc(qtd * sizeof(S));
  return s1;
}

/*Desaloca a variavel item. Função necessária para a pilha.*/
void desalocar(void *item) {
  S *s1 = (S *)item;
  free(s1);
}

/*Função que atribui os valores de valor para valor. Função necessária para a
 * pilha.*/
void atribuir(void *valor1, int p1, void *valor2, int p2) {
  S *s1 = (S *)valor1;
  S *s2 = (S *)valor2;
  (s1 + p1)->x = (s2 + p2)->x;
  (s1 + p1)->y = (s2 + p2)->y;
}

/*Encontra o menor elemento dentro de um conjunto de pontos.*/
S *menorPonto(S *s, int qtd) {
  int i;
  double y, x;
  S *s1;
  y = s->y;
  x = s->x;
  for (i = 1; i < qtd; i++) {
    /*Encontra o menor y*/
    if ((s + i)->y < y) {
      y = (s + i)->y;
      x = (s + i)->x;
      s1 = (s + i);
    }
    /*Caso dois pontos tenha o mesmo y, então o ponto que possuir o menor x e
     * selecionado.*/
    if ((s + i)->y == y && (s + i)->x < x) {
      y = (s + i)->y;
      x = (s + i)->x;
      s1 = (s + i);
    }
  }
  /*Coloca o menor ponto no inicio do vetor*/
  x = s1->x;
  y = s1->y;

  s1->x = s->x;
  s1->y = s->y;

  s->x = x;
  s->y = y;

  s1 = s;
  return s1;
}

/*Retorna um elemento abaixo do topo da pilha*/
S *nextToTop(Stack pilha) {
  S *p1 = (S *)removeTopI(pilha);
  S *p2 = (S *)getItemTop(pilha);
  insertTop(pilha, -1, p1);
  return p2;
}

/*Função utilizada para encontra a distancia quadrada de dois pontos*/
int dist(S *p1, S *p2) {
  return (p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y);
}

/*Calcula a orientação de três pontos.*/
double orientation(S *p, S *q, S *r) {
  int val = (q->y - p->y) * (r->x - q->x) - (q->x - p->x) * (r->y - q->y);
  /*Caseo val == 0 os pontos são colineares*/
  if (val == 0) {
    return 0;
  }
  /*caso val > 0 os pontos fazem uma curva para a esquerda.*/
  /*caso val < 0 os pontos fazem uma curva para a direita.*/
  return (val > 0) ? 1 : 2;
}

/*Função utilizada para ordenar o vetor de pontos. Função necessária para o
 * mergeSort.*/
int comparar(void *valor1, int p1, void *valor2, int p2) {
  S *s1 = (S *)valor1;
  S *s2 = (S *)valor2;
  int o = orientation(p0, (s1 + p1), (s2 + p2));
  if (o == 0) {
    return (dist(p0, (s2 + p2)) >= dist(p0, (s1 + p1))) ? -1 : 1;
  }
  return (o == 2) ? -1 : 1;
}

void *listQ_To_Vector(Stack stack) {
  int i, j;
  S *newVector = NULL;
  j = lengthStack(stack);
  newVector = (S *)malloc(j * sizeof(S));
  void *item;
  for (i = 0; i < j; i++) {
    item = removeTopI(stack);
    (newVector + i)->x = getXQ(item);
    (newVector + i)->y = getYQ(item);
    (newVector + i)->info = item;
  }

  return newVector;
}

void *listH_To_Vector(Stack stack){
  int i, j;
  S *newVector = NULL;
  j = lengthStack(stack);
  newVector = (S *)malloc(j * sizeof(S));
  void *item;
  for (i = 0; i < j; i++) {
    item = removeTopI(stack);
    (newVector + i)->x = getXH(item);
    (newVector + i)->y = getYH(item);
    (newVector + i)->info = item;
  }

  return newVector;
}


void *listS_To_Vector(Stack stack){
  int i, j;
  S *newVector = NULL;
  j = lengthStack(stack);
  newVector = (S *)malloc(j * sizeof(S));
  void *item;
  for (i = 0; i < j; i++) {
    item = removeTopI(stack);
    (newVector + i)->x = getXS(item);
    (newVector + i)->y = getYS(item);
    (newVector + i)->info = item;
  }

  return newVector;
}

void *listT_To_Vector(Stack stack){
  int i, j;
  S *newVector = NULL;
  j = lengthStack(stack);
  newVector = (S *)malloc(j * sizeof(S));
  void *item;
  for (i = 0; i < j; i++) {
    item = removeTopI(stack);
    (newVector + i)->x = getXT(item);
    (newVector + i)->y = getYT(item);
    (newVector + i)->info = item;
  }

  return newVector;
}

void *listR_To_Vector(Stack stack){
  int i, j;
  S *newVector = NULL;
  j = lengthStack(stack);
  newVector = (S *)malloc(j * sizeof(S));
  void *item;
  for (i = 0; i < j; i++) {
    item = removeTopI(stack);
    (newVector + i)->x = getRx(item);
    (newVector + i)->y = getRy(item);
    (newVector + i)->info = item;
  }

  return newVector;
}

void *listC_To_Vector(Stack stack){
  int i, j;
  S *newVector = NULL;
  j = lengthStack(stack);
  newVector = (S *)malloc(j * sizeof(S));
  void *item;
  for (i = 0; i < j; i++) {
    item = removeTopI(stack);
    (newVector + i)->x = getCx(item);
    (newVector + i)->y = getCy(item);
    (newVector + i)->info = item;
  }

  return newVector;
}

/*Calcula os vertices do polígono convexo.*/
Stack convexHull(void *vetor, int n) {
  int i;
  Stack pilha;
  pilha = createStack();
  S *vetorA = (S *)vetor;

  /*Encontra o menor y no conjunto de pontos*/
  p0 = menorPonto(vetorA, n);

  /*Ordena o vetor da posicão 1 até n. A posição inicial e o menor y.*/
  mergeSort(vetorA + 1, 0, n - 2, alocar, desalocar, comparar, atribuir);

  /* Coloca na pilha vetor[0] */
  S *A = (S *)malloc(sizeof(S));
  atribuir(A, 0, vetorA, 0);
  insertTop(pilha, -1, A);

  /* Coloca na pilha vetor[1] */
  A = (S *)malloc(sizeof(S));
  atribuir(A, 0, vetorA, 1);
  insertTop(pilha, -1, A);

  /* Coloca na pilha vetor[2] */
  A = (S *)malloc(sizeof(S));
  atribuir(A, 0, vetorA, 2);
  insertTop(pilha, -1, A);

  /*Comparação entre os pontos*/
  for (i = 3; i < n; i++) {
    /*Continua removendo os pontos da pilha enquanto os três pontos não fazem
     * uma curva para a esquerda.*/
    while (orientation(nextToTop(pilha), (S *)getItemTop(pilha),
                       (vetorA + i)) != 2) {
      removeTop(pilha, desalocar);
    }
    A = (S *)malloc(sizeof(S));
    atribuir(A, 0, vetorA, i);
    insertTop(pilha, -1, A);
  }
  /*Coloca na pilha o elemento inicial do vetor(vetor[0])*/
  A = (S *)malloc(sizeof(S));
  atribuir(A, 0, vetorA, 0);
  insertTop(pilha, -1, A);
  return pilha;
}
