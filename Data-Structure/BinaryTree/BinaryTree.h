#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef void* BinaryTree;
typedef void* Item;
typedef int(*compareTo)(Item, Item);
typedef void(*showItem)(Item);
typedef int(*equalTo)(Item, Item);
typedef void(*eraseItem)(Item);

BinaryTree createBinaryTree();

int lengthBinaryTree(BinaryTree tree);

void insertBinaryTree(BinaryTree tree, Item item, compareTo func);

Item isInBinaryTree(BinaryTree tree, Item item, compareTo func1, equalTo func2);

void showBinaryTreeItem(BinaryTree tree, showItem func);

void removeBinaryTreeItem1(BinaryTree tree, Item item, compareTo func1, equalTo func2, eraseItem func3);

Item removeBinaryTreeItem2(BinaryTree tree, Item item, compareTo func1, equalTo func);

void eraseBinaryTree(BinaryTree tree, eraseItem func);

#endif
