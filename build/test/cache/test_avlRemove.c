#include "CustomAssertion.h"
#include "Node.h"
#include "Avl.h"
#include "avlRemove.h"
#include "unity.h"






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

  node->left = ((void *)0);

  node->right = ((void *)0);

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

void test_avlRemove_remove_node60_in_tree(void){

    Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  { customTestAssertEqualNode(&node30,&node10,&node60,0,89); };

  int heightChange;

  Node *temp = avlRemove(&root,10,&heightChange);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node30,((void *)0),&node60,1,93); };



}

void test_avlRemove_remove_node10_in_tree(void){

    Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  { customTestAssertEqualNode(&node30,&node10,&node60,0,109); };

  int heightChange;

  Node *temp = avlRemove(&root,60,&heightChange);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node60)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node30,&node10,((void *)0),-1,113); };

}

 void test_avlRemove_remove_node5_in_tree(void){

    Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node5);

  int heightChange;

  Node *temp = avlRemove(&root,5,&heightChange);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)132, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node30,&node10,&node60,0,133); };

}

void test_avlRemove_right_rotation_remove_node10_and_the_balance_factor_of_node60_is_0_in_tree(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node50);

  cState =avlAdd(&root,&node70);

  int heightChange;



  Node *temp = avlRemove(&root,10,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,((void *)0),&node60,2,157); };

  { customTestAssertEqualNode(&node60,&node50,&node70,0,158); };

}
