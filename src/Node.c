#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
node* createNode(int data){
  node *newNode = malloc(sizeof(node));
  
  newNode->right = NULL;
  newNode->left = NULL;
  newNode->weight = 0;
  newNode->data = data;
  return newNode;
}


void insertNode(node *head,node *newNode){
   if (newNode->data < head->data) {
      if (head->left == NULL)
         head->left = newNode;
      else
         insertNode(head->left, newNode);
   }
 
   if (newNode->data > head->data) {
      if (head->right == NULL)
         head->right = newNode;
      else
         insertNode(head->right, newNode);
   }
}

void preorderNode(node *root){
  if(root == NULL){
    return ;
  }
  printf("[%d] ",root->data);
  preorderNode(root->left);
  preorderNode(root->right);  
  
}

//void testAssertEqualDataInTree(int Arr[],int index,node*root,int lineNo){
  
  // if(root!= NULL){
  // testAssertEqualDataInTree(Arr,++index,root->left);
 // UNITY_TEST_ASSERT_EQUAL_INT(Arr[index],root->data,lineNo);
  // printf("[%d] ",root->data);
  // testAssertEqualDataInTree(Arr,++index,root->right,lineNo);
  // }
  
// }
void initializeHead(node* head){
    
  insertNode(head,createNode(30));
  insertNode(head,createNode(110));
  insertNode(head,createNode(20));
  insertNode(head,createNode(80));
  insertNode(head,createNode(150));
  insertNode(head,createNode(70));
  insertNode(head,createNode(90));
  insertNode(head,createNode(130));
  insertNode(head,createNode(100));
  
}