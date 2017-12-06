#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cidade.h"
#include "ConvexHull.h"
#include "Endereco.h"
#include "Hidrante.h"
#include "List.h"
#include "QuadTree.h"
#include "Semafaro.h"
#include "Stack.h"
#include "Svg.h"
#include "Torre.h"

FILE *newArqCity = NULL;

typedef struct City {
  QuadTree listaQ, listaS, listaT, listaH;
  Dicionario dicionario;
  List operadoras;
  char *nome;
} City;

void ConvexHullAuxC(Stack stack, Cidade cidade, int type);

Dicionario configuraDicionario() {
  char secao1[] = "cpfXcep";
  char secao2[] = "numcelXpessoa";
  char secao3[] = "codtXestabC";
  char secao4[] = "cpfXpessoa";
  char secao5[] = "cepXquadra";
  char secao6[] = "cepXmoradores";
  char secao7[] = "cepXpessoas";
  char secao8[] = "cnpjXestabC";
  char secao9[] = "descricaoXestabC";
  Dicionario dicionario = NULL;

  dicionario = criaDicionario(8);

  insertSecaoDicionario(dicionario, secao1, 50);
  insertSecaoDicionario(dicionario, secao2, 50);
  insertSecaoDicionario(dicionario, secao3, 50);
  insertSecaoDicionario(dicionario, secao4, 50);
  insertSecaoDicionario(dicionario, secao5, 50);
  insertSecaoDicionario(dicionario, secao6, 50);
  insertSecaoDicionario(dicionario, secao7, 50);
  insertSecaoDicionario(dicionario, secao8, 50);
  insertSecaoDicionario(dicionario, secao9, 50);
  return dicionario;
}

Cidade criaCidade(char *name) {
  City *city = NULL;
  city = (City *)malloc(sizeof(City));
  city->nome = name;
  city->listaQ = createQuadTree();
  city->listaS = createQuadTree();
  city->listaT = createQuadTree();
  city->listaH = createQuadTree();
  city->dicionario = configuraDicionario();
  return city;
}

long int quantityElementsICity(Cidade cidade) {
  City *city = (City *)cidade;
  long int myLength = 0;
  if (city != NULL) {
    myLength = lenghtQuadTree(city->listaQ);
    myLength = myLength + lenghtQuadTree(city->listaH);
    myLength = myLength + lenghtQuadTree(city->listaS);
    myLength = myLength + lenghtQuadTree(city->listaT);
  }
  return myLength;
}

long int insertQuadra(Cidade cidade, ElementoUrbano item) {
  City *city = (City *)cidade;
  return insertQuadTree(city->listaQ, item, getXQ(item), getYQ(item));
}

long int removeQuadra(Cidade cidade, char *cep) {
  City *city = (City *)cidade;
  long int qtd;
  Quadra quadra;
  quadra = removeQuadTreeItemI(city->listaQ, cep, compareQ, &qtd);
  removeQ(quadra);
  return qtd;
}

long int insertSemafaro(Cidade cidade, ElementoUrbano item) {
  City *city = (City *)cidade;
  return insertQuadTree(city->listaS, item, getXS(item), getYS(item));
}

long int removeSemafaro(Cidade cidade, char *id) {
  City *city = (City *)cidade;
  Semafaro semafaro;
  long int qtd;
  semafaro = removeQuadTreeItemI(city->listaS, id, compareS, &qtd);
  removeS(semafaro);
  return qtd;
}

long int insertTorre(Cidade cidade, ElementoUrbano item) {
  City *city = (City *)cidade;
  return insertQuadTree(city->listaT, item, getXT(item), getYT(item));
}

long int removeTorre(Cidade cidade, char *id) {
  City *city = (City *)cidade;
  Torre torre;
  long int qtd;
  torre = removeQuadTreeItemI(city->listaT, id, compareT, &qtd);
  removeT(torre);
  return qtd;
}

long int insertHidrante(Cidade cidade, ElementoUrbano item) {
  City *city = (City *)cidade;
  return insertQuadTree(city->listaH, item, getXH(item), getYH(item));
}

long int removeHidrante(Cidade cidade, char *id) {
  City *city = (City *)cidade;
  Hidrante hidrante;
  long int qtd;
  hidrante = removeQuadTreeItemI(city->listaH, id, compareH, &qtd);
  removeQ(hidrante);
  return qtd;
}


Dicionario getDicionario(Cidade cidade){
  City *city = (City *)cidade;
  return city->dicionario;
}


void insertOperadora(Cidade cidade, Operadora operadora) {
  City *city = (City *)cidade;
  insertBeginL(city->operadoras, operadora);
}

void removeOperadora(Cidade cidade, char *nome) {
  City *city = (City *)cidade;
  removeItemL2(city->operadoras, nome, compareOperadoras);
}

List getListaOperadoras(Cidade cidade) {
  City *city = (City *)cidade;
  return city->operadoras;
}

Operadora getOperadoraC(Cidade cidade, char *nome) {
  City *city = (City *)cidade;
  return searchItemL(city->operadoras, (void *)nome, compareOperadoras);
}

char *getNome(Cidade cidade) {
  City *city = (City *)cidade;
  return city->nome;
}

void setNome(Cidade cidade, char *nome) {
  City *city = (City *)cidade;
  free(city->nome);
  city->nome = nome;
}

QuadTree getListaQ(Cidade cidade) {
  City *city = (City *)cidade;
  return city->listaQ;
}

QuadTree getListaS(Cidade cidade) {
  City *city = (City *)cidade;
  return city->listaS;
}

QuadTree getListaT(Cidade cidade) {
  City *city = (City *)cidade;
  return city->listaT;
}

QuadTree getListaH(Cidade cidade) {
  City *city = (City *)cidade;
  return city->listaH;
}

void showQ(Quadra quadra) {
  double x, y, w, h;
  char *corP, *corB;
  char cor[] = "red";
  char text[] = "Q";
  x = getXQ(quadra);
  y = getYQ(quadra);
  w = getLargQ(quadra);
  h = getAltQ(quadra);
  corP = getCorpQ(quadra);
  corB = getCorbQ(quadra);
  tagRetangulo2(newArqCity, w, h, x, y, corP, corB);
  tagTexto2(newArqCity, text, cor, 5, x, y);
}

void showH(Hidrante hidrante) {
  double x, y;
  char *corP, *corB;
  char cor[] = "red";
  char text[] = "H";
  x = getXH(hidrante);
  y = getYH(hidrante);
  corP = getCorpH(hidrante);
  corB = getCorbH(hidrante);
  tagCirculo2(newArqCity, 5, x, y, corP, corB);
  tagTexto2(newArqCity, text, cor, 5, x - 1.5, y + 1.5);
}

void showS(Semafaro semafaro) {
  double x, y;
  char *corP, *corB;
  char cor[] = "red";
  char text[] = "S";
  x = getXS(semafaro);
  y = getYS(semafaro);
  corP = getCorpS(semafaro);
  corB = getCorbS(semafaro);
  tagCirculo2(newArqCity, 5, x, y, corP, corB);
  tagTexto2(newArqCity, text, cor, 5, x - 1.5, y + 1.5);
}

void showT(Torre torre) {
  double x, y, r;
  char *corP, *corB;
  char cor[] = "red";
  char text[] = "T";
  x = getXT(torre);
  y = getYT(torre);
  corP = getCorpT(torre);
  corB = getCorbT(torre);
  r = getRaio(torre);
  if (r > 0) {
    tagCirculoOpacity(newArqCity, r, x, y, cor);
  }
  tagCirculo2(newArqCity, 5, x, y, corP, corB);
  tagTexto2(newArqCity, text, cor, 5, x - 1.5, y + 1.5);
}

void showQuadras(Cidade cidade, FILE *file) {
  City *city = (City *)cidade;
  newArqCity = file;
  showQuadTree(city->listaQ, showQ);
  newArqCity = NULL;
}

void showHidrantes(Cidade cidade, FILE *file) {
  City *city = (City *)cidade;
  newArqCity = file;
  showQuadTree(city->listaH, showH);
  newArqCity = NULL;
}

void showSemafaros(Cidade cidade, FILE *file) {
  City *city = (City *)cidade;
  newArqCity = file;
  showQuadTree(city->listaS, showS);
  newArqCity = NULL;
}

void showTorres(Cidade cidade, FILE *file) {
  City *city = (City *)cidade;
  newArqCity = file;
  showQuadTree(city->listaT, showT);
  newArqCity = NULL;
}

Quadra getQuadra(Cidade cidade, char *cep) {
  Quadra quadra = NULL;
  City *city = (City *)cidade;
  quadra = searchQuadTreeItem(city->listaQ, cep, compareQ);
  return quadra;
}

ElementoUrbano getTorre(Cidade cidade, char *id) {
  Torre torre = NULL;
  City *city = (City *)cidade;
  torre = searchQuadTreeItem(city->listaT, id, compareT);
  return torre;
}

ElementoUrbano getSemafaro(Cidade cidade, char *id) {
  Semafaro semafaro = NULL;
  City *city = (City *)cidade;
  semafaro = searchQuadTreeItem(city->listaS, id, compareS);
  return semafaro;
}

ElementoUrbano getHidrante(Cidade cidade, char *id) {
  Hidrante hidrante = NULL;
  City *city = (City *)cidade;
  hidrante = searchQuadTreeItem(city->listaH, id, compareH);
  return hidrante;
}

void eraseListaQ(Cidade cidade) {

  City *city = (City *)cidade;

  eraseQuadTreeNode(city->listaQ, removeQ);
  eraseQuadTreeBase(city->listaQ);

  city->listaQ = NULL;
}

void eraseListaS(Cidade cidade) {

  City *city = (City *)cidade;

  eraseQuadTreeNode(city->listaS, removeS);
  eraseQuadTreeBase(city->listaS);

  city->listaS = NULL;
}

void eraseListaT(Cidade cidade) {

  City *city = (City *)cidade;

  eraseQuadTreeNode(city->listaT, removeT);
  eraseQuadTreeBase(city->listaT);

  city->listaT = NULL;
}

void eraseListaH(Cidade cidade) {

  City *city = (City *)cidade;

  eraseQuadTreeNode(city->listaH, removeH);
  eraseQuadTreeBase(city->listaH);

  city->listaH = NULL;
}

void eraseCidade(Cidade cidade) {
  City *city = (City *)cidade;
  eraseListaQ(cidade);
  eraseListaS(cidade);
  eraseListaT(cidade);
  eraseListaH(cidade);
  if (city->nome != NULL) {
    free(city->nome);
  }
  free(cidade);
}

void ConvexHullAuxC(Stack stack, Cidade cidade, int type) {
  int i, n;
  void *element = NULL;

  switch (type) {
  case 1: /* Quadra. */
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertQuadra(cidade, element);
    }
    break;
  case 2: /* Hidrante. */
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertHidrante(cidade, element);
    }
    break;
  case 3: /* semafaro. */
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertSemafaro(cidade, element);
    }
    break;
  case 4: /* Torre. */
    n = lengthStack(stack);
    for (i = 0; i < n; i++) {
      element = getItemTop(stack);
      removeTop(stack, NULL);
      insertTorre(cidade, element);
    }
    break;
  }
}
