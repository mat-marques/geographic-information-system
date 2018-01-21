#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Grafo.h"
#include "StringO.h"
#include "Svg.h"

typedef struct myVertex {
  char *id;
  void *info;
  List listEdge;
} newVertex;

typedef struct myEdge {
  void *info;
  char *idOrigin, *idDestiny, *id;
} newEdge;

typedef struct myGraph {
  char *id;
  List listVertex;
} newGraph;

int compareVertex(void *vertexA, void *id) {
  newVertex *vertexB = (newVertex *)vertexA;
  char *myId = (char *)id;
  if (strcmp(vertexB->id, myId) == 0) {
    return 1;
  }
  return 0;
}

int compareEdge(void *edgeA, void *id) {
  newEdge *edgeB = (newEdge *)edgeA;
  char *myId = (char *)id;
  if (strcmp(edgeB->id, myId) == 0) {
    return 1;
  }
  return 0;
}

Graph createGraph(char *id) {
  newGraph *graph = NULL;
  graph = (newGraph *)malloc(sizeof(newGraph));
  if (graph != NULL) {
    graph->id = criarString(id);
    graph->listVertex = createL();
  }
  return graph;
}

void insertVertex(Graph graph, char *id, Info info) {
  newGraph *graphN = (newGraph *)graph;
  newVertex *vertexN = NULL;
  if (graphN != NULL) {
    vertexN = (newVertex *)malloc(sizeof(newVertex));
    if (vertexN != NULL) {
      vertexN->id = criarString(id);
      vertexN->info = info;
      vertexN->listEdge = createL();
      insertEndL(graphN->listVertex, vertexN);
    }
  }
}

void insertEdge(Graph graph, char *idOrigin, char *idDestiny, Info info) {
  newGraph *graphN = (newGraph *)graph;
  int l;
  newEdge *edgeN = NULL;
  newVertex *vertexN = NULL;
  if (graphN != NULL) {
    vertexN =
        (newVertex *)searchItemL(graphN->listVertex, idOrigin, compareVertex);
    if (vertexN != NULL) {
      edgeN = (newEdge *)malloc(sizeof(newEdge));
      if (edgeN != NULL) {
        /* Aloca o id da aresta */
        l = strlen(idOrigin) + strlen(idDestiny) + 2;
        edgeN->id = (char *)malloc(l * sizeof(char));
        strcpy(edgeN->id, idOrigin);
        strcat(edgeN->id, "-");
        strcat(edgeN->id, idDestiny);
        edgeN->info = info;
        edgeN->idOrigin = criarString(idOrigin);
        edgeN->idDestiny = criarString(idDestiny);
        insertEndL(vertexN->listEdge, edgeN);
      }
    }
  }
}

Vertex getVertex(Graph graph, char *id) {
  newGraph *graphN = (newGraph *)graph;
  newVertex *vertexN = NULL;
  if (graphN != NULL) {
    vertexN = (newVertex *)searchItemL(graphN->listVertex, id, compareVertex);
    if (vertexN != NULL) {
      return vertexN->info;
    }
  }
  return NULL;
}

Edge getEdge(Graph graph, char *idOrigin, char *idDestiny) {
  newGraph *graphN = (newGraph *)graph;
  newVertex *vertexN = NULL;
  newEdge *edgeN = NULL;
  int l;
  char *id;
  if (graphN != NULL) {
    vertexN =
        (newVertex *)searchItemL(graphN->listVertex, idOrigin, compareVertex);
    if (vertexN != NULL) {
      l = strlen(idOrigin) + strlen(idDestiny) + 2;
      id = (char *)malloc(l * sizeof(char));
      id = strcat(idOrigin, "-");
      id = strcat(id, idDestiny);
      edgeN = (newEdge *)searchItemL(vertexN->listEdge, id, compareEdge);
      free(id);
      if (edgeN != NULL) {
        return edgeN->info;
      }
    }
  }
  return NULL;
}

List getListAdjacent(Graph graph, char *id) {
  newGraph *graphN = (newGraph *)graph;
  int i, j;
  List list = NULL;
  newVertex *vertex = NULL;
  newEdge *edge = NULL;
  vertex = (newVertex *)searchItemL(graphN->listVertex, id, compareVertex);
  if (vertex != NULL) {
    list = createL();
    j = lengthL(vertex->listEdge);
    for (i = 1; i <= j; i++) {
      edge = (newEdge *)getItemL(vertex->listEdge, i);
      if (edge != NULL) {
        insertEndL(list, edge->idDestiny);
      }
      edge = NULL;
    }
  }
  return list;
}

int adjacent(Graph graph, char *idOrigin, char *idDestiny) {
  newGraph *graphN = (newGraph *)graph;
  int l;
  char *id;
  newVertex *vertex = NULL;
  newEdge *edge = NULL;
  vertex =
      (newVertex *)searchItemL(graphN->listVertex, idOrigin, compareVertex);
  if (vertex != NULL) {
    l = strlen(idOrigin) + strlen(idDestiny) + 2;
    id = (char *)malloc(l * sizeof(char));
    id = strcat(idOrigin, "-");
    id = strcat(id, idDestiny);
    edge = (newEdge *)searchItemL(vertex->listEdge, id, compareEdge);
    free(id);
    if (edge != NULL) {
      return 1;
    }
  }
  return 0;
}

void deepSearch(Graph graph);

void widthSearch(Graph graph);

Info removeEdgeGraph(Graph graph, char *idOrigin, char *idDestiny) {
  newGraph *graphN = (newGraph *)graph;
  Info info = NULL;
  int l;
  char *id;
  newVertex *vertex = NULL;
  vertex =
      (newVertex *)searchItemL(graphN->listVertex, idOrigin, compareVertex);
  if (vertex != NULL) {
    l = strlen(idOrigin) + strlen(idDestiny) + 2;
    id = (char *)malloc(l * sizeof(char));
    id = strcat(idOrigin, "-");
    id = strcat(id, idDestiny);
    removeItemL2(vertex->listEdge, id, compareEdge);
    free(id);
  }
  return info;
}

void removeVertex(void *vertexA) {
  newVertex *vertex = (newVertex *)vertexA;
  free(vertex->id);
  free(vertex);
}

void showGraph(Graph graph, FILE *fileSvg, void(showV)(void *, FILE *), void(showE)(void *, void*, FILE *)) {
  newGraph *graphN = (newGraph *)graph;
  int i, j, n, m;
  newVertex *vertex, *vertex2;
  newEdge *edge;
  if (graphN != NULL && showV != NULL) {
    j = lengthL(graphN->listVertex);
    for (i = 1; i <= j; i++) {
      vertex = (newVertex *)getItemL(graphN->listVertex, i);
      showV(vertex->info, fileSvg);
      if (vertex != NULL) {
        m = lengthL(vertex->listEdge);
        printf("m = %d\n", m);
        for (n = 1; n <= m; n++) {
          edge = (newEdge *)getItemL(vertex->listEdge, n);
          vertex2 = (newVertex*) searchItemL(graphN->listVertex, edge->idDestiny, compareVertex);
          if(vertex2 != NULL && showE != NULL){
            showE(vertex->info, vertex2->info, fileSvg);
          }
        }

      }

    }

  }
}

void removeEdge(void *edgeA) {
  newEdge *edge = (newEdge *)edgeA;
  free(edge->idDestiny);
  free(edge->idOrigin);
  free(edge->id);
  free(edge);
}

void eraseAllVertex(Graph graph, void(eraseInfo)(void *)) {
  newGraph *graphN = (newGraph *)graph;
  int i, j;
  newVertex *vertex;
  if (graphN != NULL) {
    if (eraseInfo != NULL) {
      j = lengthL(graphN->listVertex);
      for (i = 1; i <= j; i++) {
        vertex = (newVertex *)getItemL(graphN->listVertex, i);
        if (vertex != NULL) {
          eraseInfo(vertex->info);
        }
      }
    }
    eraseListL(graphN->listVertex, removeVertex);
    eraseBase(graphN->listVertex);
  }
}

void eraseAllEdge(Graph graph, void(eraseInfo)(void *)) {
  newGraph *graphN = (newGraph *)graph;
  int i, j, n, m;
  newVertex *vertex;
  newEdge *edge;
  if (graphN != NULL) {
    j = lengthL(graphN->listVertex);
    for (i = 1; i <= j; i++) {
      vertex = (newVertex *)getItemL(graphN->listVertex, i);
      if (vertex != NULL) {
        if (eraseInfo != NULL) {
          m = lengthL(vertex->listEdge);
          for (n = 1; n <= m; n++) {
            edge = (newEdge *)getItemL(vertex->listEdge, n);
            if (edge != NULL) {
              eraseInfo(edge->info);
            }
          }
        }
        eraseListL(vertex->listEdge, removeEdge);
        eraseBase(vertex->listEdge);
      }
    }
  }
}

void eraseGraph(Graph graph) {
  newGraph *graphN = (newGraph *)graph;
  if (graphN != NULL) {
    free(graphN->id);
    free(graphN);
  }
}
