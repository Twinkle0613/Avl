#include "unity.h"
#include "avlRemove.h"
#include "unity.h"
#include "Avl.h"
#include "Node.h"
#include "CustomAssertion.h"
#include "Rotation.h"


Node node0;
Node node3;
Node node5;
Node node8;
Node node9;
Node node10;
Node node15;
Node node20;
Node node25;
Node node30;
Node node35;
Node node40;
Node node50;
Node node55;
Node node60;
Node node65;
Node node70;
Node node75;
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

void setUp(void){
  resetNode(&node0,0);
  resetNode(&node3,3);
  resetNode(&node5,5);
  resetNode(&node8,8);
  resetNode(&node10,10);
  resetNode(&node15,15);
  resetNode(&node20,20);
  resetNode(&node25,25);
  resetNode(&node30,30);
  resetNode(&node35,35);
  resetNode(&node40,40);
  resetNode(&node50,50);
  resetNode(&node55,55);
  resetNode(&node60,60);
  resetNode(&node65,65);
  resetNode(&node70,70);
  resetNode(&node75,75);
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

void tearDown(void){}

/**                                           
 *             30(0)       -10         30(+1)
 *             / \      ------>        \     
 *           10  60                    60
 *                                    
 *                                    
 */

void test_avlRemove_remove_node60_in_tree(void){
    Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node60,0);
  int heightChange;
  Node *temp = avlRemove(&root,10,&heightChange);
  TEST_ASSERT_EQUAL_PTR(&node10,temp);
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,&node60,1);
  
}

/**                                           
 *             30(0)       -60        30(-1)
 *             / \      ------>       /      
 *           10  60                  10
 *                                    
 *                                    
 */

void test_avlRemove_remove_node10_in_tree(void){
    Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node60,0);
  int heightChange;
  Node *temp = avlRemove(&root,60,&heightChange);
  TEST_ASSERT_EQUAL_PTR(&node60,temp);
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,NULL,-1);
}

/**                                           
 *             30(0)       -5          30(0)
 *             / \      ------>       /   \      
 *       (-1)10  60                  10   60
 *          /                         
 *         5                           
 */

 void test_avlRemove_remove_node5_in_tree(void){
    Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node5);
  int heightChange;
  Node *temp = avlRemove(&root,5,&heightChange);
  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node5,temp);
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node60,0);
}

//------------------------------avlRemove_leftRotation---------------------------
/** 30(+1)60(0)  -> 30(+1)60(-1)                             
 *             30(+1)     -10        30(+2)                   60(-1)
 *             / \      ------>       \        ----->        /  \
 *           10  60(0)                60(0)              (+1)30 70
 *              / \                  /  \                    \
 *             50  70              50   70                   50     
 *
 **/
void test_avlRemove_remove_node5_and_given_the_bal_factor_of_node60_is_0(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node50);   
  cState =avlAdd(&root,&node70);
  
  int heightChange;
  Node *temp = avlRemove(&root,10,&heightChange);
  
  TEST_ASSERT_EQUAL(0,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node10,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node30,&node70,-1);
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,&node50,1);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0);
}
 
 /** 30(+1)60(+1)  -> 30(0)60(0)                                      
 *             30(+1)      -5        30(+2)                     60(0)
 *             / \      ------>     /    \        ----->        /  \
 *           10  60(+1)           10   60(0)                (0)30   70 
 *           /  /  \                   /  \                  /  \    \
 *          5  50  70                50   70               10   50   80  
 *                  \                      \
 *                  80                     80
 *
 *
 **/
 void test_avlRemove_remove_node5_and_given_the_bal_factor_of_node60_is_1_and_given_extra_node80(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node5);
  cState =avlAdd(&root,&node50);   
  cState =avlAdd(&root,&node70);
  cState =avlAdd(&root,&node80);
  
  int heightChange;
  Node *temp = avlRemove(&root,5,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node5,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node30,&node70,0);
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node50,0);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,&node80,1);
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0);
}
 
  /**  30(+1)60(+1)  -> 30(0)60(0)                                        
 *             30(+1)      -5        30(+2)                     60(0)
 *             / \      ------>     /    \        ----->        /    \
 *           10  60(+1)           10   60(0)                (0)30    70 
 *           /  /  \                   /  \                  /  \    /
 *          5  50  70                50   70               10   50  65   
 *                /                      /
 *              65                     65
 *
 *
 **/
 
void test_avlRemove_remove_node5_and_given_the_bal_factor_of_node60_is_1_and_given_extra_node65(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node5);
  cState =avlAdd(&root,&node50);   
  cState =avlAdd(&root,&node70);
  cState =avlAdd(&root,&node65);
  
  int heightChange;
  Node *temp = avlRemove(&root,5,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node5,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node30,&node70,0);
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node50,0);
  TEST_ASSERT_EQUAL_NODE(&node70,&node65,NULL,-1);
  TEST_ASSERT_EQUAL_NODE(&node65,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0);
}


/**  30(+1)60(+1)  -> 30(0)60(0)                                        
 *             30(+1)     -5         30(+2)                     60(0)
 *             / \      ------>     /    \        ----->        /    \
 *           10  60(+1)           10   60(0)                (0)30    70 
 *           /  /  \                   /  \                  /  \    / \
 *          5  50  70                50   70               10   50  65 80  
 *                / \                     / \
 *              65  80                  65  80
 *
 *
 **/
 
 void test_avlRemove_remove_node5_and_given_the_bal_factor_of_node60_is_1_and_given_extra_node65_and_node80(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node5);
  cState =avlAdd(&root,&node50);   
  cState =avlAdd(&root,&node70);
  cState =avlAdd(&root,&node65);
  cState =avlAdd(&root,&node80);
  
  int heightChange;
  Node *temp = avlRemove(&root,5,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node5,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node30,&node70,0);
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node50,0);
  TEST_ASSERT_EQUAL_NODE(&node70,&node65,&node80,0);
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node65,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0);
}
 
 
 //------------------------------avlRemove_rightRotation---------------------------
 
 
 /** 100(-1)60(0)  -> 100(-1)60(+1)                             
 *              100(-1)    -130         100(-2)                     60(+1)
 *             /   \      ------>       /          ----->          /  \
 *         (0)60  130              (0)60                         40   100(-1)
 *           / \                     / \                              /
 *         40  80                  40  80                           80
 *
 **/
void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node60_is_0(void){
  Node *root = &node100;
  int cState =  avlAdd(&root,&node60);
  cState =avlAdd(&root,&node130);
  cState =avlAdd(&root,&node40);
  cState =avlAdd(&root,&node80);   
  
  int heightChange;
  Node *temp = avlRemove(&root,130,&heightChange);

  TEST_ASSERT_EQUAL(0,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node130,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node40,&node100,1);
  TEST_ASSERT_EQUAL_NODE(&node100,&node80,NULL,-1);
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,NULL,0);
}
 
 
 /** 100(-1)60(-1)  -> 100(0)60(0)                             
 *              100(-1)   -140          100(-2)                     60(0)
 *             /   \      ------>       /   \       ----->          /   \
 *        (-1)60  130              (-1)60    130                  40    100(0)
 *           / \    \                / \                           \    / \
 *         40  80  140             40  80                          50  80  130
 *          \                       \
 *          50                      50
 **/
void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node60_is_negetive_1_and_given_extra_node50(void){
  Node *root = &node100;
  int cState =  avlAdd(&root,&node60);
  cState =avlAdd(&root,&node130);
  cState =avlAdd(&root,&node40);
  cState =avlAdd(&root,&node80);   
  cState =avlAdd(&root,&node140);   
  cState =avlAdd(&root,&node50);   
  
  int heightChange;
  Node *temp = avlRemove(&root,140,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node140,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node40,&node100,0);
  TEST_ASSERT_EQUAL_NODE(&node100,&node80,&node130,0);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,&node50,1);
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node130,NULL,NULL,0);
}
  /** 100(-1)60(-1)  -> 100(0)60(0)                             
 *              100(-1)                 100(-2)                     60(0)
 *             /   \      ------>       /   \       ----->          /   \
 *        (-1)60  130              (-1)60    130                  40    100(0)
 *           / \    \                / \                          /     / \
 *         40  80  140             40  80                        30   80  130
 *        /                        /
 *       30                      30
 **/
void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node60_is_negetive_1_and_given_extra_node30(void){
  Node *root = &node100;
  int cState =  avlAdd(&root,&node60);
  cState =avlAdd(&root,&node130);
  cState =avlAdd(&root,&node40);
  cState =avlAdd(&root,&node80);   
  cState =avlAdd(&root,&node140);   
  cState =avlAdd(&root,&node30);   
  
  int heightChange;
  Node *temp = avlRemove(&root,140,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node140,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node40,&node100,0);
  TEST_ASSERT_EQUAL_NODE(&node100,&node80,&node130,0);
  TEST_ASSERT_EQUAL_NODE(&node40,&node30,NULL,-1);
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node130,NULL,NULL,0);
}

  /** 100(-1)60(-1)  -> 100(0)60(0)                             
 *              100(-1)                 100(-2)                     60(0)
 *             /   \      ------>       /   \       ----->          /    \
 *        (-1)60  130              (-1)60    130                  40    100(0)
 *           / \    \                / \                         / \      / \
 *         40  80  140             40  80                      30  50    80  130
 *        /  \                    / \
 *       30  50                 30  50
 **/
 
void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node60_is_negetive_1_and_given_extra_node30_and_node50(void){
  Node *root = &node100;
  int cState =  avlAdd(&root,&node60);
  cState =avlAdd(&root,&node130);
  cState =avlAdd(&root,&node40);
  cState =avlAdd(&root,&node80);   
  cState =avlAdd(&root,&node140);   
  cState =avlAdd(&root,&node30);   
  cState =avlAdd(&root,&node50);   
  
  int heightChange;
  Node *temp = avlRemove(&root,140,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node140,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node40,&node100,0);
  TEST_ASSERT_EQUAL_NODE(&node100,&node80,&node130,0);
  TEST_ASSERT_EQUAL_NODE(&node40,&node30,&node50,0);
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node130,NULL,NULL,0);
}
 
//------------------------------avlRemove_right-left-Rotation---------------------------

/** 30(+1)60(-1)40(0)  -> 30(0)60(0)50(0)                             
 *             30(+1)                30(+2)                   40(0)
 *             / \      ------>     /  \        ----->        /   \
 *           20  60(-1)           20   60(-1)            (0)30    60(0)
 *          /    / \                   /  \                / \    / \
 *        10 (0)40  70              (0)40   70           20  35 50  70    
 *            / \                   / \
 *          35  50                35  50
 **/
void test_avlRemove_remove_node10_and_given_the_bal_factor_of_node40_is_0(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node20);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node10);
  cState =avlAdd(&root,&node40);   
  cState =avlAdd(&root,&node70);
  cState =avlAdd(&root,&node35);
  cState =avlAdd(&root,&node50);
  
  int heightChange;
  Node *temp = avlRemove(&root,10,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node10,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node30,&node60,0);
  TEST_ASSERT_EQUAL_NODE(root->left,&node20,&node35,0);
  TEST_ASSERT_EQUAL_NODE(root->right,&node50,&node70,0);
  TEST_ASSERT_EQUAL_NODE(&node20,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node35,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
}

/** 30(+1)60(-1)40(-1)  -> 30(0)60(+1)50(0)                             
 *             30(+1)                30(+2)                   40(0)
 *             / \      ------>     /  \        ----->        /   \
 *           20  60(-1)           20   60(-1)            (0)30    60(+1)
 *          /    / \                   /  \                / \      \
 *        10 (-1)40  70             (-1)40   70           20  35     70    
 *            /                     / 
 *          35                    35  
 **/

void test_avlRemove_remove_node10_and_given_the_bal_factor_of_node40_is_negative_1(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node20);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node10);
  cState =avlAdd(&root,&node40);   
  cState =avlAdd(&root,&node70);
  cState =avlAdd(&root,&node35);
  
  int heightChange;
  Node *temp = avlRemove(&root,10,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node10,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node30,&node60,0);
  TEST_ASSERT_EQUAL_NODE(root->left,&node20,&node35,0);
  TEST_ASSERT_EQUAL_NODE(root->right,NULL,&node70,1);
  TEST_ASSERT_EQUAL_NODE(&node20,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node35,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
}
 
/** 30(+1)60(-1)40(+1)  -> 30(-1)60(0)50(0)                             
 *             30(+1)                30(+2)                   40(0)
 *             / \      ------>     /  \        ----->        /   \
 *           20  60(-1)           20   60(-1)            (-1)30    60(0)
 *          /    / \                   /   \                /      / \
 *        10 (0)40  70              (+1)40 70             20     50  70    
 *            / \                     \
 *          35  50                    50
 **/
 
 void test_avlRemove_remove_node10_and_given_the_bal_factor_of_node40_is_1(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node20);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node10);
  cState =avlAdd(&root,&node40);   
  cState =avlAdd(&root,&node70);
  cState =avlAdd(&root,&node50);
  
  int heightChange;
  Node *temp = avlRemove(&root,10,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node10,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node30,&node60,0);
  TEST_ASSERT_EQUAL_NODE(root->left,&node20,NULL,-1);
  TEST_ASSERT_EQUAL_NODE(root->right,&node50,&node70,0);
  TEST_ASSERT_EQUAL_NODE(&node20,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
}
 //------------------------------avlRemove_left-right-Rotation---------------------------

 
  /** 100(-1)60(+1)80(0)  -> 100(0)60(0)80(0)                             
 *              100(-1)                  100(-2)                     80(0)
 *             /    \      ------>       /   \       ----->         /    \
 *         (+1)60   130              (+1)60  130                   60(0) 100(0)
 *           / \     \                / \                         / \    / \
 *         40  80(0) 140            40  80(0)                   40  70  90  130
 *            / \                      / \
 *          70  90                   70  90
 *
 **/
 
void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node80_is_0(void){
  Node *root = &node100;
  int cState =  avlAdd(&root,&node60);
  cState =avlAdd(&root,&node130);
  cState =avlAdd(&root,&node40);
  cState =avlAdd(&root,&node80);   
  cState =avlAdd(&root,&node140);   
  cState =avlAdd(&root,&node70);   
  cState =avlAdd(&root,&node90);   
  
  int heightChange;
  Node *temp = avlRemove(&root,140,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node140,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node60,&node100,0);
  TEST_ASSERT_EQUAL_NODE(&node100,&node90,&node130,0);
  TEST_ASSERT_EQUAL_NODE(&node60,&node40,&node70,0);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node90,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node130,NULL,NULL,0);
}
 
 
   /** 100(-1)60(+1)80(-1)  -> 100(+1)60(0)80(0)                             
 *              100(-1)                  100(-2)                     80(0)
 *             /    \      ------>       /   \       ----->         /    \
 *         (+1)60   130              (+1)60  130                   60(0) 100(+1)
 *           / \     \                / \                         / \     \
 *         40  80(0) 140            40  80(-1)                  40  70    130
 *            /                       / 
 *          70                       70  
 *
 **/
 
void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node80_is_negative_1(void){
  Node *root = &node100;
  int cState =  avlAdd(&root,&node60);
  cState =avlAdd(&root,&node130);
  cState =avlAdd(&root,&node40);
  cState =avlAdd(&root,&node80);   
  cState =avlAdd(&root,&node140);   
  cState =avlAdd(&root,&node70);   
  
  int heightChange;
  Node *temp = avlRemove(&root,140,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node140,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node60,&node100,0);
  TEST_ASSERT_EQUAL_NODE(&node100,NULL,&node130,1);
  TEST_ASSERT_EQUAL_NODE(&node60,&node40,&node70,0);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node130,NULL,NULL,0);
}
 
   /** 100(-1)60(+1)80(+1)  -> 100(0)60(-1)80(0)                             
 *              100(-1)                  100(-2)                     80(0)
 *             /    \      ------>       /   \       ----->         /     \
 *         (+1)60   130              (+1)60  130                   60(-1) 100(0)
 *           / \     \                / \                         /       / \
 *         40  80(0) 140            40  80(+1)                   40     90  130
 *             \                        \
 *              90                       90
 *
 **/

void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node80_is_1(void){
  Node *root = &node100;
  int cState =  avlAdd(&root,&node60);
  cState =avlAdd(&root,&node130);
  cState =avlAdd(&root,&node40);
  cState =avlAdd(&root,&node80);   
  cState =avlAdd(&root,&node140);   
  cState =avlAdd(&root,&node90);   
  
  int heightChange;
  Node *temp = avlRemove(&root,140,&heightChange);

  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node140,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node60,&node100,0);
  TEST_ASSERT_EQUAL_NODE(&node100,&node90,&node130,0);
  TEST_ASSERT_EQUAL_NODE(&node60,&node40,NULL,-1);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node90,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node130,NULL,NULL,0);
}
//---------------------------------------------------------------------------

/**                            
 *              100(-1)                  100(-1)         
 *             /    \      ------>       /   \       
 *         (0)60   130              (-1)60  130        
 *           / \                      /                                
 *         40  80(0)                40                          
 *
 **/

void test_avlRemove_remove_node80_and_The_BF_of_node60_is_change_from_0_to_neg_1(void){
  
  Node *root = &node100;
  int cState =  avlAdd(&root,&node60);
  cState =avlAdd(&root,&node130);
  cState =avlAdd(&root,&node40);
  cState =avlAdd(&root,&node80);   
  
  int heightChange;
  Node *temp = avlRemove(&root,80,&heightChange);
  TEST_ASSERT_EQUAL(0,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node80,temp);
  
  TEST_ASSERT_EQUAL_NODE(root,&node60,&node130,-1);
  TEST_ASSERT_EQUAL_NODE(&node60,&node40,NULL,-1);
  TEST_ASSERT_EQUAL_NODE(&node130,NULL,NULL,0);
  
}

/**                            
 *              100(+1)                  100(+1)         
 *             /    \      ------>       /   \       
 *            60   130(0)               60   130(+1)        
 *                 / \                        \
 *               110 140                      140
 *
 **/

 void test_avlRemove_remove_node80_and_The_BF_of_node60_is_(void){
  
  Node *root = &node100;
  int cState =  avlAdd(&root,&node60);
  cState =avlAdd(&root,&node130);
  cState =avlAdd(&root,&node140);
  cState =avlAdd(&root,&node110);   
  
  int heightChange;
  Node *temp = avlRemove(&root,110,&heightChange);
  TEST_ASSERT_EQUAL(0,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node110,temp);
  
  TEST_ASSERT_EQUAL_NODE(root,&node60,&node130,1);
  TEST_ASSERT_EQUAL_NODE(&node60,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node130,NULL,&node140,1);
  
}
 
 

 
 /**                             
 *             30(+1)                30(+1)               
 *             / \      ------>     /  \        heightChange = 0;
 *           20  60(-1)           20   60(-1)            
 *          /    / \             /     /  \                
 *        10 (0)40  70          10 (+1)40   70             
 *            / \                     \
 *          35  50                    50
 **/
 
void test_avlGetReplace_expected_BF_of_node60_is_negative_1_and_heightChange_is_0(void){
  
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node20);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node10);
  cState =avlAdd(&root,&node40);   
  cState =avlAdd(&root,&node70);
  cState =avlAdd(&root,&node35);
  cState =avlAdd(&root,&node50);
  
  int heightChange;
  Node *temp = avlGetReplace( &root->right ,&heightChange);
  printf("heightChange = %d\n", heightChange);
  TEST_ASSERT_EQUAL(0,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node35,temp);
  TEST_ASSERT_EQUAL_NODE(root,&node20,&node60,1);
  TEST_ASSERT_EQUAL_NODE(&node20,&node10,NULL,-1);
  TEST_ASSERT_EQUAL_NODE(&node60,&node40,&node70,-1);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,&node50,1);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
}
 
 /**                             
 *             30(+1)                30(+1)               
 *             / \      ------>     /  \         heightChange = 1;
 *           20  60(-1)           20   60(-1)            
 *          /    / \             /     /   \                
 *        10 (-1)40  70        10   (0)40   70             
 *            /                         
 *          35                          
 **/
void xtest_avlGetReplace_expected_BF_of_node60_is_negative_1_and_heightChange_is_1(void){
  
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node20);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node10);
  cState =avlAdd(&root,&node40);   
  cState =avlAdd(&root,&node35);   
  cState =avlAdd(&root,&node70);
  
  int heightChange;
  Node *temp = avlGetReplace( &root->right ,&heightChange);
  printf(" heightChange = %d\n", heightChange);
  TEST_ASSERT_EQUAL(0,heightChange);
  printf("temp->data = %d",temp->data);
  TEST_ASSERT_EQUAL_PTR(&node35,temp);

  TEST_ASSERT_EQUAL_NODE(&node60,&node40,&node70,0);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
}


 
 /**                             
 *             30(+1)                30(+1)               
 *             / \      ------>     /  \        
 *           20  60(-1)           20   60(0)            
 *          /    / \             /     /   \                
 *        10 (-1)40  70        10    50    70             
 *               \                     
 *               50                    
 **/

void test_avlGetReplace_expected_BF_of_node60_is_0(void){
  
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node20);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node10);
  cState =avlAdd(&root,&node40);   
  cState =avlAdd(&root,&node70);
  cState =avlAdd(&root,&node50);   
  
  int heightChange;
  Node *temp = avlGetReplace( &root->right ,&heightChange);
  printf(" heightChange = %d\n", heightChange);
  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node40,temp);

  TEST_ASSERT_EQUAL_NODE(&node60,&node50,&node70,0);
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
}
 
 /**                             
 *             30(+1)                30(+1)                      30
 *             / \      ------>     /  \        ----->          /  \
 *           20  60(-1)           20   60(0)                  20   60
 *          /    / \             /     /   \                 /    /  \
 *        10 (+1)40  70        10 (+2)40    70              10  50   70
 *             /  \   \                 \                      / \
 *           45   50  80                50                   40  65
 *                 \                     \
 *                 65                    65
 **/
 
