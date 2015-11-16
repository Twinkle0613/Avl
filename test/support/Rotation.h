#ifndef Rotation_H
#define Rotation_H

#include "unity.h"
#include "Node.h"

#define rootRightCh ((*root)->right)
#define rootLeftCh ((*root)->left)

void leftRotate(Node** root);
void rightRotate(Node** root);
void rightLeftRotate(Node **root);
void leftRightRotate(Node **root);
void decBFByOne(Node* root);
void decBFByTwo(Node* root);
void incBFByOne(Node* root);
void incBFByTwo(Node* root);


#endif // Rotation_H
