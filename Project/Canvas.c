#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Canvas.h"
#include "QuadTree.h"
#include "Retangulo.h"
#include "Circulo.h"

typedef struct CanvasP
{
    QuadTree listaC, listaR, listaR2;
    List listaCores;
    Cidade cidade;
    double width, height;
    int id;
} CanvasP;

Canvas criaCanvas(int id)
{
    char *nome;
    CanvasP *canvas;
    canvas = (CanvasP *)malloc(sizeof(CanvasP));
    canvas->listaC = createQuadTree();
    canvas->listaR = createQuadTree();
    canvas->listaR2 = createQuadTree();
    canvas->listaCores = createDLL();
    canvas->width = 100;
    canvas->height = 100;
    canvas->id = id;
    nome = (char *)malloc(6 * sizeof(char));
    strcpy(nome, "none");
    canvas->cidade = criaCidade(nome);
    return canvas;
}

void insertRetangulo(Canvas canvas, Retangulo retangulo)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    insertQuadTree(canvasP->listaR, retangulo, getRx(retangulo), getRy(retangulo));
}

void removeRetangulo(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
}

void insertRetangulo2(Canvas canvas, Retangulo retangulo)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    insertQuadTree(canvasP->listaR2, retangulo, getRx(retangulo), getRy(retangulo));
}

void removeRetangulo2(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
}

void insertCirculo(Canvas canvas, Circulo circulo)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    insertQuadTree(canvasP->listaC, circulo, getCx(circulo), getCy(circulo));
}

void removeCirculo(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
}

void insertCor(Canvas canvas, Cor cor)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    insertBeginDLL(canvasP->listaCores, cor);
}

void removeCor(Canvas canvas, int id)
{
    Item item;
    CanvasP *canvasP = (CanvasP *)canvas;
    item = removeItemDLL(canvasP->listaCores, &id, compareCores);
    free(item);
}

double getWidth(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return canvasP->width;
}

void setWidth(Canvas canvas, double width)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    canvasP->width = width;
}

double getHeight(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return canvasP->height;
}

void setHeight(Canvas canvas, double height)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    canvasP->height = height;
}

Cidade getCidade(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return canvasP->cidade;
}

void setCidade(Canvas canvas, Cidade cidade)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    if (canvasP->cidade != NULL)
    {
        eraseCidade(canvasP->cidade);
        canvasP->cidade = NULL;
    }
    canvasP->cidade = cidade;
}

int getIdCanvas(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return canvasP->id;
}

QuadTree getListaR(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return canvasP->listaR;
}

QuadTree getListaR2(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return canvasP->listaR2;
}

QuadTree getListaC(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return canvasP->listaC;
}

List getListaCores(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return canvasP->listaCores;
}





/*****/
List getElementsListInsideR (Canvas canvas, double x, double y, double w, double h, int typeElement) {

}


List getElementsListInsideC(Canvas canvas, double x, double y, double r, int typeElement) {

}

/*****/














figuraGeometrica getRetangulo(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return searchQuadTreeItem(canvasP->listaR, &id, compareC);
}

figuraGeometrica getCirculo(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return searchQuadTreeItem(canvasP->listaR, &id, compareR);
}

Cor getCor(Canvas canvas, int id)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    return searchItemDLL(canvasP->listaCores, &id, compareCores);
}

void eraseListaR(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    eraseQuadTree(canvasP->listaR, removeRetangulo);
}

void eraseListaC(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    eraseQuadTree(canvasP->listaC, removeCirculo);
}

void eraseListaR2(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    eraseQuadTree(canvasP->listaR2, removeRetangulo);
}

void eraseListaCores(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    eraseListDLLOne(canvasP->listaCores, removeCor);
}

void setarCores(Canvas canvas)
{
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

void eraseCanvas(Canvas canvas)
{
    CanvasP *canvasP = (CanvasP *)canvas;
    eraseListaR(canvas);
    eraseListaR2(canvas);
    eraseListaCores(canvas);
    eraseListaC(canvas);
    eraseCidade(canvasP->cidade);
    free(canvas);
}
