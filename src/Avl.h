#ifndef Avl_H
#define Avl_H
#include "Node.h"
#include "Rotation.h"

int avlAdd(Node** root, Node* newNode);
void rotateTreeIfBFIsTwo(Node** root, int* change);
void balanceFactorForLRrotate(Node** root);
void balanceFactorForRrotate(Node** root);
void balanceFactorForRLrotate(Node** root);
void balanceFactorForLrotate(Node** root);
Node *avlRemove(Node** root, int value , int *heightChange);
#endif // Avl_H
