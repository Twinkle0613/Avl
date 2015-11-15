#include "unity.h"
#include "avlRemove.h"
#include "unity.h"
#include "Avl.h"
#include "Node.h"
#include "CustomAssertion.h"


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
 *             30(0)       10         30(+1)
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
 *             30(0)       60         30(-1)
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
 *             30(0)       5           30(0)
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

//------------------------------avlRemove_RightRotation---------------------------
/** 30(+1)60(0)  -> 30(+1)60(-1)                             
 *             30(+1)       10       30(+2)                   60(-1)
 *             / \      ------>       \        ----->        /  \
 *           10  60(0)                60(0)              (+1)30 70
 *              / \                  /  \                    \
 *             50  70              50   70                   50     
 *
 **/
void test_avlRemove_right_rotation_remove_node10_and_the_balance_factor_of_node60_is_0_in_tree(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node50);   
  cState =avlAdd(&root,&node70);
  int heightChange;
  //TEST_ASSERT_EQUAL_NODE(root,&node10,&node60,2);
  Node *temp = avlRemove(&root,10,&heightChange);
 // printf("root->balanceFactor = %d",root->balanceFactor);
  TEST_ASSERT_EQUAL(1,heightChange);
  TEST_ASSERT_EQUAL_PTR(&node10,temp);
  TEST_ASSERT_EQUAL_NODE(root,NULL,&node60,2);
  TEST_ASSERT_EQUAL_NODE(&node60,&node50,&node70,0);
}
 
 /** 30(+1)60(+1)  -> 30(0)60(0)                                      
 *             30(+1)       10       30(+2)                     60(0)
 *             / \      ------>     /    \        ----->        /  \
 *           10  60(+1)           10   60(0)                (0)30   70 
 *           /  /  \                   /  \                  /  \    \
 *          5  50  70                50   70               10   50   80  
 *                  \                      \
 *                  80                     80
 *
 *
 **/
 
 
  /**  30(+1)60(+1)  -> 30(0)60(0)                                        
 *             30(+1)       10       30(+2)                     60(0)
 *             / \      ------>     /    \        ----->        /    \
 *           10  60(+1)           10   60(0)                (0)30    70 
 *           /  /  \                   /  \                  /  \    /
 *          5  50  70                50   70               10   50  65   
 *                /                      /
 *              65                     65
 *
 *
 **/
 
 //------------------------------avlRemove_leftRotation---------------------------
 
 
 /** 100(-1)60(0)  -> 100(-1)60(+1)                             
 *              100(-1)                 100(-2)                     60(+1)
 *             /   \      ------>       /          ----->          /  \
 *         (0)60  130              (0)60                         40   100(-1)
 *           / \                     / \                              /
 *         40  80                  40  80                           80
 *
 **/
 
 
 /** 100(-1)60(-1)  -> 100(0)60(0)                             
 *              100(-1)                 100(-2)                     60(0)
 *             /   \      ------>       /   \       ----->          /   \
 *        (-1)60  130              (-1)60    130                  40    100(0)
 *           / \    \                / \                           \     / \
 *         40  80  140             40  80                          50   80  130
 *          \                       \
 *          50                      50
 **/
 
  /** 100(-1)60(-1)  -> 100(0)60(0)                             
 *              100(-1)                 100(-2)                     60(0)
 *             /   \      ------>       /   \       ----->          /   \
 *        (-1)60  130              (-1)60    130                  40    100(0)
 *           / \    \                / \                          /     / \
 *         40  80  140             40  80                        30   80  130
 *        /                        /
 *       30                      30
 **/
 
//------------------------------avlRemove_left-right-Rotation---------------------------

/** 30(+1)60(-1)40(0)  -> 30(0)60(0)50(0)                             
 *             30(+1)                30(+2)                   40(0)
 *             / \      ------>     /  \        ----->        /   \
 *           20  60(-1)           20   60(-1)            (0)30    60(0)
 *          /    / \                   /  \                / \    / \
 *        10 (0)40  70              (0)40   70           20  35 50  70    
 *            / \                   / \
 *          35  50                35  50
 **/


/** 30(+1)60(-1)40(-1)  -> 30(0)60(+1)50(0)                             
 *             30(+1)                30(+2)                   40(0)
 *             / \      ------>     /  \        ----->        /   \
 *           20  60(-1)           20   60(-1)            (0)30    60(+1)
 *          /    / \                   /  \                / \      \
 *        10 (0)40  70             (-1)40   70           20  35     70    
 *            / \                   / 
 *          35  50                35  
 **/

/** 30(+1)60(-1)40(+1)  -> 30(-1)60(0)50(0)                             
 *             30(+1)                30(+2)                   40(0)
 *             / \      ------>     /  \        ----->        /   \
 *           20  60(-1)           20   60(-1)            (-1)30    60(0)
 *          /    / \                   /  \                /      / \
 *        10 (0)40  70              (+1)40   70           20     50  70    
 *            / \                     \
 *          35  50                    50
 **/
 
 
 //------------------------------avlRemove_right-left-Rotation---------------------------

 
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
 
   /** 100(-1)60(+1)80(-1)  -> 100(+1)60(0)80(0)                             
 *              100(-1)                  100(-2)                     80(0)
 *             /    \      ------>       /   \       ----->         /    \
 *         (+1)60   130              (+1)60  130                   60(0) 100(+1)
 *           / \     \                / \                         / \     \
 *         40  80(0) 140            40  80(-1)                  40  70    130
 *            / \                      / 
 *          70  90                   70  
 *
 **/
 
   /** 100(-1)60(+1)80(+1)  -> 100(0)60(-1)80(0)                             
 *              100(-1)                  100(-2)                     80(0)
 *             /    \      ------>       /   \       ----->         /     \
 *         (+1)60   130              (+1)60  130                   60(-1) 100(0)
 *           / \     \                / \                         /       / \
 *         40  80(0) 140            40  80(+1)                   40     90  130
 *            / \                        \
 *          70  90                       90
 *
 **/
 
 