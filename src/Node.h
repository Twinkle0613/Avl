#ifndef Node_H
#define Node_H
#include "unity.h"

struct Node_t{
 struct Node_t *left;
 struct Node_t *right;
 int weight;
 int data;
};

typedef struct Node_t node;

void insertNode(node *head,node *newNode);
node* createNode(int data);
node* createTree(void);
void InorderNode(node *root);
void initializeTree(node* head);
void initializeTreeForLRrotateTest(node* head);
void setArrToTree(int Arr[],node* head);
#endif // Node_H
