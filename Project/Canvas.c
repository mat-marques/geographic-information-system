#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Canvas.h"
#include "ConvexHull.h"
#include "OperacoesF.h"
#include "QuadTree.h"
#include "Retangulo.h"
#include "Svg.h"

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


void removeRetangulo(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;

void removeRetangulo(Canvas canvas, int id) {
  figuraGeometrica f;
  CanvasP *canvasP = (CanvasP *)canvas;
  f = removeQuadTreeItem(canvasP->listaR, &id, compareR);
  free(f);

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


void removeCor(Canvas canvas, int id)
{
    Item item;
    CanvasP *canvasP = (CanvasP *)canvas;
    item = removeItemDLL(CanvasP->listaCores, &id, compareCores);
    free(item);

void removeCor(Canvas canvas, int id) {
  Item item;
  CanvasP *canvasP = (CanvasP *)canvas;
  item = removeItemDLL(canvasP->listaCores, &id, compareCores);
  free(item);
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
  showQuadTree(canvasP->listaR, showR);
}


void showCanvasC(Canvas canvas, FILE *file) {
  CanvasP *canvasP = (CanvasP *)canvas;
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
=======

>>>>>>> Stashed changes
QuadTree getListaC(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  return canvasP->listaC;
}

void calcConvexHull(Canvas canvas, List list, int type) {

  switch (type) {
  case 1: /* Retângulo */

    break;
  case 2: /* Círculo */

    break;
  case 3: /* Quadra */

    break;
  case 4: /* Torre */

    break;
  case 5: /* Hidrante */

    break;
  case 6: /* Semafáro */

    break;
  }
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
<<<<<<< Updated upstream
int compareRQ(Item item1, Region item2) {
=======

int compareRQ(Quadra quadra, Region region) {
  /* A função verifica se uma quadra esta dentro de um região retangular.
    Caso o quadra esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
>>>>>>> Stashed changes
  double x, y, w, h;
  Reg *newReg = (Reg *)region;
  w = getLargQ(quadra);
  h = getAltQ(quadra);
  x = getXQ(quadra);
  y = getYQ(quadra);
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
<<<<<<< Updated upstream
int compareRH(Item item1, Region item2) {
=======

int compareRH(Hidrante hidrante, Region region) {
  /* A função verifica se um hidrante esta dentro de um região retangular.
    Caso o hidrante esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
>>>>>>> Stashed changes
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXH(hidrante);
  y = getYH(hidrante);
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
=======

int compareRT(Torre torre, Region region) {
  /* A função verifica se uma torre esta dentro de um região retangular.
    Caso a torre esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXT(torre);
  y = getYT(torre);
>>>>>>> Stashed changes
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
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
=======

int compareRS(Semafaro semafaro, Region region) {
  /* A função verifica se uma semafaro esta dentro de um região retangular.
    Caso o semafaro esteja dentro da região retangular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXS(semafaro);
  y = getYS(semafaro);
>>>>>>> Stashed changes
  if (pontoInternoR(newReg->w, newReg->h, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
/****************************************************/
int compareCR(Item item1, Region item2) {
  Reg *newReg = (Reg *)item2;
=======

int compareCR(Retangulo retangulo, Region region) {
  /* A função verifica se uma retângulo esta dentro de um região circular.
    Caso o retângulo esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  Reg *newReg = (Reg *)region;
>>>>>>> Stashed changes
  double x, y, w, h;
  w = getRw(retangulo);
  h = getRh(retangulo);
  x = getRx(retangulo);
  y = getRy(retangulo);
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
<<<<<<< Updated upstream
int compareCC(Item item1, Region item2) {
  Reg *newReg = (Reg *)item2;
=======

int compareCC(Circulo circulo, Region region) {
  /* A função verifica se um círculo esta dentro de um região circular.
    Caso o circulo esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  Reg *newReg = (Reg *)region;
>>>>>>> Stashed changes
  double x, y, r;
  r = getCr(circulo);
  x = getCx(circulo);
  y = getCy(circulo);
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
<<<<<<< Updated upstream
int compareCQ(Item item1, Region item2) {
=======

int compareCQ(Quadra quadra, Region region) {
  /* A função verifica se uma quadra esta dentro de um região circular.
    Caso a quadra esteja dentro da região circular retorna 1, caso não retorna 0.
  */
>>>>>>> Stashed changes
  double x, y, w, h;
  Reg *newReg = (Reg *)region;
  w = getLargQ(quadra);
  h = getAltQ(quadra);
  x = getXQ(quadra);
  y = getYQ(quadra);
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
<<<<<<< Updated upstream
int compareCH(Item item1, Region item2) {
=======

int compareCH(Hidrante hidrante, Region region) {
  /* A função verifica se um hidrante esta dentro de um região circular.
    Caso o hidrante esteja dentro da região circular retorna 1, caso não retorna 0.
  */
>>>>>>> Stashed changes
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXH(hidrante);
  y = getYH(hidrante);
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
=======

int compareCT(Torre torre, Region region) {
  /* A função verifica se uma torre esta dentro de um região circular.
    Caso a torre esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXT(torre);
  y = getYT(torre);
>>>>>>> Stashed changes
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
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
=======

int compareCS(Semafaro semafaro, Region region) {
  /* A função verifica se um semafaro esta dentro de um região circular.
    Caso o semafaro esteja dentro da região circular retorna 1, caso não retorna 0.
  */
  double x, y;
  Reg *newReg = (Reg *)region;
  x = getXS(semafaro);
  y = getYS(semafaro);
>>>>>>> Stashed changes
  if (pontoInternoC(newReg->w, newReg->x, newReg->y, x, y) == 't') {
    return 1;
  }
  return 0;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
/****************************************************/
=======

>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
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
=======
=======

>>>>>>> Stashed changes
List getElementsListInsideC(Canvas canvas, int type, double x, double y,
                            double r) {
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
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
=======
>>>>>>> Stashed changes
=======

>>>>>>> Stashed changes
void eraseCanvas(Canvas canvas) {
  CanvasP *canvasP = (CanvasP *)canvas;
  eraseListaR(canvas);
  eraseListaR2(canvas);
  eraseListaC(canvas);
  eraseCidade(canvasP->cidade);
  free(canvas);
}
<<<<<<< Updated upstream
=======


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
>>>>>>> Stashed changes
