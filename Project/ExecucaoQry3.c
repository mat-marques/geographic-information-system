#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ExecucaoQry3.h"
#include "StringO.h"

HashTable hash;
Dicionario dicionario;


void executarQryF(FILE *arqEntradaQry, Canvas canvas){
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
    } else {
      ponto = createPoint(automaticId++, getXCelular(celular), getYCelular(celular));
      registrador = createRegister(r, ponto);
      insertRegister(sor, registrador);
    }

  }
  free(r);
  free(fone);
}


void executarQryM2(FILE *arqEntradaQry, Canvas canvas){
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
      } else {
        ponto = createPoint(automaticId++, getXEndereco(endereco), getYEndereco(endereco));
        registrador = createRegister(r, ponto);
        insertRegister(sor, registrador);
      }
    }

  free(r);
  free(cpf);
}


void executarQryE(FILE *arqEntradaQry, Canvas canvas){
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
    } else {
      ponto = createPoint(automaticId++, x, y);
      registrador = createRegister(r, ponto);
      insertRegister(sor, registrador);
    }
  }
  free(r);
  free(cep);
}


void executarQryG(FILE *arqEntradaQry, Canvas canvas){
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
    if(registrador != NULL){
      ponto = getInfoRegister(registrador);
      setXPoint(ponto, x);
      setYPoint(ponto, y);
    } else {
      ponto = createPoint(automaticId++, x, y);
      registrador = createRegister(r, ponto);
      insertRegister(sor, registrador);
    }
  }
  free(id);
  free(r);
}


void executarQryXY(FILE *arqEntradaQry, Canvas canvas){
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
  if(registrador != NULL){
    ponto = getInfoRegister(registrador);
    setXPoint(ponto, x);
    setYPoint(ponto, y);
  } else {
    ponto = createPoint(automaticId++, x, y);
    registrador = createRegister(r, ponto);
    insertRegister(sor, registrador);
  }
  free(r);
}


void executarQryTP(FILE *arqEntradaQry, Canvas canvas){
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

  if(registrador != NULL){
    point = getInfoRegister(registrador);
    getEstabCCloser(cidade, getXPoint(point), getYPoint(point), &x, &y, tp);
    registrador = getRegister(sor, r1);

    if(registrador != NULL){
      point = getInfoRegister(registrador);
      setXPoint(point, x);
      setYPoint(point, y);
    } else {
      point = createPoint(automaticId++, x, y);
      registrador = createRegister(r1, point);
      insertRegister(sor, registrador);
    }

  }

  free(r1);
  free(r2);
  free(tp);
}


void pitorico(Canvas canvas, List list, char *cor);


void textual(Canvas canvas, FILE *arqSaidaT, List list);


void executarQryP(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas){
  char t_p, D_T, *sufixo, *r1, *r2, *cor = NULL, letra;
  int i;
  Register reg1, reg2;
  Cidade cidade;
  SetOfRegisters sor;
  Point point;
  QuadTree q;
  Graph g;
  List list;
  double r = 0;
  CrossRoad v1, v2;
  Vertex v3, v4;

  fscanf(arqEntradaQry, "%c ", &t_p);

  if(t_p == 'p'){
    i = qtdCaracteres(arqEntradaQry);
    sufixo = alocarString(i);
    fscanf(arqEntradaQry, "%s ", sufixo);
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
    point = getInfoRegister(reg1);
    /* Verifica se o ponto está na QuadTree */
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
    if(D_T == 'D'){
      list = shortestPath(g, v3, v4, 0, &r);
    } else {
      list = shortestPath(g, v3, v4, 1, &r);
    }

    if(t_p == 'p'){
      fprintf(*arqSaidaT, "p? p %s %c %s %s", sufixo, D_T, r1, r2);
      if(cor != NULL){
        fprintf(*arqSaidaT, "%s\n", cor);
      } else {
        fputc('\n', *arqSaidaT);
      }
      if(D_T == 'D'){
        fprintf(*arqSaidaT, "Distância minima: %f metros\n", r);
      } else {
        fprintf(*arqSaidaT, "Tempo minimo: %f m/s\n", r);
      }

      pitorico(canvas, list, cor);

    } else {
      fprintf(*arqSaidaT, "p? t %c %s %s\n", D_T, r1, r2);
      if(D_T == 'D'){
        fprintf(*arqSaidaT, "Distância minima: %f metros\n", r);
      } else {
        fprintf(*arqSaidaT, "Tempo minimo: %f m/s\n", r);
      }

      textual(canvas, *arqSaidaT, list);

    }

  }

  free(r1);
  free(r2);
}
