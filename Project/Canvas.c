#include "Canvas.h"
#include "Circulo.h"
#include "ConvexHull.h"
#include "Exibicao.h"
#include "OperacoesF.h"
#include "QuadTree.h"
#include "Retangulo.h"
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

void showCanvasR(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  globalFile = file;
  showQuadTree(canvasP->listaR, showR);
}

void showCanvasC(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  globalFile = file;
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


/****************************************************/
int compareRR(Item item1, Region item2) {
  Reg *newReg = (Reg *)item2;
  double x, y, w, h;
  w = getRw(item1);
  h = getRh(item1);
  x = getRx(item1);
  y = getRy(item1);
  if (verificarInteiramenteSobrepostoRR(newReg->w, newReg->h, newReg->x,
                                        newReg->y, w, h, x, y) == 't') {
    return 1;
  }
  return 0;
}

int compareRC(Item item1, Region item2) {
  Reg *newReg = (Reg *)item2;
  double x, y, r;
  r = getCr(item1);
  x = getCx(item1);
  y = getCy(item1);
  if (verificarInteiramenteSobrepostoRC(newReg->w, newReg->h, newReg->x,
                                        newReg->y, r, x, y) == 't') {
    return 1;
  }
  return 0;
}

int compareRQ(Item item1, Region item2) {
  double x, y, w, h;
  Reg *newReg = (Reg *)item2;
  w = getLargQ(item1);
  h = getAltQ(item1);
  x = getXQ(item1);
  y = getYQ(item1);
  if (verificarInteiramenteSobrepostoRR(newReg->w, newReg->h, newReg->x,
                                        newReg->y, w, h, x, y) == 't') {
    return 1;
  }
  return 0;
}

int compareRH(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXH(item1);
  y = getYH(item1);
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

int compareRT(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXT(item1);
  y = getYT(item1);
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

int compareRS(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXS(item1);
  y = getYS(item1);
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

/****************************************************/
int compareCR(Item item1, Region item2) {
  Reg *newReg = (Reg *)item2;
  double x, y, w, h;
  w = getRw(item1);
  h = getRh(item1);
  x = getRx(item1);
  y = getRy(item1);
  if (verificarInteiramenteSobrepostoCR(w, h, x, y, newReg->w, newReg->x,
                                        newReg->y) == 't') {
    return 1;
  }
  return 0;
}

int compareCC(Item item1, Region item2) {
  Reg *newReg = (Reg *)item2;
  double x, y, r;
  r = getCr(item1);
  x = getCx(item1);
  y = getCy(item1);
  if (verificarInteiramenteSobrepostoRC(newReg->w, newReg->h, newReg->x,
                                        newReg->y, r, x, y) == 't') {
    return 1;
  }
  return 0;
}

int compareCQ(Item item1, Region item2) {
  double x, y, w, h;
  Reg *newReg = (Reg *)item2;
  w = getLargQ(item1);
  h = getAltQ(item1);
  x = getXQ(item1);
  y = getYQ(item1);
  if (verificarInteiramenteSobrepostoCR(w, h, x, y, newReg->w, newReg->x,
                                        newReg->y) == 't') {
    return 1;
  }
  return 0;
}

int compareCH(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXH(item1);
  y = getYH(item1);
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

int compareCT(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXT(item1);
  y = getYT(item1);
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

int compareCS(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXS(item1);
  y = getYS(item1);
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

/****************************************************/
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

/****************************************************/

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

void ConvexHullAux(Stack stack, Canvas canvas, int type) {
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
