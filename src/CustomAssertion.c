#include "CustomAssertion.h"
#include "Node.h"




void customTestAssertEqualNode(Node* root,Node* leftNode, Node* rightNode, int balanceFactor,int lineNo){
      UNITY_TEST_ASSERT_NOT_NULL(root,lineNo,"The Node should not be NULL!");
      UNITY_TEST_ASSERT_EQUAL_INT(root->left,leftNode, lineNo,"The left child is wrong.");
      UNITY_TEST_ASSERT_EQUAL_INT(root->right,rightNode, lineNo,"The right child is wrong.");
      UNITY_TEST_ASSERT_EQUAL_INT(root->balanceFactor,balanceFactor, lineNo,"The balanceFactor is not correct."); 
}