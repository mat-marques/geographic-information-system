#ifndef QUADTREE_H
#define QUADTREE_H

#include "DoubleLinkedList.h"
typedef void* QuadTree;
typedef void* ItemQt;
typedef void* Region;
typedef void (*showItem)(ItemQt);
typedef void (*eraseItem)(ItemQt);
typedef int (*compareToQt)(ItemQt, ItemQt);

QuadTree createQuadTree();


void insertQuadTree(QuadTree tree, ItemQt item, double x, double y);


void showQuadTree(QuadTree tree, showItem function);

int lenghtQuadTree(QuadTree tree);

ItemQt removeQuadTreeItem(QuadTree tree, ItemQt item, compareToQt function);


List getElementsByRegion(QuadTree tree, Region region, compareToQt function);


ItemQt searchQuadTreeItem(QuadTree tree, ItemQt item, compareToQt function);


ItemQt searchQuadTreeByCoordinate(QuadTree tree, double x, double y);


void eraseQuadTreeNode(QuadTree tree, eraseItem function);


void eraseQuadTreeBase(QuadTree tree);
#endif
