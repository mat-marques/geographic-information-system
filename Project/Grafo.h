#ifndef GRAFO_H
#define GRAFO_H

#include "HashTable.h"

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
Graph createGraph(char *id, int n);


/*
  Insere um vertíce no grafo.
  Id é uma string única que representa o vertíce.
  Info é a informação que será armazenada no vertíce.
*/
void insertVertex(Graph graph, char *id, Info info);

/*
  Insere uma aresta no grafo.
  idOrigin é o vertíce de origem.
  idDestiny é o vertíce de destino.
  p e v são os pesos do vertíce.
  Info é a informação que será armazenada na aresta.
*/
void insertEdge(Graph graph, char *idOrigin, char *idDestiny, double p, double v, Info info);


/*
  Busca um vertíce no grafo e retorna o info do vertíce encontrado.
*/
Vertex getVertex(Graph graph, char *id);

/*
  Retorna o id do vertíce vertex.
*/
char *getIdVertex(Vertex vertex);


/*
  Retorna o info do vertíce vertex.
*/
Edge getInfoVertex(Vertex vertex);

/*
  Busca uma aresta no grafo e retorna o info da aresta encontrada.
*/
Info getEdge(Graph graph, char *idOrigin, char *idDestiny);


/*
  Retorna o id da aresta edge.
*/
char *getIdEdge(Edge edge);


/*
  Retorna o Info da aresta edge.
*/
Info getInfoEdge(Edge edge);


/*
  A função retorna uma lista contendo todos os vertíces que são adjacentes ao vertíce
  com o id definido por id.
*/
List getListAdjacent(Graph graph, char *id);


/*
  A função verifica se o vertíce com idDestiny é adjacente ao vertíce com idOrigin.
  Retorna 1 se forem adjacentes.
  Retorna 0 se não forem adjacentes.
*/
int adjacent(Graph graph, char* idOrigin, char *idDestiny);


/*
A função faz uma busca em profundidade no grafo. Retorna uma lista contendo os vertíces
da busca.
*/
List deepSearch(Graph graph);


/*
  A função faz uma busca em largura no grafo. Retorna uma lista contendo os vertíces
  da busca. A busca parte do vertíce inicial vertex.
*/
List widthSearch(Graph graph, Vertex vertex);


/*
  A função implementa o algoritmo de Dijkstra. Retorna uma lista com os vertíces
  que compõem o menor caminho. A análise parte do vertíce vertexO. vertexD é o vertíce
  de destino. r será o valor a ser retornado, ele constitui o valor da analise de menor caminho.
  A análise do menor caminho pode ser feita por um dos pesos p ou v.
  0 para p.
  1 para v.

*/
List shortestPath(Graph graph, Vertex vertexO, Vertex vertexD, int p_v, double *r);


/*
  A função remove uma aresta do grafo e retorna seu Info.
  idOrigin é o vertíce de origem.
  idDestiny é o vertíce de destino.
*/
Info removeEdgeGraph(Graph graph, char *idOrigin, char *idDestiny);


/*
  O procedimento desenha o grafo em um arquivo svg(fileSvg). showV e showE são
  procedimentos que devem ser definidos pelo usuário. showV desenha os vertíces
  e showE desenha a aresta.
*/
void showGraph(Graph graph, FILE *fileSvg, void(showV)(void *, FILE *), void(showE)(void *, void*, FILE *));


/*
Apaga todas os vertíces do grafo. eraseInfo é uma função que apaga o info dos
vertíces. eraseInfo deve ser definida pelo usuário.
*/
void eraseAllVertex(Graph graph, void(eraseInfo)(void *));


/*
  Apaga todas as arestas do grafo. eraseInfo é uma função que apaga o info da
  aresta. eraseInfo deve ser definida pelo usuário.
*/
void eraseAllEdge(Graph graph, void(eraseInfo)(void *)) ;


/*
  Apaga os dados do grafo.
*/
void eraseGraph(Graph graph);

#endif
