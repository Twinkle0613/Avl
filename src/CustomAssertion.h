#ifndef CustomAssertion_H
#define CustomAssertion_H
#include "Node.h"

#include "unity.h"

#define TEST_ASSERT_EQUAL_NODE(root,leftNode,rightNode,balanceFactor){       \
 customTestAssertEqualNode(root,leftNode,rightNode,balanceFactor,__LINE__);  \
}


#define CUSTOM_TEST_FAIL(lineNo,msg,...)                        \
        {                                                       \
         char buffer[256];                                      \
         sprintf(buffer,msg, ## __VA_ARGS__);                   \
         UNITY_TEST_FAIL(lineNo,buffer);                        \
        }
        
void customTestAssertAvlTree(Node* root, int numOfNodes, int height, int lineNo);
void checkNodeValueAndChildValue(Node* root,int lineNo);
void checkBalFactorRange(Node* root,int lineNo);
int countNode(Node *root);

#define TEST_ASSERT_AVL_TREE(root,numOfNodes,height){         \
  customTestAssertAvlTree(root,numOfNodes,height,__LINE__);   \
}
        

        
#endif // CustomAssertion_H
