#ifndef Node_H
#define Node_H

struct Node_t{
 struct Node_t *left;
 struct Node_t *right;
 int weight;
 int data;
};

typedef struct Node_t node;

void insertNode(node *head,node *newNode);
node* createNode(int data);
void preorderNode(node *root);
//void testAssertEqualDataInTree(int Arr[],int index,node*root,int lineNo)
void initializeHead(node* head);

#endif // Node_H
