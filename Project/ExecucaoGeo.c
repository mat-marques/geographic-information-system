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

#include "ConvexHull.h"
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
#include "Cor.h"
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
#include "DoubleLinkedList.h"
#include "QuadTree.h"
#include "Stack.h"
#include "StringO.h"
#include "Svg.h"
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
>>>>>>> Stashed changes
#include "Canvas.h"

void executarConvexHull(List list, Canvas canvas, int type) {
  int i, n;
  void *element = NULL;
  Stack stack;

  switch (type) {
  case 1: /* Quadra. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertQuadra(canvas, element);
    }
    break;
  case 2: /* Hidrante. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertHidrante(canvas, element);
    }
    break;
  case 3: /* semafaro. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertSemafaro(canvas, element);
    }
    break;
  case 4: /* Torre. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertTorre(canvas, element);
    }
    break;
  case 5: /* Retângulo. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertRetangulo(canvas, element);
    }
    break;
  case 6: /* Círculo. */
    stack = convexHullOfAll(list, 6);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertCirculo(canvas, element);
    }
    break;
  }

  eraseStackTwo(stack);
  eraseBaseStack(stack);
}

void executarAuxC(FILE *arqEntradaGeo, List list) {
  double x = 0, y = 0, r = 0;
=======
#include "Exibicao.h"

void executarC(FILE *arqEntradaGeo, Canvas canvas) {
  double x = 0, y = 0, r = 0, width, height;
>>>>>>> Stashed changes
=======
#include "Exibicao.h"

void executarC(FILE *arqEntradaGeo, Canvas canvas) {
  double x = 0, y = 0, r = 0, width, height;
>>>>>>> Stashed changes
=======

=======

>>>>>>> Stashed changes
void executarConvexHull(List list, Canvas canvas, int type) {
  int i, n;
  void *element = NULL;
  Stack stack;

  switch (type) {
  case 1: /* Quadra. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertQuadra(canvas, element);
    }
    break;
  case 2: /* Hidrante. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertHidrante(canvas, element);
    }
    break;
  case 3: /* semafaro. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertSemafaro(canvas, element);
    }
    break;
  case 4: /* Torre. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertTorre(canvas, element);
    }
    break;
  case 5: /* Retângulo. */
    stack = convexHullOfAll(list, 1);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertRetangulo(canvas, element);
    }
    break;
  case 6: /* Círculo. */
    stack = convexHullOfAll(list, 6);
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = removeTopI(stack);
      insertCirculo(canvas, element);
    }
    break;
  }

  eraseStackTwo(stack);
  eraseBaseStack(stack);
}

void executarAuxC(FILE *arqEntradaGeo, List list) {
  double x = 0, y = 0, r = 0;
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
  char cor[60];
  int i;

  Circulo circulo = NULL;
  fscanf(arqEntradaGeo, "%d %lf %lf %lf %s\n", &i, &r, &x, &y, cor);
  circulo = createCircle(i, r, x, y, cor);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  insertEndDLL(list, circulo);
}

void executarAuxR(FILE *arqEntradaGeo, List list) {
  double w = 0, h = 0, x = 0, y = 0;
=======
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
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
  insertEndDLL(list, circulo);
}

void executarAuxR(FILE *arqEntradaGeo, List list) {
  double w = 0, h = 0, x = 0, y = 0;
>>>>>>> Stashed changes
=======
  insertEndDLL(list, circulo);
}

void executarAuxR(FILE *arqEntradaGeo, List list) {
  double w = 0, h = 0, x = 0, y = 0;
>>>>>>> Stashed changes
  char cor[60];
  int i = 0;
  Retangulo retangulo = NULL;
  fscanf(arqEntradaGeo, "%d %lf %lf %lf %lf %s\n", &i, &w, &h, &x, &y, cor);
  retangulo = createRectangle(i, w, h, x, y, cor);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  insertEndDLL(list, retangulo);
=======
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
  insertEndDLL(list, retangulo);
>>>>>>> Stashed changes
=======
  insertEndDLL(list, retangulo);
>>>>>>> Stashed changes
}

void executarD(FILE *arqEntradaGeo,  FILE *arqSaidaT, Canvas canvas) {
  void *voidPointer1 = NULL;
  int i, j;
  char caracter;
  char stringAux[] = "Nao encontrados";
  if (arqSaidaT != NULL) {
    fscanf(arqEntradaGeo, "%d %d\n", &i, &j);
    caracter = 'd';
    fillArq(arqSaidaT, caracter);
    fillSpace(arqSaidaT);

    fillArq3(arqSaidaT, i);
    fillSpace(arqSaidaT);

    fillArq2(arqSaidaT, j);
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
        comandoIc(arqSaidaT, x, y, getCx(voidPointer1), getCy(voidPointer1),
                  getCr(voidPointer1));
      } else {
        if (caracter == 'r') {
          comandoIr(arqSaidaT, getRw(voidPointer1), getRh(voidPointer1),
                    getRx(voidPointer1), getRy(voidPointer1), x, y);
=======
=======
>>>>>>> Stashed changes
        comandoIc(arqSaidaT, x, y, getCx(voidPointer1), getCy(voidPointer1), getCr(voidPointer1));
      } else {
        if (caracter == 'r') {
          comandoIr(arqSaidaT, getRw(voidPointer1), getRh(voidPointer1), getRx(voidPointer1), getRy(voidPointer1), x, y);
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
        comandoIc(arqSaidaT, x, y, getCx(voidPointer1), getCy(voidPointer1),
                  getCr(voidPointer1));
      } else {
        if (caracter == 'r') {
          comandoIr(arqSaidaT, getRw(voidPointer1), getRh(voidPointer1),
                    getRx(voidPointer1), getRy(voidPointer1), x, y);
>>>>>>> Stashed changes
=======
        comandoIc(arqSaidaT, x, y, getCx(voidPointer1), getCy(voidPointer1),
                  getCr(voidPointer1));
      } else {
        if (caracter == 'r') {
          comandoIr(arqSaidaT, getRw(voidPointer1), getRh(voidPointer1),
                    getRx(voidPointer1), getRy(voidPointer1), x, y);
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
void executarA(FILE *arqEntradaGeo, Canvas canvas, char *arqNome, char *dirPath,
               char *extensao2) {
=======
void executarA(FILE *arqEntradaGeo, Canvas canvas, char *arqNome, char *dirPath, char *extensao2) {
>>>>>>> Stashed changes
=======
void executarA(FILE *arqEntradaGeo, Canvas canvas, char *arqNome, char *dirPath, char *extensao2) {
>>>>>>> Stashed changes
=======
void executarA(FILE *arqEntradaGeo, Canvas canvas, char *arqNome, char *dirPath,
               char *extensao2) {
>>>>>>> Stashed changes
=======
void executarA(FILE *arqEntradaGeo, Canvas canvas, char *arqNome, char *dirPath,
               char *extensao2) {
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  } else if (string1[0] != '-' && arqNome[n - 1] == '-') {
    string2 = concatenarStrings(NULL, arqNome);
  } else {
    string2 = concatenarStrings(NULL, (arqNome + 1));
=======
=======
>>>>>>> Stashed changes
  } else if(string1[0] != '-' && arqNome[n - 1] == '-'){
    string2 = concatenarStrings(NULL, arqNome);
  }else{
    string2 = concatenarStrings(NULL, (arqNome+1));
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
  } else if (string1[0] != '-' && arqNome[n - 1] == '-') {
    string2 = concatenarStrings(NULL, arqNome);
  } else {
    string2 = concatenarStrings(NULL, (arqNome + 1));
>>>>>>> Stashed changes
=======
  } else if (string1[0] != '-' && arqNome[n - 1] == '-') {
    string2 = concatenarStrings(NULL, arqNome);
  } else {
    string2 = concatenarStrings(NULL, (arqNome + 1));
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  newArqCanvas = arqSaidaSvg2;
=======
  globalFile = arqSaidaSvg2;
>>>>>>> Stashed changes
=======
  globalFile = arqSaidaSvg2;
>>>>>>> Stashed changes
=======
  newArqCanvas = arqSaidaSvg2;
>>>>>>> Stashed changes
  /* Escreve no arquivo de saida os retângulos. */
  showCanvasR(canvas, arqSaidaSvg2);

  /* Escreve no arquivo de saida os círculos. */
  showCanvasC(canvas, arqSaidaSvg2);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream

  tagFechamento(arqSaidaSvg2);
}

void executarAuxQ(FILE *arqEntradaGeo, List list, Cor cor) {
=======
=======
>>>>>>> Stashed changes
  
  tagFechamento(arqSaidaSvg2);
}

void executarQ(FILE *arqEntradaGeo, Canvas canvas, int *qtdQuadrasInseridas) {
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======

  tagFechamento(arqSaidaSvg2);
}

void executarAuxQ(FILE *arqEntradaGeo, List list) {
>>>>>>> Stashed changes
=======

  tagFechamento(arqSaidaSvg2);
}

void executarAuxQ(FILE *arqEntradaGeo, List list) {
>>>>>>> Stashed changes
  double w = 0, h = 0, x = 0, y = 0;
  int i;
  char *string;
  Quadra quadra;

  fscanf(arqEntradaGeo, "%lf %lf %lf %lf ", &x, &y, &w, &h);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream

  quadra = criaQuadra(x, y, w, h, string, getCorP(cor), getCorC(cor));

  insertEndDLL(list, quadra);

=======
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
>>>>>>> Stashed changes
=======

  quadra = criaQuadra(x, y, w, h, string);

  insertEndDLL(list, quadra);

>>>>>>> Stashed changes
=======

  quadra = criaQuadra(x, y, w, h, string);

  insertEndDLL(list, quadra);

>>>>>>> Stashed changes
  desalocar(string);
  string = NULL;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
void executarAuxH(FILE *arqEntradaGeo, List list, Cor cor) {
=======
void executarH(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarH(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarAuxH(FILE *arqEntradaGeo, List list) {
>>>>>>> Stashed changes
=======
void executarAuxH(FILE *arqEntradaGeo, List list) {
>>>>>>> Stashed changes
  double x = 0, y = 0;
  Hidrante hidrante;
  int i;
  char *string;

  fscanf(arqEntradaGeo, "%lf %lf ", &x, &y);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream

  hidrante = criaHidrante(x, y, string, getCorP(cor), getCorC(cor));

  insertEndDLL(list, hidrante);

=======
  hidrante = criaHidrante(x, y, string);
  cidade = getCidade(canvas);
  insertHidrante(cidade, hidrante);
  if (x + 5 >= (getWidth(canvas))) {
    setWidth(canvas, x + 5);
  }
  if (y + 5 >= (getHeight(canvas))) {
    setHeight(canvas, y + 5);
  }
>>>>>>> Stashed changes
=======

  hidrante = criaHidrante(x, y, string);

  insertEndDLL(list, hidrante);

>>>>>>> Stashed changes
=======

  hidrante = criaHidrante(x, y, string);

  insertEndDLL(list, hidrante);

>>>>>>> Stashed changes
  desalocar(string);
  string = NULL;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
void executarAuxS(FILE *arqEntradaGeo, List list, Cor cor) {
=======
void executarS(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarS(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarAuxS(FILE *arqEntradaGeo, List list) {
>>>>>>> Stashed changes
=======
void executarAuxS(FILE *arqEntradaGeo, List list) {
>>>>>>> Stashed changes
  double x = 0, y = 0;
  int i;
  Semafaro semafaro;
  char *string;

  fscanf(arqEntradaGeo, "%lf %lf ", &x, &y);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream

  semafaro = criaSemafaro(x, y, string, getCorP(cor), getCorC(cor));

  insertEndDLL(list, semafaro);

=======
  semafaro = criaSemafaro(x, y, string);
  cidade = getCidade(canvas);
  insertSemafaro(cidade, semafaro);
  if (x + 5 >= (getWidth(canvas))) {
    setWidth(canvas, x + 5);
  }
  if (y + 5 >= (getHeight(canvas))) {
    setHeight(canvas, y + 5);
  }
>>>>>>> Stashed changes
=======

  semafaro = criaSemafaro(x, y, string);

  insertEndDLL(list, semafaro);

>>>>>>> Stashed changes
=======

  semafaro = criaSemafaro(x, y, string);

  insertEndDLL(list, semafaro);

>>>>>>> Stashed changes
  desalocar(string);
  string = NULL;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
void executarAuxT(FILE *arqEntradaGeo, List list, Cor cor) {
=======
void executarT(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarT(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarAuxT(FILE *arqEntradaGeo, List list) {
>>>>>>> Stashed changes
=======
void executarAuxT(FILE *arqEntradaGeo, List list) {
>>>>>>> Stashed changes
  double x = 0, y = 0;
  int i;
  Torre torre;
  char *string;

  fscanf(arqEntradaGeo, "%lf %lf ", &x, &y);
  i = qtdCaracteres(arqEntradaGeo);
  string = alocarString(i);
  fscanf(arqEntradaGeo, "%s\n", string);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream

  torre = criaTorre(x, y, string, getCorP(cor), getCorC(cor));

  insertEndDLL(list, torre);

=======
  torre = criaTorre(x, y, string);
  cidade = getCidade(canvas);
  insertTorre(cidade, torre);
  if (x + 5 >= (getWidth(canvas))) {
    setWidth(canvas, x + 5);
  }
  if (y + 5 >= (getHeight(canvas))) {
    setHeight(canvas, y + 5);
  }
>>>>>>> Stashed changes
=======

  torre = criaTorre(x, y, string);

  insertEndDLL(list, torre);

>>>>>>> Stashed changes
=======

  torre = criaTorre(x, y, string);

  insertEndDLL(list, torre);

>>>>>>> Stashed changes
  desalocar(string);
  string = NULL;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
Cor executarCq(FILE *arqEntradaGeo) {
=======
void executarCq(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarCq(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = criaCor(stringA, stringB, 1);
  return cor;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
Cor executarCh(FILE *arqEntradaGeo) {
=======
void executarCh(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarCh(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
char *executarCq(FILE *arqEntradaGeo) {
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  setCorP(cor, stringA);
  setCorC(cor, stringB);
  cor = criaCor();
  return cor;
}

void executarCh(FILE *arqEntradaGeo) {
>>>>>>> Stashed changes
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = criaCor(stringA, stringB, 2);
  return cor;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
Cor executarCt(FILE *arqEntradaGeo) {
=======
void executarCt(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarCt(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarCt(FILE *arqEntradaGeo) {
>>>>>>> Stashed changes
  char stringA[100], stringB[100];
  Cor cor = NULL;
  fscanf(arqEntradaGeo, "%s %s\n", stringA, stringB);
  cor = criaCor(stringA, stringB, 3);
  return cor;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
Cor executarCs(FILE *arqEntradaGeo) {
=======
void executarCs(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarCs(FILE *arqEntradaGeo, Canvas canvas) {
>>>>>>> Stashed changes
=======
void executarCs(FILE *arqEntradaGeo) {
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  if (hidrante != NULL) {
    setVazao(hidrante, vazao);
  }
=======
=======
>>>>>>> Stashed changes
  if(hidrante != NULL){
    setVazao(hidrante, vazao);
  }

>>>>>>> Stashed changes
=======
  if (hidrante != NULL) {
    setVazao(hidrante, vazao);
  }
>>>>>>> Stashed changes
=======
  if (hidrante != NULL) {
    setVazao(hidrante, vazao);
  }
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  if (torre != NULL) {
    setRaio(torre, raio);
  }
=======
=======
>>>>>>> Stashed changes
  if(torre != NULL){
    setRaio(torre, raio);
  }

>>>>>>> Stashed changes
=======
  if (torre != NULL) {
    setRaio(torre, raio);
  }
>>>>>>> Stashed changes
=======
  if (torre != NULL) {
    setRaio(torre, raio);
  }
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
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
=======
  if(semafaro != NULL){
=======
  if (semafaro != NULL) {
>>>>>>> Stashed changes
    setTempo(semafaro, tempo);
  }
}

char comandoOrr(FILE *arqSaidaT, double w1, double h1, double x1, double y1,
                double w2, double h2, double x2, double y2) {
  char palavra[] = "SIM";
  if (verificarSobreposicaoRR(w1, h1, x1, y1, w2, h2, x2, y2) == 't') {
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
char comandoOcc(FILE *arqSaidaT, double r1, double x1, double y1, double r2,
                double x2, double y2) {
  char palavra[] = "SIM";
  if (verificarSobreposicaoCC(r1, x1, y1, r2, x2, y2) == 't') {
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);

=======
=======
  if(semafaro != NULL){
=======
  if (semafaro != NULL) {
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
>>>>>>> Stashed changes
char comandoOrc(FILE *arqSaidaT, double w1, double h1, double x1, double y1, double r2, double x2, double y2) {
=======
char comandoOrc(FILE *arqSaidaT, double w1, double h1, double x1, double y1,
                double r2, double x2, double y2) {
>>>>>>> Stashed changes
=======
char comandoOrc(FILE *arqSaidaT, double w1, double h1, double x1, double y1,
                double r2, double x2, double y2) {
>>>>>>> Stashed changes
  char palavra[] = "SIM";
  if (verificarSobreposicaoRC(w1, h1, x1, y1, r2, x2, y2) == 't') {
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
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
=======
char comandoOcc(FILE *arqSaidaT, double r1, double x1, double y1, double r2, double x2, double y2) {
=======
char comandoOcc(FILE *arqSaidaT, double r1, double x1, double y1, double r2,
                double x2, double y2) {
>>>>>>> Stashed changes
  char palavra[] = "SIM";
  if (verificarSobreposicaoCC(r1, x1, y1, r2, x2, y2) == 't') {
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);

    return 't';
>>>>>>> Stashed changes
  } else {
    palavra[0] = 'N';
    palavra[1] = 'A';
    palavra[2] = 'O';
    palavra[3] = '\0';
    fillArq1(arqSaidaT, palavra);
    fillBreakLine(arqSaidaT);
<<<<<<< Updated upstream
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

Cor setCores(int type){
  char corB[] = "black";
  char corP1[] = "red";
  char corP2[] = "blue";
  char corP3[] = "yellow";
  char corP4[] = "orange";
  Cor cor = NULL;
  switch(type){
    case 1: /* Quadra. */
      cor = criaCor(corP1, corB, 1);
      break;
    case 2: /* Torre. */
      cor = criaCor(corP2, corB, 2);
      break;
    case 3: /* Hidrante. */
      cor = criaCor(corP3, corB, 3);
      break;
    case 4: /* Semafaro. */
      cor = criaCor(corP4, corB, 4);
      break;
    default: cor = criaCor(corB, corB, 5);
  }
  return cor;
=======
char comandoOcc(FILE *arqSaidaT, double r1, double x1, double y1, double r2, double x2, double y2) {
=======
char comandoOcc(FILE *arqSaidaT, double r1, double x1, double y1, double r2,
                double x2, double y2) {
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
=======
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

<<<<<<< Updated upstream
>>>>>>> Stashed changes
void comandoIr(FILE *arqSaidaT, double w, double h, double x1, double y1, double x2, double y2) {
=======
void comandoIr(FILE *arqSaidaT, double w, double h, double x1, double y1,
               double x2, double y2) {
>>>>>>> Stashed changes
=======
void comandoIr(FILE *arqSaidaT, double w, double h, double x1, double y1,
               double x2, double y2) {
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
}
