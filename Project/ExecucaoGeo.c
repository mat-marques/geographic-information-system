#include "ExecucaoGeo.h"
#include "OpEntrada.h"
#include "OperacoesF.h"

#include "Arquivo.h"
#include "Cidade.h"
#include "Circulo.h"
#include "Hidrante.h"
#include "Quadra.h"
#include "Retangulo.h"
#include "Semafaro.h"
#include "Torre.h"

#include "Canvas.h"
#include "ConvexHull.h"
#include "DoubleLinkedList.h"
#include "QuadTree.h"
#include "Stack.h"
#include "StringO.h"
#include "Svg.h"

void executarConvexHull(List list, Canvas canvas, int type) {
  int i, n;
  void *element = NULL;
  Stack stack = NULL;
  double x, y, w, h;
  w = getWidth(canvas);
  h = getHeight(canvas);
  switch (type) {
  case 1: /* Quadra. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertQuadra(getCidade(canvas), element);
      x = getXQ(element);
      y = getYQ(element);
      x = x + getLargQ(element);
      y = y + getAltQ(element);
      if (w < x) {
        setWidth(canvas, x);
        w = x;
      }
      if (h < y) {
        setHeight(canvas, y);
        h = y;
      }
    }
    break;
  case 2: /* Hidrante. */
    stack = convexHullOfAll(list, 2);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertHidrante(getCidade(canvas), element);
      x = getXH(element);
      y = getYH(element);
      if (w < x) {
        setWidth(canvas, x);
        w = x;
      }
      if (h < y) {
        setHeight(canvas, y);
        h = y;
      }
    }
    break;
  case 3: /* semafaro. */
    stack = convexHullOfAll(list, 3);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertSemafaro(getCidade(canvas), element);
      x = getXS(element);
      y = getYS(element);
      if (w < x) {
        setWidth(canvas, x);
        w = x;
      }
      if (h < y) {
        setHeight(canvas, y);
        h = y;
      }
    }
    break;
  case 4: /* Torre. */
    stack = convexHullOfAll(list, 4);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertTorre(getCidade(canvas), element);
      x = getXT(element);
      y = getYT(element);
      if (w < x) {
        setWidth(canvas, x);
        w = x;
      }
      if (h < y) {
        setHeight(canvas, y);
        h = y;
      }
    }
    break;
  case 5: /* Retângulo. */
    stack = convexHullOfAll(list, 5);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertRetangulo(canvas, element);
      x = getRx(element);
      y = getRy(element);
      x = x + getRw(element);
      y = y + getRh(element);
      if (w < x) {
        setWidth(canvas, x);
        w = x;
      }
      if (h < y) {
        setHeight(canvas, y);
        h = y;
      }
    }
    break;
  case 6: /* Círculo. */
    stack = convexHullOfAll(list, 6);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertCirculo(canvas, element);
      x = getCx(element);
      y = getCy(element);
      x = x + getCr(element);
      y = y + getCr(element);
      if (w < x) {
        setWidth(canvas, x);
        w = x;
      }
      if (h < y) {
        setHeight(canvas, y);
        h = y;
      }
    }
    break;
  }
  eraseStack(stack, NULL);
  eraseBaseStack(stack);
}

void executarC(FILE *arqEntradaGeo, List list) {
  double x = 0, y = 0, r = 0;
  char cor[60];
  int i;
  Circulo circulo = NULL;
  fscanf(arqEntradaGeo, "%d %lf %lf %lf %s\n", &i, &r, &x, &y, cor);
  circulo = createCircle(i, r, x, y, cor);
  insertEndDLL(list, circulo);
}

void executarR(FILE *arqEntradaGeo, List list) {
  double w = 0, h = 0, x = 0, y = 0;
  char cor[60];
  int i = 0;
  Retangulo retangulo = NULL;
  fscanf(arqEntradaGeo, "%d %lf %lf %lf %lf %s\n", &i, &w, &h, &x, &y, cor);
  retangulo = createRectangle(i, w, h, x, y, cor);
  insertEndDLL(list, retangulo);
}

void executarD(FILE *arqEntradaGeo, FILE *arqSaidaT, Canvas canvas) {
  void *voidPointer1 = NULL, *voidPointer2 = NULL;
  int i, j;
  char caracter = 'r';
  char caracter1 = 'r';
  char stringAux[] = "Nao encontrados";
  if (arqSaidaT != NULL) {
    fscanf(arqEntradaGeo, "%d %d\n", &i, &j);
    caracter = 'd';
    fillArq(arqSaidaT, caracter);
    fillSpace(arqSaidaT);
    fillArq3(arqSaidaT, i);
    fillSpace(arqSaidaT);
    fillArq3(arqSaidaT, j);
    fillBreakLine(arqSaidaT);
    caracter = 'r';
    voidPointer1 = getRetangulo(canvas, i);
    if (voidPointer1 == NULL) {
      voidPointer1 = getCirculo(canvas, i);
      caracter = 'c';
    }
    caracter1 = 'r';
    voidPointer2 = getRetangulo(canvas, j);
    if (voidPointer2 == NULL) {
      voidPointer2 = getCirculo(canvas, j);
      caracter1 = 'c';
    }

    if (voidPointer1 != NULL && voidPointer2 != NULL) {
      if (caracter == 'c' && caracter1 == 'c') {
        comandoD(arqSaidaT, getCx(voidPointer1), getCy(voidPointer1),
                 getCx(voidPointer2), getCy(voidPointer2));
      } else if (caracter == 'c' && caracter1 == 'r') {
        comandoD(arqSaidaT, getCx(voidPointer1), getCy(voidPointer1),
                 (getRx(voidPointer2) + getRw(voidPointer2)) / 2,
                 (getRy(voidPointer2) + getRh(voidPointer2)) / 2);
      } else if (caracter == 'r' && caracter1 == 'c') {
        comandoD(arqSaidaT, (getRx(voidPointer1) + getRw(voidPointer1)) / 2,
                 (getRy(voidPointer1) + getRh(voidPointer1)) / 2,
                 getCx(voidPointer2), getCy(voidPointer2));
      } else if (caracter == 'r' && caracter1 == 'r') {
        comandoD(arqSaidaT, (getRx(voidPointer1) + getRw(voidPointer1)) / 2,
                 (getRy(voidPointer1) + getRh(voidPointer1)) / 2,
                 (getRx(voidPointer2) + getRw(voidPointer2)) / 2,
                 (getRy(voidPointer2) + getRh(voidPointer2)) / 2);
      } else
        printf("ERRO EM COMANDO D.\n");
    } else {
      printf("Poligono não encontrado.\n");
      fillArq1(arqSaidaT, stringAux);
      fillBreakLine(arqSaidaT);
    }
    voidPointer1 = NULL;
    voidPointer2 = NULL;
  }
}

void executarI(FILE *arqEntradaGeo, FILE *arqSaidaT, Canvas canvas) {
  void *voidPointer1 = NULL;
  int i;
  double x, y;
  char caracter;
  char stringAux[] = "Nao encontrados";
  if (arqSaidaT != NULL) {
    fscanf(arqEntradaGeo, "%d %lf %lf\n", &i, &x, &y);
    caracter = 'i';
    fillArq(arqSaidaT, caracter);
    fillSpace(arqSaidaT);

    fillArq3(arqSaidaT, i);
    fillSpace(arqSaidaT);

    fillArq2(arqSaidaT, x);
    fillSpace(arqSaidaT);

    fillArq2(arqSaidaT, y);
    fillSpace(arqSaidaT);

    fillBreakLine(arqSaidaT);

    caracter = 'r';
    voidPointer1 = getRetangulo(canvas, i);
    if (voidPointer1 == NULL) {
      voidPointer1 = getCirculo(canvas, i);
      caracter = 'c';
    }
    if (voidPointer1 != NULL) {
      if (caracter == 'c') {
        comandoIc(arqSaidaT, x, y, getCx(voidPointer1), getCy(voidPointer1),
                  getCr(voidPointer1));
      } else {
        if (caracter == 'r') {
          comandoIr(arqSaidaT, getRw(voidPointer1), getRh(voidPointer1),
                    getRx(voidPointer1), getRy(voidPointer1), x, y);
        }
      }
    } else {
      printf("Poligono não encontrado.\n");
      fillArq1(arqSaidaT, stringAux);
      fillBreakLine(arqSaidaT);
    }
    voidPointer1 = NULL;
  }
}

void executarO(FILE *arqEntradaGeo, FILE *arqSaidaT, Canvas canvas) {
  void *voidPointer1 = NULL, *voidPointer2 = NULL;
  int i, j;
  char caracter;
  char caracter1;
  double x, y, w, h;
  char stringAux[] = "none";
  char stringAux2[] = "Nao encontrados";
  Retangulo retangulo;

  if (arqSaidaT != NULL) {
    fscanf(arqEntradaGeo, "%d %d\n", &i, &j);
    caracter = 'o';
    fillArq(arqSaidaT, caracter);
    fillSpace(arqSaidaT);

    fillArq3(arqSaidaT, i);
    fillSpace(arqSaidaT);

    fillArq3(arqSaidaT, j);
    fillBreakLine(arqSaidaT);

    caracter = 'r';
    voidPointer1 = getRetangulo(canvas, i);
    if (voidPointer1 == NULL) {
      voidPointer1 = getCirculo(canvas, i);
      caracter = 'c';
    }

    caracter1 = 'r';
    voidPointer2 = getRetangulo(canvas, j);
    if (voidPointer2 == NULL) {
      voidPointer2 = getCirculo(canvas, j);
      caracter1 = 'c';
    }

    if (voidPointer1 != NULL && voidPointer2 != NULL) {
      if (caracter == 'c' && caracter1 == 'c') {
        caracter =
            comandoOcc(arqSaidaT, getCr(voidPointer1), getCx(voidPointer1),
                       getCy(voidPointer1), getCr(voidPointer2),
                       getCx(voidPointer2), getCy(voidPointer2));
        if (caracter == 't') {
          sobreposicaoCC(getCr(voidPointer1), getCx(voidPointer1),
                         getCy(voidPointer1), getCr(voidPointer2),
                         getCx(voidPointer2), getCy(voidPointer2), &w, &h, &x,
                         &y);
          retangulo = createRectangle(0, w, h, x, y, stringAux);
          insertRetangulo2(canvas, retangulo);
        }
      } else if (caracter == 'c' && caracter1 == 'r') {
        caracter = comandoOrc(arqSaidaT, getRw(voidPointer2),
                              getRh(voidPointer2), getRx(voidPointer2),
                              getRy(voidPointer2), getCr(voidPointer1),
                              getCx(voidPointer1), getCy(voidPointer1));
        if (caracter == 't') {
          sobreposicaoRC(getRw(voidPointer2), getRh(voidPointer2),
                         getRx(voidPointer2), getRy(voidPointer2),
                         getCr(voidPointer1), getCx(voidPointer1),
                         getCy(voidPointer1), &w, &h, &x, &y);
          retangulo = createRectangle(0, w, h, x, y, stringAux);
          insertRetangulo2(canvas, retangulo);
        }

      } else if (caracter == 'r' && caracter1 == 'c') {
        caracter = comandoOrc(arqSaidaT, getRw(voidPointer1),
                              getRh(voidPointer1), getRx(voidPointer1),
                              getRy(voidPointer1), getCr(voidPointer2),
                              getCx(voidPointer2), getCy(voidPointer2));
        if (caracter == 't') {
          sobreposicaoRC(getRw(voidPointer1), getRh(voidPointer1),
                         getRx(voidPointer1), getRy(voidPointer1),
                         getCr(voidPointer2), getCx(voidPointer2),
                         getCy(voidPointer2), &w, &h, &x, &y);
          retangulo = createRectangle(0, w, h, x, y, stringAux);
          insertRetangulo2(canvas, retangulo);
        }

      } else if (caracter == 'r' && caracter1 == 'r') {
        caracter = comandoOrr(
            arqSaidaT, getRw(voidPointer1), getRh(voidPointer1),
            getRx(voidPointer1), getRy(voidPointer1), getRw(voidPointer2),
            getRh(voidPointer2), getRx(voidPointer2), getRy(voidPointer2));
        if (caracter == 't') {
          sobreposicaoRR(
              getRw(voidPointer1), getRh(voidPointer1), getRx(voidPointer1),
              getRy(voidPointer1), getRw(voidPointer2), getRh(voidPointer2),
              getRx(voidPointer2), getRy(voidPointer2), &w, &h, &x, &y);
          retangulo = createRectangle(0, w, h, x, y, stringAux);
          insertRetangulo2(canvas, retangulo);
        }
      } else
        printf("ERRO EM COMANDO D.\n");
    } else {
      printf("Poligono não encontrado.\n");
      fillArq1(arqSaidaT, stringAux2);
      fillBreakLine(arqSaidaT);
    }
    retangulo = NULL;
    voidPointer1 = NULL;
    voidPointer2 = NULL;
  }
}

void executarA(FILE *arqEntradaGeo, Canvas canvas, char *arqNome, char *dirPath,
               char *extensao2) {
  char *string1 = NULL, *string2 = NULL, *string3 = NULL;
  char cor[60];
  char stringAux[] = "-";
  int i, n;
  double width, height;
  FILE *arqSaidaSvg2 = NULL;

  i = qtdCaracteres(arqEntradaGeo);
  string1 = alocarString(i);
  fscanf(arqEntradaGeo, "%s %s\n", string1, cor);
  n = strlen(arqNome);
  /* Concatena o sufixo no nome do arquivo de saida. */
  if (string1[0] != '-' && arqNome[n - 1] != '-') {
    string2 = concatenarStrings(arqNome, stringAux);
  } else if (string1[0] != '-' && arqNome[n - 1] == '-') {
    string2 = concatenarStrings(NULL, arqNome);
  } else {
    string2 = concatenarStrings(NULL, (arqNome + 1));
  }
  string3 = concatenarStrings(string2, string1);

  desalocar(string1);
  string1 = NULL;
  string1 = concatenarElementos(dirPath, string3, extensao2);
  arqSaidaSvg2 = createSvg(string1);
  width = getWidth(canvas);
  height = getHeight(canvas);
  tagAbertura(arqSaidaSvg2, width, height);
  desalocar(string1);
  string1 = NULL;
  desalocar(string2);
  string2 = NULL;
  desalocar(string3);
  string3 = NULL;

  newArqCanvas = arqSaidaSvg2;
  /* Escreve no arquivo de saida os retângulos. */
  showCanvasR(canvas, arqSaidaSvg2);

  /* Escreve no arquivo de saida os círculos. */
  showCanvasC(canvas, arqSaidaSvg2);

  tagFechamento(arqSaidaSvg2);
}

void executarQ(FILE *arqEntradaGeo, List list, Cor cor) {
  double w = 0, h = 0, x = 0, y = 0;
  int i;
  char *string;
  Quadra quadra;
  fscanf(arqEntradaGeo, "%lf %lf %lf %lf ", &x, &y, &w, &h);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);

  quadra = criaQuadra(x, y, w, h, string, getCorP(cor), getCorC(cor));

  insertEndDLL(list, quadra);

  desalocar(string);
  string = NULL;
}

void executarH(FILE *arqEntradaGeo, List list, Cor cor) {
  double x = 0, y = 0;
  Hidrante hidrante;
  int i;
  char *string;

  fscanf(arqEntradaGeo, "%lf %lf ", &x, &y);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);

  hidrante = criaHidrante(x, y, string, getCorP(cor), getCorC(cor));

  insertEndDLL(list, hidrante);

  desalocar(string);
  string = NULL;
}

void executarS(FILE *arqEntradaGeo, List list, Cor cor) {
  double x = 0, y = 0;
  int i;
  Semafaro semafaro;
  char *string;

  fscanf(arqEntradaGeo, "%lf %lf ", &x, &y);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);

  semafaro = criaSemafaro(x, y, string, getCorP(cor), getCorC(cor));

  insertEndDLL(list, semafaro);

  desalocar(string);
  string = NULL;
}

void executarT(FILE *arqEntradaGeo, List list, Cor cor) {
  double x = 0, y = 0;
  int i;
  Torre torre;
  char *string;

  fscanf(arqEntradaGeo, "%lf %lf ", &x, &y);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);

  torre = criaTorre(x, y, string, getCorP(cor), getCorC(cor));

  insertEndDLL(list, torre);

  desalocar(string);
  string = NULL;
}

Cor executarCq(FILE *arqEntradaGeo) {
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = criaCor(stringA, stringB, 1);
  return cor;
}

Cor executarCh(FILE *arqEntradaGeo) {
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = criaCor(stringA, stringB, 2);
  return cor;
}

Cor executarCt(FILE *arqEntradaGeo) {
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = criaCor(stringA, stringB, 3);
  return cor;
}

Cor executarCs(FILE *arqEntradaGeo) {
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = criaCor(stringA, stringB, 4);
  return cor;
}

void executarHI(FILE *arqEntradaGeo, Canvas canvas) {

  Hidrante hidrante = NULL;
  char *id;
  double vazao;
  int i;
  QuadTree quadT;
  i = qtdCaracteres(arqEntradaGeo);
  id = alocarString(i);
  fscanf(arqEntradaGeo, "%s %lf\n", id, &vazao);

  quadT = getListaH(getCidade(canvas));

  hidrante = searchQuadTreeItem(quadT, id, compareH);
  free(id);
  if (hidrante != NULL) {
    setVazao(hidrante, vazao);
  }
}

void executarTI(FILE *arqEntradaGeo, Canvas canvas) {

  Torre torre = NULL;
  char *id;
  double raio;
  int i;
  QuadTree quadT;
  i = qtdCaracteres(arqEntradaGeo);
  id = alocarString(i);
  fscanf(arqEntradaGeo, "%s %lf\n", id, &raio);

  quadT = getListaT(getCidade(canvas));

  torre = searchQuadTreeItem(quadT, id, compareT);
  free(id);
  if (torre != NULL) {
    setRaio(torre, raio);
  }
}

void executarSI(FILE *arqEntradaGeo, Canvas canvas) {

  Semafaro semafaro = NULL;
  char *id;
  double tempo;
  int i;
  QuadTree quadT;
  i = qtdCaracteres(arqEntradaGeo);
  id = alocarString(i);
  fscanf(arqEntradaGeo, "%s %lf\n", id, &tempo);

  quadT = getListaS(getCidade(canvas));

  semafaro = searchQuadTreeItem(quadT, id, compareT);
  free(id);
  if (semafaro != NULL) {
    setTempo(semafaro, tempo);
  }
}

char comandoOrr(FILE *arqSaidaT, double w1, double h1, double x1, double y1,
                double w2, double h2, double x2, double y2) {
  char palavra[] = "SIM";
  if (verificarSobreposicaoRR(w1, h1, x1, y1, w2, h2, x2, y2) == 't') {
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
    return 't';
  } else {
    palavra[0] = 'N';
    palavra[1] = 'A';
    palavra[2] = 'O';
    palavra[3] = '\0';
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
    return 'f';
  }
}

char comandoOrc(FILE *arqSaidaT, double w1, double h1, double x1, double y1,
                double r2, double x2, double y2) {
  char palavra[] = "SIM";
  if (verificarSobreposicaoRC(w1, h1, x1, y1, r2, x2, y2) == 't') {
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
    return 't';
  } else {
    palavra[0] = 'N';
    palavra[1] = 'A';
    palavra[2] = 'O';
    palavra[3] = '\0';
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
    return 'f';
  }
}

char comandoOcc(FILE *arqSaidaT, double r1, double x1, double y1, double r2,
                double x2, double y2) {
  char palavra[] = "SIM";
  if (verificarSobreposicaoCC(r1, x1, y1, r2, x2, y2) == 't') {
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);

    return 't';
  } else {
    palavra[0] = 'N';
    palavra[1] = 'A';
    palavra[2] = 'O';
    palavra[3] = '\0';
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
    return 'f';
  }
}

void comandoD(FILE *arqSaidaT, double x1, double y1, double x2, double y2) {
  float distancia;
  distancia = distanciaEntrePontos(x1, y1, x2, y2);
  fillArq2(arqSaidaT, distancia);
  fillBreakLine(arqSaidaT);
}

void comandoIc(FILE *arqSaidaT, double x1, double y1, double x2, double y2,
               double r) {
  char palavra[] = "SIM";
  if (pontoInternoC(r, x1, y1, x2, y2) == 't') {
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
  } else {
    palavra[0] = 'N';
    palavra[1] = 'A';
    palavra[2] = 'O';
    palavra[3] = '\0';
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
  }
}

void comandoIr(FILE *arqSaidaT, double w, double h, double x1, double y1,
               double x2, double y2) {
  char palavra[] = "SIM";
  if (pontoInternoR(w, h, x1, y1, x2, y2) == 't') {
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
  } else {
    palavra[0] = 'N';
    palavra[1] = 'A';
    palavra[2] = 'O';
    palavra[3] = '\0';
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
  }
}

Cor setCores(int type) {
  char corB[] = "black";
  char corP1[] = "red";
  char corP2[] = "blue";
  char corP3[] = "yellow";
  char corP4[] = "orange";
  Cor cor = NULL;
  switch (type) {
  case 1: /* Quadra. */
    cor = criaCor(corP1, corB, 1);
    break;
  case 4: /* Torre. */
    cor = criaCor(corP2, corB, 2);
    break;
  case 2: /* Hidrante. */
    cor = criaCor(corP3, corB, 3);
    break;
  case 3: /* Semafaro. */
    cor = criaCor(corP4, corB, 4);
    break;
  default:
    cor = criaCor(corB, corB, 5);
  }
  return cor;
}
