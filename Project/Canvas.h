#ifndef CANVAS_H
#define CANVAS_H

#include "Circulo.h"
#include "Retangulo.h"
#include "DoubleLinkedList.h"
#include "Cidade.h"
#include "Cor.h"

typedef void* Canvas;
typedef void* figuraGeometrica;

/***
Autor: Matheus Augusto Marques.
Tad: Canvas
Definição:
Um canvas é um plano bidimensional composto por um comprimento e uma altura e que aloja dentro de si componentes específicos. Os componentes que podem compor um canvas são retângulos, círculos , uma lista de cores e uma cidade.
*/


/*
Cria um canvas vazio e com comprimento e altura iguais a 100.
*/
Canvas criaCanvas(int id);

/*
Insere no canvas passado como parâmetro um retângulo.
*/
void insertRetangulo(Canvas canvas, Retangulo retangulo);

/*
Remove do canvas passado como parâmetro um retângulo com uma posição específica.
*/
void removeRetangulo(Canvas canvas, int id);

/*
Insere no canvas passado como parâmetro um retângulo com bordas tracejadas e sem cor de preenchimento.
*/
void insertRetangulo2(Canvas canvas, Retangulo retangulo);

/*
Remove do canvas passado como parâmetro um retângulo com bordas tracejadas em uma posição indicada por p.
*/
void removeRetangulo2(Canvas canvas, int id);

/*
Insere no canvas passado como parâmetro um círculo.
*/
void insertCirculo(Canvas canvas, Circulo circulo);

/*
Remove do canvas passado como parâmetro um círculo em uma posição indicada por p.
*/
void removeCirculo(Canvas canvas, int id);

/*
Insere no canvas passado como parâmetro uma cor.
*/
void insertCor(Canvas canvas, Cor cor);

List getElementsListInsideR(Canvas canvas, int type, double x, double y, double w, double h);

List getElementsListInsideC(Canvas canvas, int type, double x, double y, double r);

/*
Remove do canvas passado como parâmetro uma cor em uma posição indicada por p.
*/
void removeCor(Canvas canvas, int id);

void showCanvasR(Canvas canvas, FILE *file);

void showCanvasC(Canvas canvas, FILE *file);

/*
Retorna o comprimento do canvas passado como parâmetro.
*/
double getWidth(Canvas canvas);

/*
Substitui o comprimento atual de um canvas pelo número real width.
*/
void setWidth(Canvas canvas, double width);

/*
Retorna a altura de um canvas.
*/
double getHeight(Canvas canvas);

/*
Substitui a altura atual de um canvas pelo número real heigth.
*/
void setHeight(Canvas canvas, double height);

/*
Retorna uma cidade presente em um canvas.
*/
Cidade getCidade(Canvas canvas);

/*
Substitui uma cidade presente em um canvas pela cidade passada por parâmetro.
*/
void setCidade(Canvas canvas, Cidade cidade);

/*
Retorna o número de identificação de um canvas.
*/
int getIdCanvas(Canvas canvas);

/*
Retorna um lista contendo todos os retângulos genéricos presentes em um canvas.
Retorna null caso não exista nenhum retângulo genérico no canvas.
*/
QuadTree getListaR(Canvas canvas);

/*
Retorna um lista contendo todos os retângulos com bordas tracejadas presentes em um canvas.
Retorna null caso não exista nenhum retângulo com bordas tracejadas no canvas.
*/
List getListaR2(Canvas canvas);

/*
Retorna um lista contendo todos os círculos presentes em um canvas.
Retorna null caso não exista nenhum círculo no canvas.
*/
QuadTree getListaC(Canvas canvas);

/*
Retorna um lista contendo todos as cores presentes em um canvas.
Retorna null caso não exista cores no canvas.
*/
List getListaCores(Canvas canvas);

/*
Retorna um retângulo (Figura geométrica) com  número de identificação definido pelo parâmetro id. O retângulo retornado está dentro de um canvas.
Caso o retângulo não for encontrado é retornado null.
*/
figuraGeometrica getRetangulo(Canvas canvas, int id);

/*
Retorna um retângulo (Figura geométrica) com as caracteristicas definidas pelos parâmetros x (Coordenada x), y (Coordenada y), w (Comprimento) e h (Altura). O retângulo retornado está dentro de um canvas.
Caso o retângulo não for encontrado é retornado null.
*/
figuraGeometrica getRetangulo2(Canvas canvas, double x, double y, double w, double h);

/*
Retorna um círculo (Figura geométrica) com o número de identificação definido pelo parâmetro id. O círculo retornado está dentro de um canvas.
Caso o círculo não for encontrado é retornado null.
*/
figuraGeometrica getCirculo(Canvas canvas, int id);

/*
Retorna um círculo (Figura geométrica) com as características definidas pelos parâmetros x (Coordenada x), y (Coordenada y) e r (Raio) . O círculo retornado está dentro de um canvas.
Caso o círculo não for encontrado é retornado null.
*/
figuraGeometrica getCirculo2(Canvas canvas, double x, double y, double r);

/*
Retorna uma cor especificada por um número de identificação chamado id presente no canvas passado como parâmetro.
*/
Cor getCor(Canvas canvas, int id);

/*
Apaga todos os retângulos genéricos presentes em um canvas.
*/
void eraseListaR(Canvas canvas);

/*
Apaga todos os círculos presentes em um canvas.
*/
void eraseListaC(Canvas canvas);

/*
Apaga todos os retângulos com bordas tracejadas presentes em um canvas.
*/
void eraseListaR2(Canvas canvas);

/*
Apaga todas as cores presentes em um canvas.
*/
void eraseListaCores(Canvas canvas);

/*
Inicia o canvas com algumas cores padrões.
*/
void setarCores(Canvas canvas);

/*
Apaga o canvas e todos os seus componentes.
*/
void eraseCanvas(Canvas canvas);

#endif
