#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ExecucaoQry3.h"
#include "StringO.h"
#include "Svg.h"
#include "OperacoesF.h"

HashTable hash;
Dicionario dicionario;


void executarQryF(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas){
  char *r, *fone;
  char secao15[] = "numcelXcelular";
  int i;
  Cidade cidade = NULL;
  Celular celular = NULL;
  SetOfRegisters sor = NULL;
  Register registrador = NULL;
  Point ponto = NULL;
  i = qtdCaracteres(arqEntradaQry);
  r = alocarString(i);

  fscanf(arqEntradaQry, "%s ", r);

  i = qtdCaracteres(arqEntradaQry);
  fone = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", fone);

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);

  hash = getSecaoDicionario(dicionario, secao15);

  celular = itemIsInsideHT(hash, fone, fone, compareCelulares);

  if(celular != NULL){
    sor = getRegistradores(cidade);
    registrador = getRegister(sor, r);
    if(registrador != NULL){
      ponto = getInfoRegister(registrador);
      setXPoint(ponto, getXCelular(celular));
      setYPoint(ponto, getYCelular(celular));
      fprintf(*arqSaidaT, "@f? %s %s\n", r, fone);
      fprintf(*arqSaidaT, "O registrador %s recebeu as coordenadas (%f | %f)\n", r, getXCelular(celular), getYCelular(celular));
    }
  }

  free(r);
  free(fone);
}


void executarQryM2(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas){
  char *r, *cpf;
  char secao11[] = "cpfXmorador";
  int i;
  Cidade cidade = NULL;
  SetOfRegisters sor = NULL;
  Register registrador = NULL;
  Point ponto = NULL;
  Morador morador = NULL;
  Endereco endereco = NULL;
  i = qtdCaracteres(arqEntradaQry);
  r = alocarString(i);

  fscanf(arqEntradaQry, "%s ", r);

  i = qtdCaracteres(arqEntradaQry);
  cpf = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", cpf);

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao11);

  morador = itemIsInsideHT(hash, cpf, cpf, compareMorador);

  if(morador != NULL){
      endereco = getEndereco(morador);
      sor = getRegistradores(cidade);
      registrador = getRegister(sor, r);
      if(registrador != NULL){
        ponto = getInfoRegister(registrador);
        setXPoint(ponto, getXEndereco(endereco));
        setYPoint(ponto, getYEndereco(endereco));
        fprintf(*arqSaidaT, "@m? %s %s\n", r, cpf);
        fprintf(*arqSaidaT, "O registrador %s recebeu as coordenadas (%f | %f)\n", r, getXEndereco(endereco), getYEndereco(endereco));
      }
  }

  free(r);
  free(cpf);
}


void executarQryE(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas){
  char *r, *cep, face;
  char secao5[] = "cepXquadra";
  int num;
  int i;
  double x = 0, y = 0;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  SetOfRegisters sor = NULL;
  Register registrador = NULL;
  Point ponto = NULL;
  i = qtdCaracteres(arqEntradaQry);
  r = alocarString(i);

  fscanf(arqEntradaQry, "%s ", r);

  i = qtdCaracteres(arqEntradaQry);
  cep = alocarString(i);

  fscanf(arqEntradaQry, "%s ", cep);

  fscanf(arqEntradaQry, "%c %d\n", &face, &num);

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao5);
  quadra = itemIsInsideHT(hash, cep, cep, compareQ);

  if(quadra != NULL){
    sor = getRegistradores(cidade);
    calculaCoordenadaM(quadra, num, face, &x, &y);
    registrador = getRegister(sor, r);
    if(registrador != NULL){
      ponto = getInfoRegister(registrador);
      setXPoint(ponto, x);
      setYPoint(ponto, y);
      fprintf(*arqSaidaT, "@e? %s %s %c %d\n", r, cep, face, num);
      fprintf(*arqSaidaT, "O registrador %s recebeu as coordenadas (%f | %f)\n", r, x, y);
    }
  }

  free(r);
  free(cep);
}


void executarQryG(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas){
  char *r, *id;
  Cidade cidade = NULL;
  SetOfRegisters sor = NULL;
  Register registrador = NULL;
  Point ponto = NULL;
  double x, y;
  int i;
  void *equipamentoUrbano = NULL;
  i = qtdCaracteres(arqEntradaQry);
  r = alocarString(i);

  fscanf(arqEntradaQry, "%s ", r);

  i = qtdCaracteres(arqEntradaQry);
  id = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", id);

  cidade = getCidade(canvas);

  equipamentoUrbano = getTorre(cidade, id);
  if(equipamentoUrbano == NULL){
    equipamentoUrbano = getSemafaro(cidade, id);
    if(equipamentoUrbano == NULL){
      equipamentoUrbano = getHidrante(cidade, id);
      if(equipamentoUrbano != NULL){
        x = getXH(equipamentoUrbano);
        y = getYH(equipamentoUrbano);
      }
    } else {
      x = getXS(equipamentoUrbano);
      y = getYS(equipamentoUrbano);
    }
  } else {
    x = getXT(equipamentoUrbano);
    y = getYT(equipamentoUrbano);
  }

  if(equipamentoUrbano != NULL){
    sor = getRegistradores(cidade);
    registrador = getRegister(sor, r);
    ponto = getInfoRegister(registrador);
    setXPoint(ponto, x);
    setYPoint(ponto, y);
    fprintf(*arqSaidaT, "@g? %s %s\n", r, id);
    fprintf(*arqSaidaT, "O registrador %s recebeu as coordenadas (%f | %f)\n", r, x, y);
  }

  free(id);
  free(r);
}


void executarQryXY(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas){
  char *r;
  Cidade cidade = NULL;
  SetOfRegisters sor = NULL;
  Register registrador = NULL;
  Point ponto = NULL;
  double x, y;
  int i;

  i = qtdCaracteres(arqEntradaQry);
  r = alocarString(i);

  fscanf(arqEntradaQry, "%s ", r);
  fscanf(arqEntradaQry, "%lf %lf\n", &x, &y);
  cidade = getCidade(canvas);
  sor = getRegistradores(cidade);
  registrador = getRegister(sor, r);
  ponto = getInfoRegister(registrador);
  setXPoint(ponto, x);
  setYPoint(ponto, y);

  fprintf(*arqSaidaT, "@xy %s %f %f\n", r, x, y);
  fprintf(*arqSaidaT, "O registrador %s recebeu as coordenadas (%f | %f)\n", r, x, y);

  free(r);
}


void executarQryTP(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas){
  char *r1, *r2, *tp;
  int i;
  Cidade cidade;
  SetOfRegisters sor;
  Register registrador;
  Point point;
  double x = 0, y = 0;
  i = qtdCaracteres(arqEntradaQry);
  r1 = alocarString(i);

  fscanf(arqEntradaQry, "%s ", r1);

  i = qtdCaracteres(arqEntradaQry);
  tp = alocarString(i);

  fscanf(arqEntradaQry, "%s ", tp);

  i = qtdCaracteres(arqEntradaQry);
  r2 = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", r2);

  cidade = getCidade(canvas);
  sor = getRegistradores(cidade);
  registrador = getRegister(sor, r2);

  point = getInfoRegister(registrador);
  getEstabCCloser(cidade, getXPoint(point), getYPoint(point), &x, &y, tp);

  registrador = getRegister(sor, r1);
  point = getInfoRegister(registrador);
  setXPoint(point, x);
  setYPoint(point, y);

  fprintf(*arqSaidaT, "@xy %s %s %s\n", r1, tp, r2);
  fprintf(*arqSaidaT, "O registrador %s recebeu as coordenadas (%f | %f)\n", r1, x, y);

  free(r1);
  free(r2);
  free(tp);
}


void pitorico(Canvas canvas, List list, FILE *arqSaidaSvg, char *cor){
  Quadra quadra = NULL;
  int i, j;
  Vertex v1, v2;
  CrossRoad c1, c2;
  Cidade cidade;
  Edge e;
  Street s;
  Graph g;
  char cor2[] = "black";
  char secao5[] = "cepXquadra", *cep;
  double x1, y1, x2, y2;

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao5);
  g = getGrafo(cidade);

  /* Obtenção dos vertices de origem e destino do grafo */
  v1 = getBeginItemL(list);
  v2 = getEndItemL(list);

  c1 = getInfoVertex(v1);
  c2 = getInfoVertex(v2);

  x1 = getXCrossRoad(c1);
  y1 = getYCrossRoad(c1);
  x2 = getXCrossRoad(c2);
  y2 = getYCrossRoad(c2);

  tagAbertura(arqSaidaSvg, getWidth(canvas) + 50, getHeight(canvas) + 50);
  /* Desenha as coordenadas de origem e destino. */
  tagCirculo(arqSaidaSvg, 5, x1, y1, cor2);
  tagTexto2(arqSaidaSvg, getIdCrossRoad(c1), cor2, 10, x1, y1);
  tagCirculo(arqSaidaSvg, 5, x2, y2, cor2);
  tagTexto2(arqSaidaSvg, getIdCrossRoad(c2), cor2, 10, x2, y2);

  j = lengthL(list);
  defArrow(arqSaidaSvg, cor);
  /* Desenha as quadras */
  for(i=2; i<=j; i++){
    v1 = getItemL(list, i-1);
    v2 = getItemL(list, i);
    if(v1 != NULL && v2 != NULL){
      c1 = getInfoVertex(v1);
      c2 = getInfoVertex(v2);
      e = getEdge(g, getIdVertex(v1), getIdVertex(v2));
      s = getInfoEdge(e);
      quadra = NULL;
      cep = NULL;
      cep = getCepRight(s);
      quadra = itemIsInsideHT(hash, cep, cep, compareQ);
      if(quadra != NULL){
        tagRetangulo2(arqSaidaSvg, getLargQ(quadra), getAltQ(quadra), getXQ(quadra), getYQ(quadra), getCorpQ(quadra), getCorbQ(quadra));
        tagTexto2(arqSaidaSvg, getCepQ(quadra), cor2, 12, getXQ(quadra)+10, getYQ(quadra)+20);
      }
      quadra = NULL;
      cep = NULL;
      cep = getCepLeft(s);
      quadra = itemIsInsideHT(hash, cep, cep, compareQ);
      if(quadra != NULL){
        tagRetangulo2(arqSaidaSvg, getLargQ(quadra), getAltQ(quadra), getXQ(quadra), getYQ(quadra), getCorpQ(quadra), getCorbQ(quadra));
        tagTexto2(arqSaidaSvg, getCepQ(quadra), cor2, 12, getXQ(quadra)+10, getYQ(quadra)+20);
      }

    }
  }
  /* Desenhando as arestas */
  for(i=2; i<=j; i++){
    v1 = getItemL(list, i-1);
    v2 = getItemL(list, i);
    if(v1 != NULL && v2 != NULL){
      c1 = getInfoVertex(v1);
      c2 = getInfoVertex(v2);
      arrow(arqSaidaSvg, getXCrossRoad(c1), getYCrossRoad(c1), getXCrossRoad(c2), getYCrossRoad(c2), cor);
    }
  }
  tagFechamento(arqSaidaSvg);
}


int direcao(double x1, double y1, double x2, double y2){
  double dx, dy;
  double tan_Pi_div_8 = sqrt(2.0) - 1.0;
  dx = x1 - x2;
  dy = y1 - y2;
  /*
    1 - Sul
    2 - Norte
    3 - Oeste
    4 - Leste
    5 - Suldoeste
    6 - Noroeste
    7 - Suldeste
    8 - Nordeste
  */
  if (abs(dx) > abs(dy))
   {
       if (abs(dy / dx) <= tan_Pi_div_8)
       {
           return dx > 0 ? 4 : 3;
       }

       else if (dx > 0)
       {
           return dy > 0 ? 8 : 7;
       }
       else
       {
           return dy > 0 ? 6:5;
       }
   }

   else if (abs(dy) > 0)
   {
       if (abs(dx / dy) <= tan_Pi_div_8)
       {
           return dy > 0 ? 2 : 1;
       }
       else if (dy > 0)
       {
           return dx > 0 ? 8 : 6;
       }
       else
       {
           return dx > 0 ? 7 : 5;
       }
   }
   else
   {
       return 0;
   }



}


void textual(Canvas canvas, FILE *arqSaidaT, List list){
  int i, j, p=0, n;
  char direcoes[9][10] = {"", "Norte", "Sul", "Oeste", "Leste",
                   "Suldoeste", "Noroeste", "Suldeste","Nordeste"};
  char *id1, *id2;
  Vertex v1, v2;
  Edge e1;
  Cidade cidade;
  Street s1;
  Graph g;
  CrossRoad c1, c2;

  v1 = getBeginItemL(list);
  v2 = getEndItemL(list);

  cidade = getCidade(canvas);
  g = getGrafo(cidade);

  j = lengthL(list);
  for(i=2; i<=j; i++){
    v1 = getItemL(list, i-1);
    v2 = getItemL(list, i);

    if(v1 != NULL && v2 != NULL){
      c1 = getInfoVertex(v1);
      c2 = getInfoVertex(v2);
      e1 = getEdge(g, getIdVertex(v1), getIdVertex(v2));
      s1 = getInfoEdge(e1);
      id1 = getNameStreet(s1);
      n = direcao(getXCrossRoad(c1), getYCrossRoad(c1), getXCrossRoad(c2), getYCrossRoad(c2));
      if(p == 0){
        fprintf(arqSaidaT, "Siga na rua %s na direção %s.\n", id1, direcoes[n]);
        id2 = id1;
        p = 1;
      } else if(strcmp(id1, id2) == 0) {
        fprintf(arqSaidaT, "Continui na rua %s na direção %s.\n", id1, direcoes[n]);
      } else {
        fprintf(arqSaidaT, "Vire na rua %s na direção %s.\n", id1, direcoes[n]);
        id2 = id1;
      }
    }
  }

  fprintf(arqSaidaT, "O ponto de destino se encontra na rua %s.\n", id1);

}


void executarQryP(FILE *arqEntradaQry, FILE **arqSaidaT,  char *nameArq, Canvas canvas){
  char t_p, D_T, *sufixo= NULL, *sufixoAux = NULL, *r1= NULL, *r2= NULL, *cor = NULL, letra, *nameArqS= NULL;
  char traco[] = "-", *strAux= NULL;
  int i;
  FILE *arqSaidaSvg= NULL;
  Register reg1= NULL, reg2= NULL;
  Cidade cidade= NULL;
  SetOfRegisters sor= NULL;
  Point point= NULL;
  QuadTree q= NULL;
  Graph g= NULL;
  List list;
  double r = 0;
  CrossRoad v1, v2;
  Vertex v3, v4;

  fscanf(arqEntradaQry, "%c ", &t_p);

  if(t_p == 'p'){
    i = qtdCaracteres(arqEntradaQry) + 4;
    sufixo = alocarString(i);
    fscanf(arqEntradaQry, "%s ", sufixo);

    sufixoAux = alocarString(i-4);
    strcpy(sufixoAux, sufixo);

    sufixo[i-5] = '.';
    sufixo[i-4] = 's';
    sufixo[i-3] = 'v';
    sufixo[i-2] = 'g';
    sufixo[i-1] = '\0';
  }

  fscanf(arqEntradaQry, "%c ", &D_T);

  i = qtdCaracteres(arqEntradaQry);
  r1 = alocarString(i);
  fscanf(arqEntradaQry, "%s ", r1);

  i = qtdCaracteres(arqEntradaQry);
  r2 = alocarString(i);
  fscanf(arqEntradaQry, "%s", r2);

  letra = fgetc(arqEntradaQry);
  if(t_p == 'p' && letra != '\n'){
    i = qtdCaracteres(arqEntradaQry);
    cor = alocarString(i);
    fscanf(arqEntradaQry, "%s\n", cor);
  }

  cidade = getCidade(canvas);
  sor = getRegistradores(cidade);
  reg1 = getRegister(sor, r1);
  reg2 = getRegister(sor, r2);
  q = getListaCrossRoad(cidade);
  g = getGrafo(cidade);

  if(reg1 != NULL && reg2 != NULL){

    /* Verifica se o ponto está na QuadTree */
    point = getInfoRegister(reg1);
    v1 = searchQuadTreeByCoordinate(q, getXPoint(point), getYPoint(point));
    if(v1 == NULL){ /* Encontra o ponto mais próximo que esta na QuadTree */
      v1 = getNearestPoint(q, getXPoint(point), getYPoint(point));
    }


    /* Verifica se o ponto está na QuadTree */
    point = getInfoRegister(reg2);

    v2 = searchQuadTreeByCoordinate(q, getXPoint(point), getYPoint(point));
    if(v2 == NULL){ /* Encontra o ponto mais próximo que esta na QuadTree */
      v2 = getNearestPoint(q, getXPoint(point), getYPoint(point));
    }

    /* Busca os vertíces correspondentes no grafo */

    v3 = getVertex(g, getIdCrossRoad(v1));
    v4 = getVertex(g, getIdCrossRoad(v2));

     /* Vertíces que compõem o menor caminho e o valor do caminho */
    if(v4 != v3){
      if(D_T == 'D'){
        list = shortestPath(g, v3, v4, 0, &r);
      } else {
        list = shortestPath(g, v3, v4, 1, &r);
      }

      if(t_p == 'p'){
        fprintf(*arqSaidaT, "p? p %s %c %s %s", sufixoAux, D_T, r1, r2);
        if(cor != NULL){
          fprintf(*arqSaidaT, " %s\n", cor);
        } else {
          fputc('\n', *arqSaidaT);
        }
        if(lengthL(list) > 1){
          if(D_T == 'D'){
            fprintf(*arqSaidaT, "Distância minima: %f metros\n", r);
          } else {
            fprintf(*arqSaidaT, "Tempo minimo: %f segundos\n", r);
          }
          strAux = concatenarStrings(nameArq, traco);
          nameArqS = concatenarStrings(strAux, sufixo);
          arqSaidaSvg = fopen(nameArqS, "w");
          if(arqSaidaSvg != NULL){
            pitorico(canvas, list, arqSaidaSvg, cor);
          }
        } else {
          fprintf(*arqSaidaT, "Caminho impossível de ser alcançado.\n");
        }
      } else {
        fprintf(*arqSaidaT, "p? t %c %s %s\n", D_T, r1, r2);
        if(lengthL(list) > 1){
          if(D_T == 'D'){
            fprintf(*arqSaidaT, "Distância minima: %f metros\n", r);
          } else {
            fprintf(*arqSaidaT, "Tempo minimo: %f segundos\n", r);
          }

          textual(canvas, *arqSaidaT, list);
        } else {
          fprintf(*arqSaidaT, "Caminho impossível de ser alcançado.\n");
        }
      }

      eraseListL(list, NULL);
      eraseBase(list);

    }

  }
  if(strAux != NULL)
    free(strAux);

  if(arqSaidaSvg != NULL)
    fclose(arqSaidaSvg);

  if(sufixoAux != NULL)
    free(sufixoAux);

  if(sufixo != NULL)
  free(sufixo);

  if(nameArqS != NULL)
    free(nameArqS);

  if(cor != NULL)
    free(cor);

  free(r1);
  free(r2);
}
