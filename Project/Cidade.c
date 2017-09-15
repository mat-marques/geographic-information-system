#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cidade.h"
#include "hidrante.h"
#include "semafaro.h"
#include "torre.h"


typedef struct City{
   Lista listaQ, listaS, listaT, listaH;
   char *nome;
}City;

Cidade criaCidade(char *name){
      City *city = NULL;
      city = (City*) malloc(sizeof(City));
      city->nome = name;
      city->listaQ = createLista();
      city->listaS = createLista();
      city->listaT = createLista();
      city->listaH = createLista();
      return city;
}

void insertQuadra(Cidade cidade, ElementoUrbano item){
     City *city = (City*) cidade;
     insert(city->listaQ, item);
}

void removeQuadra(Cidade cidade, Posic p){
    City *city = (City*) cidade;
    char *string0 = NULL;
    Item item = get(city->listaQ, p);
    if(item!=NULL){
      string0 = getCepQ(item);
      free(string0);
      free(item);
    }
    removeItem(city->listaQ, p);
}

void insertSemafaro(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
   insert(city->listaS, item);
}

void removeSemafaro(Cidade cidade, Posic p){
   City *city = (City*) cidade;
   char *string0 = NULL;
   Item item = get(city->listaS, p);
   if(item!=NULL){
     string0 = getIdS(item);
     free(string0);
     free(item);
   }
   removeItem(city->listaS, p);
}

void insertTorre(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
   insert(city->listaT, item);
}

void removeTorre(Cidade cidade, Posic p){
   City *city = (City*) cidade;
   char *string0 = NULL;
   Item item = get(city->listaT, p);
   if(item!=NULL){
     string0 = getIdT(item);
     free(string0);
     free(item);
   }
   removeItem(city->listaT, p);
}

void insertHidrante(Cidade cidade, ElementoUrbano item){
   City *city = (City*) cidade;
   insert(city->listaH, item);
}

void removeHidrante(Cidade cidade, Posic p){
   City *city = (City*) cidade;
   char *string0 = NULL;
   Item item = get(city->listaH, p);
   if(item!=NULL){
     string0 = getIdH(item);
     free(string0);
     free(item);
   }
   removeItem(city->listaH, p);
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

Lista getListaQ(Cidade cidade){
   City *city = (City*) cidade;
   return city->listaQ;
}

Lista getListaS(Cidade cidade){
   City *city = (City*) cidade;
   return city->listaS;
}

Lista getListaT(Cidade cidade){
   City *city = (City*) cidade;
   return city->listaT;
}

Lista getListaH(Cidade cidade){
   City *city = (City*) cidade;
   return city->listaH;
}

Quadra getQuadra(Cidade cidade, char *cep){
   void* elemento=NULL;
   Quadra quadra = NULL;
   City *city = (City*) cidade;
   int sizelist, i;
   char *cepOriginal;
   sizelist = lenght(city->listaQ);
   elemento = getFirst(city->listaQ);
   for(i=0; i<sizelist; i++){
       quadra = get(city->listaQ, elemento);
       cepOriginal = getCepQ(quadra);
       if(strcmp(cepOriginal, cep)==0){
            return quadra;
       }
       elemento = getNext(city->listaQ, elemento);
   }
   return NULL;
}

ElementoUrbano getTorre(Cidade cidade, char *id){
  void* elemento=NULL;
  Torre torre = NULL;
  City *city = (City*) cidade;
  int sizelist, i;
  char *idOriginal;
  sizelist = lenght(city->listaT);
  elemento = getFirst(city->listaT);
  for(i=0; i<sizelist; i++){
      torre = get(city->listaT, elemento);
      idOriginal = getIdT(torre);
      if(strcmp(idOriginal, id)==0){
           return torre;
      }
      elemento = getNext(city->listaT, elemento);
  }
  return NULL;
}

ElementoUrbano getSemafaro(Cidade cidade, char *id){
   void* elemento=NULL;
   Semafaro semafaro = NULL;
   City *city = (City*) cidade;
   int sizelist, i;
   char *idOriginal;
   sizelist = lenght(city->listaS);
   elemento = getFirst(city->listaS);
   for(i=0; i<sizelist; i++){
      semafaro = get(city->listaS, elemento);
      idOriginal = getIdS(semafaro);
       if(strcmp(idOriginal, id)==0){
            return semafaro;
       }
       elemento = getNext(city->listaS, elemento);
   }
   return NULL;
}

ElementoUrbano getHidrante(Cidade cidade, char *id){
   void* elemento=NULL;
   Hidrante hidrante = NULL;
   City *city = (City*) cidade;
   int sizelist, i;
   char *idOriginal;
   sizelist = lenght(city->listaH);
   elemento = getFirst(city->listaH);
   for(i=0; i<sizelist; i++){
       hidrante = get(city->listaH, elemento);
       idOriginal = getIdH(hidrante);
       if(strcmp(idOriginal, id)==0){
            return hidrante;
       }
       elemento = getNext(city->listaH, elemento);
   }
   return NULL;
}

void eraseListaQ(Cidade cidade){
  Posic p1, p2;
  int n, i;
  char *cep;
  City *city = (City*) cidade;

  Lista lista;
  lista = city->listaQ;
  n = lenght(lista);
  p1 = getFirst(lista);
  for(i=0; i<n; i++){
    p2 = get(lista, p1);
    if(p2!=NULL){
      cep = getCepQ(p2);
      if(cep!=NULL){
        free(cep);
        cep = NULL;
      }
      free(p2);
    }
    p2 = getNext(lista, p1);
    free(p1);
    p1 = p2;
  }
  free(lista);
  city->listaQ = NULL;
}

void eraseListaS(Cidade cidade){
  Posic p1, p2;
  int n, i;
  char *string=NULL;
  City *city = (City*) cidade;

  Lista lista;
  lista = city->listaS;
  n = lenght(lista);
  p1 = getFirst(lista);
  for(i=0; i<n; i++){
    p2 = get(lista, p1);
    if(p2!=NULL){
      string = getIdS(p2);
      free(string);
      free(p2);
    }
    p2 = getNext(lista, p1);
    free(p1);
    p1 = p2;
  }
  free(lista);
  city->listaS = NULL;
}

void eraseListaT(Cidade cidade){
  Posic p1, p2;
  int n, i;
  char *string=NULL;
  City *city = (City*) cidade;

  Lista lista;
  lista = city->listaT;
  n = lenght(lista);
  p1 = getFirst(lista);
  for(i=0; i<n; i++){
    p2 = get(lista, p1);
    if(p2!=NULL){
      string = getIdT(p2);
      free(string);
      free(p2);
    }
    p2 = getNext(lista, p1);
    free(p1);
    p1 = p2;
  }
  free(lista);
  city->listaT = NULL;
}

void eraseListaH(Cidade cidade){
  Posic p1, p2;
  int n, i;
  char *string=NULL;
  City *city = (City*) cidade;

  Lista lista;
  lista = city->listaH;
  n = lenght(lista);
  p1 = getFirst(lista);
  for(i=0; i<n; i++){
    p2 = get(lista, p1);
    if(p2!=NULL){
      string = getIdH(p2);
      free(string);
      free(p2);
    }
    p2 = getNext(lista, p1);
    free(p1);
    p1 = p2;
  }
  free(lista);
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
