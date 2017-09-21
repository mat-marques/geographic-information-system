#include <stdio.h>
#include <stdlib.h>
#include "QuadTree.h"

typedef struct no{
  Item info;
  double x, y;
  struct no *direction[4];
}node;

typedef struct Base{
  int size;
  node *root;
}Base;

QuadTree createQuadTree(){
  Base *base = NULL;

  base = (Base*) malloc(sizeof(Base));
  if(base!=NULL){
    base->root = NULL;
    base->size = 0;
  }
  return base;
}


void insert(node *element, node *newElement){
  node *aux = NULL, *aux2 = NULL;
  aux = element;
  while(aux != NULL){
    aux2 = aux;
    /* SE */
    if(newElement->x < aux->x && newElement->y < aux->y){
      aux = aux->direction[0];
      continue;
    }
    /* SW */
    if(newElement->x > aux->x && newElement->y < aux->y){
      aux = aux->direction[1];
      continue;
    }
    /* NE */
    if(newElement->x < aux->x && newElement->y > aux->y){
      aux = aux->direction[2];
      continue;
    }
    /* NW */
    if(newElement->x > aux->x && newElement->y > aux->y){
      aux = aux->direction[3];
      continue;
    }
  }

  if(newElement->x < aux2->x && newElement->y < aux2->y){
    aux2->direction[0] = newElement;
  }else
  /* SW */
  if(newElement->x > aux2->x && newElement->y < aux2->y){
    aux2->direction[1] = newElement;
  }else
  /* NE */
  if(newElement->x < aux2->x && newElement->y > aux2->y){
    aux2->direction[2] = newElement;
  }else {
    /* NW */
    if (newElement->x > aux2->x && newElement->y > aux2->y) {
      aux2->direction[3] = newElement;
    }
  }

}


void insertQuadTree(QuadTree tree, Item item, double x, double y){
  Base *base = (Base *) tree;
  node *aux;
  int i;
  if(base!=NULL){
    base->size = base->size + 1;
    aux = (node*) malloc(sizeof(node));
    aux->info = item;
    aux->x = x;
    aux->y = y;
    for(i = 0; i < 4; i++){
      aux->direction[i] = NULL;
    }
    if(base->root != NULL){
      insert(base->root, aux);
    }else{
      base->root = aux;
    }

  }


}


void show(node *tree, showItem function){
  node *aux = tree;
  if(aux!=NULL){
    show(aux->direction[0], function);
    function(aux->info);
    show(aux->direction[1], function);
    show(aux->direction[2], function);
    show(aux->direction[3], function);
  }
}


void showQuadTree(QuadTree tree, showItem function){
  Base *base = (Base*) tree;
  show(base->root, function);
}


Item removeItem(node *tree, double x, double y){
  Item info = NULL;
  node *aux = tree;
    while(aux != NULL){
        if(x == aux->x && y == aux->y){
            
            break;
        }
        /* SE */
        if(x < aux->x && y < aux->y){
            aux = aux->direction[0];
            continue;
        }
        /* SW */
        if(x > aux->x && y < aux->y){
            aux = aux->direction[1];
            continue;
        }
        /* NE */
        if(x < aux->x && y > aux->y){
            aux = aux->direction[2];
            continue;
        }
        /* NW */
        if(x > aux->x && y > aux->y){
            aux = aux->direction[3];
            continue;
        }
    }

  return info;
}


Item removeQuadTreeItem(QuadTree tree, double x, double y){
    Base *base = (Base*) tree;
    Item info = NULL;

    info = removeItem(base->root, x, y);

    return info;
}

void searchItem(node *tree, Item item, void** info, compareTo function){
    node *aux = tree;
    if(aux!=NULL && *info == NULL) {
        if (function(item, aux->info) == 1) {
            *info = aux->info;
        } else{
            searchItem(aux->direction[0], item, info, function);

            searchItem(aux->direction[1], item, info, function);

            searchItem(aux->direction[2], item, info, function);

            searchItem(aux->direction[3], item, info, function);
        }

    }

}

Item searchQuadTreeItem(QuadTree tree, Item item, compareTo function){
    Base *base = (Base*) tree;
    Item info = NULL;

    searchItem(base->root, item, &info, function);

    return info;
}


Item searchByCoordinate(node *tree, double x, double y){
    Item info = NULL;
    node *aux = tree;
    while(aux!=NULL) {
        if(x == aux->x && y == aux->y){
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

Item searchQuadTreeByCoordinate(QuadTree tree, double x, double y){
    Base *base = (Base*) tree;
    Item info = NULL;

    info = searchByCoordinate(base->root, x, y);

    return info;
}

void eraseTree(node *tree, eraseItem function){
  node *aux = tree;
  if(aux!=NULL){
    eraseTree(aux->direction[0], function);
    function(aux->info);
    free(aux);
    eraseTree(aux->direction[1], function);
    eraseTree(aux->direction[2], function);
    eraseTree(aux->direction[3], function);
  }
}


void eraseQuadTree(QuadTree tree, eraseItem function){
    Base *base = (Base*) tree;
    eraseTree(base->root, function);
    free(base);
}
