#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "AvlTree.h"

typedef struct node{
  Item info;
  int fb;
  struct node *left, *right;
}node;

typedef struct Base{
  node *root;
  int height;
  int size;
}Base;


int fbNo(node *no){
  if(no==NULL){
    return -1;
  }
  return no->fb;
}

int balancingFactor(node *no){
  return labs(fbNo(no->left) - fbNo(no->right));
}

int gretherThan(int x, int y){
  if(x > y){
    return x;
  }
  return y;
}

void rotationLL(node *root){
  node *aux;
  aux = root->right;
  root->right = aux->left;
  aux->left = root;
  root->fb = gretherThan(fbNo(root->left), fbNo(root->right));
  aux->fb = gretherThan(fbNo(aux->left), fbNo(aux->right));
  root = aux;
}

void rotationRR(node *root){
  node *aux;
  aux = root->left;
  root->left = aux->right;
  aux->right = root;
  root->fb = gretherThan(fbNo(root->left), fbNo(root->right));
  aux->fb = gretherThan(fbNo(aux->left), fbNo(aux->right));
  root = aux;
}

void rotationLR(node *root){
  rotationRR(root->left);
  rotationLL(root);
}

void rotationRL(node *root){
  rotationLL(root->right);
  rotationRR(root);
}
void insertAvlTree(avlTree tree, Item item, compareTo func){

}

void removeAvlTreeItem(avlTree tree, Item item, compareTo func1, eraseItem func2);

Item removeAvlItem(avlTree tree, Item item, compareTo func1);
