#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cidade.h"
#include "Hidrante.h"
#include "Semafaro.h"
#include "Torre.h"
#include "QuadTree.h"

typedef struct City{
   QuadTree listaQ, listaS, listaT, listaH;
   char *nome;
}City;

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
    quadra = removeQuadTreeItem(city->listaQ, cep, compareQ);
    removeQ(quadra);
}

void insertSemafaro(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
  insertQuadTree(city->listaS, item, getXS(item), getYS(item));
}

void removeSemafaro(Cidade cidade, char *id){
   City *city = (City*) cidade;
   Semafaro semafaro;
   semafaro = removeQuadTreeItem(city->listaS, id, compareS);
   removeS(semafaro);
}

void insertTorre(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
  insertQuadTree(city->listaT, item, getXT(item), getYT(item));
}

void removeTorre(Cidade cidade, char *id){
   City *city = (City*) cidade;
   Torre torre;
   torre = removeQuadTreeItem(city->listaT, id, compareT);
   removeT(torre);
}

void insertHidrante(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
  insertQuadTree(city->listaH, item, getXH(item), getYH(item));
}

void removeHidrante(Cidade cidade, char *id){
   City *city = (City*) cidade;
   Hidrante hidrante;
   hidrante = removeQuadTreeItem(city->listaH, id, compareH);
   removeH(hidrante);
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
