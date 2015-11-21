#include "unity.h"
#include "CustomAssertion.h"
#include "Node.h"

Node node5;
Node node10;
Node node20;
Node node30;
Node node40;
Node node50;
Node node55;
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
  resetNode(&node55,55);
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
//---------------------Test_countNode-------------------
/**
 *             80
 *           /   \
 *         50    130
 *        / \    / \
 *      40  70 120  140
 *     / \
 *   30  55
 *
 */


void test_countNode_given_9_node(void){
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node130);
  setNode(0,root->right,&node120,&node140);
  setNode(0,root->left,&node40,&node70);
  setNode(0,&node40,&node30,&node55);
  TEST_ASSERT_EQUAL(9,countNode(root));
}

/**
 *             80
 *           /   \
 *         50    130
 *        / \    / \
 *      40  70 120  140
 *       \
 *       55
 *
 */


void test_countNode_given_8_node(void){
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node130);
  setNode(0,root->right,&node120,&node140);
  setNode(0,root->left,&node40,&node70);
  setNode(0,&node40,NULL,&node55);
  TEST_ASSERT_EQUAL(8,countNode(root));
}

/**
 *             80
 *           /   \
 *         NULL  NULL
 *
 */


void test_countNode_given_1_node(void){
  Node* root;
  root = createNode(80);

  TEST_ASSERT_EQUAL(1,countNode(root));
}

/**
 *             80
 *           /   \
 *         50    130
 *        /      / 
 *      40     120  
 *       \
 *       55
 *
 */

void test_countNode_given_6_node(void){
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node130);
  setNode(0,root->right,&node120,NULL);
  setNode(0,root->left,&node40,NULL);
  setNode(0,&node40,NULL,&node55);
  TEST_ASSERT_EQUAL(6,countNode(root));
}

//----------------Test_checkBalFactorRange---------------


/**
 *             80
 *           /   \
 *         50    130
 *        / \    / \
 *      40  70 120  140
 *     / \
 *   30  55
 *
 */

void test_checkBalFactorRange_the_all_of_balance_factor_of_node_is_0(void){
  
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node130);
  setNode(0,root->right,&node120,&node140);
  setNode(0,root->left,&node40,&node70);
  setNode(0,&node40,&node30,&node55);
  checkBalFactorRange(root,__LINE__);
}

/**
 *             80(-1)
 *           /   \
 *     (-1)50    130(1)
 *        /       \
 *      40        140
 *    
 *   
 *
 */

void test_checkBalFactorRange_given_some_of_balance_factor_of_node_is_1_and_negative_1(void){
  Node* root;
  root = createNode(80);
  setNode(-1,root,&node50,&node130);
  setNode(-1,&node50,&node40,NULL);
  setNode(1,&node130,NULL,&node140);
  checkBalFactorRange(root,__LINE__);
}

/**
 *             80(0)
 *           /   \
 *     (-3)50    130(1)
 *        / \     \
 *   (-2)40  60    140
 *     /    
 *   30
 *   /
 * 10
 */

void test_checkBalFactorRange_given_some_of_balance_factor_of_node_is_1_and_negative_3(void){
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node130);
  setNode(-1,&node50,&node40,NULL);
  setNode(1,&node130,NULL,&node140);
  setNode(0,&node40,&node30,NULL);
  setNode(-1,&node30,&node10,NULL);
  setNode(1,&node140,NULL,NULL);
  checkBalFactorRange(root,__LINE__);
}


//--------------------test_checkNodeValueAndChildValue---------------

/**
 *             80
 *           /   \
 *         50    130
 *        / \    / \
 *      40  70 120  140
 *     / \
 *   30  55
 *
 */

void test_test_checkNodeValueAndChildValue_no_error(void){
  
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node130);
  setNode(0,root->right,&node120,&node140);
  setNode(0,root->left,&node40,&node70);
  setNode(0,&node40,&node30,&node55);
  checkNodeValueAndChildValue(root,__LINE__);
}


/**
 *             80
 *              \
 *               70
 *
 */

void test_test_checkNodeValueAndChildValue_error_rightCh_value_large_than_node_value_(void){
  
  Node* root;
  root = createNode(80);
  setNode(0,root,NULL,&node70);
  checkNodeValueAndChildValue(root,__LINE__);
}

/**
 *             80
 *           /   
 *         100    
 *
 */

void test_test_checkNodeValueAndChildValue_error_leftCh_value_smaller_than_node_value_(void){
  
  Node* root;
  root = createNode(80);
  setNode(0,root,&node100,NULL);
  checkNodeValueAndChildValue(root,__LINE__);
}


/**
 *             80
 *           /    \
 *         50     100
 *        / \     /  
 *      30   60 120
 *
 *
 */
void test_test_checkNodeValueAndChildValue_error_leftCh_value_smaller_than_node_value_give_node60(void){
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node100);
  setNode(0,&node50,&node30,&node60);
  setNode(0,&node100,&node120,NULL);
  checkNodeValueAndChildValue(root,__LINE__);
}

/**
 *             80
 *           /    \
 *         50     100
 *        / \     / \  
 *      30   60 90  70
 *
 */
void test_test_checkNodeValueAndChildValue_error_rightCh_value_large_than_node_value_give_node70(void){
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node100);
  setNode(0,&node50,&node30,&node60);
  setNode(0,&node100,&node90,&node70);
  checkNodeValueAndChildValue(root,__LINE__);
}
 
 /**
 *             80
 *           /    \
 *         50     100
 *        / \     / \  
 *      30  40  90   110
 *
 */
void test_test_checkNodeValueAndChildValue_error_rightCh_value_large_than_node_value_give_node40(void){
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node100);
  setNode(0,&node50,&node30,&node40);
  setNode(0,&node100,&node90,&node110);
  checkNodeValueAndChildValue(root,__LINE__);
}
 
  /**
 *             80
 *           /    \
 *         50     100
 *        / \     / \  
 *      60  70  90   110
 *
 */
void test_test_checkNodeValueAndChildValue_error_rightCh_value_large_than_node_value_give_node60(void){
  Node* root;
  root = createNode(80);
  setNode(0,root,&node50,&node100);
  setNode(0,&node50,&node60,&node70);
  setNode(0,&node100,&node90,&node110);
  checkNodeValueAndChildValue(root,__LINE__);
}
 