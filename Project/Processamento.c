#include "OpEntrada.h"
#include "OperacoesF.h"

#include "Circulo.h"
#include "Retangulo.h"
#include "torre.h"
#include "semafaro.h"
#include "hidrante.h"
#include "quadra.h"
#include "Cidade.h"
#include "Arquivo.h"
#include "Cor.h"
#include "Svg.h"
#include "StringO.h"

#include "Lista.h"
#include "Cor.h"
#include "Processamento.h"
#include "ExecucaoGeo.h"
#include "ExecucaoQry.h"

void abrirArquivos(FILE **arqEntradaGeo, FILE **arqEntradaQry, char **arqNome, char **dirPath, char **exitFileSvg, char *acc0, char *acc, char **argv, int argc)
{
  char *string0=NULL, *string1=NULL, *string2=NULL;
  char extensao2[] = ".svg";
  char travessao[] = "-";

  string0 = parametroE(argv, argc);
  string1 = parametroF(argv, argc);

  if(string0!=NULL){
    string2 = concatenarElementos2(string0, string1);
    if(string2!=NULL){
      *arqEntradaGeo = createArqR(string2);
      *arqNome =  nomeArquivo(string1);
    }
  }else{
    if(string1!=NULL){
      *arqEntradaGeo = createArqR(string1);
      *arqNome = nomeArquivo(string1);
    }else{
      exit(0);
    }
  }

  desalocar(string0);
  desalocar(string1);
  desalocar(string2);
  string0 = NULL;
  string1 = NULL;
  string2 = NULL;


  *dirPath = parametroO(argv, argc);

  string0 = parametroQ(argv, argc);

  if(string0 != NULL){
    *arqEntradaQry = createArqR(string0);
     string1 = nomeArquivo(string0);
     string2 = concatenarStrings(*arqNome, travessao);
     free(*arqNome);
     *arqNome = NULL;
     *arqNome = concatenarStrings(string2, string1);
  }

  *exitFileSvg = concatenarElementos(*dirPath, *arqNome, extensao2);

  desalocar(string0);
  desalocar(string1);
  desalocar(string2);
  string0 = NULL;
  string1 = NULL;
  string2 = NULL;
  *acc0 = parametroAcc0(argv, argc);

  *acc = parametroAcc(argv, argc);

}

void finalizarExecucao(FILE *arqSaidaSvg, Canvas canvas){
  void *elemento1, *elemento2;
  int n, i;
  double w, h, x, y;
  char *corA, *corB;
  Cor corAux;
  Lista lista;
  Cidade cidade;
  tagAbertura(arqSaidaSvg, getWidth(canvas)+50, getHeight(canvas)+50);

  lista = getListaR(canvas);
  n = lenght(lista);
  elemento1 = getFirst(lista);
  for(i=0; i<n; i++){
    elemento2 = get(lista, elemento1);
    w = getRw(elemento2);
    h = getRh(elemento2);
    x = getRx(elemento2);
    y = getRy(elemento2);
    corA = getRcor(elemento2);
    tagRetangulo(arqSaidaSvg, w, h, x, y, corA);
    elemento1 = getNext(lista, elemento1);
  }

  lista = getListaC(canvas);
  n = lenght(lista);
  elemento1 = getFirst(lista);
  for(i=0; i<n; i++){
    elemento2 = get(lista, elemento1);
    h = getCr(elemento2);
    x = getCx(elemento2);
    y = getCy(elemento2);
    corA = getCcor(elemento2);
    tagCirculo(arqSaidaSvg, h, x, y, corA);
    elemento1 = getNext(lista, elemento1);
  }

  lista = getListaR2(canvas);
  n = lenght(lista);
  elemento1 = getFirst(lista);
  for(i=0; i<n; i++){
    elemento2 = get(lista, elemento1);
    w = getRw(elemento2);
    h = getRh(elemento2);
    x = getRx(elemento2);
    y = getRy(elemento2);
    tagRetanguloSobreposicao(arqSaidaSvg, x, y, w, h);
    tagTexto(arqSaidaSvg, x+4, y+10);
    elemento1 = getNext(lista, elemento1);
  }

  cidade = getCidade(canvas);
  lista = getListaQ(cidade);
  n = lenght(lista);
  elemento1 = getFirst(lista);
  corAux = getCor(canvas, 1);
  corA = getCorP(corAux);
  corB = getCorC(corAux);
  for(i=0; i<n; i++){
    elemento2 = get(lista, elemento1);
    w = getLargQ(elemento2);
    h = getAltQ(elemento2);
    x = getXQ(elemento2);
    y = getYQ(elemento2);
    tagRetangulo2(arqSaidaSvg, w, h, x, y, corA, corB);
    elemento1 = getNext(lista, elemento1);
  }

  lista = getListaS(cidade);
  n = lenght(lista);
  elemento1 = getFirst(lista);
  corAux = getCor(canvas, 2);
  corA = getCorP(corAux);
  corB = getCorC(corAux);
  for(i=0; i<n; i++){
    elemento2 = get(lista, elemento1);
    x = getXQ(elemento2);
    y = getYQ(elemento2);
    tagCirculo2(arqSaidaSvg, 2, x, y, corA, corB);
    elemento1 = getNext(lista, elemento1);
  }

  lista = getListaT(cidade);
  n = lenght(lista);
  elemento1 = getFirst(lista);
  corAux = getCor(canvas, 3);
  corA = getCorP(corAux);
  corB = getCorC(corAux);
  for(i=0; i<n; i++){
    elemento2 = get(lista, elemento1);
    x = getXQ(elemento2);
    y = getYQ(elemento2);
    tagCirculo2(arqSaidaSvg, 2, x, y, corA, corB);
    elemento1 = getNext(lista, elemento1);
  }

  lista = getListaH(cidade);
  n = lenght(lista);
  elemento1 = getFirst(lista);
  corAux = getCor(canvas, 4);
  corA = getCorP(corAux);
  corB = getCorC(corAux);
  for(i=0; i<n; i++){
    elemento2 = get(lista, elemento1);
    x = getXQ(elemento2);
    y = getYQ(elemento2);
    tagCirculo2(arqSaidaSvg, 2, x, y, corA, corB);
    elemento1 = getNext(lista, elemento1);
  }
  tagFechamento(arqSaidaSvg);
}

void executarComandosGeo(FILE *arqEntradaGeo, char *arqNome, char *dirPath, Canvas canvas , int *qtdQuadrasInseridas)
{
  char boolean='t';
  char *string1 = NULL, entradaA[6];
  char extensao1[] = ".txt";
  char extensao2[] = ".svg";
  FILE *arqSaidaT = NULL;
  if(arqEntradaGeo==NULL){
    printf("ERRO EM ABERTURA DE ARQUIVO GEO.\n");
    exit(0);
  }
  while(1){
    fscanf(arqEntradaGeo, "%s ", entradaA);
    if(entradaA[0]=='#'){
      break;
    }
    if(boolean=='t'&&(entradaA[0]=='o'||entradaA[0]=='i'||entradaA[0]=='d')){
      string1 = concatenarElementos(dirPath, arqNome, extensao1);
      arqSaidaT = createArqW(string1);
      desalocar(string1);
      string1 = NULL;
      boolean = 'f';
    }

    if(strcmp(entradaA, "cq")==0){
      executarCq(arqEntradaGeo, canvas);
    } else
    if(strcmp(entradaA, "ch")==0){
      executarCh(arqEntradaGeo, canvas);
    } else
    if(strcmp(entradaA, "ct")==0){
      executarCt(arqEntradaGeo, canvas);
    }else
    if(strcmp(entradaA, "cs")==0){
      executarCs(arqEntradaGeo, canvas);
    }else
    if(entradaA[0] == 'c'){
      executarC(arqEntradaGeo, canvas);
    } else
    if(entradaA[0] == 'r'){
      executarR(arqEntradaGeo, canvas);
    } else
    if(entradaA[0] == 'q'){
      executarQ(arqEntradaGeo, canvas, qtdQuadrasInseridas);
    } else
    if(entradaA[0] == 'h'){
      executarH(arqEntradaGeo, canvas);
    } else
    if(entradaA[0] == 't'){
      executarT(arqEntradaGeo, canvas);
    } else
    if(entradaA[0] == 's'){
      executarS(arqEntradaGeo, canvas);
    } else
    if(entradaA[0] == 'd'){
      executarD(arqEntradaGeo, arqSaidaT,canvas);
    } else
    if(entradaA[0] == 'i'){
      executarI(arqEntradaGeo, arqSaidaT,canvas);
    } else
    if(entradaA[0] == 'o'){
      executarO(arqEntradaGeo, arqSaidaT, canvas);
    } else {
      if(entradaA[0] == 'a'){
        executarA(arqEntradaGeo, canvas, arqNome, dirPath, extensao2);
      }
    }
    entradaA[0] = '\0';
  }
  if(arqSaidaT!=NULL){
    fclose(arqSaidaT);
  }
}

void executarComandosQry(FILE *arqEntradaQry, char *arqNome, char *dirPath, Canvas canvas, int *qtdQuadrasRemovidas)
{
  char *path = NULL, entradaA[6];
  char extensao1[] = ".txt";
  FILE *arqSaidaT = NULL;

  path = concatenarElementos(dirPath, arqNome, extensao1);

  if(arqEntradaQry!=NULL){
    while(1){

      if(feof(arqEntradaQry)!=0){
        break;
      }
        fscanf(arqEntradaQry, "%s ", entradaA);

      if(strcmp(entradaA, "dq")==0){
        executardq(arqEntradaQry, &arqSaidaT, path, canvas, qtdQuadrasRemovidas);
      }
      if(strcmp(entradaA, "dh")==0){
        executardh(arqEntradaQry, &arqSaidaT, path, canvas);
      } else
      if(strcmp(entradaA, "ds")==0){
        executards(arqEntradaQry, &arqSaidaT, path, canvas);
      } else
      if(strcmp(entradaA, "dt")==0){
        executardt(arqEntradaQry, &arqSaidaT, path, canvas);
      } else
      if(strcmp(entradaA, "Dq")==0){
        executarDq(arqEntradaQry, &arqSaidaT, path, canvas, qtdQuadrasRemovidas);
      } else
      if(strcmp(entradaA, "Dh")==0){
        executarDh(arqEntradaQry, &arqSaidaT, path, canvas);
      } else
      if(strcmp(entradaA, "Ds")==0){
        executarDs(arqEntradaQry, &arqSaidaT, path, canvas);
      } else
      if(strcmp(entradaA, "Dt")==0){
        executarDt(arqEntradaQry, &arqSaidaT, path, canvas);
      } else{
        if(strcmp(entradaA, "crd?")==0){
          executarCrd(arqEntradaQry, &arqSaidaT, path, canvas);
        }
      }
    }
    entradaA[0] = '\0';
  }
  desalocar(path);
  if(arqSaidaT!=NULL){
    fclose(arqSaidaT);
  }
}

void processarDados(char **argv, int argc){
  char *arqNome=NULL, *dirPath=NULL, *exitFileSvg = NULL;
  char acc0='f', acc='f';
  char extensao1[] = ".txt";
  int qtdQuadrasInseridas=0, qtdCompararacoesI=0, qtdQuadrasRemovidas=0, qtdCompararacoesR=0;
  FILE *arqEntradaGeo=NULL, *arqEntradaQry=NULL;
  FILE *arqSaidaSvg;
  Canvas canvas;

  abrirArquivos(&arqEntradaGeo, &arqEntradaQry, &arqNome, &dirPath, &exitFileSvg, &acc0, &acc, argv, argc);

  canvas = criaCanvas(1);
  setarCores(canvas);

  executarComandosGeo(arqEntradaGeo, arqNome, dirPath, canvas, &qtdQuadrasInseridas);

  executarComandosQry(arqEntradaQry, arqNome, dirPath, canvas, &qtdQuadrasRemovidas);


  if(acc0=='t'){
    qtdCompararacoesI = qtdQuadrasInseridas * 2;
    qtdCompararacoesR = qtdQuadrasRemovidas * 10;
    executarAcc0(dirPath, arqNome, extensao1, qtdQuadrasInseridas, qtdCompararacoesI, qtdQuadrasRemovidas, qtdCompararacoesR);
  }
  if(acc=='t'){
    qtdCompararacoesI = qtdQuadrasInseridas * 2;
    qtdCompararacoesR = qtdQuadrasRemovidas * 10;
    executarAcc(dirPath, arqNome, extensao1, qtdQuadrasInseridas, qtdCompararacoesI, qtdQuadrasRemovidas, qtdCompararacoesR);
  }
  if(exitFileSvg!=NULL){
    arqSaidaSvg = createArqW(exitFileSvg);
    finalizarExecucao(arqSaidaSvg, canvas);
    eraseCanvas(canvas);
    fclose(arqSaidaSvg);
  }

    if(arqNome!=NULL){free(arqNome);}
    if(dirPath!=NULL){free(dirPath);}
    if(exitFileSvg!=NULL){free(exitFileSvg);}
    if(arqEntradaGeo!=NULL){ fclose(arqEntradaGeo);}
    if(arqEntradaQry!=NULL){ fclose(arqEntradaQry);}
  }
