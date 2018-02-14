#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cidade.h"
#include "ConvexHull.h"
#include "Endereco.h"

#include "List.h"
#include "Svg.h"
#include "Ponto.h"
#include "OperacoesF.h"
#include "Celular.h"
#include "StringO.h"

FILE *newArqCity = NULL;

typedef struct City {
  QuadTree listaQ, listaS, listaT, listaH;
  Dicionario dicionario;
  List listaMoradores, listaEstabComerciais, listaPessoas;
  Graph grafo;
  QuadTree listCrossRoad;
  SetOfRegisters registradores;
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
  char secao10[] = "cepXestabC";
  char secao11[] = "cpfXmorador";
  char secao12[] = "operadoraXcelular";
  char secao13[] = "torreXcelular";
  char secao14[] = "numcelXtorre";
  char secao15[] = "numcelXcelular";
  char secao16[] = "operadoraXtorre";

  Dicionario dicionario = NULL;

  dicionario = criaDicionario(16);

  insertSecaoDicionario(dicionario, secao1, 50);
  insertSecaoDicionario(dicionario, secao2, 50);
  insertSecaoDicionario(dicionario, secao3, 50);
  insertSecaoDicionario(dicionario, secao4, 50);
  insertSecaoDicionario(dicionario, secao5, 50);
  insertSecaoDicionario(dicionario, secao6, 50);
  insertSecaoDicionario(dicionario, secao7, 50);
  insertSecaoDicionario(dicionario, secao8, 50);
  insertSecaoDicionario(dicionario, secao9, 50);
  insertSecaoDicionario(dicionario, secao10, 50);
  insertSecaoDicionario(dicionario, secao11, 50);

  insertSecaoDicionario(dicionario, secao12, 50);
  insertSecaoDicionario(dicionario, secao13, 50);
  insertSecaoDicionario(dicionario, secao14, 50);
  insertSecaoDicionario(dicionario, secao15, 50);
  insertSecaoDicionario(dicionario, secao16, 5);
  return dicionario;
}

SetOfRegisters configurarRegistradores(){
  SetOfRegisters sor;
  Register r;
  Point p;
  char name[] = "Registradores";
  char r0[] = "R0";
  char r1[] = "R1";
  char r2[] = "R2";
  char r3[] = "R3";
  char r4[] = "R4";
  char r5[] = "R5";
  char r6[] = "R6";
  char r7[] = "R7";
  char r8[] = "R8";
  char r9[] = "R9";
  char r10[] = "R10";

  sor = createSetOfRegisters(name, 11);

  p = createPoint(1, 0, 0);
  r = createRegister(r0, p);
  insertRegister(sor, r);

  p = createPoint(2, 0, 0);
  r = createRegister(r1, p);
  insertRegister(sor, r);

  p = createPoint(3, 0, 0);
  r = createRegister(r2, p);
  insertRegister(sor, r);

  p = createPoint(4, 0, 0);
  r = createRegister(r3, p);
  insertRegister(sor, r);

  p = createPoint(5, 0, 0);
  r = createRegister(r4, p);
  insertRegister(sor, r);

  p = createPoint(6, 0, 0);
  r = createRegister(r5, p);
  insertRegister(sor, r);

  p = createPoint(7, 0, 0);
  r = createRegister(r6, p);
  insertRegister(sor, r);

  p = createPoint(8, 0, 0);
  r = createRegister(r7, p);
  insertRegister(sor, r);

  p = createPoint(9, 0, 0);
  r = createRegister(r8, p);
  insertRegister(sor, r);

  p = createPoint(10, 0, 0);
  r = createRegister(r9, p);
  insertRegister(sor, r);

  p = createPoint(11, 0, 0);
  r = createRegister(r10, p);
  insertRegister(sor, r);

  return sor;
}

Cidade criaCidade(char *name) {
  City *city = NULL;
  city = (City *)malloc(sizeof(City));
  city->nome = name;
  city->listaQ = createQuadTree();
  city->listaS = createQuadTree();
  city->listaT = createQuadTree();
  city->listaH = createQuadTree();
  city->listCrossRoad = createQuadTree();
  city->listaPessoas = createL();
  city->listaMoradores = createL();
  city->listaEstabComerciais = createL();
  city->dicionario = configuraDicionario();
  city->registradores = configurarRegistradores();
  city->grafo = NULL;
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
  removeH(hidrante);
  return qtd;
}

void insertPessoas(Cidade cidade, Pessoa pessoa){
  City *city = (City *)cidade;
  insertEndL(city->listaPessoas, pessoa);
}

void insertMorador(Cidade cidade, Morador morador){
  City *city = (City *)cidade;
  insertEndL(city->listaMoradores, morador);
}

void insertEstabC(Cidade cidade, EstabC estabC){
  City *city = (City *)cidade;
  insertEndL(city->listaEstabComerciais, estabC);
}

void removePessoasCidade(Cidade cidade, char *cpf){
  City *city = (City *)cidade;
  Pessoa pessoa;
  pessoa = removeItemL2(city->listaPessoas, cpf, comparePessoas);
  if(pessoa != NULL){
    removePessoa(pessoa);
  }
}

void removeMoradorCidade(Cidade cidade, char *cpf){
  City *city = (City *)cidade;
  Morador morador;
  morador = removeItemL2(city->listaMoradores, cpf, compareMorador);
  if(morador != NULL){
    removeMorador(morador);
  }
}

void removeEstabCidade(Cidade cidade, char *cnpj){
  City *city = (City *)cidade;
  EstabC estabC;
  estabC = removeItemL2(city->listaEstabComerciais, cnpj, compareEstabC);
  if(estabC != NULL){
    removeEstabC(estabC);
  }
}

Dicionario getDicionario(Cidade cidade){
  City *city = (City *)cidade;
  return city->dicionario;
}

SetOfRegisters getRegistradores(Cidade cidade){
  City *city = (City *)cidade;
  return city->registradores;
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

QuadTree getListaCrossRoad(Cidade cidade) {
  City *city = (City *)cidade;
  return city->listCrossRoad;
}

List getListaMoradores(Cidade cidade){
  City *city = (City *)cidade;
  return city->listaMoradores;
}

List getListaPessoas(Cidade cidade){
  City *city = (City *)cidade;
  return city->listaPessoas;
}

List getListaEstabelecimentos(Cidade cidade){
  City *city = (City *)cidade;
  return city->listaEstabComerciais;
}

Graph getGrafo(Cidade cidade){
  City *city = (City *)cidade;
  return city->grafo;
}

void setGrafo(Cidade cidade, char *id, int n){
  City *city = (City *)cidade;
  city->grafo  = createGraph(id, n);
}

void showQ(Quadra quadra) {
  double x, y, w, h;
  char *corP, *corB;
  char cor[] = "red";
  char cor2[] = "black";
  char text[] = "Q";
  x = getXQ(quadra);
  y = getYQ(quadra);
  w = getLargQ(quadra);
  h = getAltQ(quadra);
  corP = getCorpQ(quadra);
  corB = getCorbQ(quadra);
  tagRetangulo2(newArqCity, w, h, x, y, corP, corB);
  tagTexto2(newArqCity, text, cor, 5, x, y);
  tagTexto2(newArqCity, getCepQ(quadra), cor2, 12, x+10, y+20);
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

void calculaCoordenadaM(Quadra quadra, int num, char face, double *x,
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

void showMoradores(Cidade cidade, FILE *file){
  City *city = (City *)cidade;
  int i, j;
  char *cep, cor[] = "green", cor2[] = "red", m[] = "M";
  Endereco endereco;
  Morador morador;
  Quadra quadra;
  double x = 0, y = 0;
  j = lengthL(city->listaMoradores);
  for(i=1; i<=j; i++){
    morador = getItemL(city->listaMoradores, i);
    if(morador != NULL){
      endereco = getEndereco(morador);
      cep = getCep(endereco);
      quadra = getQuadra(cidade, cep);
      if(quadra != NULL){
        calculaCoordenadaM(quadra, getNum(endereco), getFace(endereco), &x, &y);
        tagCirculo(file, 3, x, y, cor);
        tagTexto2(file, m, cor2, 5, x, y);
      }
    }
  }

}

void showEstabelecimentos(Cidade cidade, FILE *file){
  City *city = (City *)cidade;
  int i, j;
  char *cep, cor[] = "yellow", cor2[] = "red", e[] = "E", face;
  Endereco endereco;
  EstabC estabC;
  Quadra quadra;

  double x = 0, y = 0;
  j = lengthL(city->listaEstabComerciais);
  for(i=1; i<=j; i++){
    estabC = getItemL(city->listaEstabComerciais, i);
    if(estabC != NULL){
      endereco = getEnderecoEstabC(estabC);
      cep = getCep(endereco);
      quadra = getQuadra(cidade, cep);
      if(quadra != NULL){
        face = getFace(endereco);
        calculaCoordenadaM(quadra, getNum(endereco), face, &x, &y);
        if(face == 'N'){
          tagRetangulo(file, 5, 5, x, y-5, cor);
          tagTexto2(file, e, cor2, 5, x, y-5);
        } else if(face == 'O'){
          tagRetangulo(file, 5, 5, x-5, y, cor);
          tagTexto2(file, e, cor2, 5, x-5, y);
        } else {
          tagRetangulo(file, 5, 5, x, y, cor);
          tagTexto2(file, e, cor2, 5, x, y);
        }
      }
    }
  }

}


void showCrossRoad(CrossRoad crossRoad, FILE *file){
  char cor[] = "red";
  tagCirculo(file, 3, getXCrossRoad(crossRoad), getYCrossRoad(crossRoad), cor);
}


void showStreet(CrossRoad crossRoad1, CrossRoad crossRoad2, FILE *file){
  char cor[] = "black";
  arrow(file, getXCrossRoad(crossRoad1), getYCrossRoad(crossRoad1), getXCrossRoad(crossRoad2), getYCrossRoad(crossRoad2), cor);
}


void showVia(Cidade cidade, FILE *file){
  City *city = (City *)cidade;
  char cor[] = "black";
  if(city->grafo != NULL){
    defArrow(file, cor);
    showGraph(city->grafo, file, showCrossRoad, showStreet);
  }
}


void getEstabCCloser(Cidade cidade, double x, double y, double *xr, double *yr, char *tp){
  City *city = (City *)cidade;
  int i, j;
  char *tipo, secao3[] = "codtXestabC";
  double dist = 0, lessDist = 0;
  Endereco endereco;
  EstabC estabC = NULL;
  List list;
  HashTable hash;
  hash = getSecaoDicionario(city->dicionario, secao3);
  list = getHtList(hash, tp);
  j = lengthL(list);
  for(i=1; i<=j; i++){
    estabC = getItemL(list, i);
    if(estabC != NULL){
      tipo = getCodt(estabC);
      if(strcmp(tipo, tp) == 0){
        endereco = getEnderecoEstabC(estabC);
        dist = distanciaEntrePontos(x, y, getXEndereco(endereco), getYEndereco(endereco));
        if(i == 1){
          lessDist = dist;
        } else {
          if(lessDist < dist){
            lessDist = dist;
            *xr = getXEndereco(endereco);
            *yr = getYEndereco(endereco);
          }
        }
    }
    }
  }
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

void eraseListaCrossRoad(Cidade cidade) {

  City *city = (City *)cidade;
  if(city->listCrossRoad != NULL){
    eraseQuadTreeNode(city->listCrossRoad, NULL);
    eraseQuadTreeBase(city->listCrossRoad);
  }

  city->listaH = NULL;
}

void eraseGraf(Cidade cidade){

  City *city = (City *)cidade;
  if(city->grafo != NULL){
    eraseAllEdge(city->grafo, removeStreet);
    eraseAllVertex(city->grafo, removeCrossRoad);
    eraseGraph(city->grafo);
  }
}

void eraseHashTables(Cidade cidade){
  City *city = (City *)cidade;
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

  hash = getSecaoDicionario(city->dicionario, secao1);
  eraseHT(hash, desalocarString);

  hash = getSecaoDicionario(city->dicionario, secao2);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao3);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao4);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao5);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao6);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao7);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao8);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao9);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao10);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao11);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao12);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao13);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao14);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao15);
  eraseHT(hash, NULL);

  hash = getSecaoDicionario(city->dicionario, secao16);
  eraseHT(hash, NULL);
}

void eraseListaPessoas(Cidade cidade) {
  City *city = (City *)cidade;
  eraseListL(city->listaPessoas, removePessoa);
  eraseBase(city->listaPessoas);
}

void eraseListaMoradores(Cidade cidade) {
  City *city = (City *)cidade;
  eraseListL(city->listaMoradores, removeMorador);
  eraseBase(city->listaMoradores);
}

void eraseListaEstabC(Cidade cidade) {
  City *city = (City *)cidade;
  eraseListL(city->listaEstabComerciais, removeEstabC);
  eraseBase(city->listaEstabComerciais);
}

void eraseRegistradores(Cidade cidade) {
  City *city = (City *)cidade;
  if(city->registradores != NULL){
    removeSetOfRegisters(city->registradores, removePoint);
  }
}

void eraseCidade(Cidade cidade) {
  City *city = (City *)cidade;
  eraseListaQ(cidade);
  eraseListaS(cidade);
  eraseListaT(cidade);
  eraseListaH(cidade);
  eraseHashTables(cidade);
  eraseListaPessoas(cidade);
  eraseListaMoradores(cidade);
  eraseListaEstabC(cidade);
  removeDicionario(city->dicionario);
  eraseRegistradores(cidade);
  eraseListaCrossRoad(cidade);
  eraseGraf(cidade);
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
