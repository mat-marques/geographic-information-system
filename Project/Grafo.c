#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Grafo.h"
#include "StringO.h"

typedef struct myVertex{
  char *id;
  void *info;
  List listEdge;
}newVertex;

typedef struct myEdge{
  void *info;
  char *idOrigin, *idDestiny, *id;
}newEdge;

typedef struct myGraph{
  char *id;
  List listVertex;
}newGraph;


int compareVertex(void *vertexA, void*id){
  newVertex *vertexB = (newVertex*) vertexA;
  char *myId = (char*) id;
  if(strcmp(vertexB->id, myId)){
      return 1;
  }
  return 0;
}


int compareEdge(void *edgeA, void*id){
  newEdge *edgeB = (newEdge*) edgeA;
  char *myId = (char*) id;
  if(strcmp(edgeB->id, myId) == 0){
      return 1;
  }
  return 0;
}


Graph createGraph(char *id){
  newGraph *graph = NULL;
  graph = (newGraph*) malloc(sizeof(newGraph));
  if(graph != NULL){
    graph->id = criarString(id);
    graph->listVertex = createL();
  }
  return graph;
}


void insertVertex(Graph graph, char *id, Info info){
  newGraph *graphN = (newGraph*) graph;
  newVertex *vertexN = NULL;
  if(graphN != NULL){
    vertexN = (newVertex*) malloc(sizeof(newVertex));
    if(vertexN != NULL){
      vertexN->id = criarString(id);
      vertexN->info = info;
      vertexN->listEdge = createL();
      insertEndL(graphN->listVertex, vertexN);
    }
  }
}


void insertEdge(Graph graph, char *idOrigin, char *idDestiny, Info info){
  newGraph *graphN = (newGraph*) graph;
  int l;
  newEdge *edgeN = NULL;
  newVertex *vertexN = NULL;
  if(graphN != NULL){
    edgeN = (newEdge*) malloc(sizeof(newEdge));
    if(edgeN != NULL){
      /* Aloca o id da aresta */
      l = strlen(idOrigin) + strlen(idDestiny) + 2;
      edgeN->id = (char*) malloc(l * sizeof(char));
      edgeN->id = strcat(idOrigin, "-");
      edgeN->id = strcat(edgeN->id, idDestiny);

      edgeN->info = info;
      edgeN->idDestiny = criarString(idDestiny);
      edgeN->idOrigin = criarString(idOrigin);
      /* Obtem o vertice de origem */
      vertexN = (newVertex*) searchItemL(graphN->listVertex, idOrigin, compareVertex);
      if(vertexN != NULL){
        insertEndL(vertexN->listEdge, edgeN);
      }
    }
  }
}


Vertex getVertex(Graph graph, char *id){
  newGraph *graphN = (newGraph*) graph;
  newVertex *vertexN = NULL;
  if(graphN != NULL){
    vertexN = (newVertex*) searchItemL(graphN->listVertex, id, compareVertex);
    if(vertexN != NULL){
      return vertexN->info;
    }
  }
  return NULL;
}


Edge getEdge(Graph graph, char *idOrigin, char *idDestiny){
  newGraph *graphN = (newGraph*) graph;
  newVertex *vertexN = NULL;
  newEdge *edgeN = NULL;
  int l;
  char *id;
  if(graphN != NULL){
    vertexN = (newVertex*) searchItemL(graphN->listVertex, idOrigin, compareVertex);
    if(vertexN != NULL){
      l = strlen(idOrigin) + strlen(idDestiny) + 2;
      id = (char*) malloc(l * sizeof(char));
      id = strcat(idOrigin, "-");
      id = strcat(id, idDestiny);
      edgeN = (newEdge*) searchItemL(vertexN->listEdge, id, compareEdge);
      free(id);
      if(edgeN != NULL){
        return edgeN->info;
      }
    }
  }
  return NULL;
}

/*
List getListAdjacent(Graph graph, char *id){
  newGraph *graphN = (newGraph*) graph;
  int i, j;
  List list = NULL;
  newVertex *vertex = NULL;
  newEdge *edge = NULL;
  vertex = (newVertex*) searchItemL(graphN->listVertex, id, compareVertexG);
  if(vertex != NULL){
    list = createL();
    j = lengthL(vertex->listEdge);
    for(i=0; i<j; i++){
      edge = (newEdge*) getItemL(vertex->listEdge, i);
      if(edge != NULL){
        insertEndL(list, edge->vertex->info);
      }
      edge = NULL;
    }
  }
  return list;
}


int adjacent(Graph graph, char* idOrigin, char *idDestiny){
  newGraph *graphN = (newGraph*) graph;
  newVertex *vertex = NULL;
  newEdge *edge = NULL;
  vertex = (newVertex*) searchItemL(graphN->listVertex, idOrigin, compareVertexG);
  if(vertex != NULL){
    edge = (newEdge*) searchItemL(vertex->listEdge, idDestiny, compareEdgeG);
    if(edge != NULL){
      return 1;
    }
  }
  return 0;
}
*/

Vertex removeVertexGraph(Graph graph, char *id);


Edge removeEdgeGraph(Graph graph, char *idOrigin, char *idDestiny);


void eraseVertex(Graph graph, void (eraseV)(void*)){
}


void eraseEdge(Graph graph, void (eraseE)(void*)){

}


void eraseGraph(Graph graph){
  newGraph *graphN = (newGraph*) graph;
  if(graphN != NULL){
    free(graphN->id);
    free(graphN);
  }
}
