#include "Processamento.h"

#include "OpEntrada.h"
#include "OperacoesF.h"

#include "Arquivo.h"
#include "Cidade.h"
#include "Cor.h"

#include "StringO.h"
#include "Svg.h"

#include "ExecucaoEcPmTmVia.h"
#include "ExecucaoGeo.h"
#include "ExecucaoQry.h"
#include "ExecucaoQry2.h"
#include "ExecucaoQry3.h"

void abrirArquivos(FILE **arqEntradaGeo, FILE **arqEntradaQry,
                   FILE **arqEntradaEc, FILE **arqEntradaPm,
                   FILE **arqEntradaTm, FILE **arqEntradaVia, char **arqNome,
                   char **dirPath, char **exitFileSvg, char **exitFileGeoViaSvg, char *acc0, char *acc,
                   char **argv, int argc) {
  char *string0 = NULL, *string1 = NULL, *string2 = NULL, *string3 = NULL,
       *string4 = NULL;
  char extensao2[] = ".svg", *string5 = NULL, *string6 = NULL;
  char travessao[] = "-";

  parametroId(argv, argc);
  string0 = parametroE(argv, argc);
  string1 = parametroF(argv, argc);
  if (string0 != NULL) {
    string2 = concatenarElementos2(string0, string1);
    if (string2 != NULL) {
      *arqEntradaGeo = createArqR(string2);
      *arqNome = nomeArquivo(string1);
    }
  } else {
    if (string1 != NULL) {
      *arqEntradaGeo = createArqR(string1);
      *arqNome = nomeArquivo(string1);
    } else {
      exit(0);
    }
  }

  desalocar(string1);
  desalocar(string2);
  string1 = NULL;
  string2 = NULL;

  string1 = criarString(*arqNome);
  string6 = concatenarStrings(string1, travessao);

  desalocar(string1);
  string1 = NULL;

  *dirPath = parametroO(argv, argc);

  string1 = parametroQ(argv, argc);

  if (string1 != NULL) {
    if (string0 != NULL) {
      string2 = concatenarElementos2(string0, string1);
      *arqEntradaQry = createArqR(string2);
      desalocar(string2);
      string2 = NULL;
      desalocar(string0);
      string0 = NULL;
      string2 = nomeArquivo(string1);
      string0 = concatenarStrings(*arqNome, travessao);
      free(*arqNome);
      *arqNome = NULL;
      *arqNome = concatenarStrings(string0, string2);
    } else {
      *arqEntradaQry = createArqR(string1);
      string0 = nomeArquivo(string1);
      string2 = concatenarStrings(*arqNome, travessao);
      free(*arqNome);
      *arqNome = NULL;
      *arqNome = concatenarStrings(string2, string0);
    }
  }

  *exitFileSvg = concatenarElementos(*dirPath, *arqNome, extensao2);

  desalocar(string0);
  desalocar(string1);
  desalocar(string2);
  string0 = NULL;
  string1 = NULL;
  string2 = NULL;
  string3 = NULL;

  string0 = parametroEc(argv, argc);

  string1 = parametroPm(argv, argc);

  string2 = parametroTm(argv, argc);

  string3 = parametroV(argv, argc);

  string4 = parametroE(argv, argc);

  if (string4 != NULL) {
    if (string0 != NULL) {
      string5 = concatenarElementos2(string4, string0);
      *arqEntradaEc = createArqR(string5);
    }
    desalocar(string5);
    string5 = NULL;
    if (string1 != NULL) {
      string5 = concatenarElementos2(string4, string1);
      *arqEntradaPm = createArqR(string5);
    }
    desalocar(string5);
    string5 = NULL;
    if (string2 != NULL) {
      string5 = concatenarElementos2(string4, string2);
      *arqEntradaTm = createArqR(string5);
    }
    desalocar(string5);
    string5 = NULL;
    if (string3 != NULL) {
      string5 = concatenarElementos2(string4, string3);
      *arqEntradaVia = createArqR(string5);

      desalocar(string5);
      string5 = NULL;

      string5 = concatenarStrings(string6, string3);

      desalocar(string6);
      string6 = NULL;

      *exitFileGeoViaSvg = concatenarElementos(*dirPath, string5, extensao2);
    }
    desalocar(string5);
    string5 = NULL;
  } else {
    if (string0 != NULL) {
      *arqEntradaEc = createArqR(string0);
    }

    if (string1 != NULL) {
      *arqEntradaPm = createArqR(string1);
    }

    if (string2 != NULL) {
      *arqEntradaTm = createArqR(string2);
    }

    if (string3 != NULL) {
      *arqEntradaVia = createArqR(string3);

      string5 = concatenarStrings(string6, string3);

      desalocar(string6);
      string6 = NULL;

      *exitFileGeoViaSvg = concatenarElementos(*dirPath, string5, extensao2);
    }
  }

  desalocar(string0);
  desalocar(string1);
  desalocar(string2);
  desalocar(string3);
  desalocar(string4);
  desalocar(string5);
  desalocar(string6);
  string0 = NULL;
  string1 = NULL;
  string2 = NULL;

  *acc0 = parametroAcc0(argv, argc);

  *acc = parametroAcc(argv, argc);
}

long int executarComandosGeo(FILE *arqEntradaGeo, char *arqNome, char *dirPath,
                             Canvas canvas, int *qtdQuadrasInseridas,
                             long int *qtdCompararacoesI) {
  char boolean = 't';
  char *string1 = NULL, entradaA[6];
  char extensao1[] = ".txt";
  char extensao2[] = ".svg";
  char secao5[] = "cepXquadra", secao16[] = "operadoraXtorre";
  Dicionario dicionario = NULL;
  HashTable hash = NULL;
  FILE *arqSaidaT = NULL;

  List quadras = NULL, semafaros = NULL, torres = NULL, hidrantes = NULL,
       retangulos = NULL, circulos = NULL;

  Cor cq = NULL, cs = NULL, ct = NULL, ch = NULL;
  int bool1 = 0, bool2 = 0, bool3 = 0, bool4 = 0, myCont = 0;
  long int cont = 0;

  /*  Listas auxiliares. */
  quadras = createL();
  semafaros = createL();
  torres = createL();
  hidrantes = createL();
  retangulos = createL();
  circulos = createL();

  /*  Cores dos objetos. */
  cq = setCores(1);
  ct = setCores(2);
  ch = setCores(3);
  cs = setCores(4);

  dicionario = getDicionario(getCidade(canvas));

  if (arqEntradaGeo == NULL) {
    printf("ERRO EM ABERTURA DE ARQUIVO GEO.\n");
    exit(0);
  }

  while (1) {
    fscanf(arqEntradaGeo, "%s ", entradaA);

    if (entradaA[0] == '#') {
      break;
    }
    /* printf("%s %d\n", entradaA, myCont); */
    myCont++;
    if (boolean == 't' &&
        (entradaA[0] == 'o' || entradaA[0] == 'i' || entradaA[0] == 'd')) {
      /*  Abre o arquivo de saída .txt. */
      string1 = concatenarElementos(dirPath, arqNome, extensao1);
      arqSaidaT = createArqW(string1);
      desalocar(string1);
      string1 = NULL;
      boolean = 'f';
    }

    if ((entradaA[0] == 'o' || entradaA[0] == 'i' || entradaA[0] == 'd' ||
         entradaA[0] == 'a') &&
        (bool1 == 0)) {
      cont = cont + executarConvexHull(retangulos, canvas, 5);
      cont = cont + executarConvexHull(circulos, canvas, 6);
      bool1 = 1;
    }

    if (strcmp(entradaA, "cq") == 0) {
      removeCor(cq);
      cq = executarCq(arqEntradaGeo);
    } else if (strcmp(entradaA, "ch") == 0) {
      removeCor(ch);
      ch = executarCh(arqEntradaGeo);
    } else if (strcmp(entradaA, "ct") == 0) {
      removeCor(ct);
      ct = executarCt(arqEntradaGeo);
    } else if (strcmp(entradaA, "cs") == 0) {
      removeCor(cs);
      cs = executarCs(arqEntradaGeo);
    } else if (strcmp(entradaA, "hI") == 0) {
      if (bool2 == 0) {
        cont = cont + executarConvexHull(hidrantes, canvas, 2);
        bool2 = 1;
      }
      executarHI(arqEntradaGeo, canvas);
    } else if (strcmp(entradaA, "tI") == 0) {
      if (bool3 == 0) {
        cont = cont + executarConvexHull(torres, canvas, 4);
        bool3 = 1;
      }
      executarTI(arqEntradaGeo, canvas);
    } else if (strcmp(entradaA, "sI") == 0) {
      if (bool4 == 0) {
        cont = cont + executarConvexHull(semafaros, canvas, 3);
        bool4 = 1;
      }
      executarSI(arqEntradaGeo, canvas);
    } else if (strcmp(entradaA, "su") == 0) {
      hash = getSecaoDicionario(dicionario, secao16);
      executarGeoSu(arqEntradaGeo, canvas, hash);
    } else if (strcmp(entradaA, "um") == 0) {
      hash = getSecaoDicionario(dicionario, secao16);
      executarGeoUm(arqEntradaGeo, canvas, hash);
    } else if (entradaA[0] == 'c') {
      executarC(arqEntradaGeo, circulos);
    } else if (entradaA[0] == 'r') {
      executarR(arqEntradaGeo, retangulos);
    } else if (entradaA[0] == 'q') {
      *qtdQuadrasInseridas = *qtdQuadrasInseridas + 1;
      hash = getSecaoDicionario(dicionario, secao5);
      executarQ(arqEntradaGeo, quadras, cq, hash);
    } else if (entradaA[0] == 'h') {
      executarH(arqEntradaGeo, hidrantes, ch);
    } else if (entradaA[0] == 't') {
      executarT(arqEntradaGeo, torres, ct);
    } else if (entradaA[0] == 's') {
      executarS(arqEntradaGeo, semafaros, cs);
    } else if (entradaA[0] == 'd') {
      executarD(arqEntradaGeo, arqSaidaT, canvas);
    } else if (entradaA[0] == 'i') {
      executarI(arqEntradaGeo, arqSaidaT, canvas);
    } else if (entradaA[0] == 'o') {
      executarO(arqEntradaGeo, arqSaidaT, canvas);
    } else {
      if (entradaA[0] == 'a') {
        executarA(arqEntradaGeo, canvas, arqNome, dirPath, extensao2);
      }
    }
    entradaA[0] = '\0';
  }

  if (bool1 == 0) {
    if (lengthL(retangulos))
      cont = cont + executarConvexHull(retangulos, canvas, 5);

    if (lengthL(circulos))
      cont = cont + executarConvexHull(circulos, canvas, 6);

    bool1 = 1;
  }

  if (bool2 == 0) {
    if (lengthL(hidrantes))
      cont = cont + executarConvexHull(hidrantes, canvas, 2);
    bool2 = 1;
  }

  if (bool3 == 0) {
    if (lengthL(torres))
      cont = cont + executarConvexHull(torres, canvas, 4);
    bool3 = 1;
  }

  if (bool4 == 0) {
    if (lengthL(semafaros))
      cont = cont + executarConvexHull(semafaros, canvas, 3);
    bool4 = 1;
  }

  if (lengthL(quadras) > 0) {
    *qtdCompararacoesI = executarConvexHull(quadras, canvas, 1);
    cont = cont + *qtdCompararacoesI;
  }

  eraseListL(retangulos, NULL);
  eraseBase(retangulos);

  eraseListL(circulos, NULL);
  eraseBase(circulos);

  eraseListL(quadras, NULL);
  eraseBase(quadras);

  eraseListL(torres, NULL);
  eraseBase(torres);

  eraseListL(semafaros, NULL);
  eraseBase(semafaros);

  eraseListL(hidrantes, NULL);
  eraseBase(hidrantes);

  removeCor(cq);
  removeCor(cs);
  removeCor(ct);
  removeCor(ch);
  if (arqSaidaT != NULL) {
    fclose(arqSaidaT);
  }

  return cont;
}

long int executarComandosQry(FILE *arqEntradaQry, char *arqNome, char *dirPath,
                             Canvas canvas, int *qtdQuadrasRemovidas,
                             long int *qtdCompararacoesR,
                             int *qtdElementosRemovidos) {
  char *path = NULL, *path2,entradaA[6];
  char extensao1[] = ".txt";
  char extensao2[] = ".svg";
  FILE *arqSaidaT = NULL;
  long int cont = 0;
  path = concatenarElementos(dirPath, arqNome, extensao1);
  path2 = concatenarElementos2(dirPath, arqNome);

  if (arqEntradaQry != NULL) {
    arqSaidaT = createArqW(path);
  }

  if (arqEntradaQry != NULL) {
    while (1) {

      if (feof(arqEntradaQry) != 0) {
        break;
      }
      if (fscanf(arqEntradaQry, "%s ", entradaA) < 0) {
        break;
      }

      if (strcmp(entradaA, "dq") == 0) {
        *qtdCompararacoesR =
            *qtdCompararacoesR + executardq(arqEntradaQry, &arqSaidaT, path,
                                            canvas, qtdQuadrasRemovidas);
        cont = cont + *qtdCompararacoesR;
        *qtdElementosRemovidos = *qtdElementosRemovidos + *qtdQuadrasRemovidas;
      } else if (strcmp(entradaA, "dh") == 0) {
        cont = cont + executardh(arqEntradaQry, &arqSaidaT, path, canvas,
                                 qtdElementosRemovidos);
      } else if (strcmp(entradaA, "ds") == 0) {
        cont = cont + executards(arqEntradaQry, &arqSaidaT, path, canvas,
                                 qtdElementosRemovidos);
      } else if (strcmp(entradaA, "dt") == 0) {
        cont = cont + executardt(arqEntradaQry, &arqSaidaT, path, canvas,
                                 qtdElementosRemovidos);
      } else if (strcmp(entradaA, "Dq") == 0) {
        cont = cont + executarDq(arqEntradaQry, &arqSaidaT, path, canvas,
                                 qtdQuadrasRemovidas);
        *qtdElementosRemovidos = *qtdElementosRemovidos + *qtdQuadrasRemovidas;
      } else if (strcmp(entradaA, "Dh") == 0) {
        cont = cont + executarDh(arqEntradaQry, &arqSaidaT, path, canvas,
                                 qtdElementosRemovidos);
      } else if (strcmp(entradaA, "Ds") == 0) {
        cont = cont + executarDs(arqEntradaQry, &arqSaidaT, path, canvas,
                                 qtdElementosRemovidos);
      } else if (strcmp(entradaA, "pc?") == 0) {
        executarPc(arqEntradaQry, arqNome, dirPath, extensao2, canvas);
      } else if (strcmp(entradaA, "ac?") == 0) {
        fseek(arqEntradaQry, -1, SEEK_CUR);
        executarAc(arqEntradaQry, &arqSaidaT, path, canvas);
      } else if (strcmp(entradaA, "Dt") == 0) {
        executarDt(arqEntradaQry, &arqSaidaT, path, canvas,
                   qtdElementosRemovidos);
      } else if (strcmp(entradaA, "crd?") == 0) {
        executarCrd(arqEntradaQry, &arqSaidaT, path, canvas);
      } else if (strcmp(entradaA, "mv") == 0) {
        executarQryMv(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "m?") == 0) {
        executarQryM(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "mr?") == 0) {
        executarQryMr(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "dm?") == 0) {
        executarQryDm(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "de?") == 0) {
        executarQryDe(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "con") == 0) {
        executarQryCon(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "mse?") == 0) {
        executarQryMse(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "rip") == 0) {
        executarQryRip(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "lk?") == 0) {
        executarQryLk(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "rb?") == 0) {
        executarQryRb(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "co?") == 0) {
        executarQryCo(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "lnr?") == 0) {
        executarQryLnr(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "ecq?") == 0) {
        executarQryEcq(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "ecr?") == 0) {
        executarQryEcr(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "tecq?") == 0) {
        executarQryTecq(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "tecr?") == 0) {
        executarQryTecr(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "dc?") == 0) {
        executarQryDc(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "lec?") == 0) {
        executarQryLec(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "lcc?") == 0) {
        executarQryLcc(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "dpr") == 0) {
        executarQryDpr(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "@f?") == 0) {
        executarQryF(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "@m?") == 0) {
        executarQryM2(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "@e?") == 0) {
        executarQryE(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "@g?") == 0) {
        executarQryG(arqEntradaQry, &arqSaidaT, canvas);
      } else if ((strcmp(entradaA, "@xy?") == 0) || (strcmp(entradaA, "@xy") == 0)) {
        executarQryXY(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "@tp?") == 0) {
        executarQryTP(arqEntradaQry, &arqSaidaT, canvas);
      } else if (strcmp(entradaA, "p?") == 0) {
        executarQryP(arqEntradaQry, &arqSaidaT, path2, canvas);
      } else {
        printf("Comando invalido no qry\n");
      }
    }
    entradaA[0] = '\0';
  }
  desalocar(path);
  desalocar(path2);
  if (arqSaidaT != NULL) {
    fclose(arqSaidaT);
  }

  return cont;
}

void executarComandoEc(FILE *arqEntradaEc, Canvas canvas) {
  char entrada[3];
  if (arqEntradaEc != NULL) {
    while (1) {
      if (feof(arqEntradaEc) != 0) {
        break;
      }

      if (fscanf(arqEntradaEc, "%s ", entrada) < 0) {
        break;
      }

      if (strcmp(entrada, "e") == 0) {
        executarEcE(canvas, arqEntradaEc);
      } else if (strcmp(entrada, "t") == 0) {
        executarEcT(canvas, arqEntradaEc);
      } else {
        printf("Comando Invalido em arquivo Ec.\n");
      }
    }
  }
}

void executarComandoPm(FILE *arqEntradaPm, Canvas canvas) {
  char entrada[3];
  if (arqEntradaPm != NULL) {
    while (1) {
      if (feof(arqEntradaPm) != 0) {
        break;
      }

      if (fscanf(arqEntradaPm, "%s ", entrada) < 0) {
        break;
      }

      if (strcmp(entrada, "p") == 0) {
        executarPmP(canvas, arqEntradaPm);
      } else if (strcmp(entrada, "m") == 0) {
        executarPmM(canvas, arqEntradaPm);
      } else {
        printf("Comando Invalido em arquivo Pm.\n");
      }
    }
  }
}

void executarComandoTm(FILE *arqEntradaTm, Canvas canvas) {
  char entrada[3];
  if (arqEntradaTm != NULL) {
    while (1) {
      if (feof(arqEntradaTm) != 0) {
        break;
      }

      if (fscanf(arqEntradaTm, "%s ", entrada) < 0) {
        break;
      }

      if (strcmp(entrada, "su") == 0) {
        executarTmSu(canvas, arqEntradaTm);
      } else if (strcmp(entrada, "um") == 0) {
        executarTmUm(canvas, arqEntradaTm);
      } else {
        printf("Comando Invalido em arquivo Tm.\n");
      }
    }
  }
}

void executarComandoVia(FILE *arqEntradaVia, Canvas canvas) {
  char entrada[3], idG[] = "Vias da cidade";
  List list = createL();
  int b = 0;
  CrossRoad cross = NULL;
  Graph g;
  QuadTree q;
  if (arqEntradaVia != NULL) {
    while (1) {
      if (feof(arqEntradaVia) != 0) {
        break;
      }

      if (fscanf(arqEntradaVia, "%s ", entrada) < 0) {
        break;
      }

      if (strcmp(entrada, "v") == 0) {
        executarViaV(list, arqEntradaVia);
      } else if (strcmp(entrada, "e") == 0) {
        /* Insere os vertíces (Cruzamentos) no grafo e em uma QuadTree */
        if(b == 0){
          b = 1;
          setGrafo(getCidade(canvas), idG, lengthL(list));
          g = getGrafo(getCidade(canvas));
          q = getListaCrossRoad(getCidade(canvas));
          do {
            cross = getBeginItemL(list);
            removeBeginL(list, NULL);
            insertVertex(g, getIdCrossRoad(cross), cross);
            insertQuadTree(q, cross, getXCrossRoad(cross), getYCrossRoad(cross));
          } while(lengthL(list) > 0);
          eraseListL(list, NULL);
          eraseBase(list);
          list = NULL;
        }

        executarViaE(canvas, arqEntradaVia);

      } else {
        printf("Comando invalido em arquivo via.\n");
      }
    }

  }
  if(list != NULL){
    eraseListL(list, NULL);
    eraseBase(list);
  }
}

void desenharElementos(FILE *arqSaidaSvg, Canvas canvas) {

  tagAbertura(arqSaidaSvg, getWidth(canvas) + 50, getHeight(canvas) + 50);

  /* Retângulos */
  showCanvasElements(canvas, arqSaidaSvg, 5);

  /* Retângulos de sobreposição. */
  showCanvasElements(canvas, arqSaidaSvg, 7);

  /* Quadra */
  showCanvasElements(canvas, arqSaidaSvg, 1);

  /* Círculos */
  showCanvasElements(canvas, arqSaidaSvg, 6);

  /* Hidrante */
  showCanvasElements(canvas, arqSaidaSvg, 2);

  /* Semafaro */
  showCanvasElements(canvas, arqSaidaSvg, 3);

  /* Torre */
  showCanvasElements(canvas, arqSaidaSvg, 4);

  showMoradores(getCidade(canvas), arqSaidaSvg);

  showEstabelecimentos(getCidade(canvas), arqSaidaSvg);

  showListPolygons(canvas, arqSaidaSvg);

  showListTexts(canvas, arqSaidaSvg);

  showListLines(canvas, arqSaidaSvg);

  showListPoints(canvas, arqSaidaSvg);

  showVia(getCidade(canvas), arqSaidaSvg);

  tagFechamento(arqSaidaSvg);
}

void processarDados(char **argv, int argc) {
  char *arqNome = NULL, *dirPath = NULL, *exitFileSvg = NULL, *exitFileGeoViaSvg = NULL;
  char acc0 = 'f', acc = 'f';
  char extensao1[] = ".txt";
  int qtdQuadrasInseridas = 0, qtdQuadrasRemovidas = 0,
      qtdElementosRemovidos = 0;
  long int qtdCompararacoesI = 0, qtdCompararacoesR = 0;
  FILE *arqEntradaGeo = NULL, *arqEntradaQry = NULL, *arqSaidaSvg = NULL,
       *arqEntradaEc = NULL, *arqEntradaPm = NULL, *arqEntradaTm = NULL,
       *arqEntradaVia = NULL;
  Canvas canvas;
  automaticId = 0;
  abrirArquivos(&arqEntradaGeo, &arqEntradaQry, &arqEntradaEc, &arqEntradaPm,
                &arqEntradaTm, &arqEntradaVia, &arqNome, &dirPath, &exitFileSvg,
                &exitFileGeoViaSvg , &acc0, &acc, argv, argc);

  canvas = criaCanvas(1);

  executarComandosGeo(arqEntradaGeo, arqNome, dirPath, canvas,
                      &qtdQuadrasInseridas, &qtdCompararacoesI);

  executarComandoEc(arqEntradaEc, canvas);

  executarComandoPm(arqEntradaPm, canvas);

  executarComandoTm(arqEntradaTm, canvas);

  executarComandoVia(arqEntradaVia, canvas);

  if(exitFileGeoViaSvg != NULL){
    arqSaidaSvg = createArqW(exitFileGeoViaSvg);
    if(arqSaidaSvg != NULL){
      desenharElementos(arqSaidaSvg, canvas);
      fclose(arqSaidaSvg);
      arqSaidaSvg = NULL;
    }
  }

  executarComandosQry(arqEntradaQry, arqNome, dirPath, canvas,
                      &qtdQuadrasRemovidas, &qtdCompararacoesR,
                      &qtdElementosRemovidos);

  if (acc0 == 't') {
    executarAcc0(dirPath, arqNome, extensao1, qtdQuadrasInseridas,
                 qtdCompararacoesI, qtdQuadrasRemovidas, qtdCompararacoesR);
  }
  if (acc == 't') {
    executarAcc(dirPath, arqNome, extensao1, qtdQuadrasInseridas,
                qtdCompararacoesI, qtdQuadrasRemovidas, qtdCompararacoesR);
  }
  if (exitFileSvg != NULL) {
    arqSaidaSvg = createArqW(exitFileSvg);
    desenharElementos(arqSaidaSvg, canvas);
    eraseCanvas(canvas);
    fclose(arqSaidaSvg);
  }

  if (arqNome != NULL) {
    free(arqNome);
  }
  if (dirPath != NULL) {
    free(dirPath);
  }
  if (exitFileSvg != NULL) {
    free(exitFileSvg);
  }
  if (exitFileGeoViaSvg != NULL) {
    free(exitFileGeoViaSvg);
  }
  if (arqEntradaGeo != NULL) {
    fclose(arqEntradaGeo);
  }
  if (arqEntradaQry != NULL) {
    fclose(arqEntradaQry);
  }

  if (arqEntradaEc != NULL) {
    fclose(arqEntradaEc);
  }

  if (arqEntradaPm != NULL) {
    fclose(arqEntradaPm);
  }

  if (arqEntradaTm != NULL) {
    fclose(arqEntradaTm);
  }

  if (arqEntradaVia != NULL) {
    fclose(arqEntradaVia);
  }
}
