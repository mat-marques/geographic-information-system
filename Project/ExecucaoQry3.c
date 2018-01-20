#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ExecucaoQry3.h"
#include "StringO.h"

char secao1[] = "cpfXcep";
char secao2[] = "numcelXpessoa";
char secao3[] = "codtXestabC";
char secao4[] = "cpfXpessoa";
char secao5[] = "cepXquadra";
char secao6[] = "cepXmoradores";
char secao7[] = "cepXpessoas";
char secao8[] = "cnpjXestabC";
char secao9[] = "descricaoXestabC";
char secao10[] = "cepXestabC";
char secao11[] = "cpfXmorador";
char secao12[] = "operadoraXcelular";
char secao13[] = "torreXcelular";
char secao14[] = "numcelXtorre";
char secao15[] = "numcelXcelular";
char secao16[] = "operadoraXtorre";

HashTable hash;
Dicionario dicionario;


void executarQryF(FILE *arqEntradaQry, Canvas canvas){
  char *r, *fone;
  int i;
  Cidade cidade = NULL;
  Celular celular = NULL;
  SetOfRegisters sor = NULL;
  Register registrador = NULL;
  //Point ponto = NULL;
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

    } else {

    }

  }
  free(r);
  free(fone);
}


void executarQryM(FILE *arqEntradaQry, Canvas canvas){
  char *r, *cpf, *cep = NULL;
  int i;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  SetOfRegisters sor = NULL;
  Register registrador = NULL;
  Point ponto = NULL;
  i = qtdCaracteres(arqEntradaQry);
  r = alocarString(i);

  fscanf(arqEntradaQry, "%s ", r);

  i = qtdCaracteres(arqEntradaQry);
  cpf = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", cpf);

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);

  hash = getSecaoDicionario(dicionario, secao1);

  cep = (char*) itemIsInsideHT(hash, cpf, cpf, compareStrings);

  if(cep != NULL){
    quadra = getQuadra(cidade, cep);
    if(quadra != NULL){
      sor = getRegistradores(cidade);
      registrador = getRegister(sor, r);
      if(registrador != NULL){
        ponto = getInfoRegister(registrador);
        setXPoint(ponto, getXQ(quadra));
        setYPoint(ponto, getXQ(quadra));
      } else {
        ponto = createPoint(automaticId++, getXQ(quadra), getYQ(quadra));
        registrador = createRegister(r, ponto);
        insertRegister(sor, registrador);
      }
    }
  }

  free(r);
  free(cpf);
}


void executarQryE(FILE *arqEntradaQry, Canvas canvas){
  char *r, *cep, face;
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

  i = qtdCaracteres(arqEntradaQry);
  r1 = alocarString(i);

  fscanf(arqEntradaQry, "%s ", r1);

  i = qtdCaracteres(arqEntradaQry);
  r2 = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", r2);

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
