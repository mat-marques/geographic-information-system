#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cidade.h"
#include "Hidrante.h"
#include "Semafaro.h"
#include "Torre.h"
#include "QuadTree.h"
#include "DoubleLinkedList.h"
#include "Stack.h"
#include "ConvexHull.h"
#include "Svg.h"


typedef struct City{
   QuadTree listaQ, listaS, listaT, listaH;
   char *nome;
}City;

void ConvexHullAuxC(Stack stack, Cidade cidade, int type);

Cidade criaCidade(char *name){
      City *city = NULL;
      city = (City*) malloc(sizeof(City));
      city->nome = name;
      city->listaQ = createQuadTree();
      city->listaS = createQuadTree();
      city->listaT = createQuadTree();
      city->listaH = createQuadTree();
      return city;
}

void insertQuadra(Cidade cidade, ElementoUrbano item){
     City *city = (City*) cidade;
     insertQuadTree(city->listaQ, item, getXQ(item), getYQ(item));
}

void removeQuadra(Cidade cidade, char *cep){
    City *city = (City*) cidade;
    Quadra quadra;
    Stack stack = NULL;
    List list = createDLL();
    quadra = removeQuadTreeItem(city->listaQ, cep, compareQ, list);
    removeQ(quadra);
    stack = convexHullOfAll(list, 1);
    ConvexHullAuxC(stack, cidade, 2);
    eraseStack(stack, NULL);
    eraseBaseStack(stack);
}

void insertSemafaro(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
  insertQuadTree(city->listaS, item, getXS(item), getYS(item));
}

void removeSemafaro(Cidade cidade, char *id){
   City *city = (City*) cidade;
   Semafaro semafaro;
   Stack stack = NULL;
   List list = createDLL();
   semafaro = removeQuadTreeItem(city->listaS, id, compareS, list);
   removeS(semafaro);
   stack = convexHullOfAll(list, 3);
   ConvexHullAuxC(stack, cidade, 3);
   eraseStack(stack, NULL);
   eraseBaseStack(stack);
}

void insertTorre(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
  insertQuadTree(city->listaT, item, getXT(item), getYT(item));
}

void removeTorre(Cidade cidade, char *id){
   City *city = (City*) cidade;
   Torre torre;
   Stack stack = NULL;
   List list = createDLL();
   torre = removeQuadTreeItem(city->listaT, id, compareT, list);
   removeT(torre);
   stack = convexHullOfAll(list, 4);
   ConvexHullAuxC(stack, cidade, 4);
   eraseStack(stack, NULL);
   eraseBaseStack(stack);
}

void insertHidrante(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
  insertQuadTree(city->listaH, item, getXH(item), getYH(item));
}

void removeHidrante(Cidade cidade, char *id){
   City *city = (City*) cidade;
   Hidrante hidrante;
   Stack stack = NULL;
   List list = createDLL();
   hidrante = removeQuadTreeItem(city->listaH, id, compareH, list);
   removeQ(hidrante);
   stack = convexHullOfAll(list, 2);
   ConvexHullAuxC(stack, cidade, 2);
   eraseStack(stack, NULL);
   eraseBaseStack(stack);
}

char *getNome(Cidade cidade){
   City *city = (City*) cidade;
   return city->nome;
}

void setNome(Cidade cidade, char *nome){
      City *city = (City*) cidade;
      free(city->nome);
      city->nome = nome;
}

QuadTree getListaQ(Cidade cidade){
   City *city = (City*) cidade;
   return city->listaQ;
}

QuadTree getListaS(Cidade cidade){
   City *city = (City*) cidade;
   return city->listaS;
}

QuadTree getListaT(Cidade cidade){
   City *city = (City*) cidade;
   return city->listaT;
}

QuadTree getListaH(Cidade cidade){
   City *city = (City*) cidade;
   return city->listaH;
}

Quadra getQuadra(Cidade cidade, char *cep){
   Quadra quadra = NULL;
   City *city = (City*) cidade;
   quadra = searchQuadTreeItem(city->listaQ, cep, compareQ);
   return quadra;
}

void showQ(Quadra quadra){
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

void showH(Hidrante hidrante){
  double x, y;
  char *corP, *corB;
  char cor[] = "red";
  char text[] = "H";
  x = getXH(hidrante);
  y = getYH(hidrante);
  corP = getCorpH(hidrante);
  corB = getCorbH(hidrante);
  tagCirculo2(newArqCity, 5, x, y, corP, corB);
  tagTexto2(newArqCity, text, cor, 5, x-1.5, y+1.5);
}

void showS(Semafaro semafaro){
  double x, y;
  char *corP, *corB;
  char cor[] = "red";
  char text[] = "S";
  x = getXS(semafaro);
  y = getYS(semafaro);
  corP = getCorpS(semafaro);
  corB = getCorbS(semafaro);
  tagCirculo2(newArqCity, 5, x, y, corP, corB);
  tagTexto2(newArqCity, text, cor, 5, x-1.5, y+1.5);
}

void showT(Torre torre){
  double x, y, r;
  char *corP, *corB;
  char cor[] = "red";
  char text[] = "T";
  x = getXT(torre);
  y = getYT(torre);
  corP = getCorpT(torre);
  corB = getCorbT(torre);
  r = getRaio(torre);
  if(r > 0){
    tagCirculoOpacity(newArqCity, r, x, y, cor);
  }
  tagCirculo2(newArqCity, 5, x, y, corP, corB);
  tagTexto2(newArqCity, text, cor, 5, x-1.5, y+1.5);
}


ElementoUrbano getTorre(Cidade cidade, char *id){
  Torre torre = NULL;
  City *city = (City*) cidade;
  torre = searchQuadTreeItem(city->listaT, id, compareT);
  return torre;
}

ElementoUrbano getSemafaro(Cidade cidade, char *id){
   Semafaro semafaro = NULL;
   City *city = (City*) cidade;
   semafaro = searchQuadTreeItem(city->listaS, id, compareS);
   return semafaro;
}

ElementoUrbano getHidrante(Cidade cidade, char *id){
   Hidrante hidrante = NULL;
   City *city = (City*) cidade;
   hidrante = searchQuadTreeItem(city->listaH, id, compareH);
   return hidrante;
}

void eraseListaQ(Cidade cidade){

  City *city = (City*) cidade;

  eraseQuadTreeNode(city->listaQ, removeQ);
  eraseQuadTreeBase(city->listaQ);

  city->listaQ = NULL;
}

void eraseListaS(Cidade cidade){

  City *city = (City*) cidade;

  eraseQuadTreeNode(city->listaS, removeS);
  eraseQuadTreeBase(city->listaS);

  city->listaS = NULL;
}

void eraseListaT(Cidade cidade){

  City *city = (City*) cidade;

  eraseQuadTreeNode(city->listaT, removeT);
  eraseQuadTreeBase(city->listaT);

  city->listaT = NULL;
}

void eraseListaH(Cidade cidade){

  City *city = (City*) cidade;

  eraseQuadTreeNode(city->listaH, removeH);
  eraseQuadTreeBase(city->listaH);

  city->listaH = NULL;
}

void eraseCidade(Cidade cidade){
  City *city = (City*) cidade;
  eraseListaQ(cidade);
  eraseListaS(cidade);
  eraseListaT(cidade);
  eraseListaH(cidade);
  if(city->nome!=NULL){
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
