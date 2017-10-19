#include "Circulo.h"
#include "ConvexHull.h"
#include "Hidrante.h"
#include "Ordination.h"
#include "QuadTree.h"
#include "Quadra.h"
#include "Retangulo.h"
#include "Semafaro.h"
#include "Stack.h"
#include "Svg.h"
#include "Torre.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

<<<<<<< Updated upstream
=======
typedef void (*eraseElement)(void*);

>>>>>>> Stashed changes
typedef struct Dots {
  void *info;
  double x, y;
}S;

S *p0;

/*Aloca um vetor ou variavel do tipo S. Função necessária para a pilha.*/
void *allocate(int qtd) {
  S *s1 = (S *)malloc(qtd * sizeof(S));
  return s1;
}

/*Desaloca a variavel item. Função necessária para a pilha.*/
void deallocate(void *item) {
  S *s1 = (S *)item;
  free(s1);
}

/*Função que atribui os valores de valor para valor. Função necessária para a
 * pilha.*/
void assign(void *valor1, int i, void *valor2, int j) {
  S *s1 = (S *)valor1;
  S *s2 = (S *)valor2;
  (s1 + i)->x = (s2 + j)->x;
  (s1 + i)->y = (s2 + j)->y;
  (s1 + i)->info = (s2 + j)->info;
}

/*Encontra o menor elemento dentro de um conjunto de pontos.*/
S *smallerDot(S *s, int qtd) {
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

/*Função utilizada para encontra a distancia de dois pontos. Utiliza fórmula de
 * vetores. */
int dist(S *p, S *q) {
  return (p->x - q->x) * (p->x - q->x) + (p->y - q->y) * (p->y - q->y);
}

/*Calcula a orientação de três pontos.*/
int orientation(S *p, S *q, S *r) {
  int curve = (q->y - p->y) * (r->x - q->x) - (q->x - p->x) * (r->y - q->y);
  /*Case curve == 0 os pontos são colineares*/
  if (curve == 0) {
    return 0;
  }
  /*caso curve > 0 os pontos fazem uma curva para a esquerda.*/
  /*caso curve < 0 os pontos fazem uma curva para a direita.*/
  return (curve > 0) ? 1 : 2;
}

/*Função utilizada para ordenar o vetor de pontos. Função necessária para o
 * mergeSort.*/
int compare(void *valor1, int i, void *valor2, int j) {
  S *s1 = (S *)valor1;
  S *s2 = (S *)valor2;
  int o = orientation(p0, s1, s2);
  if (o == 0) {
    return (dist(p0, s2 + j) >= dist(p0, s1 + i)) ? -1 : 1;
  }
  return (o == 2) ? -1 : 1;
}

Vector listToVector(List list, int typeOfList) {
  int i, j;
  S *newVector = NULL;
  Item item;
  j = lengthDLL(list);
  newVector = (S *)malloc(j * sizeof(S));
  switch (typeOfList) {
  case 1: /* Quadra */
    for (i = 0; i < j; i++) {
      item = getItemDLL(list, i + 1);
      (newVector + i)->x = getXQ(item);
      (newVector + i)->y = getYQ(item);
      (newVector + i)->info = item;
    }
    break;
  case 2: /* Hidrante */
    for (i = 0; i < j; i++) {
      item = getItemDLL(list, i + 1);
      (newVector + i)->x = getXH(item);
      (newVector + i)->y = getYH(item);
      (newVector + i)->info = item;
    }
    break;
  case 3: /* Semafáro */
    for (i = 0; i < j; i++) {
      item = getItemDLL(list, i + 1);
      (newVector + i)->x = getXS(item);
      (newVector + i)->y = getYS(item);
      (newVector + i)->info = item;
    }
    break;
  case 4: /* Torre */
    for (i = 0; i < j; i++) {
      item = getItemDLL(list, i + 1);
      (newVector + i)->x = getXT(item);
      (newVector + i)->y = getYT(item);
      (newVector + i)->info = item;
    }
    break;
  case 5: /* Retângulo */
    for (i = 0; i < j; i++) {
      item = getItemDLL(list, i + 1);
      (newVector + i)->x = getRx(item);
      (newVector + i)->y = getRy(item);
      (newVector + i)->info = item;
    }
    break;
  case 6: /* Círculo */
    for (i = 0; i < j; i++) {
      item = getItemDLL(list, i + 1);
      (newVector + i)->x = getCx(item);
      (newVector + i)->y = getCy(item);
      (newVector + i)->info = item;
    }
    break;
  }
  return newVector;
}

/* Converte uma lista para um vetor */
Stack convexHullOfElements(List list, int typeOfList) {
  int i, j;
  S *newVector = NULL;
  List listConvex, listPi;
  Item item;

  Stack stack = createStack();

  /* Configura o primeiro vetor de pontos   */
  newVector = (S*)listToVector(list, typeOfList);
  listConvex =
      createDLL(); /* Cria a lista de elementos que formam a envoltória convexa
                      */
  listPi = createDLL(); /* Cria a lista de elementos que não formam a envoltória
                           convexa */
  while (j > 2) {

    convexHull(newVector, j, listConvex, listPi); /* Calcula a envoltória convexa */

    j = lengthDLL(listConvex);
    for (i = 0; i < j; i++) {
      item = removeEndDLLTwo(listConvex);
      insertTop(stack, item);
    }
    eraseListDLLTwo(listConvex);

    j = lengthDLL(listPi);
    if (j > 2) {
      free(newVector);
      newVector =  (S*) listToVector(listPi, typeOfList);
      eraseListDLLTwo(listPi);
      listPi = createDLL();
      listConvex = createDLL();
    } else {
      if (j > 0) {
        free(newVector);
        item = removeEndDLLTwo(listPi);
        insertTop(stack, item);
        item = removeEndDLLTwo(listPi);
        insertTop(stack, item);
        eraseListDLLTwo(listPi);
      }
    }
  }

  return stack;
}

/*Calcula os vertices do polígono convexo.*/
void convexHull(void *vetor, int n, List listConvex, List listPi) {
  int i;
  S *vetorA = (S*) vetor;
  Item elementOne = NULL;
  /*Encontra o menor y no conjunto de pontos*/
  p0 = smallerDot(vetorA, n);

  /*Ordena o vetor da posicão 1 até n. A posição inicial e o menor y.*/
  mergeSort(vetorA + 1, 0, n - 2, allocate, deallocate, compare, assign);

  /* Coloca na listaCovex vetor[0] */
  elementOne = (S *)malloc(sizeof(S));
  assign(elementOne, 0, vetorA, 0);
  insertBeginDLL(listConvex, elementOne);

  /* Coloca na listaCovex vetor[1] */
  elementOne = (S *)malloc(sizeof(S));
  assign(elementOne, 0, vetorA, 1);
  insertBeginDLL(listConvex, elementOne);

  /* Coloca na listaCovex vetor[2] */
  elementOne = (S *)malloc(sizeof(S));
  assign(elementOne, 0, vetorA, 2);
  insertBeginDLL(listConvex, elementOne);

  /*Comparação entre os pontos*/
  for (i = 3; i < n; i++) {
    /*Continua removendo os pontos da listaCovex enquanto os três pontos não
     * fazem
     * uma curva para a esquerda.*/
    while (orientation((S *)getItemDLL(listConvex, 2),
                       (S *)getItemDLL(listConvex, 1), (vetorA + i)) != 2) {
      elementOne = removeBeginDLLTwo(listConvex);
      insertBeginDLL(listPi, elementOne);
    }
    /*  Insere um novo elemento na listaCovex*/
    elementOne = (S *)malloc(sizeof(S));
    assign(elementOne, 0, vetorA, i);
    insertBeginDLL(listConvex, elementOne);
  }

}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void inserInQuadTree(QuadTree quadTree, Stack stack) {
  int i, j;
  S *item;
  j = lengthStack(stack);
  for (i = 0; i < j; i++) {
    item = (S *)removeTopI(stack);
    insertQuadTree(quadTree, item->info, item->x, item->y);
    free(item);
  }
=======
=======
>>>>>>> Stashed changes
List createListPoints(double x, double y, double r) {
  S *item;
  List list;
  int i;
  double L, A;
  list = createDLL();
  L = (r * sqrt(2.0)) / 2;
  A = (r * sqrt(2.0)) / 2;
  for (i = 0; i < 8; i++) {
    item = (S *)malloc(sizeof(S));
    item->info = NULL;
    switch (i) {
    case 0:
      item->x = x;
      item->y = y - r;
      break;
    case 1:
      item->x = x;
      item->y = y + r;
      break;
    case 2:
      item->x = x + r;
      item->y = y;
      break;
    case 3:
      item->x = x - r;
      item->y = y;
      break;
    case 4:
      item->x = x - A;
      item->y = y - L;
      break;
    case 5:
      item->x = x - A;
      item->y = y + L;
      break;
    case 6:
      item->x = x + A;
      item->y = y - L;
      break;
    case 7:
      item->x = x + A;
      item->y = y + L;
      break;
    }
    insertEndDLL(list, item);
  }
  return list;
}

void generateConvexHullT(List list, FILE *file){
  List list2 = NULL, list3 = NULL;
  int i, n;
  double x, y, r;
  Torre torre;
  S *vetor;
  S *element;
  char cor[] = "red";
  char cor2[]= "black";

  /* Pega os oito pontos envolta do alcance da torre. */
  n = lengthDLL(list);
  list3 = createDLL();
  for(i=0; i<n; i++){
    torre = getItemDLL(list, i+1);
    x = getXT(torre);
    y = getYT(torre);
    r = getRaio(torre);
    if(r > 0){
      list2 = createListPoints(x, y, r);
      concatDLL(list3, list2);
      tagCirculoOpacity(file, r, x, y, cor);
      eraseListDLLTwo(list2);
      eraseBase(list2);
    }
  }

  /* Converte a lista em vetor. */
  n = lengthDLL(list3);
  if(n>0){
    vetor = (S*) malloc(sizeof(S) * n);
  }
  for(i=0; i<n; i++){
    element = (S*) getItemDLL(list3, i+1);
    if(element != NULL){
      (vetor + i)->x = element->x;
      (vetor + i)->y = element->y;
      (vetor + i)->info = element->info;
      /* Coloca os pontos no svg. */
      pontos(file, (element+i)->x, (element+i)->y, cor);
    }
  }
  /* Encontra a envoltória convexa. */
  eraseListDLLTwo(list3);
  list2 = createDLL();
  convexHull(vetor, n, list2, list3);

  /* Coloca as linhas no svg. */
  for(i=0; i<n-2; i++){
    element = (S*) getItemDLL(list3, i+1);
    x = (element+i)->x;
    y = (element+i)->y;
    element = (S*) getItemDLL(list3, i+2);
    linha(file, x, y, (element+i)->x, (element+i)->y, cor2);
  }

  eraseListDLLTwo(list3);
  eraseListDLLTwo(list2);
  eraseBase(list3);
  eraseBase(list2);
  free(vetor);
}

double **allocateMatrix(int row, int col) {
  double **matrix;
  int i;
  matrix = (double **)malloc(row * sizeof(double *));
  for (i = 0; i < row; i++) {
    matrix[i] = (double *)malloc(col * sizeof(double));
  }
  return matrix;
}

void deallocMatrix(double **matrix, int col) {
  int i = 0;
  for (i = 0; i < col; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void display(double **mat, int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++)
      printf("  %lf", mat[i][j]);
    printf("\n");
  }
}

double calcArea(List list){
  double area = 0, aux1 = 0, aux2 = 0;
  int n;
  int i, j;
  double **mat;
  S *element;
  n = lengthDLL(list);
  mat = allocateMatrix(n, 2);
  j = 0;
  for(i=n; i>0; i--){
    element = (S*) getItemDLL(list, i);
    if(element != NULL){
      mat[j][0] = element->x;
      mat[j][1] = element->y;
      j++;
    }
  }
  for(i=0; i<n-1; i++){
    aux1 = aux1 + (mat[i][0] * mat[i+1][1]);
  }
  for(i=0; i<n-1; i++){
    aux2 = aux2 + (mat[i+1][0] * mat[i][1]);
  }
  area = fabs(aux1 - aux2)/2;
  deallocMatrix(mat, n);
  return area;
}

double areaConvexHull(List list){
  double area;
  List list2 = NULL, list3 = NULL;
  int i, n;
  double x, y, r;
  Torre torre;
  S *vetor;
  S *element;

  /* Pega os oito pontos envolta do alcance da torre. */
  n = lengthDLL(list);
  list3 = createDLL();
  for(i=0; i<n; i++){
    torre = getItemDLL(list, i+1);
    x = getXT(torre);
    y = getYT(torre);
    r = getRaio(torre);
    if(r > 0){
      list2 = createListPoints(x, y, r);
      concatDLL(list3, list2);
      eraseListDLLTwo(list2);
      eraseBase(list2);
    }
  }

  /* Converte a lista em vetor. */
  n = lengthDLL(list3);
  if(n>0){
    vetor = (S*) malloc(sizeof(S) * n);
  }
  for(i=0; i<n; i++){
    element = (S*) getItemDLL(list3, i+1);
    if(element != NULL){
      (vetor + i)->x = element->x;
      (vetor + i)->y = element->y;
      (vetor + i)->info = element->info;
    }
  }

  /* Encontra a envoltória convexa. */
  eraseListDLLTwo(list3);
  list2 = createDLL();
  convexHull(vetor, n, list2, list3);

  area = calcArea(list2);

  eraseListDLLTwo(list3);
  eraseListDLLTwo(list2);
  eraseBase(list3);
  eraseBase(list2);
  free(vetor);


  return area;
>>>>>>> Stashed changes
}
