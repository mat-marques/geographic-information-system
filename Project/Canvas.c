#include "Canvas.h"
#include "Circulo.h"
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
  List listaCores, listaR2;
  Cidade cidade;
  double width, height;
  int id;
} CanvasP;

Canvas criaCanvas(int id) {
  char *nome;
  CanvasP *canvas;
  canvas = (CanvasP *)malloc(sizeof(CanvasP));
  canvas->listaC = createQuadTree();
  canvas->listaR = createQuadTree();
  canvas->listaR2 = createDLL();
  canvas->listaCores = createDLL();
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void removeRetangulo(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
=======
=======
>>>>>>> Stashed changes
void removeRetangulo(Canvas canvas, int id) {
  figuraGeometrica f;
  CanvasP *canvasP = (CanvasP *)canvas;
  f = removeQuadTreeItem(canvasP->listaR, &id, compareR);
  free(f);
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
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
  f = removeQuadTreeItem(canvasP->listaC, &id, compareC);
  free(f);
}

void insertCor(Canvas canvas, Cor cor) {
  CanvasP *canvasP = (CanvasP *)canvas;
  insertEndDLL(canvasP->listaCores, cor);
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void removeCor(Canvas canvas, int id)
{
    Item item;
    CanvasP *canvasP = (CanvasP *)canvas;
    item = removeItemDLL(CanvasP->listaCores, &id, compareCores);
    free(item);
=======
=======
>>>>>>> Stashed changes
void removeCor(Canvas canvas, int id) {
  Item item;
  CanvasP *canvasP = (CanvasP *)canvas;
  item = removeItemDLL(canvasP->listaCores, &id, compareCores);
  free(item);
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
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

<<<<<<< Updated upstream
figuraGeometrica getRetangulo(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return searchQuadTreeItem(canvasP->listaR, &id, compareC);
}

figuraGeometrica getRetangulo2(Canvas canvas, double x, double y, double w, double h)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    //searchQuadTreeItem(canvasP->listaR, &config, compareC);
    return NULL;
}

figuraGeometrica getCirculo(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return searchQuadTreeItem(canvasP->listaR, &id, compareR);
}

figuraGeometrica getCirculo2(Canvas canvas, double x, double y, double r)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return NULL;
}

Cor getCor(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return searchItemDLL(CanvasP->listaCores, &id, compareCores);
=======
QuadTree getListaC(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaC;
}

List getListaCores(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaCores;
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
=======
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

List getListaCores(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaCores;
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
>>>>>>> Stashed changes
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
int compareRQ(Item item1, Region item2) {
  double x, y, w, h;
  Reg *newReg = (Reg *)item2;
  w = getLargQ(item1);
  h = getAltQ(item1);
  x = getXQ(item1);
  y = getYQ(item1);
  if (verificarInteiramenteSobrepostoRR(newReg->w, newReg->h, newReg->x,
                                        newReg->y, w, h, x, y) == 't') {
=======
int compareRC(Item item1, Region item2) {
  Reg *newReg = (Reg *)item2;
  double x, y, r;
  r = getCr(item1);
  x = getCx(item1);
  y = getCy(item1);
  if (verificarInteiramenteSobrepostoRC(newReg->w, newReg->h, newReg->x,
                                        newReg->y, r, x, y) == 't') {
>>>>>>> Stashed changes
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
int compareRH(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXH(item1);
  y = getYH(item1);
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
=======
int compareRQ(Item item1, Region item2) {
  double x, y, w, h;
  Reg *newReg = (Reg *)item2;
  w = getLargQ(item1);
  h = getAltQ(item1);
  x = getXQ(item1);
  y = getYQ(item1);
  if (verificarInteiramenteSobrepostoRR(newReg->w, newReg->h, newReg->x,
                                        newReg->y, w, h, x, y) == 't') {
>>>>>>> Stashed changes
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
int compareRT(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXT(item1);
  y = getYT(item1);
=======
int compareRH(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXH(item1);
  y = getYH(item1);
>>>>>>> Stashed changes
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
int compareRS(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXS(item1);
  y = getYS(item1);
=======
int compareRT(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXT(item1);
  y = getYT(item1);
>>>>>>> Stashed changes
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
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
=======
int compareRS(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXS(item1);
  y = getYS(item1);
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
>>>>>>> Stashed changes
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
int compareCC(Item item1, Region item2) {
  Reg *newReg = (Reg *)item2;
  double x, y, r;
  r = getCr(item1);
  x = getCx(item1);
  y = getCy(item1);
  if (verificarInteiramenteSobrepostoRC(newReg->w, newReg->h, newReg->x,
                                        newReg->y, r, x, y) == 't') {
=======
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
>>>>>>> Stashed changes
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
int compareCQ(Item item1, Region item2) {
  double x, y, w, h;
  Reg *newReg = (Reg *)item2;
  w = getLargQ(item1);
  h = getAltQ(item1);
  x = getXQ(item1);
  y = getYQ(item1);
  if (verificarInteiramenteSobrepostoCR(w, h, x, y, newReg->w, newReg->x,
                                        newReg->y) == 't') {
=======
int compareCC(Item item1, Region item2) {
  Reg *newReg = (Reg *)item2;
  double x, y, r;
  r = getCr(item1);
  x = getCx(item1);
  y = getCy(item1);
  if (verificarInteiramenteSobrepostoRC(newReg->w, newReg->h, newReg->x,
                                        newReg->y, r, x, y) == 't') {
>>>>>>> Stashed changes
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
int compareCH(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXH(item1);
  y = getYH(item1);
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
=======
int compareCQ(Item item1, Region item2) {
  double x, y, w, h;
  Reg *newReg = (Reg *)item2;
  w = getLargQ(item1);
  h = getAltQ(item1);
  x = getXQ(item1);
  y = getYQ(item1);
  if (verificarInteiramenteSobrepostoCR(w, h, x, y, newReg->w, newReg->x,
                                        newReg->y) == 't') {
>>>>>>> Stashed changes
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
int compareCT(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXT(item1);
  y = getYT(item1);
=======
int compareCH(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXH(item1);
  y = getYH(item1);
>>>>>>> Stashed changes
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
int compareCS(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXS(item1);
  y = getYS(item1);
=======
int compareCT(Item item1, Region item2) {
  double x, y;
  Reg *newReg = (Reg *)item2;
  x = getXT(item1);
  y = getYT(item1);
>>>>>>> Stashed changes
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
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

List getElementsListInsideC(Canvas canvas, int type, double x, double y, double r) {
=======
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
>>>>>>> Stashed changes
  CanvasP *canvasP = (CanvasP *)canvas;
  Reg *newReg;
  List list = NULL;
  Cidade cidade = NULL;
  newReg = (Reg *)malloc(sizeof(Reg));
<<<<<<< Updated upstream
  newReg->w = r;
  newReg->h = 0;
=======
  newReg->w = w;
  newReg->h = h;
>>>>>>> Stashed changes
  newReg->x = x;
  newReg->y = y;
  switch (type) {
  case 1: /* Retângulo */
<<<<<<< Updated upstream
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
=======
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
>>>>>>> Stashed changes
    break;
  default:
    printf("COMANDO INVÁLIDO.\n");
  }
  free(newReg);
  return list;
}

<<<<<<< Updated upstream
/****************************************************/

figuraGeometrica getRetangulo(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return searchQuadTreeItem(canvasP->listaR, &id, compareC);
}

figuraGeometrica getCirculo(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return searchQuadTreeItem(canvasP->listaR, &id, compareR);
}

Cor getCor(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return searchItemDLL(canvasP->listaCores, &id, compareCores);
>>>>>>> Stashed changes
}

void eraseListaR(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseQuadTreeNode(canvasP->listaR, removeR);
}

void eraseListaC(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseQuadTreeNode(canvasP->listaC, removeC);
}

void eraseListaR2(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListDLLOne(canvasP->listaR2, removeR);
}

void eraseListaCores(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListDLLOne(canvasP->listaCores, removeCor);
}

void setarCores(Canvas canvas) {
  Cor cor = NULL;
  char corContorno[] = "black";
  char corA[] = "blue";
  char corB[] = "red";
  char corC[] = "yellow";
  char corD[] = "orange";
  cor = criaCor(corA, corContorno, 1);
  insertCor(canvas, cor);
  cor = criaCor(corB, corContorno, 2);
  insertCor(canvas, cor);
  cor = criaCor(corC, corContorno, 3);
  insertCor(canvas, cor);
  cor = criaCor(corD, corContorno, 4);
  insertCor(canvas, cor);
}

=======
List getElementsListInsideC(Canvas canvas, int type, double x, double y, double r) {
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

Cor getCor(Canvas canvas, int id) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return searchItemDLL(canvasP->listaCores, &id, compareCores);
}

void eraseListaR(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseQuadTreeNode(canvasP->listaR, removeR);
}

void eraseListaC(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseQuadTreeNode(canvasP->listaC, removeC);
}

void eraseListaR2(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListDLLOne(canvasP->listaR2, removeR);
}

void eraseListaCores(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListDLLOne(canvasP->listaCores, removeCor);
}

void setarCores(Canvas canvas) {
  Cor cor = NULL;
  char corContorno[] = "black";
  char corA[] = "blue";
  char corB[] = "red";
  char corC[] = "yellow";
  char corD[] = "orange";
  cor = criaCor(corA, corContorno, 1);
  insertCor(canvas, cor);
  cor = criaCor(corB, corContorno, 2);
  insertCor(canvas, cor);
  cor = criaCor(corC, corContorno, 3);
  insertCor(canvas, cor);
  cor = criaCor(corD, corContorno, 4);
  insertCor(canvas, cor);
}

>>>>>>> Stashed changes
void eraseCanvas(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListaR(canvas);
  eraseListaR2(canvas);
  eraseListaCores(canvas);
  eraseListaC(canvas);
  eraseCidade(canvasP->cidade);
  free(canvas);
}
