#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "unity.h"

#define getArrSize(Arr) (sizeof(Arr)/sizeof(Arr[0]))

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

void InorderNode(node *root){
  if(root == NULL){
    return ;
  }
  printf("[%d] ",root->data);
  InorderNode(root->left);
  InorderNode(root->right);  
}

void initializeTree(node* head){

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

void initializeTreeForLRrotateTest(node* head){

  insertNode(head,createNode(80));
  insertNode(head,createNode(180));
  insertNode(head,createNode(50));
  insertNode(head,createNode(100));
  insertNode(head,createNode(200));
  insertNode(head,createNode(30));
  insertNode(head,createNode(60));
  insertNode(head,createNode(110));

}