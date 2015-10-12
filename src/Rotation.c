#include "Rotation.h"
#include "Node.h"
#include <stdlib.h>
// void leftRightRotate(){}
// void rightLeftRotate(){}
// void leftRotate(){}

void swap(int* value1, int* value2){
  int temp;
  temp = *value1;
  *value1 = *value2;
  *value2 = temp; 
}

void rightRotate (node* root){ 
  node* letfCh = root->left;
  node* rightCh = root->right;
  node* temp = rightCh->left;
  rightCh->left = NULL;
  root->right = temp;
  rightCh->left = root;
  root = rightCh;
}

