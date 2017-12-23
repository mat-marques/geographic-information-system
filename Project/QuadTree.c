#include <stdio.h>
#include <stdlib.h>
#include "QuadTree.h"

typedef struct node {
  ItemQt info;
  double x, y;
  struct node *direction[4];
  struct node *father;
} node;

typedef struct Base {
  long int size;
  node *root;
} Base;

void eraseTree(node *tree, eraseItem function);

QuadTree createQuadTree() {
  Base *base = NULL;

  base = (Base *)malloc(sizeof(Base));
  if (base != NULL) {
    base->root = NULL;
    base->size = 0;
  }
  return base;
}

/* Função interna. */
long int insert(node *element, node *newElement) {
  long int qtdI;
  node *aux = NULL, *aux2 = NULL;
  aux = element;
  qtdI = 2;
  if (element != NULL) {
    while (aux != NULL) {
      aux2 = aux;
      qtdI = qtdI + 2;
      /* SE */
      if (newElement->x <= aux->x && newElement->y <= aux->y) {
        aux = aux->direction[0];
        continue;
      }
      /* SW */
      if (newElement->x > aux->x && newElement->y < aux->y) {
        aux = aux->direction[1];
        continue;
      }
      /* NE */
      if (newElement->x < aux->x && newElement->y > aux->y) {
        aux = aux->direction[2];
        continue;
      }
      /* NW */
      if (newElement->x >= aux->x && newElement->y >= aux->y) {
        aux = aux->direction[3];
        continue;
      }
    }

    if (newElement->x <= aux2->x && newElement->y <= aux2->y) {
      aux2->direction[0] = newElement;
      newElement->father = aux2;
    } else
        /* SW */
        if (newElement->x > aux2->x && newElement->y < aux2->y) {
      aux2->direction[1] = newElement;
      newElement->father = aux2;
    } else
        /* NE */
        if (newElement->x < aux2->x && newElement->y > aux2->y) {
      aux2->direction[2] = newElement;
      newElement->father = aux2;
    } else {
      /* NW */
      if (newElement->x >= aux2->x && newElement->y >= aux2->y) {
        aux2->direction[3] = newElement;
        newElement->father = aux2;
      }
    }
  }

  return qtdI;
}

long int insertQuadTree(QuadTree tree, ItemQt item, double x, double y) {
  Base *base = (Base *)tree;
  node *newElement = NULL;
  int i;
  long int qtdI = 0;
  if (base != NULL) {
    newElement = (node *)malloc(sizeof(node));
    newElement->info = item;
    newElement->x = x;
    newElement->y = y;
    base->size = base->size + 1;
    for (i = 0; i < 4; i++) {
      newElement->direction[i] = NULL;
    }
    if (base->root == NULL) {
      base->root = newElement;
      newElement->father = NULL;
    } else {
      qtdI = 6;
      qtdI = qtdI + insert(base->root, newElement);
    }
  }
  return qtdI;
}

long int lenghtQuadTree(QuadTree tree) {
  Base *base = (Base *)tree;
  if (base != NULL)
    return base->size;
  return 0;
}

/* Função interna. */
void show(node *tree, showItem function) {
  node *aux = tree;
  if (aux != NULL) {
    show(aux->direction[0], function);
    show(aux->direction[1], function);
    show(aux->direction[2], function);
    show(aux->direction[3], function);
    function(aux->info);
  }
}

void showQuadTree(QuadTree tree, showItem function) {
  Base *base = (Base *)tree;
  show(base->root, function);
}

/* Função interna. */
long int reInsertSubTree(node *tree, node *subTree) {
  /* Reinsere nó a nó da sub-árvore subTree na árvore tree. */
  node *aux = subTree;
  long int qtdR = 1;
  if (aux != NULL) {
    qtdR = qtdR + reInsertSubTree(tree, aux->direction[0]);
    qtdR = qtdR + reInsertSubTree(tree, aux->direction[1]);
    qtdR = qtdR + reInsertSubTree(tree, aux->direction[2]);
    qtdR = qtdR + reInsertSubTree(tree, aux->direction[3]);
    qtdR = qtdR + 1;
    if (aux != NULL) {
      aux->father = NULL;
      aux->direction[0] = NULL;
      aux->direction[1] = NULL;
      aux->direction[2] = NULL;
      aux->direction[3] = NULL;
      qtdR = qtdR + insert(tree, aux);
    }
  }
  return qtdR;
}

/* Função interna. Coloca os elementos em uma lista. */
void listQAux(List list, node *subTree) {
  if (subTree != NULL) {
    listQAux(list, subTree->direction[0]);
    insertEndL(list, subTree->info);
    listQAux(list, subTree->direction[1]);
    listQAux(list, subTree->direction[2]);
    listQAux(list, subTree->direction[3]);
  }
}

/* Função interna. */
long int removeItem(node *tree, ItemQt item, node **r, compareToQt function) {
  /* Encontra o nó que deve ser removido da árvore. */
  node *aux = tree;
  long int qtdR = 1;
  if (aux != NULL && *r == NULL) {
    qtdR = qtdR + 2;
    if (function(aux->info, item) == 1) {
      *r = aux;
    } else {
      qtdR = qtdR + removeItem(aux->direction[0], item, r, function);

      qtdR = qtdR + removeItem(aux->direction[1], item, r, function);

      qtdR = qtdR + removeItem(aux->direction[2], item, r, function);

      qtdR = qtdR + removeItem(aux->direction[3], item, r, function);
    }
  }
  return qtdR;
}

ItemQt removeQuadTreeItemI(QuadTree tree, ItemQt item, compareToQt function,
                           long int *qtdR) {
  Base *base = (Base *)tree;
  node *r = NULL;
  node *f = NULL;
  int i;
  ItemQt info = NULL;
  *qtdR = 0;
  base->size = base->size - 1;
  if (function(base->root->info, item) == 1) { /* Raiz da árvore. */
    info = base->root->info;
    r = base->root;
    base->root = NULL;
    base->size = base->size - 1;
    *qtdR = 2;
    for (i = 0; i < 4; i++) {
      if (r->direction[i] != NULL) {
        base->root = r->direction[i];
        r->direction[i] = NULL;
        *qtdR = *qtdR + 2;
        break;
      }
    }
    for (i = 0; i < 4; i++) {
      if (r->direction[i] != NULL)
        *qtdR = *qtdR + reInsertSubTree(base->root, r->direction[i]) + 2;
    }

    free(r);
  } else { /* Nó qualquer da árvore. */
    *qtdR = removeItem(base->root, item, &r, function);
    if (r != NULL) {
      f = r->father;
      for (i = 0; i < 4; i++) { /* Direção do father. */
        if (f->direction[i] == r) {
          f->direction[i] = NULL;
          *qtdR = *qtdR + 2;
          break;
        }
      }
      info = r->info;
      for (i = 0; i < 4; i++) {
        if (r->direction[i] != NULL)
          *qtdR = *qtdR + reInsertSubTree(base->root, r->direction[i]) + 2;
      }
      base->size = base->size - 1;
      free(r);
    }
  }

  return info;
}

ItemQt removeQuadTreeItem(QuadTree tree, ItemQt item, compareToQt function,
                          List list) {
  Base *base = (Base *)tree;
  node *r = NULL;
  node *f = NULL;
  int i;
  ItemQt info = NULL;
  base->size = base->size - 1;
  if (function(base->root->info, item) == 1) { /* Raiz da árvore. */
    info = base->root->info;
    r = base->root;
    base->root = NULL;
    for (i = 0; i < 4; i++) {
      listQAux(list, r->direction[i]);
    }
    eraseTree(r, NULL);
    base->size = 0;
  } else { /* Nó qualquer da árvore. */
    removeItem(base->root, item, &r, function);
    if (r != NULL) {
      f = r->father;
      for (i = 0; i < 4; i++) { /* Direção do father. */
        if (f->direction[i] == r) {
          f->direction[i] = NULL;
          break;
        }
      }
      info = r->info;
      for (i = 0; i < 4; i++) {
        if (r->direction[i] != NULL)
          listQAux(list, r->direction[i]);
      }
      eraseTree(r, NULL);
      base->size = base->size - lengthL(list);
    }
  }

  return info;
}

/* Função interna. */
void getByRegion(List list, node *tree, Region region, compareToQt function) {
  node *aux = tree;
  if (aux != NULL) {
    getByRegion(list, aux->direction[0], region, function);
    getByRegion(list, aux->direction[1], region, function);
    getByRegion(list, aux->direction[2], region, function);
    getByRegion(list, aux->direction[3], region, function);
    if (function(aux->info, region) == 1) {
      insertEndL(list, aux->info);
    }
  }
}

List getElementsByRegion(QuadTree tree, Region region, compareToQt function) {
  List list = NULL;
  Base *base = (Base *)tree;
  if (tree != NULL) {
    if (base->root != NULL) {
      list = createL();
      getByRegion(list, base->root, region, function);
    }
  }
  return list;
}

/* Função interna. */
ItemQt searchItem(node *tree, ItemQt item, ItemQt info, compareToQt function) {
  node *aux = tree;
  ItemQt r = info;
  if (aux != NULL) {

    r = searchItem(aux->direction[0], item, r, function);

    r = searchItem(aux->direction[1], item, r, function);

    r = searchItem(aux->direction[2], item, r, function);

    r = searchItem(aux->direction[3], item, r, function);

    if (function(aux->info, item) == 1) {
      r = aux->info;
    }
  }
  return r;
}

ItemQt searchQuadTreeItem(QuadTree tree, ItemQt item, compareToQt function) {
  Base *base = (Base *)tree;
  ItemQt info = NULL;
  if (base != NULL) {
    if (base->root != NULL) {
      info = searchItem(base->root, item, NULL, function);
    }
  }

  return info;
}

/* Função interna. */
ItemQt searchByCoordinate(node *tree, double x, double y) {
  ItemQt info = NULL;
  node *aux = tree;
  while (aux != NULL) {
    if (x == aux->x && y == aux->y) {
      info = aux->info;
      break;
    }
    if (x < aux->x && y < aux->y) {
      aux = aux->direction[0];
    } else
        /* SW */
        if (x > aux->x && y < aux->y) {
      aux = aux->direction[1];
    } else
        /* NE */
        if (x < aux->x && y > aux->y) {
      aux = aux->direction[2];
    } else {
      /* NW */
      if (x > aux->x && y > aux->y) {
        aux = aux->direction[3];
      }
    }
  }
  return info;
}

ItemQt searchQuadTreeByCoordinate(QuadTree tree, double x, double y) {
  Base *base = (Base *)tree;
  ItemQt info = NULL;

  info = searchByCoordinate(base->root, x, y);

  return info;
}

/* Função interna. */
void eraseTree(node *tree, eraseItem function) {
  /* Recursão para eliminar nó a nó da ávore. */
  node *aux = tree;
  if (aux != NULL) {
    eraseTree(aux->direction[0], function);
    eraseTree(aux->direction[1], function);
    eraseTree(aux->direction[2], function);
    eraseTree(aux->direction[3], function);
    if (function != NULL && aux->info != NULL) {
      function(aux->info);
      aux->info = NULL;
    }
    free(aux);
  }
}

void eraseQuadTreeNode(QuadTree tree, eraseItem function) {
  /* Elimina os nós da árvore. */
  Base *base = (Base *)tree;
  eraseTree(base->root, function);
}

void eraseQuadTreeBase(QuadTree tree) {
  /* Elimina a base da árvore. */
  Base *base = (Base *)tree;
  free(base);
}
