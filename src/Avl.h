#ifndef Avl_H
#define Avl_H
#include "Node.h"
#include "Rotation.h"

int avlAdd(Node** root, Node* newNode);
void rotateTreeIfBFIsTwo(Node** root, int* change);
#endif // Avl_H
