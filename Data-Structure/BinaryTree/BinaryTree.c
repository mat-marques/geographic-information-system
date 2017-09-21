#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

typedef struct node{
  Item info;
  struct node *left, *right, *father;
}node;

typedef struct Base{
  node *root;
  int size;
}Base;


BinaryTree createBinaryTree(){
  Base *base = (Base*) malloc(sizeof(Base));
  if(base!=NULL){
    base->root = NULL;
    base->size = 0;
  }
  return base;
}

int lengthBinaryTree(BinaryTree tree){
  Base *base = (Base*) tree;
  return base->size;
}

void insertBinaryTree(BinaryTree tree, Item item, compareTo func){
  node *aux = NULL;
  node *aux2 = NULL;
  Base *base = (Base*) tree;
  if(base!=NULL){
    aux = base->root;
    if(aux==NULL){
      /*Insere na raiz da árvore*/
      aux2 = (node*) malloc(sizeof(node));
      aux2->info = item;
      aux2->left = NULL;
      aux2->right = NULL;
      aux2->father = NULL;
      base->root = aux2;
    }else{
        /*Insere uma folha na árvore*/
        while(aux!=NULL){
          aux2 = aux;
          /*Verifica se aux é menor que aux->info. Sub-árvore esquerda*/
          if(func(item, aux->info) == -1){
            if(aux->left == NULL){
              aux2 = (node*) malloc(sizeof(node));
              aux2->info = item;
              aux2->left = NULL;
              aux2->right = NULL;
              aux->left = aux2;
              aux2->father = aux;
              break;
            }
            aux = aux->left;
          } else
          /*aux é maior que aux->info. Sub-árvore direita*/
          {
            if(aux->right == NULL){
              aux2 = (node*) malloc(sizeof(node));
              aux2->info = item;
              aux2->left = NULL;
              aux2->right = NULL;
              aux->right = aux2;
              aux2->father = aux;
              break;
            }
            aux = aux->right;
          }
        }

      }
  }
}

Item isInBinaryTree(BinaryTree tree, Item item, compareTo func1, equalTo func2){
  node *aux = NULL;
  Base *base = (Base*) tree;
  if(base==NULL){
    return NULL;
  }
  aux = base->root;
  while(aux!=NULL){
    /*Verifica se aux e item sao iguais.*/
    if(func2(aux->info, item) == 1){
      break;
    } else
    /*Verifica se item é menor que aux->info.*/
    if(func1(item, aux->info) == -1){
      aux = aux->left;
    } else
    /*Verifica se item é maior que aux->info..*/
    {
      aux = aux->right;
    }
  }
  return aux;
}

void showTreeItem(node *tree, showItem func){
  /*Função recursiva, disponível somente ao projetista do módulo, para mostra cada nó da árvore.*/
  node *aux = tree;
  if(aux!=NULL){
    showTreeItem(aux->left, func);
    func(aux->info);
    showTreeItem(aux->right, func);
  }
}

void showBinaryTreeItem(BinaryTree tree, showItem func){
  /*Função disponivel ao usuário para mostra todos os nós da árvore.*/
  Base *base = (Base*) tree;
  showTreeItem(base->root, func);
}

void rmItem(Base *tree, node *aux, int subTree){
  /*Função que remove um item da árvore. Disponível apenas ao projetista do módulo.*/

  node *aux2;
    /*Se subTree == 0, então aux é raiz da árvore.*/
    /*Se subTree == 1, então aux esta a direita do nó father.*/
    /*Se subTree == -1, então aux esta a esquerda do nó father.*/

  /*Elemento aux não possui c.*/
  if(aux->left == NULL && aux->right == NULL){
    /*Comparações necessárias para determinar se o aux->father esta a direita de aux, esquerda de aux ou aux é a raiz da árvore.*/
    if(subTree == 0){
      free(aux);
      tree->root = NULL;
    } else
    if(subTree == -1){
      aux->father->left = NULL;
      free(aux);
    } else {
      aux->father->right = NULL;
      free(aux);
    }

  } else
  /*Elemento aux possui sub-árvores apenas à esquerda.*/
  if(aux->left != NULL && aux->right == NULL){
    /*Comparações necessárias para determinar se o aux->father esta a direita de aux, esquerda de aux ou aux é a raiz da árvore.*/
    if(subTree == 0){
      aux->left->father = NULL;
      tree->root = aux->left;
      free(aux);
    } else
    if(subTree == -1){
      aux->father->left = aux->left;
      free(aux);
    } else {
      aux->father->right = aux->left;
      free(aux);
    }

  } else
  /*Elemento aux possui sub-árvores apenas à direita.*/
  if(aux->left == NULL && aux->right != NULL){

    /*Comparações necessárias para determinar se o aux->father esta a direita de aux, esquerda de aux ou aux é a raiz da árvore.*/
    if(subTree == 0){
      aux->right->father = NULL;
      tree->root = aux->right;
      free(aux);
    } else
    if(subTree == -1){
      aux->father->left = aux->right;
      free(aux);
    } else {
      aux->father->right = aux->right;
      free(aux);
    }

  } else {
    /*Elemento aux possui sub-árvores na esquerda e direita.*/
    /*Busca o nó na sub-árvore esquerda de aux mais a direita.*/
    aux2 = aux->left;
    if(aux2->left!=NULL){
      while(aux2->right!=NULL){
        aux2 = aux2->right;
      }
      aux2->father->right = NULL;
    }else{
      aux2->father->left = NULL;
    }

    /*Comparações necessárias para determinar se o aux->father esta a direita de aux, esquerda de aux ou aux é a raiz da árvore.*/
    if(subTree == 0){
      aux2->left = aux->left;
      aux2->right = aux->right;
      aux2->father = NULL;
      free(aux);
    } else
    {   /*Exclui um nó(aux) na esquerda ou direita.*/
      aux2->left = aux->left;
      aux2->right = aux->right;
      aux2->father = aux->father;
      free(aux);
    }

  }

}

void removeBinaryTreeItem1(BinaryTree tree, Item item, compareTo func1, equalTo func2, eraseItem func3){
  node *aux = NULL;
  /*0 == raiz. -1 = sub-árvore esquerda. 1 = sub-árvore direita.*/
  int subTree = 0;
  Base *base = (Base*) tree;
  if(base!=NULL){
    aux = base->root;
    while(aux!=NULL){
      /*Verifica se aux e item sao iguais.*/
      if(func2(aux->info, item) == 1){
        func3(aux->info);
        rmItem(base, aux, subTree);
        break;
      } else
      /*Verifica se aux é menor que aux->info. Sub-árvore esquerda*/
      if(func1(item, aux->info) == -1){
        aux = aux->left;
        subTree = -1;
      } else
      /*Verifica se aux é menor que aux->info. Sub-árvore direita*/
      {
        aux = aux->right;
        subTree = 1;
      }
    }
  }
}

Item removeBinaryTreeItem2(BinaryTree tree, Item item, compareTo func1, equalTo func2){
  node *aux = NULL;
  int subTree = 0; /*0 == raiz. -1 = desceu sub-árvore esquerda. 1 = desceu sub-árvore direita.*/
  Base *base = (Base*) tree;
  Item info = NULL;
  if(base!=NULL){
    aux = base->root;
    while(aux!=NULL){
      /*Verifica se aux e item sao iguais.*/
      if(func2(aux->info, item) == 1){
        info = aux->info;
        rmItem(base, aux, subTree);
        break;
      } else
      /*Verifica se aux é menor que aux->info. Sub-árvore esquerda*/
      if(func1(item, aux->info) == -1){
        aux = aux->left;
        subTree = -1;
      } else
      /*Verifica se aux é menor que aux->info. Sub-árvore direita*/
      {
        aux = aux->right;
        subTree = 1;
      }
    }
  }
  return info;
}

void eraseTree(node *tree, eraseItem func){
  node *aux = tree;
  /*Função recursiva para apagar todos os nós da árvore. Disponivel apenas para o projetista do módulo.*/
  if(aux!=NULL){
    eraseTree(aux->left, func);
    func(aux->info);
    free(aux);
    eraseTree(aux->right, func);
  }
}

void eraseBinaryTree(BinaryTree tree, eraseItem func){
  Base *base = (Base*) tree;
  eraseTree(base->root, func);
  free(base);
}
