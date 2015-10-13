#include "Rotation.h"
#include "Node.h"
#include <stdlib.h>
// void leftRightRotate(){}
// void rightLeftRotate(){}
// void leftRotate(){}


void leftRotate(node** root){ 
  node* rightCh = (*root)->right;
  node* temp = rightCh->left;
  (*root)->right = temp;
  rightCh->left = (*root);
  *root = rightCh;
}

void rightRotate(node** root){
  node* leftCh = (*root)->left;
  node* temp = leftCh->right;

  (*root)->left = temp;
  leftCh->right = (*root);
  (*root) = leftCh;
}


void rightLeftRotate(node **root){
  rightRotate(&((*root)->right));
  leftRotate(&(*root));
}

void leftRightRotate(node **root){
  leftRotate(&((*root)->left));
  rightRotate(&(*root));
}

