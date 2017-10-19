
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Canvas.h"
#include "ConvexHull.h"
#include "OperacoesF.h"
#include "QuadTree.h"
#include "Retangulo.h"
#include "Svg.h"
#include "QuadTree.h"
#include "Stack.h"
#include "DoubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg { double w, h, x, y; } Reg;

typedef struct CanvasP {
  QuadTree listaC, listaR;
  List listaR2;
  Cidade cidade;
  double width, height;
  int id;
} CanvasP;


void ConvexHullAux(Stack stack, Canvas canvas, int type);


Canvas criaCanvas(int id) {
  char *nome;
  CanvasP *canvas;
  canvas = (CanvasP *)malloc(sizeof(CanvasP));
  canvas->listaC = createQuadTree();
  canvas->listaR = createQuadTree();
  canvas->listaR2 = createDLL();
  canvas->width = 100;
  canvas->height = 100;
  canvas->id = id;
  nome = (char *)malloc(6 * sizeof(char));
  strcpy(nome, "none");
  canvas->cidade = criaCidade(nome);
  return canvas;
}


void insertRetangulo(Canvas canvas, Retangulo retangulo) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertQuadTree(canvasP->listaR, retangulo, getRx(retangulo),
                 getRy(retangulo));
}


void removeRetangulo(Canvas canvas, int id) {
  figuraGeometrica f;
  CanvasP *canvasP = (CanvasP *)canvas;
  List list = createDLL();
  Stack stack;
  f = removeQuadTreeItem(canvasP->listaR, &id, compareR, list);
  removeR(f);
  stack = convexHullOfAll(list, 5);
  ConvexHullAux(stack, canvas, 1);
  eraseStackTwo(stack);
  eraseBaseStack(stack);
}


void insertRetangulo2(Canvas canvas, Retangulo retangulo) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertEndDLL(canvasP->listaR2, retangulo);
}


void removeRetangulo2(Canvas canvas, int id) {
  figuraGeometrica f;
  CanvasP *canvasP = (CanvasP *)canvas;
  f = removeItemDLL(canvasP->listaR2, &id, compareR);
  free(f);
}


void insertCirculo(Canvas canvas, Circulo circulo) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertQuadTree(canvasP->listaC, circulo, getCx(circulo), getCy(circulo));
}


void removeCirculo(Canvas canvas, int id) {
  figuraGeometrica f;
  CanvasP *canvasP = (CanvasP *)canvas;
  Stack stack = NULL;
  List list = createDLL();
  f = removeQuadTreeItem(canvasP->listaC, &id, compareC, list);
  removeC(f);
  stack = convexHullOfAll(list, 6);
  ConvexHullAux(stack, canvas, 2);
  eraseStackTwo(stack);
  eraseBaseStack(stack);
}


void showR(Retangulo retangulo) {
  /* Escreve em um arquivo svg as propriedades de um retângulo.
     O arquivo svg deve estar sendo referenciado pela variável newArqCanvas.
  */
  double w, h, x, y;
  char *cor;
  x = getRx(retangulo);
  y = getRy(retangulo);
  w = getRw(retangulo);
  h = getRh(retangulo);
  cor = getRcor(retangulo);
  tagRetangulo(newArqCanvas, w, h, x, y, cor);
}


void showR2(Retangulo retangulo) {
  /* Escreve em um arquivo svg as propriedades de um retângulo de sobreposição.
     O arquivo svg deve estar sendo referenciado pela variável newArqCanvas.
   */
  double w, h, x, y;
  x = getRx(retangulo);
  y = getRy(retangulo);
  w = getRw(retangulo);
  h = getRh(retangulo);
  tagRetanguloSobreposicao(newArqCanvas, x, y, w, h);
}


void showC(Circulo circulo) {
  /* Escreve em um arquivo svg as propriedades de um círculo.
     O arquivo svg deve estar sendo referenciado pela variável newArqCanvas.
  */
  double x, y, r;
  char *cor;
  x = getCx(circulo);
  y = getCy(circulo);
  r = getCr(circulo);
  cor = getCcor(circulo);
  tagCirculo(newArqCanvas, r, x, y, cor);
}


void showCanvasR(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  newArqCanvas = file;
  showQuadTree(canvasP->listaR, showR);
}


void showCanvasC(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  newArqCanvas = file;
  showQuadTree(canvasP->listaC, showC);
}


double getWidth(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->width;
}


void setWidth(Canvas canvas, double width) {
  CanvasP *canvasP = (CanvasP *)canvas;
  canvasP->width = width;
}


double getHeight(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->height;
}


void setHeight(Canvas canvas, double height) {
  CanvasP *canvasP = (CanvasP *)canvas;
  canvasP->height = height;
}


Cidade getCidade(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->cidade;
}


void setCidade(Canvas canvas, Cidade cidade) {
  CanvasP *canvasP = (CanvasP *)canvas;
  if (canvasP->cidade != NULL) {
    eraseCidade(canvasP->cidade);
    canvasP->cidade = NULL;
  }
  canvasP->cidade = cidade;
}


int getIdCanvas(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->id;
}


QuadTree getListaR(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaR;
}


List getListaR2(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaR2;
}


QuadTree getListaC(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaC;
}


int compareRR(Retangulo retangulo, Region region) {
  /* A função verifica se um retângulo esta dentro de um região retangular.
    Case o retângulo esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
  Reg *newReg = (Reg *)region;

  double x, y, w, h;
  w = getRw(retangulo);
  h = getRh(retangulo);
  x = getRx(retangulo);
  y = getRy(retangulo);
  if (verificarInteiramenteSobrepostoRR(newReg->w, newReg->h, newReg->x,
                                        newReg->y, w, h, x, y) == 't') {
    return 1;
  }
  return 0;
}


int compareRC(Circulo circulo, Region region) {
  /* A função verifica se um círculo esta dentro de um região retangular.
    Case o círculo esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
  Reg *newReg = (Reg *)region;
  double x, y, r;
  r = getCr(circulo);
  x = getCx(circulo);
  y = getCy(circulo);
  if (verificarInteiramenteSobrepostoRC(newReg->w, newReg->h, newReg->x,
                                        newReg->y, r, x, y) == 't') {
    return 1;
  }
  return 0;
}


int compareRQ(Quadra quadra, Region region) {
  /* A função verifica se uma quadra esta dentro de um região retangular.
    Caso o quadra esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
  double x, y, w, h;
  Reg *newReg = (Reg *)region;
  w = getLargQ(quadra);
  h = getAltQ(quadra);
  x = getXQ(quadra);
  y = getYQ(quadra);
  if (verificarInteiramenteSobrepostoRR(newReg->w, newReg->h, newReg->x,
                                        newReg->y, w, h, x, y) == 't') {
    return 1;
  }
  return 0;
}


int compareRH(Hidrante hidrante, Region region) {
  /* A função verifica se um hidrante esta dentro de um região retangular.
    Caso o hidrante esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXH(hidrante);
  y = getYH(hidrante);
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}


int compareRT(Torre torre, Region region) {
  /* A função verifica se uma torre esta dentro de um região retangular.
    Caso a torre esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXT(torre);
  y = getYT(torre);
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}


int compareRS(Semafaro semafaro, Region region) {
  /* A função verifica se uma semafaro esta dentro de um região retangular.
    Caso o semafaro esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXS(semafaro);
  y = getYS(semafaro);
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}


int compareCR(Retangulo retangulo, Region region) {
  /* A função verifica se uma retângulo esta dentro de um região circular.
    Caso o retângulo esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  Reg *newReg = (Reg *)region;
  double x, y, w, h;
  w = getRw(retangulo);
  h = getRh(retangulo);
  x = getRx(retangulo);
  y = getRy(retangulo);
  if (verificarInteiramenteSobrepostoCR(w, h, x, y, newReg->w, newReg->x,
                                        newReg->y) == 't') {
    return 1;
  }
  return 0;
}


int compareCC(Circulo circulo, Region region) {
  /* A função verifica se um círculo esta dentro de um região circular.
    Caso o circulo esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  Reg *newReg = (Reg *)region;
  double x, y, r;
  r = getCr(circulo);
  x = getCx(circulo);
  y = getCy(circulo);
  if (verificarInteiramenteSobrepostoRC(newReg->w, newReg->h, newReg->x,
                                        newReg->y, r, x, y) == 't') {
    return 1;
  }
  return 0;
}


int compareCQ(Quadra quadra, Region region) {
  /* A função verifica se uma quadra esta dentro de um região circular.
    Caso a quadra esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  double x, y, w, h;
  Reg *newReg = (Reg *)region;
  w = getLargQ(quadra);
  h = getAltQ(quadra);
  x = getXQ(quadra);
  y = getYQ(quadra);
  if (verificarInteiramenteSobrepostoCR(w, h, x, y, newReg->w, newReg->x,
                                        newReg->y) == 't') {
    return 1;
  }
  return 0;
}


int compareCH(Hidrante hidrante, Region region) {
  /* A função verifica se um hidrante esta dentro de um região circular.
    Caso o hidrante esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXH(hidrante);
  y = getYH(hidrante);
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}


int compareCT(Torre torre, Region region) {
  /* A função verifica se uma torre esta dentro de um região circular.
    Caso a torre esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXT(torre);
  y = getYT(torre);
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}


int compareCS(Semafaro semafaro, Region region) {
  /* A função verifica se um semafaro esta dentro de um região circular.
    Caso o semafaro esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXS(semafaro);
  y = getYS(semafaro);
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}


List getElementsListInsideR(Canvas canvas, int type, double x, double y,
                            double w, double h) {
  CanvasP *canvasP = (CanvasP *)canvas;
  Reg *newReg;
  List list = NULL;
  Cidade cidade = NULL;
  newReg = (Reg *)malloc(sizeof(Reg));
  newReg->w = w;
  newReg->h = h;
  newReg->x = x;
  newReg->y = y;
  switch (type) {
  case 1: /* Retângulo */
    list = getElementsByRegion(canvasP->listaR, newReg, compareRR);
    break;
  case 2: /* Círculo */
    list = getElementsByRegion(canvasP->listaC, newReg, compareRC);
    break;
  case 3: /* Quadra */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaQ(cidade), newReg, compareRQ);
    break;
  case 4: /* Torre */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaT(cidade), newReg, compareRT);
    break;
  case 5: /* Hidrante */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaH(cidade), newReg, compareRH);
    break;
  case 6: /* Semafáro */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaS(cidade), newReg, compareRS);
    break;
  default:
    printf("COMANDO INVÁLIDO.\n");
  }
  free(newReg);
  return list;
}


List getElementsListInsideC(Canvas canvas, int type, double x, double y,
                            double r) {
  CanvasP *canvasP = (CanvasP *)canvas;
  Reg *newReg;
  List list = NULL;
  Cidade cidade = NULL;
  newReg = (Reg *)malloc(sizeof(Reg));
  newReg->w = r;
  newReg->h = 0;
  newReg->x = x;
  newReg->y = y;
  switch (type) {
  case 1: /* Retângulo */
    list = getElementsByRegion(canvasP->listaR, newReg, compareCR);
    break;
  case 2: /* Círculo */
    list = getElementsByRegion(canvasP->listaC, newReg, compareCC);
    break;
  case 3: /* Quadra */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaQ(cidade), newReg, compareCQ);
    break;
  case 4: /* Torre */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaT(cidade), newReg, compareCT);
    break;
  case 5: /* Hidrante */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaH(cidade), newReg, compareCH);
    break;
  case 6: /* Semafáro */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaS(cidade), newReg, compareCS);
    break;
  default:
    printf("COMANDO INVÁLIDO.\n");
  }
  free(newReg);
  return list;
}


figuraGeometrica getRetangulo(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return searchQuadTreeItem(canvasP->listaR, &id, compareC);
}


figuraGeometrica getCirculo(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return searchQuadTreeItem(canvasP->listaR, &id, compareR);
}

void eraseListaR(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseQuadTreeNodeOne(canvasP->listaR, removeR);
}


void eraseListaC(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseQuadTreeNodeOne(canvasP->listaC, removeC);
}


void eraseListaR2(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListDLLOne(canvasP->listaR2, removeR);
}


void eraseCanvas(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListaR(canvas);
  eraseListaR2(canvas);
  eraseListaC(canvas);
  eraseCidade(canvasP->cidade);
  free(canvas);
}


void showCanvasElements(Canvas canvas, int type) {
  Cidade cidade;
  void *conjunto;
  CanvasP *canvasP = (CanvasP *)canvas;
  int i, n;
  switch (type) {
  case 1: /* Quadra. */
    cidade = canvasP->cidade;
    conjunto = getListaQ(cidade);
    newArqCity = newArqCanvas;
    showQuadTree(conjunto, showQ);
    break;
  case 2: /* hidrante */
    cidade = canvasP->cidade;
    conjunto = getListaH(cidade);
    newArqCity = newArqCanvas;
    showQuadTree(conjunto, showH);
    break;
  case 3: /* Torre */
    cidade = canvasP->cidade;
    conjunto = getListaT(cidade);
    newArqCity = newArqCanvas;
    showQuadTree(conjunto, showT);
    break;
  case 4: /* Semafaro */
    cidade = canvasP->cidade;
    conjunto = getListaS(cidade);
    newArqCity = newArqCanvas;
    showQuadTree(conjunto, showS);
    break;
  case 5: /* Retângulo */
    showQuadTree(canvasP->listaR, showR);
    break;
  case 6: /* Círculo */
    showQuadTree(canvasP->listaC, showC);
    break;
  case 7:
  n = lengthDLL(canvasP->listaR2);
  for(i=0; i<n; i++){
    conjunto = getItemDLL(canvasP->listaR2, i+1);
    tagRetanguloSobreposicao(newArqCanvas, getRx(conjunto), getRy(conjunto), getRw(conjunto), getRh(conjunto));
  }
    break;
  }
}


void ConvexHullAux(Stack stack, Canvas canvas, int type) {
  /*
  A funcão tem a funcionalidade de fazer as chamadas de outras funções para se criar as quadTree de círculo e retângulo.
  O argumento type pode receber um dos seguintes valores:
  1 : Retângulo;
  2 : Círculo.
 */
  int i, n;
  void *element = NULL;
  switch (type) {
  case 1: /* Retângulo. */
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertRetangulo(canvas, element);
    }
    break;
  case 2: /* Círculo. */
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertCirculo(canvas, element);
    }
    break;
  }
}
