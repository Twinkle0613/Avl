#include "unity.h"
#include "Avl.h"
#include "Node.h"
#include "CustomAssertion.h"
#include "Rotation.h"
//#include "TestCode.h"
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
void tearDown(void)
{
}
/**
 * No height change
 *   +1  -> 0
 *   -1  -> 0
 *   +1  -> +2
 *   -1  ->  -2
 * Height change
 *   0  -> +1
 *   0  ->  -1
 *
 *
 */



/**
 *        30(0)    60       30(1)
 *              ------>       \
 *                             60(0)
 */
#define CHANGE 1
#define NO_CHANGE 0
void test_avlAdd(){ 
  Node *root = &node30;
  int cState = avlAdd(&root,&node60);
  TEST_ASSERT_EQUAL_NODE(root,NULL,&node60,1);
  TEST_ASSERT_EQUAL(cState,CHANGE);
}

/**
 *        30(0)    10       30(-1)
 *              ------>     /  
 *                        10
 */
void test_avlAdd_add_rightNode(){
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  TEST_ASSERT_EQUAL_NODE(root,&node10,NULL,-1);
  TEST_ASSERT_EQUAL(cState,CHANGE);
  
}


/**
 *        30(0)    10       30(-1)     40       30(0) 
 *              ------>     /       ------>    / \ 
 *                        10                 10  60
 */
 
void test_avlAdd_add_rightNode_and_then_add_leftNode(void){
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  TEST_ASSERT_EQUAL_NODE(root,&node10,NULL,-1);
  TEST_ASSERT_EQUAL(cState,CHANGE);
  cState =  avlAdd(&root,&node60);
  TEST_ASSERT_EQUAL_NODE(root,&node10,&node60,0);
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);
}

/**                                           
 *             30(0)     80         30(+1) 
 *             / \      ------>    / \ 
 *           10  60              10  60(+1)
 *                                    \
 *                                    80(0)
 */
 void test_avlAdd_add_node80_into_node30Tree(void){
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node80);

  TEST_ASSERT_EQUAL_NODE(root,&node10,&node60,1);
  TEST_ASSERT_EQUAL_NODE(root->right,NULL,&node80,1);
  TEST_ASSERT_EQUAL_NODE(root->left,NULL,NULL,0);
  TEST_ASSERT_EQUAL(cState,CHANGE);

  }
 
 /**                                           
 *              30(1)     5         30(0)   
 *             / \      ------>    / \ 
 *           10  60          (-1)10  60(+1)
 *                 \             /    \
 *                 80        (0)5     80(0)
 */
 
void test_avlAdd_add_node5_into_node30Tree(void){
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node80);
  cState =avlAdd(&root,&node5);

  TEST_ASSERT_EQUAL_NODE(root,&node10,&node60,0);
  TEST_ASSERT_EQUAL_NODE(root->right,NULL,&node80,1);
  TEST_ASSERT_EQUAL_NODE(root->left,&node5,NULL,-1);
  TEST_ASSERT_EQUAL(NO_CHANGE,cState);

  }
  
/**                                           
 *             30(0)     80         30(+1) 
 *             / \      ------>    / \ 
 *           10  60              10  60(0)
 *                                  / \
 *                             (0)50  80(0)
 */
 
void test_avlAdd_add_node50_into_node30Tree(void){
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node80);
  cState =avlAdd(&root,&node50);

  TEST_ASSERT_EQUAL_NODE(root,&node10,&node60,1);          //node 30
  TEST_ASSERT_EQUAL_NODE(root->right,&node50,&node80,0);   //node 60
  TEST_ASSERT_EQUAL_NODE(root->left,NULL,NULL,0);          //node 10
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);

}
 
  /**                                           
 *              30(0)     5         30(-1) 
 *             / \      ------>    / \ 
 *           10  60          (-1)10  60(0)
 *                               /    
 *                          (0)5     
 */
  
  
void test_avlAdd_add_2node5_into_node30Tree(void){
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node5);

  TEST_ASSERT_EQUAL_NODE(root,&node10,&node60,-1);
  TEST_ASSERT_EQUAL_NODE(root->right,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(root->left,&node5,NULL,-1);
  TEST_ASSERT_EQUAL(cState,CHANGE);

  }
  
  
/**                                           
 *              30(0)     20        30(-1) 
 *             / \      ------>    / \ 
 *           10  60          (0)10  60(0)
 *          /                   / \    
 *         5                (0)5  20(0)  
 */
 
void test_avlAdd_add_node20_into_node30Tree(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node20);
  cState =avlAdd(&root,&node5);

  TEST_ASSERT_EQUAL_NODE(root,&node10,&node60,-1);
  TEST_ASSERT_EQUAL_NODE(root->right,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(root->left,&node5,&node20,0);
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);

}





//-------------------------------Left_Rotation-----------------------------//
/**                                           
 *             30(0)     90         30(+2)       leftRotate        60(0)
 *             / \      ------>    / \            ------>          / \
 *           10  60              10  60(+1)                   (0)30  80(+1)
 *              / \                  / \                        / \    \
 *            50  80            (0)50  80(+1)                 10  50   90(0)
 *                                       \ 
 *                                       90(0) 
 */
void test_avlAdd_add_node90_into_node30Tree(void){
  
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node80);
  cState =avlAdd(&root,&node50);
  cState =avlAdd(&root,&node90);
  TEST_ASSERT_EQUAL_NODE(&node60,&node30,&node80,0);          
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node50,0);   
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,&node90,1);        
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,NULL,0);  
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0); 
  TEST_ASSERT_EQUAL_NODE(&node90,NULL,NULL,0);
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);
}
  
/**                                           
 *             30(0)     70         30(+2)       leftRotate         60(0)
 *             / \      ------>    / \            ------>          /   \
 *           10  60              10  60(+1)                   (0)30    80(-1)
 *              / \                  / \                        / \    /
 *            50  80            (0)50  80(-1)                 10  50  70(0)
 *                                    / 
 *                                  70(0) 
 */
 
void test_avlAdd_add_node70_into_node30Tree(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node80);
  cState =avlAdd(&root,&node50);
  cState =avlAdd(&root,&node70);
  TEST_ASSERT_EQUAL_NODE(&node60,&node30,&node80,0);          
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node50,0);   
  TEST_ASSERT_EQUAL_NODE(&node80,&node70,NULL,-1);        
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,NULL,0);  
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,NULL,0); 
  TEST_ASSERT_EQUAL_NODE(&node70,NULL,NULL,0);
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);
}

/**                                           
 *             30(0)     80         30(+2)       leftRotate         60(0)
 *               \      ------>      \            ------>          /   \
 *               60                  60(+1)                   (0)30    80(0)
 *                                    \                               
 *                                    80(0)                         
 *                                     
 *                                   
 */
void test_avlAdd_add_node80_only_into_node30Tree(void){
  Node *root = &node30;
  int cState;
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node80);
  TEST_ASSERT_EQUAL_NODE(&node60,&node30,&node80,0);          
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,NULL,0);   
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,NULL,0);        
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);
}
 
 
/**                                           
 *             30(0)     70         30(+2)       leftRotate         60(0)
 *             / \      ------>    /    \            ------>          /   \
 *           10  60              10    60(1)                   (0)30    80(-1)
 *              / \             /     /    \                        / \    /
 *            50  80           8 (-1)50   80(-1)                 10  50  70(0)
 *                                 /     /     \
 *                             (0)40  70(-1)   90(0)
 *                                    /       
 *                                  75(0)
 *
 */

 
 /**                                           
 *             30(0)     70         30(+2)         leftRotate         60(0)
 *             / \      ------>    /      \            ------>          /   \
 *           10  60              10     60(1)                   (0)30    80(-1)
 *              / \             /      /     \                        / \    /
 *            50  80           8 (+1)50      80(-1)                 10  50  70(0)
 *                                    \      /     \
 *                                    55   70(-1)  90(0)
 *                                        /       
 *                                      75(0)
 *
 */
 
 
 
 

 
//-------------------------------Right_Rotation-----------------------------// 
 /**                                           
 *              30(-1)                    30(-2)                        10(0)           
 *              / \          0            / \                          /  \ 
 *         (0)10  60(0)      ->     (-1)10  60(0)   --->          (-1)5   30(0)
 *           / \                       / \                         /     / \ 
 *       (0)5  20(0)              (-1)5  20(0)                  (0)0 (0)20  60(0)
 *                                  /                                  
 *                              (0)0       
 */ 
 
 void test_avlAdd_add_node25_into_node30Tree(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node20);
  cState =avlAdd(&root,&node5);
  cState =avlAdd(&root,&node0);

  TEST_ASSERT_EQUAL_NODE(&node10,&node5,&node30,0);
  TEST_ASSERT_EQUAL_NODE(&node5,&node0,NULL,-1);
  TEST_ASSERT_EQUAL_NODE(&node30,&node20,&node60,0);
  TEST_ASSERT_EQUAL_NODE(&node20,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node60,NULL,NULL,0);
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);

}

 /**                                           
 *              30(-1)                    30(-2)                         10(0)           
 *              / \          0            / \                          /     \ 
 *         (0)10  60(0)      ->     (-1)10  60(0)   --->          (+1)5     30(0)
 *           / \                       / \                            \     /   \ 
 *       (0)5  20(0)              (+1)5  20(0)                      (0)8  (0)20  60(0)
 *                                    \                                
 *                                     8(0)
 */ 
 
 void test_avlAdd_add_node8_into_node30Tree(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node20);
  cState =avlAdd(&root,&node5);
  cState =avlAdd(&root,&node8);
  TEST_ASSERT_EQUAL_NODE(&node10,&node5,&node30,0);
  TEST_ASSERT_EQUAL_NODE(&node5,NULL,&node8,1);
  TEST_ASSERT_EQUAL_NODE(&node30,&node20,&node60,0);
  TEST_ASSERT_EQUAL_NODE(&node20,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node60,NULL,NULL,0);
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);

}

 /**                                           
 *              30(-1)                    30(-2)                         10(0)           
 *              / \          0            /     \                          /     \ 
 *         (0)10  60(0)      ->     (-1)10      60(0)   --->          (+1)5     30(0)
 *           / \                       / \        \                       \     /   \ 
 *       (0)5  20(0)              (-1)5  20(0)   80(0)                    (0)8  (0)20  60(0)
 *                                  / \                                
 *                              (0)3   8(0)
 *                               /
 *                             0
 */ 
 
 /**                                           
 *              30(-1)                    30(-2)                         10(0)           
 *              / \          0            /     \                          /     \ 
 *         (0)10  60(0)      ->     (-1)10      60(0)   --->          (+1)5     30(0)
 *           / \                       / \        \                       \     /   \ 
 *       (0)5  20(0)              (+1)5  20(0)   80(0)                    (0)8  (0)20  60(0)
 *                                  / \                                
 *                              (0)3   8(0)
 *                                      \
 *                                       9
 */ 


/**                                           
 *              30(-2)                    30(-2)                        10(0)           
 *              /            15            /                            /  \ 
 *         (+1)10           --->     (+1)10       --->             (0)15   30(0)
 *                                        \                          
 *                                        15      
 *                                                                   
 *                                    
 */ 

  void test_avlAdd_add_node8_only_into_node30Tree(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node8);

  TEST_ASSERT_EQUAL_NODE(&node10,&node8,&node30,0);
  TEST_ASSERT_EQUAL_NODE(&node8,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,NULL,0);
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);

}
 
 
 
//-------------------------------Right_Left_Rotation-----------------------------// 
 
 /**                                           
 *             30(0)     50         30(+2)       leftRotate        50(0)
 *             / \      ------>    / \            ------>          / \
 *           10  60              10  60(-1)                  (-1)30  60(0)
 *              / \                  / \                        /   /  \
 *            50  80            (+1)50  80(0)                 10  55   80
 *                                  \ 
 *                                  55(0) 
 */
void test_avlAdd_add_node55_only_into_node30Tree(void){
  Node *root = &node30;
  int cState;
  cState =avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
   TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node60,0); 
  cState =avlAdd(&root,&node50);
  cState =avlAdd(&root,&node80);
  cState =avlAdd(&root,&node55);
 //  TEST_ASSERT_EQUAL_NODE(&node60,&node50,&node80,-1); 
  TEST_ASSERT_EQUAL_NODE(&node50,&node30,&node60,0);          
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,NULL,-1);   
  TEST_ASSERT_EQUAL_NODE(&node60,&node55,&node80,0);      
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,NULL,0);        
  TEST_ASSERT_EQUAL_NODE(&node55,NULL,NULL,0);        
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,NULL,0);        
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);
}
 
  /**                                           
 *             30(0)     40         30(+2)       leftRotate        50(0)
 *             / \      ------>    / \            ------>        8  cState =avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node50);
  cState =avlAdd(&root,&node80);
  cState =avlAdd(&root,&node40);
  TEST_ASSERT_EQUAL_NODE(&node50,&node30,&node60,0);          
  TEST_ASSERT_EQUAL_NODE(&node30,&node10,&node40,0);   
  TEST_ASSERT_EQUAL_NODE(&node60,NULL,&node80,1);      
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,NULL,0);        
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,NULL,0);        
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,NULL,0);        
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);
}
 
 /**                                           
 *             30(0)     80         30(+2)       leftRotate         50(0)
 *               \      ------>      \            ------>          /   \
 *               60                  60(-1)                   (0)30    60(0)
 *                                  /                               
 *                                 50                       
 *                                     
 *                                   
 */
 
 void test_avlAdd_add_node50_only_into_node30Tree(void){
  Node *root = &node30;
  int cState;
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node50,&node30,&node60,0);          
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,NULL,0);   
  TEST_ASSERT_EQUAL_NODE(&node60,NULL,NULL,0);        
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);
}
 
 
 //-------------------------------left_Right_Rotation-----------------------------//
 
 
 /**                                           
 *              30(-1)                    30(-2)                        20(0)           
 *              / \          0            / \                          /     \ 
 *         (0)10  60(0)    --->     (+1)10  60(0)   --->          (-1)10     30(0)
 *           / \                       / \                           /       /   \ 
 *       (0)5  20(0)              (0)5  20(+1)                      5     (0)25  60(0)
 *                                       \                                
 *                                       25(0)
 */ 
 
  void test_avlAdd_add_node25_only_into_node30Tree(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node20);
  cState =avlAdd(&root,&node5);
  cState =avlAdd(&root,&node25);
  TEST_ASSERT_EQUAL_NODE(&node20,&node10,&node30,0);
  TEST_ASSERT_EQUAL_NODE(&node10,&node5,NULL,-1);
  TEST_ASSERT_EQUAL_NODE(&node30,&node25,&node60,0);
  TEST_ASSERT_EQUAL_NODE(&node25,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node60,NULL,NULL,0);
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);

}
 
/**                                           
 *              30(-1)                    30(-2)                        20(0)           
 *              / \          0            / \                          /     \ 
 *         (0)10  60(0)    --->     (+1)10  60(0)   --->            (0)10     30(+1)
 *           / \                       / \                           /  \      \ 
 *       (0)5  20(0)              (0)5  20(+1)                      5    15    60
 *                                      /                                
 *                                    15
 */ 
 
void test_avlAdd_add_node15_only_into_node30Tree(void){
  Node *root = &node30;
  int cState =  avlAdd(&root,&node10);
  cState =avlAdd(&root,&node60);
  cState =avlAdd(&root,&node20);
  cState =avlAdd(&root,&node5);
  cState =avlAdd(&root,&node15);
  TEST_ASSERT_EQUAL_NODE(&node20,&node10,&node30,0);
  TEST_ASSERT_EQUAL_NODE(&node10,&node5,&node15,0);
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,&node60,1);
  TEST_ASSERT_EQUAL_NODE(&node5,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node15,NULL,NULL,0);
  TEST_ASSERT_EQUAL_NODE(&node60,NULL,NULL,0);
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);
}
 
 
  /**                                           
 *             30(0)     80         30(-2)       leftRotate        20(0)
 *             /       ------>     /             ------>          /   \
 *           20               (-1)20                         (0)10     30(0)
 *                               /                               
 *                             10                             
 
 *                                     
 *                                   
 */
 
  void test_avlAdd_add_node10_only_into_node30Tree(void){
  Node *root = &node30;
  int cState;
  cState =avlAdd(&root,&node20);
  cState =avlAdd(&root,&node10);
  TEST_ASSERT_EQUAL_NODE(&node20,&node10,&node30,0);          
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,NULL,0);   
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,NULL,0);        
  TEST_ASSERT_EQUAL(cState,NO_CHANGE);
}
 
 
 
 
 
 
 
 