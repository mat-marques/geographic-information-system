#include "Circulo.h"
#include "ConvexHull.h"
#include "Hidrante.h"
#include "OperacoesF.h"
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

typedef void (*eraseElement)(void *);
int convexHull(void *vetor, int n, List listConvex, List listPi);

typedef struct Dots {
  void *info;
  double x, y;
} S;

S *p0;

/*Aloca um vetor ou variavel do tipo S. Função necessária para a pilha.*/
void *allocate(int qtd) {
  S *s1 = (S *)malloc(qtd * sizeof(S));
  return s1;
}

/*Desaloca a variavel item. Função necessária para a pilha.*/
void deallocate(void *item) {
  S *s1 = (S *)item;
  if (s1 != NULL) {
    free(s1);
  }
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
  s1 = s;
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
  return (curve > 0) ? 1 : -1;
}

/*Função utilizada para ordenar o vetor de pontos. Função necessária para o
 * mergeSort.*/
int compare(void *valor1, int i, void *valor2, int j) {
  S *s1 = (S *)valor1;
  S *s2 = (S *)valor2;
  int o = orientation(p0, s1 + i, s2 + j);
  if (o == 0) {
    return (dist(p0, s2 + j) >= dist(p0, s1 + i)) ? -1 : 1;
  }
  return (o == -1) ? -1 : 1;
}

Vector listToVectorOne(List list, int type) {
  int i, j;
  S *newVector = NULL;
  Item item;
  j = lengthL(list);
  newVector = (S *)malloc(j * sizeof(S));
  switch (type) {
  case 1: /* Quadra */
    for (i = 1; i <= j; i++) {
      item = getItemL(list, i);
      (newVector + i - 1)->x = getXQ(item);
      (newVector + i - 1)->y = getYQ(item);
      (newVector + i - 1)->info = item;
    }
    break;
  case 2: /* Hidrante */
    for (i = 1; i <= j; i++) {
      item = getItemL(list, i);
      (newVector + i - 1)->x = getXH(item);
      (newVector + i - 1)->y = getYH(item);
      (newVector + i - 1)->info = item;
    }
    break;
  case 3: /* Semafáro */
    for (i = 1; i <= j; i++) {
      item = getItemL(list, i);
      (newVector + i - 1)->x = getXS(item);
      (newVector + i - 1)->y = getYS(item);
      (newVector + i - 1)->info = item;
    }
    break;
  case 4: /* Torre */
    for (i = 1; i <= j; i++) {
      item = getItemL(list, i);
      (newVector + i - 1)->x = getXT(item);
      (newVector + i - 1)->y = getYT(item);
      (newVector + i - 1)->info = item;
    }
    break;
  case 5: /* Retângulo */
    for (i = 1; i <= j; i++) {
      item = getItemL(list, i);
      (newVector + i - 1)->x = getRx(item);
      (newVector + i - 1)->y = getRy(item);
      (newVector + i - 1)->info = item;
    }
    break;
  case 6: /* Círculo */
    for (i = 1; i <= j; i++) {
      item = getItemL(list, i);
      (newVector + i - 1)->x = getCx(item);
      (newVector + i - 1)->y = getCy(item);
      (newVector + i - 1)->info = item;
    }
    break;
  }
  return newVector;
}

Vector listToVectorTwo(List list) {
  int i, j;
  S *newVector = NULL;
  S *item;
  j = lengthL(list);
  newVector = (S *)malloc(j * sizeof(S));
  for (i = 1; i <= j; i++) {
    item = (S *)getItemL(list, i);
    (newVector + i - 1)->x = item->x;
    (newVector + i - 1)->y = item->y;
    (newVector + i - 1)->info = item->info;
  }
  return newVector;
}

/* Calcula a envoltória convexa */
Stack convexHullOfAll(List list, int type) {
  int i, j = 0;
  S *newVector = NULL;
  List listConvex, listPi;
  S *item;
  void *item2;

  Stack stack = createStack();

  j = lengthL(list);

  if (j >= 3) {
    /* Configura o primeiro vetor de pontos   */
    newVector = (S *)listToVectorOne(list, type);
    listConvex = createL(); /* Cria a lista de elementos que formam a
                                 envoltória convexa */

    listPi = createL(); /* Cria a lista de elementos que não formam a
                             envoltória convexa */

    while (j > 2) {

      convexHull(newVector, j, listConvex,
                 listPi); /* Calcula a envoltória convexa */

      j = lengthL(listConvex);
      for (i = 1; i <= j; i++) {
        item = (S *)getEndItemL(listConvex);
        removeEndL(listConvex, NULL);
        insertTop(stack, item->info);
        free(item);
      }
      eraseListL(listConvex, deallocate);

      j = lengthL(listPi);
      if (j > 2) {
        free(newVector);
        newVector = NULL;
        newVector = (S *)listToVectorTwo(listPi);
        eraseListL(listPi, deallocate);
      } else {
        free(newVector);
        newVector = NULL;
        for (i = 1; i <= j; i++) {
          item = (S *)getEndItemL(listPi);
          removeEndL(listPi, NULL);
          insertTop(stack, item->info);
          free(item);
        }
        eraseListL(listConvex, deallocate);
        eraseListL(listPi, deallocate);
      }
    }
    eraseBase(listConvex);
    eraseBase(listPi);
  } else {
    for (i = 1; i <= j; i++) {
      item2 = (S *)getItemL(list, i);
      insertTop(stack, item2);
    }
  }
  return stack;
}

void swap(void *valor1, int i, void *valor2, int j) {
  S *s1 = (S *)valor1;
  S *s2 = (S *)valor2;
  S s3;
  s3.x = (s1 + i)->x;
  s3.y = (s1 + i)->y;
  s3.info = (s1 + i)->info;
  (s1 + i)->x = (s2 + j)->x;
  (s1 + i)->y = (s2 + j)->y;
  (s1 + i)->info = (s2 + j)->info;
  (s2 + j)->x = s3.x;
  (s2 + j)->y = s3.y;
  (s2 + j)->info = s3.info;
}

/* Calcula os vertices do polígono convexo. */
int convexHull(void *vetor, int n, List listConvex, List listPi) {
  int i, m;
  double a;
  S *vetorA = (S *)vetor;
  S *elementOne = NULL;

  /*Encontra o menor y no conjunto de pontos*/

  p0 = smallerDot(vetorA, n);

  /*Ordena o vetor da posicão 1 até n. A posição inicial e o menor y.*/
  mergeSort(vetorA + 1, 0, n - 2, allocate, deallocate, compare, assign);

  /*Verifica a quantidade de pontos do vetor que são colineares com p0.*/
  m = 1;
  for (i = 1; i < n; i++) {
    while ((i < n - 1) &&
           orientation(p0, (vetorA + i), (vetorA + i + 1)) == 0) {
      i++;
    }
    swap(vetorA, m, vetorA, i);
    m++;
  }

  if (m < 3) {
    for (i = 0; i < n; i++) {
      elementOne = (S *)malloc(sizeof(S));
      assign(elementOne, 0, vetorA, i);
      insertBeginL(listConvex, elementOne);
    }
    return 0;
  }

  /* Coloca na listaCovex vetor[0] */
  elementOne = (S *)malloc(sizeof(S));
  assign(elementOne, 0, vetorA, 0);
  insertBeginL(listConvex, elementOne);

  /* Coloca na listaCovex vetor[1] */
  elementOne = (S *)malloc(sizeof(S));
  assign(elementOne, 0, vetorA, 1);
  insertBeginL(listConvex, elementOne);

  /* Coloca na listaCovex vetor[2] */
  elementOne = (S *)malloc(sizeof(S));
  assign(elementOne, 0, vetorA, 2);
  insertBeginL(listConvex, elementOne);

  /*Comparação entre os pontos*/
  for (i = 3; i < m; i++) {
    /*Continua removendo os pontos da listaCovex enquanto os três pontos não
     * fazem uma curva para a esquerda.*/
    while (1) {
      a = orientation((S *)getItemL(listConvex, 2),
                      (S *)getItemL(listConvex, 1), (vetorA + i));
      if (a != -1) {
        elementOne = (S *)getBeginItemL(listConvex);
        removeBeginL(listConvex, NULL);
        insertBeginL(listPi, elementOne);
        if (lengthL(listConvex) == 1) {
          break;
        }
      } else {
        break;
      }
    }
    /*  Insere um novo elemento na listaCovex*/
    elementOne = (S *)malloc(sizeof(S));
    assign(elementOne, 0, vetorA, i);
    insertBeginL(listConvex, elementOne);
  }
  if (m < n) {
    for (i = m; i < n; i++) {
      elementOne = (S *)malloc(sizeof(S));
      assign(elementOne, 0, vetorA, i);
      insertBeginL(listPi, elementOne);
    }
  }
  return 1;
}

List createListPoints(double x, double y, double r) {
  S *item;
  List list;
  int i;
  double L, A;
  list = createL();
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
    insertEndL(list, item);
  }
  return list;
}

void generateConvexHullT(List list, FILE *file) {
  List list2 = NULL, list3 = NULL;
  int i, n, j, k, a;
  double x, y, r;
  Torre torre;
  S *vetor;
  S *element;
  char cor[] = "red";
  char cor2[] = "black";

  /* Pega os oito pontos envolta do alcance da torre. */
  n = lengthL(list);
  list3 = createL();
  for (i = 0; i < n; i++) {
    torre = getItemL(list, i + 1);
    x = getXT(torre);
    y = getYT(torre);
    r = getRaio(torre);
    if (r > 0) {
      list2 = createListPoints(x, y, r);
      concatL(list3, list2);
      tagCirculoOpacity(file, r, x, y, cor);
      eraseBase(list2);
    }
  }

  /* Converte a lista em vetor e verifica se não existem elementos repetidos.*/
  n = lengthL(list3);
  if (n > 0) {
    vetor = (S *)malloc(sizeof(S) * n);
    k = 0;
    for (i = 1; i <= n; i++) {
      element = (S *)getItemL(list3, i);
      if (element != NULL) {
        a = 0;
        for (j = 0; j < k; j++) { /* elementos repetidos. */
          if (((vetor + j)->x == element->x) &&
              ((vetor + j)->y == element->y)) {
            a = 1;
            break;
          }
        }
        if (a == 0) {
          (vetor + k)->x = element->x;
          (vetor + k)->y = element->y;
          (vetor + k)->info = element->info;
          /* Coloca os pontos no svg. */
          pontos(file, element->x, element->y, cor);
          k++;
        }
      }
    }

    /* Encontra a envoltória convexa. */
    eraseListL(list3, deallocate);
    list2 = createL();
    convexHull(vetor, k, list2, list3);

    n = lengthL(list2);
    /* Coloca as linhas no svg. */
    for (i = n; i > 1; i--) {
      element = (S *)getItemL(list2, i);
      x = element->x;
      y = element->y;
      element = (S *)getItemL(list2, i - 1);
      linha(file, x, y, element->x, element->y, cor2);
    }
    element = (S *)getBeginItemL(list2);
    x = element->x;
    y = element->y;
    element = (S *)getEndItemL(list2);
    linha(file, x, y, element->x, element->y, cor2);
    free(vetor);
  }

  eraseListL(list3, deallocate);
  eraseListL(list2, deallocate);
  eraseBase(list3);
  eraseBase(list2);
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
      printf("  %f", mat[i][j]);
    printf("\n");
  }
}

double calcArea(List list) {
  double area = 0, aux1 = 0, aux2 = 0;
  int n;
  int i, j;
  double **mat;
  S *element;
  n = lengthL(list);
  mat = allocateMatrix(n, 2);
  j = 0;
  for (i = n; i > 0; i--) {
    element = (S *)getItemL(list, i);
    if (element != NULL) {
      mat[j][0] = element->x;
      mat[j][1] = element->y;
      j++;
    }
  }
  for (i = 0; i < n - 1; i++) {
    aux1 = aux1 + (mat[i][0] * mat[i + 1][1]);
  }
  for (i = 0; i < n - 1; i++) {
    aux2 = aux2 + (mat[i + 1][0] * mat[i][1]);
  }
  area = fabs(aux1 - aux2) / 2;
  deallocMatrix(mat, n);
  return area;
}

double areaConvexHull(List list) {
  double area = 0;
  List list2 = NULL, list3 = NULL;
  int i, n;
  double x, y, r;
  Torre torre;
  S *vetor;
  S *element;

  /* Pega os oito pontos envolta do alcance da torre. */
  n = lengthL(list);
  list3 = createL();
  for (i = 0; i < n; i++) {
    torre = getItemL(list, i + 1);
    x = getXT(torre);
    y = getYT(torre);
    r = getRaio(torre);
    if (r > 0) {
      list2 = createListPoints(x, y, r);
      concatL(list3, list2);
      eraseBase(list2);
      list2 = NULL;
    }
  }

  /* Converte a lista em vetor. */
  n = lengthL(list3);
  if (n > 0) {
    vetor = (S *)malloc(sizeof(S) * n);

    for (i = 1; i <= n; i++) {
      element = (S *)getItemL(list3, i);
      if (element != NULL) {
        (vetor + i - 1)->x = element->x;
        (vetor + i - 1)->y = element->y;
        (vetor + i - 1)->info = element->info;
      }
    }
    /* Encontra a envoltória convexa. */
    eraseListL(list3, deallocate);
    list2 = createL();
    convexHull(vetor, n, list2, list3);
    area = calcArea(list2);
    free(vetor);
  }

  eraseListL(list3, deallocate);
  eraseListL(list2, deallocate);
  eraseBase(list3);
  eraseBase(list2);

  return area;
}
