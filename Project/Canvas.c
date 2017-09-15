#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Canvas.h"

typedef struct CanvasP{
    Lista listaC, listaR, listaR2;
    Lista listaCores;
    Cidade cidade;
    double width, height;
    int id;
}CanvasP;

Canvas criaCanvas(int id){
  char *nome;
  CanvasP *canvas;
  canvas = (CanvasP*) malloc(sizeof(CanvasP));
  canvas->listaC = createLista();
  canvas->listaR = createLista();
  canvas->listaR2 = createLista();
  canvas->listaCores = createLista();
  canvas->width = 100;
  canvas->height = 100;
  canvas->id = id;
  nome = (char*) malloc(6*sizeof(char));
  strcpy(nome, "none");
  canvas->cidade = criaCidade(nome);
  return canvas;
}

void insertRetangulo(Canvas canvas, Retangulo retangulo){
      CanvasP *canvasP = (CanvasP*) canvas;
      insert(canvasP->listaR, retangulo);
}

void removeRetangulo(Canvas canvas, Posic p){
     CanvasP *canvasP = (CanvasP*) canvas;
     removeItem(canvasP->listaR, p);
}

void insertRetangulo2(Canvas canvas, Retangulo retangulo){
      CanvasP *canvasP = (CanvasP*) canvas;
      insert(canvasP->listaR2, retangulo);
}

void removeRetangulo2(Canvas canvas, Posic p){
     CanvasP *canvasP = (CanvasP*) canvas;
     removeItem(canvasP->listaR2, p);
}

void insertCirculo(Canvas canvas, Circulo circulo){
    CanvasP *canvasP = (CanvasP*) canvas;
    insert(canvasP->listaC, circulo);

}

void removeCirculo(Canvas canvas, Posic p){
     CanvasP *canvasP = (CanvasP*) canvas;
     removeItem(canvasP->listaC, p);
}

void insertCor(Canvas canvas, Cor cor){
    CanvasP *canvasP = (CanvasP*) canvas;
    insert(canvasP->listaCores, cor);

}

void removeCor(Canvas canvas, Posic p){
     CanvasP *canvasP = (CanvasP*) canvas;
     removeItem(canvasP->listaCores, p);
}

double getWidth(Canvas canvas){
    CanvasP *canvasP = (CanvasP*) canvas;
    return canvasP->width;
}

void setWidth(Canvas canvas, double width){
    CanvasP *canvasP = (CanvasP*) canvas;
    canvasP->width = width;
}


double getHeight(Canvas canvas){
    CanvasP *canvasP = (CanvasP*) canvas;
    return canvasP->height;
}

void setHeight(Canvas canvas, double height){
    CanvasP *canvasP = (CanvasP*) canvas;
    canvasP->height = height;
}

Cidade getCidade(Canvas canvas){
  CanvasP *canvasP = (CanvasP*) canvas;
  return canvasP->cidade;
}

void setCidade(Canvas canvas, Cidade cidade){
  CanvasP *canvasP = (CanvasP*) canvas;
  if(canvasP->cidade!=NULL){
    eraseCidade(canvasP->cidade);
    canvasP->cidade = NULL;
  }
  canvasP->cidade = cidade;
}

int getIdC(Canvas canvas){
    CanvasP *canvasP = (CanvasP*) canvas;
    return canvasP->id;
}

Lista getListaR(Canvas canvas){
    CanvasP *canvasP = (CanvasP*) canvas;
    return canvasP->listaR;
}

Lista getListaR2(Canvas canvas){
    CanvasP *canvasP = (CanvasP*) canvas;
    return canvasP->listaR2;
}

Lista getListaC(Canvas canvas){
    CanvasP *canvasP = (CanvasP*) canvas;
    return canvasP->listaC;
}

Lista getListaCores(Canvas canvas){
    CanvasP *canvasP = (CanvasP*) canvas;
    return canvasP->listaCores;
}

figuraGeometrica getRetangulo(Canvas canvas, int id){
   void* figuraG=NULL;
   figuraGeometrica figuraG2 = NULL;
   CanvasP *canvasP = (CanvasP*) canvas;
   int sizelist, i;
   sizelist = lenght(canvasP->listaR);
   figuraG = getFirst(canvasP->listaR);
   for(i=0; i<sizelist; i++){
       figuraG2 = get(canvasP->listaR, figuraG);
       if(getRi(figuraG2)==id){
            return figuraG2;
       }
       figuraG = getNext(canvasP->listaR, figuraG);
   }
   return NULL;
}

figuraGeometrica getRetangulo2(Canvas canvas, double x, double y, double w, double h){
   void* figuraG=NULL;
   figuraGeometrica figuraG2 = NULL;
   CanvasP *canvasP = (CanvasP*) canvas;
   int sizelist, i;
   sizelist = lenght(canvasP->listaR);
   figuraG = getFirst(canvasP->listaR);
   for(i=0; i<sizelist; i++){
       figuraG2 = get(canvasP->listaR, figuraG);
       if(getRx(figuraG2)==x && getRy(figuraG2)==y && getRw(figuraG2)==w && getRh(figuraG2)==h){
            return figuraG2;
       }
       figuraG = getNext(canvasP->listaR, figuraG);
   }
   return NULL;
}

figuraGeometrica getCirculo(Canvas canvas, int id){
   void* figuraG=NULL;
   figuraGeometrica figuraG2 = NULL;
   CanvasP *canvasP = (CanvasP*) canvas;
   int sizelist, i;
   sizelist = lenght(canvasP->listaC);
   figuraG = getFirst(canvasP->listaC);
   for(i=0; i<sizelist; i++){
       figuraG2 = get(canvasP->listaC, figuraG);
       if(getCi(figuraG2)==id){
            return figuraG2;
       }
       figuraG = getNext(canvasP->listaC, figuraG);
   }
   return NULL;
}

figuraGeometrica getCirculo2(Canvas canvas, double x, double y, double r){
   void* figuraG=NULL;
   figuraGeometrica figuraG2 = NULL;
   CanvasP *canvasP = (CanvasP*) canvas;
   int sizelist, i;
   sizelist = lenght(canvasP->listaC);
   figuraG = getFirst(canvasP->listaC);
   for(i=0; i<sizelist; i++){
       figuraG2 = get(canvasP->listaC, figuraG);
       if(getCx(figuraG2)==x && getCy(figuraG2)==y && getCy(figuraG2)==y && getCr(figuraG2)==r){
            return figuraG2;
       }
       figuraG = getNext(canvasP->listaC, figuraG);
   }
   return NULL;
}

Cor getCor(Canvas canvas, int id){
   void* corA=NULL;
   Cor corB = NULL;
   CanvasP *canvasP = (CanvasP*) canvas;
   int sizelist, i;
   sizelist = lenght(canvasP->listaCores);
   corA = getFirst(canvasP->listaCores);
   for(i=0; i<sizelist; i++){
       corB = get(canvasP->listaCores, corA);
       if(getCorId(corB)==id){
            return corB;
       }
       corA = getNext(canvasP->listaCores, corA);
   }
   return NULL;
}

void eraseListaR(Canvas canvas){
  Posic p1, p2;
  int n, i;
  CanvasP *canvasP = (CanvasP*) canvas;

  Lista lista;
  lista = canvasP->listaR;
  n = lenght(lista);
  p1 = getFirst(lista);
  for(i=0; i<n; i++){
    p2 = get(lista, p1);
    if(p2!=NULL){
      free(p2);
    }
    p2 = getNext(lista, p1);
    free(p1);
    p1 = p2;
  }
  free(lista);
  canvasP->listaR = NULL;
}

void eraseListaC(Canvas canvas){
  Posic p1, p2;
  int n, i;
  CanvasP *canvasP = (CanvasP*) canvas;

  Lista lista;
  lista = canvasP->listaC;
  n = lenght(lista);
  p1 = getFirst(lista);
  for(i=0; i<n; i++){
    p2 = get(lista, p1);
    if(p2!=NULL){
      free(p2);
    }
    p2 = getNext(lista, p1);
    free(p1);
    p1 = p2;
  }
  free(lista);
  canvasP->listaC = NULL;
}

void eraseListaR2(Canvas canvas){
  Posic p1, p2;
  int n, i;
  CanvasP *canvasP = (CanvasP*) canvas;

  Lista lista;
  lista = canvasP->listaR2;
  n = lenght(lista);
  p1 = getFirst(lista);
  for(i=0; i<n; i++){
    p2 = get(lista, p1);
    if(p2!=NULL){
      free(p2);
    }
    p2 = getNext(lista, p1);
    free(p1);
    p1 = p2;
  }
  free(lista);
  canvasP->listaR2 = NULL;
}

void eraseListaCores(Canvas canvas){
  Posic p1, p2;
  int n, i;
  CanvasP *canvasP = (CanvasP*) canvas;

  Lista lista;
  lista = canvasP->listaCores;
  n = lenght(lista);
  p1 = getFirst(lista);
  for(i=0; i<n; i++){
    p2 = get(lista, p1);
    if(p2!=NULL){
      resetarCores(p2);
      free(p2);
    }
    p2 = getNext(lista, p1);
    free(p1);
    p1 = p2;
  }
  free(lista);
  canvasP->listaCores = NULL;
}

void setarCores(Canvas canvas){
    Cor cor = NULL;
    char corContorno[] = "black";
    char corA[] = "blue";
    char corB[] = "red";
    char corC[] = "yellow";
    char corD[] = "orange";
    cor = criaCor(corA, corContorno, 1);
    insertCor(canvas, cor);
    cor = criaCor(corB, corContorno, 2);
    insertCor(canvas, cor);
    cor = criaCor(corC, corContorno, 3);
    insertCor(canvas, cor);
    cor = criaCor(corD, corContorno, 4);
    insertCor(canvas, cor);
}

void eraseCanvas(Canvas canvas){
  CanvasP *canvasP = (CanvasP*) canvas;
  eraseListaR(canvas);
  eraseListaR2(canvas);
  eraseListaCores(canvas);
  eraseListaC(canvas);
  eraseCidade(canvasP->cidade);
  free(canvas);
}
