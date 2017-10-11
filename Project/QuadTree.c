#include "QuadTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  ItemQt info;
  double x, y;
  struct node *direction[4];
  struct node *father;
} node;

typedef struct Base {
  int size;
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
void insert(node *element, node *newElement) {
  node *aux = NULL, *aux2 = NULL;
  aux = element;
  while (aux != NULL) {
    aux2 = aux;
    /* SE */
    if (newElement->x < aux->x && newElement->y < aux->y) {
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
    if (newElement->x > aux->x && newElement->y > aux->y) {
      aux = aux->direction[3];
      continue;
    }
  }

  if (newElement->x < aux2->x && newElement->y < aux2->y) {
    aux2->direction[0] = newElement;
    newElement->father = aux2->direction[0];
  } else
      /* SW */
      if (newElement->x > aux2->x && newElement->y < aux2->y) {
    aux2->direction[1] = newElement;
    newElement->father = aux2->direction[1];
  } else
      /* NE */
      if (newElement->x < aux2->x && newElement->y > aux2->y) {
    aux2->direction[2] = newElement;
    newElement->father = aux2->direction[2];
  } else {
    /* NW */
    if (newElement->x > aux2->x && newElement->y > aux2->y) {
      aux2->direction[3] = newElement;
      newElement->father = aux2->direction[3];
    }
  }
}

void insertQuadTree(QuadTree tree, ItemQt item, double x, double y) {
  Base *base = (Base *)tree;
  node *newElement = NULL;
  int i;
  if (base != NULL) {
    newElement = (node *)malloc(sizeof(node));
    newElement->info = item;
    newElement->x = x;
    newElement->y = y;
    for (i = 0; i < 4; i++) {
      newElement->direction[i] = NULL;
    }
    base->size = base->size + 1;
    if (base->root == NULL) {
      base->root = newElement;
      newElement->father = NULL;
    } else {
      insert(base->root, newElement);
    }
  }
}

/* Função interna. */
void show(node *tree, showItem function) {
  node *aux = tree;
  if (aux != NULL) {
    show(aux->direction[0], function);
    function(aux->info);
    show(aux->direction[1], function);
    show(aux->direction[2], function);
    show(aux->direction[3], function);
  }
}

void showQuadTree(QuadTree tree, showItem function) {
  Base *base = (Base *)tree;
  show(base->root, function);
}



/* Função interna. */
void reInsertSubTree(node *tree, node *subTree) {
  /* Reinsere nó a nó da sub-árvore subTree na árvore tree. */
  node *aux = subTree;
  if (aux != NULL) {
    insertQuadTree(tree, aux->direction[0]->info, aux->direction[0]->x,
                   aux->direction[0]->y);
    reInsertSubTree(aux->direction[0], subTree);
    reInsertSubTree(aux->direction[1], subTree);
    reInsertSubTree(aux->direction[2], subTree);
    reInsertSubTree(aux->direction[3], subTree);
  }
}

/* Função interna. */
void removeItem(node *tree, ItemQt item, node **r, compareToQt function) {
  /* Encontra o nó que deve ser removido da árvore. */
  node *aux = tree;
  if (aux != NULL && *r == NULL) {
    if (function(item, aux->info) == 1) {
      *r = aux;
    } else {
      removeItem(aux->direction[0], item, r, function);

      removeItem(aux->direction[1], item, r, function);

      removeItem(aux->direction[2], item, r, function);

      removeItem(aux->direction[3], item, r, function);
    }
  }
}

ItemQt removeQuadTreeItem(QuadTree tree, ItemQt item, compareToQt function) {
  Base *base = (Base *)tree;
  node *r = NULL;
  node *f = NULL;
  int i;
  ItemQt info = NULL;

  if (function(base->root, item) == 1) { /* Raiz da árvore. */
    base->root = NULL;
    info = r->info;
    for (i = 0; i < 4; i++) {
      reInsertSubTree(base->root, r->direction[i]);
    }
    free(r);
    base->size = base->size - 1;
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
        reInsertSubTree(base->root, r->direction[i]);
      }
      free(r);
      base->size = base->size - 1;
      eraseTree(r, NULL);
    }
  }

  return info;
}

/* Função interna. */
void getByRegion(List list, node *tree, Region region, compareToQt function) {
  node *aux = tree;
  if (aux != NULL) {
    getByRegion(list, aux->direction[0], region, function);
    if (function(aux->info, region) == 1) {
      insertEndDLL(list, aux->info);
    }
    getByRegion(list, aux->direction[1], region, function);
    getByRegion(list, aux->direction[2], region, function);
    getByRegion(list, aux->direction[3], region, function);
  }
}

List getElementsByRegion(QuadTree tree, Region region, compareToQt function) {
  List list;
  Base *base = (Base *)tree;
  list = createDLL();
  getByRegion(list, base->root, region, function);
  return list;
}

/* Função interna. */
void searchItem(node *tree, ItemQt item, void **info, compareToQt function) {
  node *aux = tree;
  if (aux != NULL && *info == NULL) {
    if (function(item, aux->info) == 1) {
      *info = aux->info;
    } else {
      searchItem(aux->direction[0], item, info, function);

      searchItem(aux->direction[1], item, info, function);

      searchItem(aux->direction[2], item, info, function);

      searchItem(aux->direction[3], item, info, function);
    }
  }
}

ItemQt searchQuadTreeItem(QuadTree tree, ItemQt item, compareToQt function) {
  Base *base = (Base *)tree;
  ItemQt info = NULL;

  searchItem(base->root, item, &info, function);

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
    if (function != NULL) {
      function(aux->info);
    }
    free(aux);
    eraseTree(aux->direction[1], function);
    eraseTree(aux->direction[2], function);
    eraseTree(aux->direction[3], function);
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
