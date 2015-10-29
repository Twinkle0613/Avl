#include "Rotation.h"
#include "Node.h"
#include <stdlib.h>
#define rootRightCh ((*root)->right)
#define rootLeftCh ((*root)->left)

void decBFByOne(Node* root){
   root->balanceFactor = root->balanceFactor - 1;
}

void decBFByTwo(Node* root){
   root->balanceFactor = root->balanceFactor - 2;
}

void incBFByOne(Node* root){
   root->balanceFactor = root->balanceFactor + 1;
}

void incBFByTwo(Node* root){
   root->balanceFactor = root->balanceFactor + 2;
}

void leftRotate(Node** root){ 
  if(rootRightCh->balanceFactor == 0){
    decBFByOne((*root));
  }else{
    decBFByTwo((*root));
  }
   decBFByOne(rootRightCh);
  Node* rightCh = (*root)->right;
  Node* temp = rightCh->left;
  (*root)->right = temp;
  rightCh->left = (*root);
  *root = rightCh;
  
}

void rightRotate(Node** root){
  
  if(rootLeftCh->balanceFactor == 0){
    incBFByOne((*root));
  }else{
    incBFByTwo((*root));
  }
    incBFByOne(rootLeftCh);
  
  Node* leftCh = (*root)->left;
  Node* temp = leftCh->right;
  (*root)->left = temp;
  leftCh->right = (*root);
  (*root) = leftCh;
}


void rightLeftRotate(Node **root){
  rightRotate(&((*root)->right));
  leftRotate(&(*root));
}

void leftRightRotate(Node **root){
  leftRotate(&((*root)->left));
  rightRotate(&(*root));
}
