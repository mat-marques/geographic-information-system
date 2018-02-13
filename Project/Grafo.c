#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Grafo.h"
#include "StringO.h"

#define Branco 0
#define Cinza 1
#define Preto 2
#define Max 1000000000

int myTime = 0;

struct widthS {
  int cor;
  double dist;
  int d;
  struct myVertex *p;
};

typedef struct myVertex {
  char *id;
  void *info;
  List listEdge;
  struct widthS *u;
} newVertex;

typedef struct myEdge {
  void *info;
  char *idOrigin, *idDestiny, *id;
  double p, v;
  newVertex *vertex;
} newEdge;

typedef struct myGraph {
  char *id;
  HashTable hashVertex;
  newVertex **vectorVertex;
  long int qtdVD, qtdV;
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


Graph createGraph(char *id, int n) {
  newGraph *graph = NULL;
  graph = (newGraph *)malloc(sizeof(newGraph));
  if (graph != NULL) {
    graph->id = criarString(id);
    graph->hashVertex = createHT(50);
    graph->qtdVD = n;
    graph->qtdV = 0;
    graph->vectorVertex = (newVertex**) malloc(n * sizeof(newVertex));
  }
  return graph;
}


void insertVertex(Graph graph, char *id, Info info) {
  newGraph *graphN = (newGraph *)graph;
  newVertex *vertexN = NULL;
  if (graphN != NULL) {
    if(graphN->qtdV < graphN->qtdVD){
      vertexN = (newVertex *)malloc(sizeof(newVertex));
      if (vertexN != NULL) {
        vertexN->id = criarString(id);
        vertexN->info = info;
        vertexN->listEdge = createL();
        vertexN->u = NULL;
        insertHT(graphN->hashVertex, id, vertexN);
        *(graphN->vectorVertex + graphN->qtdV) = vertexN;
        graphN->qtdV++;
      }
    }
  }
}


void insertEdge(Graph graph, char *idOrigin, char *idDestiny, double p, double v,
                Info info) {
  newGraph *graphN = (newGraph *)graph;
  int l;
  newEdge *edgeN = NULL;
  newVertex *vertexN = NULL;
  if (graphN != NULL) {
    vertexN = (newVertex *)itemIsInsideHT(graphN->hashVertex, idOrigin,
                                          idOrigin, compareVertex);
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
        edgeN->p = p;
        edgeN->v = v;
        edgeN->vertex = (newVertex *)itemIsInsideHT(
            graphN->hashVertex, idDestiny, idDestiny, compareVertex);
        insertEndL(vertexN->listEdge, edgeN);
      }
    }
  }
}


Vertex getVertex(Graph graph, char *id) {
  newGraph *graphN = (newGraph *)graph;
  newVertex *vertexN = NULL;
  if (graphN != NULL) {
    vertexN =
        (newVertex *)itemIsInsideHT(graphN->hashVertex, id, id, compareVertex);
    if (vertexN != NULL) {
      return vertexN;
    }
  }
  return NULL;
}


char *getIdVertex(Vertex vertex) {
  newVertex *v = (newVertex *)vertex;
  return v->id;
}


Info getInfoVertex(Vertex vertex) {
  newVertex *v = (newVertex *)vertex;
  return v->info;
}


Edge getEdge(Graph graph, char *idOrigin, char *idDestiny) {
  newGraph *graphN = (newGraph *)graph;
  newVertex *vertexN = NULL;
  newEdge *edgeN = NULL;
  int l;
  char *id, traco[] = "-";
  if (graphN != NULL) {
    vertexN = (newVertex *)itemIsInsideHT(graphN->hashVertex, idOrigin,
                                          idOrigin, compareVertex);
    if (vertexN != NULL) {
      l = strlen(idOrigin) + strlen(idDestiny) + 3;
      id = (char *)malloc(l * sizeof(char));
      strcpy(id, idOrigin);
      strcat(id, traco);
      strcat(id, idDestiny);
      edgeN = (newEdge *)searchItemL(vertexN->listEdge, id, compareEdge);
      free(id);
      if (edgeN != NULL) {
        return edgeN;
      }
    }
  }
  return NULL;
}


char *getIdEdge(Edge edge) {
  newEdge *e = (newEdge *)edge;
  return e->id;
}


Info getInfoEdge(Edge edge) {
  newEdge *e = (newEdge *)edge;
  return e->info;
}


List getListAdjacent(Graph graph, char *id) {
  newGraph *graphN = (newGraph *)graph;
  int i, j;
  List list = NULL;
  newVertex *vertex = NULL;
  newEdge *edge = NULL;
  vertex =
      (newVertex *)itemIsInsideHT(graphN->hashVertex, id, id, compareVertex);
  if (vertex != NULL) {
    list = createL();
    j = lengthL(vertex->listEdge);
    for (i = 1; i <= j; i++) {
      edge = (newEdge *)getItemL(vertex->listEdge, i);
      if (edge != NULL) {
        insertEndL(list, edge->vertex);
      }
      edge = NULL;
    }
  }
  return list;
}


int adjacent(Graph graph, char *idOrigin, char *idDestiny) {
  newGraph *graphN = (newGraph *)graph;
  int l;
  char *id, traco[] = "-";
  newVertex *vertex = NULL;
  newEdge *edge = NULL;
  vertex = (newVertex *)itemIsInsideHT(graphN->hashVertex, idOrigin, idOrigin,
                                       compareVertex);
  if (vertex != NULL) {
    l = strlen(idOrigin) + strlen(idDestiny) + 3;
    id = (char *)malloc(l * sizeof(char));
    strcpy(id, idOrigin);
    strcat(id, traco);
    strcat(id, idDestiny);
    edge = (newEdge *)searchItemL(vertex->listEdge, id, compareEdge);
    free(id);
    if (edge != NULL) {
      return 1;
    }
  }
  return 0;
}


void DSG(newVertex *v, List listR) {
  int i, j;
  newEdge *e = NULL;
  myTime = myTime + 1;
  v->u->d = myTime;
  v->u->cor = Cinza;
  j = lengthL(v->listEdge);
  for (i = 1; i <= j; i++) {
    e = (newEdge *)getItemL(v->listEdge, i);
    if (e->vertex->u->cor == Branco) {
      e->vertex->u->p = v;
      insertEndL(listR, e->vertex);
      DSG(e->vertex, listR);
    }
  }
  v->u->cor = Preto;
  myTime = myTime + 1;
  v->u->d = myTime;
}


List deepSearch(Graph graph) {
  newGraph *graphN = (newGraph *)graph;
  List listR = NULL;
  int i;
  newVertex *v = NULL;

  if (graphN != NULL) {
    /* Define as condições iniciais de todos os vertíces menos o vertice s */
    for (i = 0; i < graphN->qtdVD; i++) {
      v = *(graphN->vectorVertex + i);
      if ((v != NULL)) {
        if (v->u == NULL) {
          v->u = (struct widthS *)malloc(sizeof(struct widthS));
        }
        if (v->u != NULL) {
          v->u->cor = Branco;
          v->u->p = NULL;
          v->u->d = 0;
        }
      }
    }
    myTime = 0;
    listR = createL();

    /* Busca em profundidade */
    for (i = 0; i < graphN->qtdVD; i++) {
      v = *(graphN->vectorVertex + i);
      if (v->u->cor == Branco) {
        DSG(v, listR);
      }
    }
  }

  return listR;
}


List widthSearch(Graph graph, Vertex vertex) {
  newGraph *graphN = (newGraph *)graph;
  List list = NULL, listR = NULL;
  int i, n, m;
  newVertex *v = NULL;
  newEdge *edge = NULL;
  newVertex *s = (newVertex *)vertex;
  if (graphN != NULL) {
    /* Define as condições iniciais de todos os vertíces menos o vertice s */
    for (i = 0; i <= graphN->qtdVD; i++) {
      v = *(graphN->vectorVertex + i);
      if ((v != NULL) && (strcmp(v->id, s->id) != 0)) {
        if (v->u == NULL) {
          v->u = (struct widthS *)malloc(sizeof(struct widthS));
        }
        if (v->u != NULL) {
          v->u->cor = Branco;
          v->u->d = 0;
          v->u->p = NULL;
        }
      }
    }
    /* Define as condições iniciais do vertice de partida */
    s->u->cor = Cinza;
    s->u->d = 0;
    s->u->p = NULL;

    /* Fila de prioridades */
    list = createL();

    listR = createL();
    insertEndL(list, s);
    insertEndL(listR, s);

    v = NULL;
    /* Busca em largura */
    while (lengthL(list) != 0) {
      v = (newVertex *)getBeginItemL(list);
      removeBeginL(list, NULL);
      if (v != NULL) {
        m = lengthL(v->listEdge);
        if (m > 0) {
          for (n = 1; n <= m; n++) {
            edge = (newEdge *)getItemL(v->listEdge, n);
            if (edge != NULL) {
              if (edge->vertex->u->cor == Branco) {
                edge->vertex->u->cor = Cinza;
                edge->vertex->u->d = v->u->d + 1;
                edge->vertex->u->p = v;
                insertEndL(list, edge->vertex);
                insertEndL(listR, edge->vertex);
              }
            }
          }
          v->u->cor = Preto;
        }
      }
    }

    eraseListL(list, NULL);
    eraseBase(list);
  }
  return listR;
}


void initializeSingleSource(newGraph *graph) {
  int i;
  newVertex *v;
  for (i = 0; i < graph->qtdVD; i++) {
    v = *(graph->vectorVertex + i);
    if ((v != NULL)) {
      if(v->u == NULL){
        v->u = (struct widthS *)malloc(sizeof(struct widthS));
      }
      if (v->u != NULL) {
        v->u->dist = Max;
        v->u->p = NULL;
      }
    }
  }
}


void relax(newVertex *u, newVertex *v, newEdge *w, int p_v) {
  if(p_v == 0){
    if ((u->u->dist + w->p) < v->u->dist) {
      v->u->dist = u->u->dist + w->p;
      v->u->p = u;
    }
  } else {
    if(w->v == 0){
      w->v = 1;
    }
    if ((u->u->dist + (w->p/w->v)) < v->u->dist) {
      v->u->dist = u->u->dist + (w->p/w->v);
      v->u->p = u;
    }
  }
}


int extractMin(List listQ) {
  newVertex *v = NULL;
  int i, j, n;
  double p;
  j = lengthL(listQ);
  v = (newVertex *)getBeginItemL(listQ);
  p = v->u->dist;
  n = 1;
  for (i = 2; i <= j; i++) {
    v = (newVertex *)getItemL(listQ, i);
    if (v->u->dist < p) {
      n = i;
    }
  }
  return n;
}


List shortestPath(Graph graph, Vertex vertexO, Vertex vertexD, int p_v, double *r) {
  newGraph *graphN = (newGraph *)graph;
  List listS = NULL, listQ = NULL;
  int i, j, n;
  newVertex *u = NULL;
  newEdge *edge = NULL;
  newVertex *origin = (newVertex *)vertexO;
  newVertex *destiny = (newVertex *)vertexD;
  if (graphN != NULL) {

    initializeSingleSource(graphN);
    origin->u->dist = 0;

    listS = createL();
    listQ = createL();
    for (i = 0; i < graphN->qtdVD; i++) {
      u = *(graphN->vectorVertex + i);
      if ((u != NULL)) {
        insertEndL(listQ, u);
      }
    }

    u = NULL;

    while (lengthL(listQ) != 0) {
      n = extractMin(listQ);
      u = (newVertex *)getItemL(listQ, n);
      removeMiddleL(listQ, n, NULL);
      insertEndL(listS, u);
      j = lengthL(u->listEdge);
      for (i = 1; i <= j; i++) {
        edge = (newEdge *)getItemL(u->listEdge, i);
        if (edge != NULL) {
          relax(u, edge->vertex, edge, p_v);
        }
      }
    }
  }

  eraseListL(listQ, NULL);
  /* Lista que conterá os vertíces que compõem o menor caminho */
  if(destiny->u->p != NULL){
    *r = destiny->u->dist; /* Valor da menor distância ou menor velocidade. */
    insertBeginL(listQ, destiny);
    u = destiny->u->p;
    while(u != NULL){
      insertBeginL(listQ, u);
      u = u->u->p;
    }
  } else {
    eraseBase(listQ);
    listQ = NULL;
  }

  eraseListL(listS, NULL);
  eraseBase(listS);

  return listQ;
}


Info removeEdgeGraph(Graph graph, char *idOrigin, char *idDestiny) {
  newGraph *graphN = (newGraph *)graph;
  Info info = NULL;
  int l;
  char *id, traco[] = "-";
  newVertex *vertex = NULL;
  vertex = (newVertex *)itemIsInsideHT(graphN->hashVertex, idOrigin, idOrigin,
                                       compareVertex);
  if (vertex != NULL) {
    l = strlen(idOrigin) + strlen(idDestiny) + 3;
    id = (char *)malloc(l * sizeof(char));
    strcpy(id, idOrigin);
    strcat(id, traco);
    strcat(id, idDestiny);
    info = removeItemL2(vertex->listEdge, id, compareEdge);
    free(id);
  }
  return info;
}


void showGraph(Graph graph, FILE *fileSvg, void(showV)(void *, FILE *),
               void(showE)(void *, void *, FILE *)) {
  newGraph *graphN = (newGraph *)graph;
  int i, n, m;
  newVertex *vertex, *vertex2;
  newEdge *edge;
  if (graphN != NULL && showV != NULL) {
    for (i = 0; i < graphN->qtdVD; i++) {
      vertex = *(graphN->vectorVertex + i);
      showV(vertex->info, fileSvg);
      if (vertex != NULL) {
        m = lengthL(vertex->listEdge);
        for (n = 1; n <= m; n++) {
          edge = (newEdge *)getItemL(vertex->listEdge, n);
          vertex2 =
              (newVertex *)itemIsInsideHT(graphN->hashVertex, edge->idDestiny,
                                          edge->idDestiny, compareVertex);
          if (vertex2 != NULL && showE != NULL) {
            showE(vertex->info, vertex2->info, fileSvg);
          }
        }
      }
    }
  }
}


void removeVertex(void *vertexA) {
  newVertex *vertex = (newVertex *)vertexA;
  free(vertex->id);
  if (vertex->u != NULL) {
    free(vertex->u);
  }
  free(vertex);
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
  int i;
  newVertex *vertex;
  if (graphN != NULL) {
    eraseHT(graphN->hashVertex, NULL);
    if (eraseInfo != NULL) {
      for (i = 0; i < graphN->qtdVD; i++) {
        vertex = *(graphN->vectorVertex + i);
        if (vertex != NULL) {
          eraseInfo(vertex->info);
        }
        removeVertex(vertex);
      }
    }
  }
}


void eraseAllEdge(Graph graph, void(eraseInfo)(void *)) {
  newGraph *graphN = (newGraph *)graph;
  int i, n, m;
  newVertex *vertex;
  newEdge *edge;
  if (graphN != NULL) {
    for (i = 0; i < graphN->qtdVD; i++) {
      vertex = *(graphN->vectorVertex + i);
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
    free(graphN->vectorVertex);
    free(graphN);
  }
}
