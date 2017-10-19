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
#include "Exibicao.h"
#include "Cor.h"
<<<<<<< Updated upstream
#include "Lista.h"
=======
#include "Svg.h"
#include "DoubleLinkedList.h"
>>>>>>> Stashed changes
#include "StringO.h"
#include "ConvexHull.h"

void executardq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas){
  double w=0, h=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *cep = NULL;
<<<<<<< Updated upstream
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

=======
  List lista = NULL;

  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
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
<<<<<<< Updated upstream
  Lista lista = NULL;
=======
  List lista = NULL;
>>>>>>> Stashed changes
  char *id = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);
  lista = getElementsListInsideR(canvas, 5, x, y, w,  h);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
<<<<<<< Updated upstream
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
=======
>>>>>>> Stashed changes
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
  void *elemento = NULL;
  int i, n;
  char *id;
  List lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

  lista = getElementsListInsideR(canvas, 6, x, y, w,  h);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdS(elemento);
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

void executardt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double w=0, h=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *id;
  List lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);
  lista = getElementsListInsideR(canvas, 4, x, y, w,  h);

  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdT(elemento);
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

void executarDq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas){
  double r=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *cep;
  List lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
  lista = getElementsListInsideC(canvas, 3, x, y, r);
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
    }
    eraseListDLLTwo(lista);
    eraseBase(lista);
  }
}

void executarDh(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double r=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *id;
  List lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
  lista = getElementsListInsideC(canvas, 5, x, y, r);
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

void executarDs(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double r=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *id;

  List lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
  lista = getElementsListInsideC(canvas, 6, x, y, r);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdS(elemento);
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

void executarDt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas){
  double r=0, x=0, y=0;
  void *elemento = NULL;
  int i, n;
  char *id;
  List lista = NULL;
  fscanf(arqEntradaQry, "%lf %lf %lf\n", &x, &y, &r);
  lista = getElementsListInsideC(canvas, 4, x, y, r);
  if(*arqSaidaT==NULL){
    *arqSaidaT = createArqA(path);
  }

  if(lista != NULL){
    n = lengthDLL(lista);
    id = NULL;
    for(i=1; i<=n; i++){
      elemento = getItemDLL(lista, i);
      id = getIdT(elemento);
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

void executarPc(FILE *arqEntradaQry, Canvas canvas, char *arqNome, char *dirPath, char *extensao2){
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



  tagFechamento(arqSaidaSvg2);
}

void executarAc(FILE *arqEntradaQry , FILE **arqSaidaT, char *path, Canvas canvas){

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
