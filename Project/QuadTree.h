#ifndef QUADTREE_H
#define QUADTREE_H

typedef void* QuadTree;
typedef void* ItemQt;
typedef void (*showItem)(ItemQt);
typedef void (*eraseItem)(ItemQt);
typedef int (*compareToQt)(ItemQt, ItemQt);


QuadTree createQuadTree();


void insertQuadTree(QuadTree tree, ItemQt item, double x, double y);


void showQuadTree(QuadTree tree, showItem function);


ItemQt removeQuadTreeItem(QuadTree tree, double x, double y);


ItemQt searchQuadTreeItem(QuadTree tree, ItemQt item, compareToQt function);


ItemQt searchQuadTreeByCoordinate(QuadTree tree, double x, double y);


void eraseQuadTree(QuadTree tree, eraseItem function);

#endif
