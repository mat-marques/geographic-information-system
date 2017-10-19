#include "ExecucaoQry.h"
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
#include "Lista.h"
#include "StringO.h"

void executardq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas){
  double w=0, h=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *cep = NULL;
<<<<<<< Updated upstream
  Cidade cidade;
  Lista lista = NULL;

  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

    cidade = getCidade(canvas);
    lista = getListaQ(cidade);
    n = lenght(lista);
    elemento = getFirst(lista);
    for(i=0;i<n;i++){
      elemento2 = get(lista, elemento);
      if(elemento2!=NULL){
        w1 = getLargQ(elemento2);
        h1 = getAltQ(elemento2);
        x1 = getXQ(elemento2);
        y1 = getYQ(elemento2);
        cep = getCepQ(elemento2);
        if(verificarInteiramenteSobrepostoRR(w, h, x, y, w1, h1, x1, y1) == 't'){
          if(*arqSaidaT==NULL){
            *arqSaidaT = createArqA(path);
          }
          fillArq1(*arqSaidaT, cep);
          fillBreakLine(*arqSaidaT);
          elemento2 = getNext(lista, elemento);
          removeQuadra(cidade, elemento);
          *qtdQuadrasRemovidas = *qtdQuadrasRemovidas+1;
          elemento = elemento2;
        }else{
          elemento = getNext(lista, elemento);
        }
=======
  List lista = NULL;

  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

  lista = getElementsListInsideR(canvas, 3, x, y, w,  h);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
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
      cep = NULL;
>>>>>>> Stashed changes
    }
    eraseListDLLTwo(lista);
    eraseBase(lista);
  }


}

void executardh(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double w=0, h=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  Lista lista = NULL;
  char *id = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);
  lista = getElementsListInsideR(canvas, 5, x, y, w,  h);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdH(elemento);
      if(id != NULL){
        fillArq1(*arqSaidaT, id);
        fillBreakLine(*arqSaidaT);
      }
      id = NULL;
    }
    eraseListDLLTwo(lista);
    eraseBase(lista);
  }
}

void executards(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double w=0, h=0, x=0, y=0;
  double x1=0, y1=0;
  void *elemento = NULL, *elemento2=NULL;
  int i, n;
  char *id;
  Cidade cidade;
  Lista lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);
    cidade = getCidade(canvas);
    lista = getListaS(cidade);
    n = lenght(lista);
    elemento = getFirst(lista);
    for(i=0;i<n;i++){
      elemento2 = get(lista, elemento);
      if(elemento2!=NULL){
        x1 = getXS(elemento2);
        y1 = getYS(elemento2);
        id = getIdS(elemento2);
        if(pontoInternoR(w, h, x, y, x1, y1) == 't'){
          if(*arqSaidaT==NULL){
            *arqSaidaT = createArqA(path);
          }
          fillArq1(*arqSaidaT, id);
          fillBreakLine(*arqSaidaT);
          elemento2 = getNext(lista, elemento);
          removeSemafaro(cidade, elemento);
          elemento = elemento2;
        }else{
          elemento = getNext(lista, elemento);
        }
      }
  }
}

void executardt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double w=0, h=0, x=0, y=0;
  double x1=0, y1=0;
  void *elemento = NULL, *elemento2=NULL;
  int i, n;
  char *id;
  Cidade cidade;
  Lista lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);
    cidade = getCidade(canvas);
    lista = getListaT(cidade);
    n = lenght(lista);
    elemento = getFirst(lista);
    for(i=0;i<n;i++){
      elemento2 = get(lista, elemento);
      if(elemento2!=NULL){
        x1 = getXT(elemento2);
        y1 = getYT(elemento2);
        id = getIdT(elemento2);
        if(pontoInternoR(w, h, x, y, x1, y1) == 't'){
          if(*arqSaidaT==NULL){
            *arqSaidaT = createArqA(path);
          }
          fillArq1(*arqSaidaT, id);
          fillBreakLine(*arqSaidaT);
          elemento2 = getNext(lista, elemento);
          removeTorre(cidade, elemento);
          elemento = elemento2;
        }else{
          elemento = getNext(lista, elemento);
        }
    }
    }
}

void executarDq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas){
  double r=0, x=0, y=0;
  double w1=0, h1=0, x1=0, y1=0;
  void *elemento = NULL, *elemento2=NULL;
  int i, n;
  char *cep;
  Cidade cidade=NULL;
  Lista lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);

    cidade = getCidade(canvas);
    lista = getListaQ(cidade);
    n = lenght(lista);

    elemento = getFirst(lista);
    for(i=0;i<n;i++){
      elemento2 = get(lista, elemento);
      if(elemento2!=NULL){
        w1 = getLargQ(elemento2);
        h1 = getAltQ(elemento2);
        x1 = getXQ(elemento2);
        y1 = getYQ(elemento2);
        cep = getCepQ(elemento2);
        if(verificarInteiramenteSobrepostoCR(w1, h1, x1, y1, r, x, y) == 't'){
          if(*arqSaidaT==NULL){
            *arqSaidaT = createArqA(path);
          }
          fillArq1(*arqSaidaT, cep);
          fillBreakLine(*arqSaidaT);
          elemento2 = getNext(lista, elemento);
          removeQuadra(cidade, elemento);
          *qtdQuadrasRemovidas = *qtdQuadrasRemovidas+1;
          elemento = elemento2;
        }else{
          elemento = getNext(lista, elemento);
        }
      }
    }
}

void executarDh(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double r=0, x=0, y=0;
  double x1=0, y1=0;
  void *elemento = NULL, *elemento2=NULL;
  int i, n;
  char *id;
  Cidade cidade=NULL;
  Lista lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
    cidade = getCidade(canvas);
    lista = getListaH(cidade);
    n = lenght(lista);
    elemento = getFirst(lista);
    for(i=0;i<n;i++){
      elemento2 = get(lista, elemento);
      if(elemento2!=NULL){
        x1 = getXH(elemento2);
        y1 = getYH(elemento2);
        id = getIdH(elemento2);
        if(pontoInternoC(r, x, y, x1, y1) == 't'){
          if(*arqSaidaT==NULL){
            *arqSaidaT = createArqA(path);
          }
          fillArq1(*arqSaidaT, id);
          fillBreakLine(*arqSaidaT);
          elemento2 = getNext(lista, elemento);
          removeHidrante(cidade, elemento);
          elemento = elemento2;
        }else{
          elemento = getNext(lista, elemento);
        }
      }
   }
}

void executarDs(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double r=0, x=0, y=0;
  double x1=0, y1=0;
  void *elemento = NULL, *elemento2=NULL;
  int i, n;
  char *id;
  Cidade cidade=NULL;
  Lista lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
    cidade = getCidade(canvas);
    lista = getListaS(cidade);
    n = lenght(lista);
    elemento = getFirst(lista);
    for(i=0;i<n;i++){
      elemento2 = get(lista, elemento);
      if(elemento2!=NULL){
        x1 = getXS(elemento2);
        y1 = getYS(elemento2);
        id = getIdS(elemento2);
        if(pontoInternoC(r, x, y, x1, y1) == 't'){
          if(*arqSaidaT==NULL){
            *arqSaidaT = createArqA(path);
          }
          fillArq1(*arqSaidaT, id);
          fillBreakLine(*arqSaidaT);
          elemento2 = getNext(lista, elemento);
          removeSemafaro(cidade, elemento);
          elemento = elemento2;
        }else{
          elemento = getNext(lista, elemento);
        }
      }
    }
}

void executarDt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double r=0, x=0, y=0;
  double x1=0, y1=0;
  void *elemento = NULL, *elemento2=NULL;
  int i, n;
  char *id;
  Cidade cidade=NULL;
  Lista lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
    cidade = getCidade(canvas);
    lista = getListaT(cidade);
    n = lenght(lista);
    elemento = getFirst(lista);
    for(i=0;i<n;i++){
      elemento2 = get(lista, elemento);
      if(elemento2!=NULL){
        x1 = getXT(elemento2);
        y1 = getYT(elemento2);
        id = getIdT(elemento2);
        if(pontoInternoC(r, x, y, x1, y1) == 't'){
          if(*arqSaidaT==NULL){
            *arqSaidaT = createArqA(path);
          }
          fillArq1(*arqSaidaT, id);
          fillBreakLine(*arqSaidaT);
          elemento2 = getNext(lista, elemento);
          removeTorre(cidade, elemento);
          elemento = elemento2;
        }else{
          elemento = getNext(lista, elemento);
        }
      }
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
