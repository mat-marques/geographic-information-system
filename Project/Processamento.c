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
#include "StringO.h"

#include "DoubleLinkedList.h"
#include "QuadTree.h"
<<<<<<< Updated upstream
#include "Cor.h"
=======
>>>>>>> Stashed changes
#include "Processamento.h"
#include "ExecucaoGeo.h"
#include "ExecucaoQry.h"
#include "Exibicao.h"

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

  QuadTree conjunto;

  globalFile = arqSaidaSvg;

  tagAbertura(arqSaidaSvg, getWidth(canvas)+50, getHeight(canvas)+50);

  /* Retângulos */
  conjunto = getListaR(canvas);
  showQuadTree(conjunto, showR);

  /* Círculos */
  conjunto = getListaC(canvas);
  showQuadTree(conjunto, showC);

  /* Retângulos de sobreposição. */


  /* Quadra */
  conjunto = getListaQ(canvas);
  showQuadTree(conjunto, showQ);

  /* Semafaro */
  conjunto = getListaS(canvas);
  showQuadTree(conjunto, showS);

  /* Torre */
  conjunto = getListaT(canvas);
  showQuadTree(conjunto, showT);

  /* Hidrante */
  conjunto = getListaH(canvas);
  showQuadTree(conjunto, showH);

  tagFechamento(arqSaidaSvg);
}

void executarComandosGeo(FILE *arqEntradaGeo, char *arqNome, char *dirPath, Canvas canvas , int *qtdQuadrasInseridas)
{
  char boolean='t';
  char *string1 = NULL, entradaA[6];
  char extensao1[] = ".txt";
  char extensao2[] = ".svg";
  int i, n;
  FILE *arqSaidaT = NULL;
  List quadras, semafaros, torres, hidrantes, retangulos, circulos;
<<<<<<< Updated upstream
=======
  char *cq = NULL, *cs = NULL, *ct = NULL, *ct = NULL;
>>>>>>> Stashed changes
  if(arqEntradaGeo==NULL){
    printf("ERRO EM ABERTURA DE ARQUIVO GEO.\n");
    exit(0);
  }
  /*  Lista de auxiliares. */
  quadras = createDLL();
  semafaros = createDLL();
  torres = createDLL();
  hidrantes = createDLL();
  retangulos = createDLL();
  circulos = createDLL();

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
      if(cq != NULL){
        free(cq);
      }
      cq = executarCq(arqEntradaGeo);
    } else
    if(strcmp(entradaA, "ch")==0){
      if(ch != NULL){
        free(cq);
      }
      ch = executarCh(arqEntradaGeo);
    } else
    if(strcmp(entradaA, "ct")==0){
      if(ct != NULL){
        free(cq);
      }
      ct = executarCt(arqEntradaGeo);
    }else
    if(strcmp(entradaA, "cs")==0){
      if(cs != NULL){
        free(cq);
      }
      if(cq != NULL){
        free(cq);
      }
      cs = executarCs(arqEntradaGeo);
    }else
    if(strcmp(entradaA, "hI")==0){
      executarHI(arqEntradaGeo, canvas);
    }else
    if(strcmp(entradaA, "tI")==0){
      executarTI(arqEntradaGeo, canvas);
    }else
    if(strcmp(entradaA, "sI")==0){
      executarSI(arqEntradaGeo, canvas);
    }else
    if(entradaA[0] == 'c'){
      executarAuxC(arqEntradaGeo, circulos);
    } else
    if(entradaA[0] == 'r'){
      executarAuxR(arqEntradaGeo, retangulos);
    } else
    if(entradaA[0] == 'q'){
      qtdQuadrasInseridas++;
      executarAuxQ(arqEntradaGeo, quadras);
    } else
    if(entradaA[0] == 'h'){
      executarAuxH(arqEntradaGeo, hidrantes);
    } else
    if(entradaA[0] == 't'){
      executarAuxT(arqEntradaGeo, torres);
    } else
    if(entradaA[0] == 's'){
      executarAuxS(arqEntradaGeo, semafaros);
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
