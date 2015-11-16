#ifndef Avl_H
#define Avl_H

#include "Node.h"

int avlAdd(Node** root, Node* newNode);
void editBalFactorForAvlAddLRrotate(Node** root);
void editBalFactorForAvlAddRrotate(Node** root);
void editBalFactorForAvlAddRLrotate(Node** root);
void editBalFactorForAvlAddLrotate(Node** root);

Node *avlRemove(Node** root, int value , int *heightChange);
void editBalFactorForAvlRovRLrotate(Node** root);
void editBalFactorForAvlRovLRrotate(Node** root);
void editBalFactorForAvlRovRrotate(Node** root);
void editBalFactorForAvlRovLrotate(Node** root);


void rotateTreeForAvlAdd(Node** root, int* change);
void rotateTreeForAvlRemove(Node** root);
#endif // Avl_H


