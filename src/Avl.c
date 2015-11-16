#include "Avl.h"
#include "Node.h"
#include <stdlib.h>
#include "Rotation.h"

#define rootBalFactor ((*root)->balanceFactor)
#define returnOne {return 1;}
#define returnZero {return 0;}
#define returnOneIfBFIsNegOrPosOne(root) {((*root)->balanceFactor == -1 || (*root)->balanceFactor == 1)?(returnOne):(returnZero);}


int avlAdd(Node** root, Node* newNode){
  int change; 
  if((*root)->data > newNode->data && (*root)->left == NULL ){
    (*root)->left = newNode; 
    decBFByOne((*root));    
    returnOneIfBFIsNegOrPosOne(root);
  }else if((*root)->data < newNode->data && (*root)->right == NULL ){
   (*root)->right = newNode;
    incBFByOne((*root));  
    returnOneIfBFIsNegOrPosOne(root);
  }else if( (*root)->data > newNode->data ){
   change = avlAdd(&(*root)->left,newNode);
   if(change){
     decBFByOne((*root));
   }
  }else{
   change = avlAdd(&(*root)->right,newNode);
   if(change){
     incBFByOne((*root));
   }
  }
   rotateTreeForAvlAdd(root,&change);
  return change;
}

void rotateTreeForAvlAdd(Node** root, int* change){
  if((*root)->balanceFactor == 2){
      if( rootRightCh->balanceFactor == -1){
        editBalFactorForAvlAddRLrotate(root);
        rightLeftRotate(root); 
      }else{
        editBalFactorForAvlAddLrotate(root);
        leftRotate(root);        
      }
      *change = 0;
  }else if((*root)->balanceFactor == -2){

      if( rootLeftCh->balanceFactor == 1){
        editBalFactorForAvlAddLRrotate(root);
        leftRightRotate(root); 
      }else{
            
        editBalFactorForAvlAddRrotate(root);
        rightRotate(root);        
      }
      *change = 0;
  }
}



void editBalFactorForAvlAddLRrotate(Node** root){
  if( (*root)->left->right->balanceFactor == -1){
    (*root)->balanceFactor = 1;                 //double circle 
    (*root)->left->balanceFactor = 0;           //flower
    (*root)->left->right->balanceFactor = 0;    //durian
  }else if ( (*root)->left->right->balanceFactor == 1){
    (*root)->balanceFactor = 0;                 //double circle
    (*root)->left->balanceFactor = -1;          //flower
    (*root)->left->right->balanceFactor = 0;    //durian 
  }else{
    (*root)->balanceFactor = 0;                 //double circle
    (*root)->left->balanceFactor = 0;           //flower
    (*root)->right->left->balanceFactor = 0;    //durian 
  }
}

void editBalFactorForAvlAddRrotate(Node** root){
  if(rootLeftCh->balanceFactor == 0){
    incBFByOne((*root));
  }else{
    incBFByTwo((*root));
  }
    incBFByOne(rootLeftCh);
}

void editBalFactorForAvlAddLrotate(Node** root){
  if(rootRightCh->balanceFactor == 0){
    decBFByOne((*root));
  }else{
    decBFByTwo((*root));
  }
    decBFByOne(rootRightCh);
}

void editBalFactorForAvlAddRLrotate(Node** root){
  if( (*root)->right->left->balanceFactor == 1){
    (*root)->balanceFactor = -1;              //double circle 
    (*root)->right->balanceFactor = 0;        //flower
    (*root)->right->left->balanceFactor = 0;  //durian
  }else if ( (*root)->right->left->balanceFactor == -1){
    (*root)->balanceFactor = 0;                //double circle
    (*root)->right->balanceFactor = 1;         //flower
    (*root)->right->left->balanceFactor = 0;   //durian
  }else{
    (*root)->balanceFactor = 0;                //double circle 
    (*root)->right->balanceFactor = 0;         //flower
    (*root)->right->left->balanceFactor = 0;   //durian
  }
}



Node *avlRemove(Node** root, int value , int *heightChange){
     Node* temp;
    if( value == (*root)->data ){
      temp = (*root);
      (*root) = NULL;
      *heightChange = 1;
      return temp;  
    }else if( (*root) == NULL){
      return NULL;
    }else if( value > (*root)->data ){
     temp = avlRemove( &(*root)->right , value , heightChange );
      if( *heightChange ==  1 ){
      --((*root)->balanceFactor);
      }
     rotateTreeForAvlRemove(root);
    }else if ( value < (*root)->data){
     temp = avlRemove( &(*root)->left , value , heightChange );
     if( *heightChange ==  1){
      ++((*root)->balanceFactor);
      }
      rotateTreeForAvlRemove(root);
    }
    return temp;
}

void rotateTreeForAvlRemove(Node** root){
  switch( (*root)->balanceFactor ){
     case 2:
      if( (*root)->right->balanceFactor == -1 ){
        rightLeftRotate(root); 
        editBalFactorForAvlRovRLrotate(root);
      }else{
        leftRotate(root); 
        editBalFactorForAvlRovLrotate(root);
      }
     break;
    case -2:
    
      if((*root)->left->balanceFactor == 1){
        leftRightRotate(root); 
        editBalFactorForAvlRovLRrotate(root);
      }else{
        rightRotate(root); 
        editBalFactorForAvlRovRrotate(root);
      }
    break;
     default:break;
   }
}

void editBalFactorForAvlRovRLrotate(Node** root){
  if( (*root)->balanceFactor == 0 ){
    (*root)->balanceFactor = 0;
    (*root)->left->balanceFactor = 0;
    (*root)->right->balanceFactor = 0;
  }else if( (*root)->balanceFactor  == 1 ){
    (*root)->balanceFactor = 0;
    (*root)->left->balanceFactor = -1;
    (*root)->right->balanceFactor = 0;
  }else if( (*root)->balanceFactor  == -1 ){
    (*root)->balanceFactor = 0;
    (*root)->left->balanceFactor = 0;
    (*root)->right->balanceFactor = 1;
  }
}
void editBalFactorForAvlRovLRrotate(Node** root){
  if( (*root)->balanceFactor  == 0 ){
    (*root)->balanceFactor = 0;
    (*root)->left->balanceFactor = 0;
    (*root)->right->balanceFactor = 0;
  }else if( (*root)->balanceFactor  == 1 ){
    (*root)->balanceFactor = 0;
    (*root)->left->balanceFactor = -1;
    (*root)->right->balanceFactor = 0;
  }else if( (*root)->balanceFactor  == -1 ){
    (*root)->balanceFactor = 0;
    (*root)->left->balanceFactor = 0;
    (*root)->right->balanceFactor = 1;
  }
}

void editBalFactorForAvlRovLrotate(Node** root){
  if( (*root)->balanceFactor == 1){
    (*root)->balanceFactor = 0;
    (*root)->left->balanceFactor = 0;
  }else{
    (*root)->balanceFactor = -1;
    (*root)->left->balanceFactor = 1;
  }
}

void editBalFactorForAvlRovRrotate(Node** root){
  if( (*root)->balanceFactor == -1){
    (*root)->balanceFactor = 0;
    (*root)->right->balanceFactor = 0;
  }else{
    (*root)->balanceFactor = 1;
    (*root)->right->balanceFactor = -1;
  }
}






