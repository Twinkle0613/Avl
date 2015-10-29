#include "unity.h"
#include "CustomAssertion.h"
#include "Node.h"

Node node5;
Node node10;
Node node20;
Node node30;
Node node40;
Node node50;
Node node60;
Node node70;
Node node80;
Node node90;
Node node100;
Node node110;
Node node120;
Node node140;
Node node130;
Node node150;
Node node160;
Node node170;
Node node180;

void resetNode(Node *node, int val){
  node->data = val;
  node->left = NULL;
  node->right = NULL;
  node->balanceFactor = 0;
}

void setUp(void)
{
  resetNode(&node5,5);
  resetNode(&node10,10);
  resetNode(&node20,20);
  resetNode(&node30,30);
  resetNode(&node40,40);
  resetNode(&node50,50);
  resetNode(&node60,60);
  resetNode(&node70,70);
  resetNode(&node80,80);
  resetNode(&node90,90);
  resetNode(&node100,100);
  resetNode(&node110,110);
  resetNode(&node120,120);
  resetNode(&node130,130);
  resetNode(&node140,140);
  resetNode(&node150,150);
  resetNode(&node160,160);
  resetNode(&node170,170);
  resetNode(&node180,180);
}

void tearDown(void)
{
}
/**
 *             30
 *           /   \
 *         10    100
 *        / \    / \
 *       5   70 80  110
 *
 */


void test_customTestAssertEqualNode(void){
  
  Node* root;
  root = createNode(30);
  setNode(0,root,&node10,&node100);
  setNode(0,root->right,&node80,&node110);
  setNode(0,root->left,&node5,&node70);
  TEST_ASSERT_EQUAL_NODE(root,&node10,&node100,0);
  TEST_ASSERT_EQUAL_NODE(&node100,&node80,&node110,0);
  TEST_ASSERT_EQUAL_NODE(&node10,&node5,&node70,0);

  
}