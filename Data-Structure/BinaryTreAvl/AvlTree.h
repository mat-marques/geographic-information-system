#ifndef AVLTREE_H
#define AVLTREE_H

typedef void* avlTree;
typedef void* Item;
typedef int(*compareTo)(Item, Item);
typedef void(*showItem)(Item);
typedef int(*equalTo)(Item, Item);
typedef void(*eraseItem)(Item);

avlTree createAvlTree();

void insertAvlTree(avlTree tree, Item item, compareTo func);

void removeAvlTreeItem(avlTree tree, Item item, compareTo func1, eraseItem func2);

Item removeAvlItem(avlTree tree, Item item, compareTo func1);

Item searchAvlItem(avlTree tree, Item item, compareTo func1, equalTo func2);

void showAvlTree(avlTree tree, compareTo func1, showItem func);

void eraseAvlTree(avlTree tree, compareTo func1, eraseItem func2);

#endif
