#ifndef QUADTREE_H
#define QUADTREE_H

typedef void* QuadTree;
typedef void* Item;
typedef void(*showItem)(Item);
typedef void(*eraseItem)(Item);
typedef int(*compareTo)(Item, Item);


QuadTree createQuadTree();


void insertQuadTree(QuadTree tree, Item item, double x, double y);


void showQuadTree(QuadTree tree, showItem function);


Item removeQuadTreeItem(QuadTree tree, double x, double y);


Item searchQuadTreeItem(QuadTree tree, Item item, compareTo function);


Item searchQuadTreeByCoordinate(QuadTree tree, double x, double y);


void eraseQuadTree(QuadTree tree, eraseItem function);

#endif
