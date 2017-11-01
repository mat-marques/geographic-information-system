#include "ExecucaoQry.h"
#include "OpEntrada.h"
#include "OperacoesF.h"

#include "Circulo.h"
#include "Retangulo.h"
#include "Torre.h"
#include "Semafaro.h"
#include "Hidrante.h"
#include "Quadra.h"
#include "Cidade.h"
#include "Arquivo.h"
#include "Cor.h"
#include "Svg.h"
#include "DoubleLinkedList.h"
#include "StringO.h"
#include "ConvexHull.h"

void executardq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas){
  double w=0, h=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *cep = NULL;
  List lista = NULL;
  QuadTree quadra;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

  lista = getElementsListInsideR(canvas, 3, x, y, w,  h);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    quadra = getListaQ(getCidade(canvas));
    n = lengthDLL(lista);
    cep = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      cep =getCepQ(elemento);
      if(cep != NULL){
        fillArq1(*arqSaidaT, cep);
        fillBreakLine(*arqSaidaT);
        *qtdQuadrasRemovidas = *qtdQuadrasRemovidas+1;
      }
      removeQuadTreeItemI(quadra, cep, compareQ);
      cep = NULL;
    }
    eraseListDLL(lista, removeQ);
    eraseBase(lista);
  }


}

void executardh(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double w=0, h=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  List lista = NULL;
  QuadTree hidrante;
  char *id = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);
  lista = getElementsListInsideR(canvas, 5, x, y, w,  h);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    hidrante =  getListaH(getCidade(canvas));
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdH(elemento);
      if(id != NULL){
        fillArq1(*arqSaidaT, id);
        fillBreakLine(*arqSaidaT);
      }
      removeQuadTreeItemI(hidrante, id, compareH);
      id = NULL;
    }
    eraseListDLL(lista, removeH);
    eraseBase(lista);
  }

}

void executards(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double w=0, h=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *id;
  List lista = NULL;
  QuadTree semafaro;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

  lista = getElementsListInsideR(canvas, 6, x, y, w,  h);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    semafaro = getListaS(getCidade(canvas));
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdS(elemento);
      if(id != NULL){
        fillArq1(*arqSaidaT, id);
        fillBreakLine(*arqSaidaT);
      }
      removeQuadTreeItemI(semafaro, id, compareS);
      id = NULL;
    }
    eraseListDLL(lista, removeS);
    eraseBase(lista);
  }

}

void executardt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double w=0, h=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *id;
  List lista = NULL;
  QuadTree torre;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);
  lista = getElementsListInsideR(canvas, 4, x, y, w,  h);

  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    torre = getListaT(getCidade(canvas));
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdT(elemento);
      if(id != NULL){
        fillArq1(*arqSaidaT, id);
        fillBreakLine(*arqSaidaT);
      }
      removeQuadTreeItemI(torre, id, compareT);
      id = NULL;
    }
    eraseListDLL(lista, removeT);
    eraseBase(lista);
  }
}

void executarDq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas){
  double r=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *cep;
  List lista = NULL;
  QuadTree quadra;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
  lista = getElementsListInsideC(canvas, 3, x, y, r);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    quadra = getListaQ(getCidade(canvas));
    n = lengthDLL(lista);
    cep = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      cep =getCepQ(elemento);
      if(cep != NULL){
        fillArq1(*arqSaidaT, cep);
        fillBreakLine(*arqSaidaT);
        *qtdQuadrasRemovidas = *qtdQuadrasRemovidas+1;
      }
      removeQuadTreeItemI(quadra, cep, compareQ);
      cep = NULL;
    }
    eraseListDLL(lista, removeQ);
    eraseBase(lista);
  }
}

void executarDh(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double r=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *id;
  List lista = NULL;
  QuadTree hidrante;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
  lista = getElementsListInsideC(canvas, 5, x, y, r);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    hidrante = getListaH(getCidade(canvas));
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdH(elemento);
      if(id != NULL){
        fillArq1(*arqSaidaT, id);
        fillBreakLine(*arqSaidaT);
      }
      removeQuadTreeItemI(hidrante, id, compareH);
      id = NULL;
    }
    eraseListDLL(lista, removeH);
    eraseBase(lista);
  }

}

void executarDs(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double r=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *id;
  List lista = NULL;
  QuadTree semafaro;

  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
  lista = getElementsListInsideC(canvas, 6, x, y, r);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    semafaro = getListaS(getCidade(canvas));
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdS(elemento);
      if(id != NULL){
        fillArq1(*arqSaidaT, id);
        fillBreakLine(*arqSaidaT);
      }
      removeQuadTreeItemI(semafaro, id, compareS);
      id = NULL;
    }
    eraseListDLL(lista, removeS);
    eraseBase(lista);
  }
}

void executarDt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double r=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *id;
  List lista = NULL;
  QuadTree torre;

  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
  lista = getElementsListInsideC(canvas, 4, x, y, r);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    torre = getListaT(getCidade(canvas));
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdT(elemento);
      if(id != NULL){
        fillArq1(*arqSaidaT, id);
        fillBreakLine(*arqSaidaT);
      }
      removeQuadTreeItemI(torre, id, compareT);
      id = NULL;
    }
    eraseListDLL(lista, removeT);
    eraseBase(lista);
  }
}

void executarCrd(FILE *arqEntradaQry , FILE **arqSaidaT, char *path, Canvas canvas){
  char *string = NULL;
  int sizeString;
  char stringQuadra[] = "Quadra";
  char stringHidrante[] = "Hidrante";
  char stringSemafaro[] = "Semafaro";
  char stringTorre[] = "Torre Celular";
  char crd[] = "crd?";
  char saida[] = "O elemento nao existe.";
  void *elemento;
  char *id = NULL;
  double x, y;
  char caracter = 'q';
  Cidade cidade = NULL;
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }
  sizeString = qtdCaracteres(arqEntradaQry);

  string = alocarString(sizeString);

  fscanf(arqEntradaQry, "%s\n", string);

  cidade = getCidade(canvas);
  elemento = getQuadra(cidade, string);
  if(elemento==NULL){
    elemento = getHidrante(cidade, string);
    caracter = 'h';
  }
  if(elemento == NULL){
    elemento = getSemafaro(cidade, string);
    caracter = 's';
  }
  if(elemento == NULL){
    elemento = getTorre(cidade, string);
    caracter = 't';
  }

  if(elemento!=NULL){
    if(caracter=='q'){
      x = getXQ(elemento);
      y = getYQ(elemento);
      id = getCepQ(elemento);
      fillArq1(*arqSaidaT, stringQuadra);
      fillSpace(*arqSaidaT);
    }else
    if(caracter=='h'){
      x = getXH(elemento);
      y = getYH(elemento);
      id = getIdH(elemento);
      fillArq1(*arqSaidaT, stringHidrante);
      fillSpace(*arqSaidaT);
    }else
    if(caracter=='s'){
      x = getXS(elemento);
      y = getYS(elemento);
      id = getIdS(elemento);
      fillArq1(*arqSaidaT, stringSemafaro);
      fillSpace(*arqSaidaT);
    }else
    if(caracter=='t'){
      x = getXT(elemento);
      y = getYT(elemento);
      id = getIdT(elemento);
      fillArq1(*arqSaidaT, stringTorre);
      fillSpace(*arqSaidaT);
    }
    fillArq4(*arqSaidaT, x);
    fillSpace(*arqSaidaT);
    fillArq4(*arqSaidaT, y);
    fillSpace(*arqSaidaT);
    fillArq1(*arqSaidaT, id);
    fillBreakLine(*arqSaidaT);
  }else{
    fillArq1(*arqSaidaT, crd);
    fillSpace(*arqSaidaT);
    fillArq1(*arqSaidaT, string);
    fillBreakLine(*arqSaidaT);
    fillArq1(*arqSaidaT, saida);
    fillBreakLine(*arqSaidaT);
  }
  desalocar(string);
  string = NULL;
}

void executarPc(FILE *arqEntradaQry, char *arqNome, char *dirPath, char *extensao2, Canvas canvas){
  char *string1 = NULL, *string2 = NULL, *string3 = NULL;
  char stringAux[] = "-";
  int i, n;
  double width, height, x, y, w, h;
  FILE *arqSaidaSvg2 = NULL;
  List lista;

  i = qtdCaracteres(arqEntradaQry);
  string1 = alocarString(i);

  fscanf(arqEntradaQry, "%s %lf %lf %lf %lf\n", string1, &x, &y, &w, &h);

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
  desalocar(string1);
  string1 = NULL;
  desalocar(string2);
  string2 = NULL;
  desalocar(string3);
  string3 = NULL;

  tagAbertura(arqSaidaSvg2, width, height);
  lista = getElementsListInsideR(canvas, 4, x, y,  w, h);

  generateConvexHullT(lista, arqSaidaSvg2);

  eraseListDLL(lista, NULL);
  eraseBase(lista);

  tagFechamento(arqSaidaSvg2);
  fclose(arqSaidaSvg2);
}

void executarAc(FILE *arqEntradaQry , FILE **arqSaidaT, char *path, Canvas canvas){
  double x, y, w, h;
  double area;
  List lista;
  char texto[] = "Comando ac? Area";
  char ms[] = "metros quadrados";
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

  lista = getElementsListInsideR(canvas, 4, x, y,  w, h);
  if(lengthDLL(lista) > 0){
    if(*arqSaidaT==NULL){
      *arqSaidaT = createArqA(path);
    }
    area = areaConvexHull(lista);
    fillArq1(*arqSaidaT, texto);
    fillSpace(*arqSaidaT);
    fillArq4(*arqSaidaT, area);
    fillSpace(*arqSaidaT);
    fillArq1(*arqSaidaT, ms);
    fillBreakLine(*arqSaidaT);
  }
  eraseListDLL(lista, NULL);
  eraseBase(lista);

}

void executarAcc0(char *dirPath, char *arqNome, char *extensao, int qtdQuadrasInseridas, int qtdCompararacoesI, int qtdQuadrasRemovidas, int qtdCompararacoesR){
  char *string = NULL;
  char stringResumo[] = "resumo";
  char extensao2[] = ".geo";
  FILE *resumo = NULL;

  string = concatenarElementos(dirPath, stringResumo, extensao);
  resumo = createArqW(string);

  desalocar(string);
  string = NULL;
  string = concatenarStrings(arqNome, extensao2);
  fillArq1(resumo, string);
  fillTab(resumo);
  desalocar(string);
  string = NULL;

  fillArq3(resumo, qtdQuadrasInseridas);
  fillTab(resumo);

  fillArq3(resumo, qtdCompararacoesI);
  fillTab(resumo);

  fillArq3(resumo, qtdQuadrasRemovidas);
  fillTab(resumo);

  fillArq3(resumo, qtdCompararacoesR);
  fillBreakLine(resumo);
    fclose(resumo);
}

void executarAcc(char *dirPath, char *arqNome, char *extensao, int qtdQuadrasInseridas, int qtdCompararacoesI, int qtdQuadrasRemovidas, int qtdCompararacoesR){
  char *string = NULL;
  char stringResumo[] = "resumo";
  char extensao2[] = ".geo";
  FILE *resumo = NULL;

  string = concatenarElementos(dirPath, stringResumo, extensao);
  resumo = createArqA(string);
  desalocar(string);
  string = NULL;

  string = concatenarStrings(arqNome, extensao2);
  fillArq1(resumo, string);
  fillTab(resumo);
  desalocar(string);
  string = NULL;

  fillArq3(resumo, qtdQuadrasInseridas);
  fillTab(resumo);

  fillArq3(resumo, qtdCompararacoesI);
  fillTab(resumo);

  fillArq3(resumo, qtdQuadrasRemovidas);
  fillTab(resumo);

  fillArq3(resumo, qtdCompararacoesR);
  fillBreakLine(resumo);
  fclose(resumo);
}
