#include "Rotation.c"
#include "Avl.h"
#include "Node.h"



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
   rotateTreeIfBFIsTwo(root,&change);
  return change;
}


void rotateTreeIfBFIsTwo(Node** root, int* change){
  
    if((*root)->balanceFactor == 2){
      if( rootRightCh->balanceFactor == -1){
        //rightLeftRotate(&(*root)); 
     }else{
        leftRotate(&(*root));        
      }
      *change = 0;
  }else if((*root)->balanceFactor == -2){
    
      if( rootLeftCh->balanceFactor == 1){
        //leftRightRotate(&(*root)); 
      }else{
        rightRotate(&(*root));        
      }
      *change = 0;
  }
  
  
}