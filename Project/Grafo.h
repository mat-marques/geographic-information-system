#ifndef GRAFO_H
#define GRAFO_H

#include "List.h"

typedef void* Graph;
typedef void* Info;
typedef void* Vertex;
typedef void* Edge;

/*
  Autor: Matheus Augusto Marques
  Tad Grafo:
  Um grafo direcionado G é constituı́do por um conjunto de vértices V e
  um conjunto de arestas E ⊆ V × V , denotado por G = (V , E ). Uma
  aresta e = (u, v ) ∈ E é ordenada, i.e., (u, v ) 6 = (v , u). Os nomes dos
  vértices são valores inteiros entre 0 e | V | − 1. Pode-se associar um dado
  (tipo Info) a cada aresta de G. (Obs. Por brevidade, estamos associando
  informações apenas às arestas. Este TAD pode ser facilmente modificado
  para permitir informações também (ou só para) vértices. Também por
  brevidade, o nome dos nós são números inteiros: exercı́cio modificar TAD
  para que nomes sejam strings).
*/

/*
  A função e retorna um grafo definido com um id.
*/
Graph createGraph(char *id);


/*
  Insere um vertíce no grafo.
  Info é a informação que será armazenada no vertíce.
*/
void insertVertex(Graph graph, char *id, Info info);

/*
  Insere uma aresta no grafo.
  Info é a informação que será armazenada na aresta.
*/
void insertEdge(Graph graph, char *idOrigin, char *idDestiny, Info info);


/*
  Busca um vertíce no grafo e retorna o info do vertíce encontrado.
*/
Vertex getVertex(Graph graph, char *id);


/*
  Busca uma aresta no grafo e retorna o info da aresta encontrada.
*/
Edge getEdge(Graph graph, char *idOrigin, char *idDestiny);


/*

*/
List getListAdjacent(Graph graph, char *id);


/*

*/
int adjacent(Graph graph, char* idOrigin, char *idDestiny);


Info removeEdgeGraph(Graph graph, char *idOrigin, char *idDestiny);

void showGraph(Graph graph, FILE *fileSvg, void(showV)(void *, FILE *), void(showE)(void *, void*, FILE *));

/*
  Apaga todos os vertíces dentro do grafo.
*/
void eraseAllVertex(Graph graph, void (eraseInfo)(void*));


/*
  Apaga todos as arestas dentro do grafo.
*/
void eraseAllEdge(Graph graph, void (eraseInfo)(void*));


/*
  Apaga os dados do grafo.
*/
void eraseGraph(Graph graph);

#endif
