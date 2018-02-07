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


void executarQryM(FILE *arqEntradaQry, Canvas canvas){
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
  char *r1, *r2;
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
  r2 = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", r2);

  cidade = getCidade(canvas);
  sor = getRegistradores(cidade);
  registrador = getRegister(sor, r2);

  if(registrador != NULL){
    point = getInfoRegister(registrador);
    getEstabCCloser(cidade, getXPoint(point), getYPoint(point), &x, &y);
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
}


void executarQryP(FILE *arqEntradaQry, Canvas canvas){
  char *r1, *r2, *cor, letra;
  int i, boolean = 0;

  i = qtdCaracteres(arqEntradaQry);
  r1 = alocarString(i);

  fscanf(arqEntradaQry, "%s ", r1);

  i = qtdCaracteres(arqEntradaQry);
  r2 = alocarString(i);

  fscanf(arqEntradaQry, "%s", r2);
  letra = fgetc(arqEntradaQry);
  if(letra == ' '){
    letra = fgetc(arqEntradaQry);
    if((letra != ' ') && (letra != '\n')){
      boolean = 1;
    }
  }
  if(boolean == 1){
    fseek(arqEntradaQry, -1, SEEK_CUR);
    i = qtdCaracteres(arqEntradaQry);
    cor = alocarString(i);

    fscanf(arqEntradaQry, "%s\n", cor);

    free(cor);
  } else {

  }

  free(r1);
  free(r2);
}
