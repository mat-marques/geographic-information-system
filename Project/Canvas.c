
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Canvas.h"
#include "ConvexHull.h"
#include "List.h"
#include "OperacoesF.h"
#include "QuadTree.h"
#include "Retangulo.h"
#include "Stack.h"
#include "StringO.h"
#include "Svg.h"

typedef struct reg { double w, h, x, y; } Reg;

typedef struct CanvasP {
  QuadTree listaC, listaR;
  List listaR2, listLines, listTexts, listPolygons, listPolyLines, listEllipses;
  Cidade cidade;
  double width, height;
  int id;
} CanvasP;

char *globalCor = NULL;
FILE *newArqCanvas = NULL;

void ConvexHullAux(Stack stack, Canvas canvas, int type) {
  /*
  A funcão tem a funcionalidade de fazer as chamadas de outras funções para se
  criar as quadTree de círculo e retângulo.
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
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertRetangulo(canvas, element);
    }
    break;
  case 2: /* Círculo. */
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertCirculo(canvas, element);
    }
    break;
  }
}

Canvas criaCanvas(int id) {
  char *nome;
  CanvasP *canvas;
  canvas = (CanvasP *)malloc(sizeof(CanvasP));
  canvas->listaC = createQuadTree();
  canvas->listaR = createQuadTree();
  canvas->listaR2 = createL();
  canvas->listLines = createL();
  canvas->listPolygons = createL();
  canvas->listPolyLines = createL();
  canvas->listTexts = createL();
  canvas->listEllipses = createL();
  canvas->width = 100;
  canvas->height = 100;
  canvas->id = id;
  nome = (char *)malloc(6 * sizeof(char));
  strcpy(nome, "none");
  canvas->cidade = criaCidade(nome);
  return canvas;
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

long int quantityElementsICanvas(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  long int myLength = 0;
  if (canvasP != NULL) {
    myLength = lenghtQuadTree(canvasP->listaR);
    myLength = myLength + lenghtQuadTree(canvasP->listaC);
    myLength = myLength + quantityElementsICity(canvasP->cidade);
  }
  return myLength;
}

long int insertRetangulo(Canvas canvas, Retangulo retangulo) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return insertQuadTree(canvasP->listaR, retangulo, getRx(retangulo),
                        getRy(retangulo));
}

long int removeRetangulo(Canvas canvas, int id) {
  figuraGeometrica f;
  long int qtd;
  CanvasP *canvasP = (CanvasP *)canvas;
  f = removeQuadTreeItemI(canvasP->listaR, &id, compareR, &qtd);
  removeR(f);
  return qtd;
}

void insertRetangulo2(Canvas canvas, Retangulo retangulo) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertEndL(canvasP->listaR2, retangulo);
}

void removeRetangulo2(Canvas canvas, int id) {
  figuraGeometrica f;
  CanvasP *canvasP = (CanvasP *)canvas;
  f = removeItemL2(canvasP->listaR2, &id, compareR);
  free(f);
}

long int insertCirculo(Canvas canvas, Circulo circulo) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return insertQuadTree(canvasP->listaC, circulo, getCx(circulo),
                        getCy(circulo));
}

long int removeCirculo(Canvas canvas, int id) {
  figuraGeometrica f;
  long int qtd;
  CanvasP *canvasP = (CanvasP *)canvas;
  f = removeQuadTreeItemI(canvasP->listaC, &id, compareC, &qtd);
  removeC(f);
  return qtd;
}

void insertLineCanvas(Canvas canvas, Line line) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertEndL(canvasP->listLines, line);
}

void removeLineCanvas(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  Item item;
  item = removeItemL2(canvasP->listLines, &id, compareLines);
  eraseLine(item);
}

void insertTextCanvas(Canvas canvas, Text text) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertEndL(canvasP->listTexts, text);
}

void removeTextCanvas(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  Item item;
  item = removeItemL2(canvasP->listTexts, &id, compareText);
  eraseText(item);
}

void insertPolygonCanvas(Canvas canvas, Polygon polygon) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertEndL(canvasP->listPolygons, polygon);
}

void removePolygonCanvas(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  Item item;
  item = removeItemL2(canvasP->listPolygons, &id, comparePolygon);
  erasePolygon(item);
}

void insertEllipseCanvas(Canvas canvas, Ellipse ellipse) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertEndL(canvasP->listEllipses, ellipse);
}

void removeEllipseCanvas(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  Item item;
  item = removeItemL2(canvasP->listEllipses, &id, compareEllipses);
  eraseEllipse(item);
}

void insertPolyLinesCanvas(Canvas canvas, PolyLine polyLine) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertEndL(canvasP->listPolyLines, polyLine);
}

void removePolyLinesCanvas(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  Item item;
  item = removeItemL2(canvasP->listPolyLines, &id, comparePolyLine);
  erasePolyLine(item);
}

void showR(Retangulo retangulo) {
  /* Escreve em um arquivo svg as propriedades de um retângulo.
     O arquivo svg deve estar sendo referenciado pela variável newArqCanvas.
  */
  double w, h, x, y;
  char *cor;
  char cor1[] = "red";
  char text[] = "R";
  x = getRx(retangulo);
  y = getRy(retangulo);
  w = getRw(retangulo);
  h = getRh(retangulo);
  cor = getRcor(retangulo);
  tagRetangulo(newArqCanvas, w, h, x, y, cor);
  tagTexto2(newArqCanvas, text, cor1, 4, x, y);
}

void showRV(Retangulo retangulo) {
  /* Escreve em um arquivo svg as propriedades de um retângulo.
     O arquivo svg deve estar sendo referenciado pela variável newArqCanvas.
  */
  double w, h, x, y;
  x = getRx(retangulo);
  y = getRy(retangulo);
  w = getRw(retangulo);
  h = getRh(retangulo);
  pontos(newArqCanvas, x, y, globalCor);
  pontos(newArqCanvas, x + w, y, globalCor);
  pontos(newArqCanvas, x, y + h, globalCor);
  pontos(newArqCanvas, x + w, y + h, globalCor);
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
  char cor1[] = "red";
  char text[] = "C";
  x = getCx(circulo);
  y = getCy(circulo);
  r = getCr(circulo);
  cor = getCcor(circulo);
  tagCirculo(newArqCanvas, r, x, y, cor);
  tagTexto2(newArqCanvas, text, cor1, 4, x, y);
}

void showCV(Circulo circulo) {
  /* Escreve em um arquivo svg as propriedades de um círculo.
     O arquivo svg deve estar sendo referenciado pela variável newArqCanvas.
  */
  double x, y;
  x = getCx(circulo);
  y = getCy(circulo);
  pontos(newArqCanvas, x, y, globalCor);
}

void showCanvasR(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  newArqCanvas = file;
  showQuadTree(canvasP->listaR, showR);
  newArqCanvas = NULL;
}

void showCanvasC(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  newArqCanvas = file;
  showQuadTree(canvasP->listaC, showC);
  newArqCanvas = NULL;
}

void showCanvasRV(Canvas canvas, char cor[30], FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  newArqCanvas = file;
  globalCor = cor;
  showQuadTree(canvasP->listaR, showRV);
  newArqCanvas = NULL;
  globalCor = NULL;
}

void showCanvasCV(Canvas canvas, char cor[30], FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  newArqCanvas = file;
  globalCor = cor;
  showQuadTree(canvasP->listaC, showCV);
  newArqCanvas = NULL;
  globalCor = NULL;
}

void showListLines(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  int i, j;
  Item item;
  j = lengthL(canvasP->listLines);
  for (i = 1; i <= j; i++) {
    item = getItemL(canvasP->listLines, i);
    if (item != NULL) {
      tagLinha2(file, getIdLine(item) + i, getX1Line(item), getY1Line(item),
                getX2Line(item), getY2Line(item), getColourLine(item),
                getSizeLine(item));
    }
    item = NULL;
  }
}

void showListTexts(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  int i, j;
  Item item;
  j = lengthL(canvasP->listTexts);
  for (i = 1; i <= j; i++) {
    item = getItemL(canvasP->listTexts, i);
    if (item != NULL) {
      tagTexto3(file, getIdText(item) + i, getText(item), getColourText(item),
                getFontSizeText(item), getFontFamilyText(item), getXText(item),
                getYText(item));
    }
    item = NULL;
  }
}

void showListPolygons(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  int i, j;
  Item item;
  j = lengthL(canvasP->listPolygons);
  for (i = 1; i <= j; i++) {
    item = getItemL(canvasP->listPolygons, i);
    if (item != NULL) {
      tagPoligono(file, getIdPolygon(item) + i, getPointsPolygon(item),
                  getqtdPointsPolygon(item) * 2, getColourLinePolygon(item),
                  getColourFillPolygon(item), getLineSizePolygon(item));
    }
    item = NULL;
  }
}

void showListPolyLines(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  int i, j;
  Item item;
  j = lengthL(canvasP->listPolyLines);
  for (i = 1; i <= j; i++) {
    item = getItemL(canvasP->listPolyLines, i);
    if (item != NULL) {
      tagMultiplasLinhas(
          file, getIdPolyLine(item) + i, getPointsPolyLine(item),
          getqtdPointsPolyLine(item) * 2, getColourLinePolyLine(item),
          getColourFillPolyLine(item), getLineSizePolyLine(item));
    }
    item = NULL;
  }
}

void showListEllipses(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
  int i, j;
  Item item;
  j = lengthL(canvasP->listEllipses);
  for (i = 1; i <= j; i++) {
    item = getItemL(canvasP->listEllipses, i);
    if (item != NULL) {
      tagEllipse(file, getIdEllipse(item) + i, getCXEllipse(item),
                 getCYEllipse(item), getRXEllipse(item), getRYEllipse(item),
                 getColourLineFillEllipse(item), getColourFillEllipse(item),
                 getLineSizeEllipse(item));
    }
    item = NULL;
  }
}

QuadTree getListaR(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaR;
}

List getListaR2(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaR2;
}

List getListLines(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listLines;
}

List getListEllipses(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listEllipses;
}

List getListPolygons(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listPolygons;
}

List getListPolyLines(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listPolyLines;
}

List getListTexts(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listTexts;
}

QuadTree getListaC(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaC;
}

int compareRR(Retangulo retangulo, Region region) {
  /* A função verifica se um retângulo esta dentro de um região retangular.
    Case o retângulo esteja dentro da região retangular retorna 1, caso não
    retorna 0.
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
    Case o círculo esteja dentro da região retangular retorna 1, caso não
    retorna 0.
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
    Caso o quadra esteja dentro da região retangular retorna 1, caso não retorna
    0.
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
    Caso o hidrante esteja dentro da região retangular retorna 1, caso não
    retorna 0.
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
    Caso a torre esteja dentro da região retangular retorna 1, caso não retorna
    0.
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
    Caso o semafaro esteja dentro da região retangular retorna 1, caso não
    retorna 0.
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
    Caso o retângulo esteja dentro da região circular retorna 1, caso não
    retorna 0.
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
    Caso o circulo esteja dentro da região circular retorna 1, caso não retorna
    0.
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
    Caso a quadra esteja dentro da região circular retorna 1, caso não retorna
    0.
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
    Caso o hidrante esteja dentro da região circular retorna 1, caso não retorna
    0.
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
    Caso o semafaro esteja dentro da região circular retorna 1, caso não retorna
    0.
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
  case 1: /* Quadra */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaQ(cidade), newReg, compareRQ);
    break;
  case 2: /* Hidrante */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaH(cidade), newReg, compareRH);
    break;
  case 3: /* Semafáro */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaS(cidade), newReg, compareRS);
    break;
  case 4: /* Torre */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaT(cidade), newReg, compareRT);
    break;
  case 5: /* Retângulo */
    list = getElementsByRegion(canvasP->listaR, newReg, compareRR);
    break;
  case 6: /* Círculo */
    list = getElementsByRegion(canvasP->listaC, newReg, compareRC);
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
  case 1: /* Quadra */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaQ(cidade), newReg, compareCQ);
    break;
  case 2: /* Hidrante */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaH(cidade), newReg, compareCH);
    break;
  case 3: /* Semafáro */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaS(cidade), newReg, compareCS);
    break;
  case 4: /* Torre */
    cidade = getCidade(canvas);
    list = getElementsByRegion(getListaT(cidade), newReg, compareCT);
    break;
  case 5: /* Retângulo */
    list = getElementsByRegion(canvasP->listaR, newReg, compareCR);
    break;
  case 6: /* Círculo */
    list = getElementsByRegion(canvasP->listaC, newReg, compareCC);
    break;
  default:
    printf("COMANDO INVÁLIDO.\n");
  }
  free(newReg);
  return list;
}

figuraGeometrica getRetangulo(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return searchQuadTreeItem(canvasP->listaR, &id, compareR);
}

figuraGeometrica getCirculo(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return searchQuadTreeItem(canvasP->listaC, &id, compareC);
}

void eraseListaR(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseQuadTreeNode(canvasP->listaR, removeR);
  eraseQuadTreeBase(canvasP->listaR);
}

void eraseListaC(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseQuadTreeNode(canvasP->listaC, removeC);
  eraseQuadTreeBase(canvasP->listaC);
}

void eraseListaR2(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListL(canvasP->listaR2, removeR);
  eraseBase(canvasP->listaR2);
}

void eraseListLines(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListL(canvasP->listLines, eraseLine);
  eraseBase(canvasP->listLines);
}

void eraseListEllipses(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListL(canvasP->listEllipses, eraseEllipse);
  eraseBase(canvasP->listEllipses);
}

void eraseListPolygons(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListL(canvasP->listPolygons, erasePolygon);
  eraseBase(canvasP->listPolygons);
}

void eraseListPolyLines(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListL(canvasP->listPolyLines, erasePolyLine);
  eraseBase(canvasP->listPolyLines);
}

void eraseListTexts(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListL(canvasP->listTexts, eraseText);
  eraseBase(canvasP->listTexts);
}

void eraseCanvas(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListaR(canvas);
  eraseListaR2(canvas);
  eraseListaC(canvas);
  eraseListLines(canvas);
  eraseListPolygons(canvas);
  eraseListEllipses(canvas);
  eraseListPolyLines(canvas);
  eraseListTexts(canvas);
  eraseCidade(canvasP->cidade);
  free(canvas);
}

void showCanvasElements(Canvas canvas, FILE *file, int type) {
  void *conjunto;
  CanvasP *canvasP = (CanvasP *)canvas;
  int i, n;
  switch (type) {
  case 1: /* Quadra. */
    showQuadras(canvasP->cidade, file);
    break;
  case 2: /* hidrante */
    showHidrantes(canvasP->cidade, file);
    break;
  case 3: /* Semafaro */
    showSemafaros(canvasP->cidade, file);
    break;
  case 4: /* Torre */
    showTorres(canvasP->cidade, file);
    break;
  case 5: /* Retângulo */
    showCanvasR(canvas, file);
    break;
  case 6: /* Círculo */
    showCanvasC(canvas, file);
    break;
  case 7:
    n = lengthL(canvasP->listaR2);
    for (i = 0; i < n; i++) {
      conjunto = getItemL(canvasP->listaR2, i + 1);
      tagRetanguloSobreposicao(file, getRx(conjunto), getRy(conjunto),
                               getRw(conjunto), getRh(conjunto));
      tagTexto(file, getRx(conjunto), getRy(conjunto) - 10);
    }
    break;
  }
}
