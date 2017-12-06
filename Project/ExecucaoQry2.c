#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ExecucaoQry2.h"
#include "OpEntrada.h"
#include "OperacoesF.h"

#include "Arquivo.h"
#include "Cidade.h"
#include "Circulo.h"
#include "ConvexHull.h"
#include "Cor.h"
#include "Endereco.h"
#include "Hidrante.h"
#include "List.h"
#include "Morador.h"
#include "Pessoa.h"
#include "Quadra.h"
#include "Retangulo.h"
#include "Semafaro.h"
#include "StringO.h"
#include "Svg.h"
#include "Torre.h"

char secao1[] = "cpfXcep";
char secao2[] = "numcelXpessoa";
char secao3[] = "codtXestabC";
char secao4[] = "cpfXpessoa";
char secao5[] = "cepXquadra";
char secao6[] = "cepXmoradores";
char secao7[] = "cepXpessoas";
char secao8[] = "cnpjXestabC";
char secao9[] = "descricaoXestabC";

HashTable hash;
Dicionario dicionario;

void calculaCoordenadaM(Quadra quadra, double num, char face, double *x,
                        double *y) {
  double xQ, yQ, wQ, hQ;
  xQ = getXQ(quadra);
  yQ = getYQ(quadra);
  wQ = getLargQ(quadra);
  hQ = getAltQ(quadra);
  switch (face) {
  case 'N':
    *x = xQ + num;
    *y = yQ + hQ;
    break;
  case 'S':
    *x = xQ + num;
    *y = yQ;
    break;
  case 'L':
    *x = xQ;
    *y = yQ + num;
    break;
  case 'O':
    *x = xQ + wQ;
    *y = yQ + num;
    break;
  default:
    printf("Face nao existe.\n");
  }
}

void executarQryMv(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryM(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  char *cep;
  int sizeString, i, l;
  Quadra quadra = NULL;
  HashTable hash = NULL;
  HashTable hash2 = NULL;
  List list = NULL;
  Endereco endereco = NULL;
  Pessoa pessoa = NULL;
  Morador morador = NULL;
  Cidade cidade = NULL;
  char *cpf = NULL;

  sizeString = qtdCaracteres(arqEntradaQry);
  cep = alocarString(sizeString);

  fscanf(arqEntradaQry, "%s\n", cep);
  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao5);
  quadra = itemIsInsideHT(hash, cep, cep, compareQ);
  if (quadra == NULL) {
    printf("Cep de quadra fornecida nao existe na cidade.\n");
  } else {
    hash = getSecaoDicionario(dicionario, secao6);
    hash2 = getSecaoDicionario(dicionario, secao4);
    list = getHtList(hash, cep);
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      morador = getItemL(list, i);
      if (morador != NULL) {
        cpf = getCpfM(morador);
        endereco = getEndereco(morador);
        pessoa = itemIsInsideHT(hash, cpf, cpf, comparePessoas);
        if (pessoa != NULL) {
          endereco = getEndereco(morador);
          fprintf(*arqSaidaT, "Comando m?\nNome: %s, Endereco: %s %c %lf %d, "
                              "Numero Celular: %s, Nome Operadora: %s",
                  getNomeP(pessoa), getCep(endereco), getFace(endereco),
                  getNum(endereco), getComp(endereco), getNumCelular(pessoa),
                  getNomeP(pessoa));
        }
      }
      morador = NULL;
      pessoa = NULL;
    }
  }
  free(cep);
}

void executarQryMr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  List list = NULL;
  Pessoa pessoa = NULL;
  List moradores = NULL;
  Endereco endereco = NULL;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  Morador morador = NULL;
  int i, l, j, k;
  double x, y, w, h;
  char *cep, *cpf;

  fscanf(arqEntradaQry, "%lf %lf %lf %lf", &x, &y, &w, &h);

  list = getElementsListInsideR(canvas, 1, x, y, w, h);

  cidade = getCidade(canvas);

  if (list != NULL) {
    l = lengthL(list);
    dicionario = getDicionario(cidade);
    hash = getSecaoDicionario(dicionario, secao6);

    for (i = 1; i < l; i++) { /*Percorre lista das quadras*/
      quadra = getItemL(list, i);
      cep = getCepQ(quadra);
      moradores = getHtList(hash, cep);

      if (moradores != NULL) {
        k = lengthL(moradores);

        for (j = 1; j < k; j++) { /*Percorre lista de moradores*/
          morador = getItemL(moradores, i);
          endereco = getEndereco(morador);

          if (compareEnderecos(endereco, cep) == 0) {
            cpf = getCpfM(morador);
            pessoa = itemIsInsideHT(getSecaoDicionario(dicionario, secao4), cpf,
                                    cpf, comparePessoas);
            if (pessoa != NULL) {
              fprintf(*arqSaidaT, "Comando mr?\nNome: %s, Endereco: %s %c %lf "
                                  "%d, Numero Celular: %s, Nome Operadora: %s",
                      getNomeP(pessoa), getCep(endereco), getFace(endereco),
                      getNum(endereco), getComp(endereco),
                      getNumCelular(pessoa), getNomeP(pessoa));
            }
          }
        }
      }
    }
  }
}

void executarQryDm(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  Pessoa pessoa = NULL;
  Endereco endereco = NULL;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  int i;
  char *cpf;
  double x, y;

  i = qtdCaracteres(arqEntradaQry);
  cpf = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", cpf);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao5);
  pessoa = itemIsInsideHT(hash, cpf, cpf, comparePessoas);

  if (pessoa != NULL) {
    endereco = getEnderecoP(pessoa);
    if (endereco != NULL) {
      quadra = itemIsInsideHT(getSecaoDicionario(dicionario, secao1), cpf, cpf,
                              comparePessoas);

      if (quadra != NULL) {
        calculaCoordenadaM(quadra, getNum(endereco), getFace(endereco), &x, &y);
        fprintf(*arqSaidaT, "Comando dm?\nNome: %s, Endereco: %s %c %lf "
                            "%d, Numero Celular: %s, Nome Operadora: %s",
                getNomeP(pessoa), getCep(endereco), getFace(endereco),
                getNum(endereco), getComp(endereco), getNumCelular(pessoa),
                getNomeP(pessoa));
      } else {
        printf("Região (Quadra) onde a pessoa mora nao existe na cidade.\n");
      }
    }
  } else {
    printf("Pessoa com cpf fornecido não existe no banco de dados.\n");
  }

  free(cpf);
}

void executarQryDe(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  Endereco endereco = NULL;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  EstabC estabC = NULL;
  int i;
  char *cnpj = NULL;
  char *cep;
  double x, y;
  i = qtdCaracteres(arqEntradaQry);
  cnpj = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", cnpj);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao8);
  estabC = itemIsInsideHT(hash, cnpj, cnpj, compareEstabC);

  if (estabC != NULL) {

    endereco = getEnderecoEstabC(estabC);
    cep = getCep(endereco);
    quadra = itemIsInsideHT(getSecaoDicionario(dicionario, secao5), cep, cep, compareEstabC);

    if(quadra != NULL){
      calculaCoordenadaM(quadra, getNum(endereco), getFace(endereco), &x, &y);
      fprintf(*arqSaidaT, "Comando de?\nCodt: %s, Descricao: %s, Cep: %s, Face: %c, Num: %lf, Cnpj: %s, Nome: %s, Coordenada: %lf %lf", getCodt(estabC), getDescription(estabC), getCep(endereco), getFace(endereco), getNum(endereco), getCnpj(estabC), getNomeEstabC(estabC), x, y);
    } else {
      printf("Quadra nao existe.\n");
    }
  } else {
    printf("Pessoa com cpf fornecido não existe no banco de dados.\n");
  }

  free(cnpj);
}

void executarQryCon(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryMse(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas){
  Endereco endereco = NULL;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  EstabC estabC = NULL;
  List list = NULL;
  int i;
  char *cep, sx, *tp;
  double x, y, w, h;

  fscanf(arqEntradaQry, "%c ", &sx);

  i = qtdCaracteres(arqEntradaQry);
  tp = alocarString(i);

  fscanf(arqEntradaQry, "%c %s %lf %lf %lf %lf\n", &sx, tp, &x, &y, &w, &h);

  cidade = getCidade(canvas);

  list = getElementsListInsideR(canvas, 1, x, y, w, h);
  

  if (estabC != NULL) {

    endereco = getEnderecoEstabC(estabC);
    cep = getCep(endereco);
    quadra = itemIsInsideHT(getSecaoDicionario(dicionario, secao5), cep, cep, compareEstabC);

    if(quadra != NULL){
      fprintf(*arqSaidaT, "Comando de?\nCodt: %s, Descricao: %s, Cep: %s, Face: %c, Num: %lf, Cnpj: %s, Nome: %s\n", getCodt(estabC), getDescription(estabC), getCep(endereco), getFace(endereco), getNum(endereco), getCnpj(estabC), getNomeEstabC(estabC));
    } else {
      printf("Quadra nao existe.\n");
    }
  } else {
    printf("Pessoa com cpf fornecido não existe no banco de dados.\n");
  }

  free(tp);
}

void executarQryRip(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryLk(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryRb(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryCo(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryLnr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryEcq(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryEcr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryTecq(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryTecr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryDc(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryLec(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryLcc(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

void executarQryDpr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);
