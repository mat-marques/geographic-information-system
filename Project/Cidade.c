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

}

void insertSemafaro(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
        insertQuadTree(city->listaQ, item, getXS(item), getYS(item));
}

void removeSemafaro(Cidade cidade, char *id){
   City *city = (City*) cidade;

}

void insertTorre(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
    insertQuadTree(city->listaQ, item, getXT(item), getYT(item));
}

void removeTorre(Cidade cidade, char *id){
   City *city = (City*) cidade;

}

void insertHidrante(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
   insert(city->listaH, item);
}

void removeHidrante(Cidade cidade, char *id){
   City *city = (City*) cidade;

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
   void* elemento=NULL;
   Quadra quadra = NULL;
   City *city = (City*) cidade;

   return NULL;
}

ElementoUrbano getTorre(Cidade cidade, char *id){
  void* elemento=NULL;
  Torre torre = NULL;
  City *city = (City*) cidade;

  return NULL;
}

ElementoUrbano getSemafaro(Cidade cidade, char *id){
   void* elemento=NULL;
   Semafaro semafaro = NULL;
   City *city = (City*) cidade;

   return NULL;
}

ElementoUrbano getHidrante(Cidade cidade, char *id){
   void* elemento=NULL;
   Hidrante hidrante = NULL;
   City *city = (City*) cidade;

   return NULL;
}

void eraseListaQ(Cidade cidade){

  City *city = (City*) cidade;

  //eraseQuadTree(city->listaQ, );

  city->listaQ = NULL;
}

void eraseListaS(Cidade cidade){

  City *city = (City*) cidade;

  //eraseQuadTree(city->listaS, );

  city->listaS = NULL;
}

void eraseListaT(Cidade cidade){

  City *city = (City*) cidade;

  //eraseQuadTree(city->listaT, );

  city->listaT = NULL;
}

void eraseListaH(Cidade cidade){

  City *city = (City*) cidade;

  //eraseQuadTree(city->listaH, );

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
