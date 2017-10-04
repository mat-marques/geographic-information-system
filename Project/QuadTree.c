#include "QuadTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  ItemQt info;
  double x, y;
  struct no *direction[4];
} node;

typedef struct Base {
  int size;
  node *root;
} Base;

QuadTree createQuadTree() {
  Base *base = NULL;

  base = (Base *)malloc(sizeof(Base));
  if (base != NULL) {
    base->root = NULL;
    base->size = 0;
  }
  return base;
}

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
  } else
      /* SW */
      if (newElement->x > aux2->x && newElement->y < aux2->y) {
    aux2->direction[1] = newElement;
  } else
      /* NE */
      if (newElement->x < aux2->x && newElement->y > aux2->y) {
    aux2->direction[2] = newElement;
  } else {
    /* NW */
    if (newElement->x > aux2->x && newElement->y > aux2->y) {
      aux2->direction[3] = newElement;
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
    } else {
      insert(base->root, newElement);
    }
  }
}

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

void reInsertSubTree(node *tree, node *subTree) {
  node *aux = subTree;
  if (aux != NULL) {
    reInsertSubTree(aux->direction[0], subTree);
    insert(tree, subTree);
    aux->direction[0] = NULL;
    reInsertSubTree(aux->direction[1], subTree);
    reInsertSubTree(aux->direction[2], subTree);
    reInsertSubTree(aux->direction[3], subTree);
  }
}

ItemQt removeItem(Base *tree, double x, double y) {
  ItemQt info = NULL;
  node *aux = tree->root;
  node *vectorAux[4];
  node *aux2;
  int i, j = 0;
  int region = 0;
  while (aux != NULL) {
    if (x == aux->x && y == aux->y) {
      for (i = 0; i < 4; i++) {
        vectorAux[i] = aux->direction[i];
        if (aux->direction[i] != NULL) {
          j++;
        }
      }
      info = aux->info;
      tree->size = tree->size + 1;
      free(aux);
      /* Possui filhos */
      if (j > 0) {
        /* Elimina a raiz da árvore */
        if (region == 0) {
          j = -1;
          for (i = 0; i < 4; i++) {
            /* Torna o primeiro filho a esquerda a raiz da árvore. */
            if ((vectorAux[i] != NULL) && (j == -1)) {
              tree->root = vectorAux[i];
              j = 0;
            } else {
              /* Reinsere os demais filhos na árvore. */
              if ((vectorAux[i] != NULL) && (j == 0)) {
                reInsertSubTree(tree->root, vectorAux[i]);
              }
            }
          }
          break;
        } else if (region == 1) { /* Reseta o pai */
          aux2->direction[0] = NULL;
        } else if (region == 2) { /* Reseta o pai */
          aux2->direction[1] = NULL;
        } else if (region == 3) { /* Reseta o pai */
          aux2->direction[2] = NULL;
        } else {
          if (region == 4) { /* Reseta o pai */
            aux2->direction[3] = NULL;
          }
        }

        for (i = 0; i < 4; i++) {
          if (vectorAux[i] != NULL) {
            reInsertSubTree(tree->root, vectorAux[i]);
          }
        }

      } else {
        if (region == 0) { /*  Raiz */
          tree->root = NULL;
        } else if (region == 1) { /* Reseta o pai */
          aux2->direction[0] = NULL;
        } else if (region == 2) { /* Reseta o pai */
          aux2->direction[1] = NULL;
        } else if (region == 3) { /* Reseta o pai */
          aux2->direction[2] = NULL;
        } else {
          if (region == 4) { /* Reseta o pai */
            aux2->direction[3] = NULL;
          }
        }
      }
      break;
    }
    /* SE */
    if (x < aux->x && y < aux->y) {
      region = 1;
      aux2 = aux;
      aux = aux->direction[0];
      continue;
    }
    /* SW */
    if (x > aux->x && y < aux->y) {
      region = 2;
      aux2 = aux;
      aux = aux->direction[1];
      continue;
    }
    /* NE */
    if (x < aux->x && y > aux->y) {
      region = 3;
      aux2 = aux;
      aux = aux->direction[2];
      continue;
    }
    /* NW */
    if (x > aux->x && y > aux->y) {
      region = 4;
      aux2 = aux;
      aux = aux->direction[3];
      continue;
    }
  }

  return info;
}

ItemQt removeQuadTreeItem(QuadTree tree, double x, double y) {
  Base *base = (Base *)tree;
  ItemQt info = NULL;

  info = removeItem(base, x, y);

  return info;
}

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

void eraseTree(node *tree, eraseItem function) {
  node *aux = tree;
  if (aux != NULL) {
    eraseTree(aux->direction[0], function);
    function(aux->info);
    free(aux);
    eraseTree(aux->direction[1], function);
    eraseTree(aux->direction[2], function);
    eraseTree(aux->direction[3], function);
  }
}

void eraseQuadTree(QuadTree tree, eraseItem function) {
  Base *base = (Base *)tree;
  eraseTree(base->root, function);
  free(base);
}
