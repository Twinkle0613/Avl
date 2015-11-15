#include "Rotation.c"
#include "Avl.h"
#include "Node.h"
#include <stdlib.h>

#define rootBalFactor ((*root)->balanceFactor)
#define returnOne {return 1;}
#define returnZero {return 0;}
#define returnOneIfBFIsNegOrPosOne(root) {((*root)->balanceFactor == -1 || (*root)->balanceFactor == 1)?(returnOne):(returnZero);}
// #define avlRemove(root,value,heightChange) {     \
  // Node *temp = _avlRemove(&root,value,heightChange);          \
  // rotateTreeForAvlRemove(&root);             \
  // return temp;
// }

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


void balanceFactorForLRrotate(Node** root){
  
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

void balanceFactorForRrotate(Node** root){
  if(rootLeftCh->balanceFactor == 0){
    incBFByOne((*root));
  }else{
    incBFByTwo((*root));
  }
    incBFByOne(rootLeftCh);
       
}
void balanceFactorForLrotate(Node** root){
  
  if(rootRightCh->balanceFactor == 0){
    decBFByOne((*root));
  }else{
    decBFByTwo((*root));
  }
    decBFByOne(rootRightCh);
  
}
void balanceFactorForRLrotate(Node** root){
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



void rotateTreeIfBFIsTwo(Node** root, int* change){
  if((*root)->balanceFactor == 2){
      if( rootRightCh->balanceFactor == -1){
        balanceFactorForRLrotate(&(*root));
        rightLeftRotate(&(*root)); 
      }else{
        balanceFactorForLrotate(&(*root));
        leftRotate(&(*root));        
      }
      *change = 0;
  }else if((*root)->balanceFactor == -2){

      if( rootLeftCh->balanceFactor == 1){
        balanceFactorForLRrotate(&(*root));
        leftRightRotate(&(*root)); 
      }else{
            
        balanceFactorForRrotate(&(*root));
        rightRotate(&(*root));        
      }
      *change = 0;
  }
}

void rotateTreeForAvlRemove(Node** root){
  //printf("rootBalFactor = %d\n",(*root)->balanceFactor);
  switch( (*root)->balanceFactor ){
     case 2:
      printf("rootBalFactor is 2\n");
         printf("rootRightCh->balanceFactor = %d\n",(*root)->right->balanceFactor);
       switch( (*root)->right->balanceFactor ){
         case -1:
          // rightLeftRotate(root); 
         break;
         case 1:
          // rightRotate(root); 
          // (*root)->balanceFactor = 0;
          // (*root)->left->balanceFactor = 0;
         break;
         case 0:
           rightRotate(&root); 
          // (*root)->balanceFactor = -1;
          // (*root)->left->balanceFactor = 1;
         break;
         default:break;
       }
     break;
    case -2:
      // switch((*root)->left->balanceFactor){
         // case 1:
          // leftRightRotate(root); 
         // break;
         // case -1:
          // leftRotate(root); 
          // (*root)->balanceFactor = 0;
          // (*root)->right->balanceFactor = 0;
         // break;
         // case 0:
          // leftRotate(root); 
          // (*root)->balanceFactor = 1;
          // (*root)->right->balanceFactor = -1;
         // break;
         // default:break;
       // }
    break;
     default:break;
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
    //rotateTreeForAvlRemove(root);
    }else if ( value < (*root)->data){
     temp = avlRemove( &(*root)->left , value , heightChange );
     if( *heightChange ==  1){
      ++((*root)->balanceFactor);
      }
      printf("root->balanceFactor = %d\n",(*root)->balanceFactor);
      rotateTreeForAvlRemove(&(*root));
    }
    return temp;
}

// Node *avlRemove(Node** root, int value, int *heightChange){   
  // printf("Hello\n");
  // Node *temp = _avlRemove(&(*root),value,heightChange);          
  // rotateTreeForAvlRemove(&root);             
  // return temp;
// }