#include "CustomAssertion.h"
#include "Node.h"




void customTestAssertEqualNode(Node* root,Node* leftNode, Node* rightNode, int balanceFactor,int lineNo){
      UNITY_TEST_ASSERT_NOT_NULL(root,lineNo,"The Node should not be NULL!");
      UNITY_TEST_ASSERT_EQUAL_INT(leftNode,root->left, lineNo,"The left child is wrong.");
      UNITY_TEST_ASSERT_EQUAL_INT(rightNode,root->right, lineNo,"The right child is wrong.");
      UNITY_TEST_ASSERT_EQUAL_INT(balanceFactor,root->balanceFactor, lineNo,"The balanceFactor is not correct."); 
}