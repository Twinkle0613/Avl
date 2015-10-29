#ifndef Node_H
#define Node_H
#include "unity.h"

struct Node_t{
 struct Node_t *left;
 struct Node_t *right;
 int balanceFactor;
 int data;
};

typedef struct Node_t Node;

void insertNode(Node *head,Node *newNode);
Node* createNode(int data);
Node* createTree(void);
void InorderNode(Node *root);
void initializeTree(Node* head);
void initializeTreeForLRrotateTest(Node* head);
void setArrToTree(int Arr[],Node* head);
void setNode(int weight,Node* root ,Node* leftNode,Node* rightNode);
#endif // Node_H
