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

#include "Cor.h"
#include "DoubleLinkedList.h"
#include "QuadTree.h"
#include "StringO.h"
#include "Svg.h"
#include "Exibicao.h"

void executarC(FILE *arqEntradaGeo, Canvas canvas) {
  double x = 0, y = 0, r = 0, width, height;
  char cor[60];
  int i;

  Circulo circulo = NULL;
  fscanf(arqEntradaGeo, "%d %lf %lf %lf %s\n", &i, &r, &x, &y, cor);
  circulo = createCircle(i, r, x, y, cor);
  insertCirculo(canvas, circulo);
  width = getWidth(canvas);
  height = getHeight(canvas);
  if (x + r >= (width)) {
    setWidth(canvas, x + r);
  }
  if (y + r >= (height)) {
    setHeight(canvas, y + r);
  }
}

void executarR(FILE *arqEntradaGeo, Canvas canvas) {
  double w = 0, h = 0, x = 0, y = 0, width, height;
  char cor[60];
  int i = 0;
  Retangulo retangulo = NULL;
  fscanf(arqEntradaGeo, "%d %lf %lf %lf %lf %s\n", &i, &w, &h, &x, &y, cor);
  retangulo = createRectangle(i, w, h, x, y, cor);
  insertRetangulo(canvas, retangulo);
  width = getWidth(canvas);
  height = getHeight(canvas);
  if (x + w >= (width)) {
    setWidth(canvas, x + w);
  }
  if (y + h >= (height)) {
    setHeight(canvas, y + h);
  }
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
        comandoIc(arqSaidaT, x, y, getCx(voidPointer1), getCy(voidPointer1), getCr(voidPointer1));
      } else {
        if (caracter == 'r') {
          comandoIr(arqSaidaT, getRw(voidPointer1), getRh(voidPointer1), getRx(voidPointer1), getRy(voidPointer1), x, y);
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

void executarA(FILE *arqEntradaGeo, Canvas canvas, char *arqNome, char *dirPath, char *extensao2) {
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
  } else if(string1[0] != '-' && arqNome[n - 1] == '-'){
    string2 = concatenarStrings(NULL, arqNome);
  }else{
    string2 = concatenarStrings(NULL, (arqNome+1));
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

  globalFile = arqSaidaSvg2;
  /* Escreve no arquivo de saida os retângulos. */
  showCanvasR(canvas, arqSaidaSvg2);

  /* Escreve no arquivo de saida os círculos. */
  showCanvasC(canvas, arqSaidaSvg2);
  
  tagFechamento(arqSaidaSvg2);
}

void executarQ(FILE *arqEntradaGeo, Canvas canvas, int *qtdQuadrasInseridas) {
  double w = 0, h = 0, x = 0, y = 0;
  int i;
  char *string;
  Quadra quadra;
  Cidade cidade;
  fscanf(arqEntradaGeo, "%lf %lf %lf %lf ", &x, &y, &w, &h);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);
  quadra = criaQuadra(x, y, w, h, string);
  cidade = getCidade(canvas);
  insertQuadra(cidade, quadra);
  *qtdQuadrasInseridas = *qtdQuadrasInseridas + 1;
  if (x + w >= (getWidth(canvas))) {
    setWidth(canvas, x + w);
  }
  if (y + h >= (getHeight(canvas))) {
    setHeight(canvas, y + h);
  }
  desalocar(string);
  string = NULL;
}

void executarH(FILE *arqEntradaGeo, Canvas canvas) {
  double x = 0, y = 0;
  Hidrante hidrante;
  Cidade cidade;
  int i;
  char *string;
  fscanf(arqEntradaGeo, "%lf %lf ", &x, &y);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);
  hidrante = criaHidrante(x, y, string);
  cidade = getCidade(canvas);
  insertHidrante(cidade, hidrante);
  if (x + 5 >= (getWidth(canvas))) {
    setWidth(canvas, x + 5);
  }
  if (y + 5 >= (getHeight(canvas))) {
    setHeight(canvas, y + 5);
  }
  desalocar(string);
  string = NULL;
}

void executarS(FILE *arqEntradaGeo, Canvas canvas) {
  double x = 0, y = 0;
  int i;
  Semafaro semafaro;
  Cidade cidade;
  char *string;
  fscanf(arqEntradaGeo, "%lf %lf ", &x, &y);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);
  semafaro = criaSemafaro(x, y, string);
  cidade = getCidade(canvas);
  insertSemafaro(cidade, semafaro);
  if (x + 5 >= (getWidth(canvas))) {
    setWidth(canvas, x + 5);
  }
  if (y + 5 >= (getHeight(canvas))) {
    setHeight(canvas, y + 5);
  }
  desalocar(string);
  string = NULL;
}

void executarT(FILE *arqEntradaGeo, Canvas canvas) {
  double x = 0, y = 0;
  int i;
  Torre torre;
  Cidade cidade;
  char *string;
  fscanf(arqEntradaGeo, "%lf %lf ", &x, &y);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);
  torre = criaTorre(x, y, string);
  cidade = getCidade(canvas);
  insertTorre(cidade, torre);
  if (x + 5 >= (getWidth(canvas))) {
    setWidth(canvas, x + 5);
  }
  if (y + 5 >= (getHeight(canvas))) {
    setHeight(canvas, y + 5);
  }
  desalocar(string);
  string = NULL;
}

void executarCq(FILE *arqEntradaGeo, Canvas canvas) {
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = getCor(canvas, 1);
  setCorP(cor, stringA);
  setCorC(cor, stringB);
}

void executarCh(FILE *arqEntradaGeo, Canvas canvas) {
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = getCor(canvas, 4);
  setCorP(cor, stringA);
  setCorC(cor, stringB);
}

void executarCt(FILE *arqEntradaGeo, Canvas canvas) {
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = getCor(canvas, 3);
  setCorP(cor, stringA);
  setCorC(cor, stringB);
}

void executarCs(FILE *arqEntradaGeo, Canvas canvas) {
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = getCor(canvas, 2);
  setCorP(cor, stringA);
  setCorC(cor, stringB);
}

void executarHI(FILE *arqEntradaGeo, Canvas canvas) {

  Hidrante hidrante = NULL;
  char *id;
  double vazao;
  int i;
  i = qtdCaracteres(arqEntradaGeo);
  id = alocarString(i);
  fscanf(arqEntradaGeo, "%s %lf\n", id, &vazao);

  QuadTree quadT = getListaH(getCidade(canvas));

  hidrante = searchQuadTreeItem(quadT, id, compareH);

  if(hidrante != NULL){
    setVazao(hidrante, vazao);
  }

}

void executarTI(FILE *arqEntradaGeo, Canvas canvas) {

  Torre torre = NULL;
  char *id;
  double raio;
  int i;
  i = qtdCaracteres(arqEntradaGeo);
  id = alocarString(i);
  fscanf(arqEntradaGeo, "%s %lf\n", id, &raio);

  QuadTree quadT = getListaT(getCidade(canvas));

  torre = searchQuadTreeItem(quadT, id, compareT);

  if(torre != NULL){
    setRaio(torre, raio);
  }

}

void executarSI(FILE *arqEntradaGeo, Canvas canvas) {

  Semafaro semafaro = NULL;
  char *id;
  double tempo;
  int i;
  i = qtdCaracteres(arqEntradaGeo);
  id = alocarString(i);
  fscanf(arqEntradaGeo, "%s %lf\n", id, &tempo);

  QuadTree quadT = getListaS(getCidade(canvas));

  semafaro = searchQuadTreeItem(quadT, id, compareT);

  if(semafaro != NULL){
    setTempo(semafaro, tempo);
  }

}

char comandoOrr(FILE *arqSaidaT, double w1, double h1, double x1, double y1, double w2, double h2, double x2, double y2) {
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

char comandoOrc(FILE *arqSaidaT, double w1, double h1, double x1, double y1, double r2, double x2, double y2) {
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

char comandoOcc(FILE *arqSaidaT, double r1, double x1, double y1, double r2, double x2, double y2) {
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

void comandoIc(FILE *arqSaidaT, double x1, double y1, double x2, double y2, double r) {
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

void comandoIr(FILE *arqSaidaT, double w, double h, double x1, double y1, double x2, double y2) {
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
