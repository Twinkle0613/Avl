#include "Rotation.h"
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

Node node45;

Node node50;

Node node55;

Node node60;

Node node65;

Node node70;

Node node75;

Node node80;

Node node90;

Node node100;

Node node105;

Node node110;

Node node115;

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

  resetNode(&node45,45);

  resetNode(&node50,50);

  resetNode(&node55,55);

  resetNode(&node60,60);

  resetNode(&node65,65);

  resetNode(&node70,70);

  resetNode(&node75,75);

  resetNode(&node80,80);

  resetNode(&node90,90);

  resetNode(&node100,100);

  resetNode(&node105,105);

  resetNode(&node110,110);

  resetNode(&node115,115);

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

  { customTestAssertEqualNode(&node30,&node10,&node60,0,98); };

  int heightChange;

  Node *temp = avlRemove(&root,10,&heightChange);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node30,((void *)0),&node60,1,102); };



}

void test_avlRemove_remove_node10_in_tree(void){

    Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  { customTestAssertEqualNode(&node30,&node10,&node60,0,118); };

  int heightChange;

  Node *temp = avlRemove(&root,60,&heightChange);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node60)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node30,&node10,((void *)0),-1,122); };

}

 void test_avlRemove_remove_node5_in_tree(void){

    Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node5);

  int heightChange;

  Node *temp = avlRemove(&root,5,&heightChange);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node30,&node10,&node60,0,142); };

}

void test_avlRemove_remove_node5_and_given_the_bal_factor_of_node60_is_0(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node50);

  cState =avlAdd(&root,&node70);



  int heightChange;

  Node *temp = avlRemove(&root,10,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node70,-1,166); };

  { customTestAssertEqualNode(&node30,((void *)0),&node50,1,167); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,168); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,169); };

}

 void test_avlRemove_remove_node5_and_given_the_bal_factor_of_node60_is_1_and_given_extra_node80(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node5);

  cState =avlAdd(&root,&node50);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node80);



  int heightChange;

  Node *temp = avlRemove(&root,5,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)195, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node70,0,197); };

  { customTestAssertEqualNode(&node30,&node10,&node50,0,198); };

  { customTestAssertEqualNode(&node70,((void *)0),&node80,1,199); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,200); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,201); };

}

void test_avlRemove_remove_node5_and_given_the_bal_factor_of_node60_is_1_and_given_extra_node65(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node5);

  cState =avlAdd(&root,&node50);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node65);



  int heightChange;

  Node *temp = avlRemove(&root,5,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node70,0,230); };

  { customTestAssertEqualNode(&node30,&node10,&node50,0,231); };

  { customTestAssertEqualNode(&node70,&node65,((void *)0),-1,232); };

  { customTestAssertEqualNode(&node65,((void *)0),((void *)0),0,233); };

  { customTestAssertEqualNode(&node10,((void *)0),((void *)0),0,234); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,235); };

}

 void test_avlRemove_remove_node5_and_given_the_bal_factor_of_node60_is_1_and_given_extra_node65_and_node80(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node5);

  cState =avlAdd(&root,&node50);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node65);

  cState =avlAdd(&root,&node80);



  int heightChange;

  Node *temp = avlRemove(&root,5,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)265, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node70,0,266); };

  { customTestAssertEqualNode(&node30,&node10,&node50,0,267); };

  { customTestAssertEqualNode(&node70,&node65,&node80,0,268); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,269); };

  { customTestAssertEqualNode(&node65,((void *)0),((void *)0),0,270); };

  { customTestAssertEqualNode(&node10,((void *)0),((void *)0),0,271); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,272); };

}

void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node60_is_0(void){

  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node80);



  int heightChange;

  Node *temp = avlRemove(&root,130,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)297, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node130)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)298, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node40,&node100,1,299); };

  { customTestAssertEqualNode(&node100,&node80,((void *)0),-1,300); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,301); };

  { customTestAssertEqualNode(&node40,((void *)0),((void *)0),0,302); };

}

void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node60_is_negetive_1_and_given_extra_node50(void){

  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node140);

  cState =avlAdd(&root,&node50);



  int heightChange;

  Node *temp = avlRemove(&root,140,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)328, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node40,&node100,0,329); };

  { customTestAssertEqualNode(&node100,&node80,&node130,0,330); };

  { customTestAssertEqualNode(&node40,((void *)0),&node50,1,331); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,332); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,333); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,334); };

}

void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node60_is_negetive_1_and_given_extra_node30(void){

  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node140);

  cState =avlAdd(&root,&node30);



  int heightChange;

  Node *temp = avlRemove(&root,140,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)357, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node40,&node100,0,359); };

  { customTestAssertEqualNode(&node100,&node80,&node130,0,360); };

  { customTestAssertEqualNode(&node40,&node30,((void *)0),-1,361); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,362); };

  { customTestAssertEqualNode(&node30,((void *)0),((void *)0),0,363); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,364); };

}

void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node60_is_negetive_1_and_given_extra_node30_and_node50(void){

  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node140);

  cState =avlAdd(&root,&node30);

  cState =avlAdd(&root,&node50);



  int heightChange;

  Node *temp = avlRemove(&root,140,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)390, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node40,&node100,0,392); };

  { customTestAssertEqualNode(&node100,&node80,&node130,0,393); };

  { customTestAssertEqualNode(&node40,&node30,&node50,0,394); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,395); };

  { customTestAssertEqualNode(&node30,((void *)0),((void *)0),0,396); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,397); };

}

void test_avlRemove_remove_node10_and_given_the_bal_factor_of_node40_is_0(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node20);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node10);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node35);

  cState =avlAdd(&root,&node50);



  int heightChange;

  Node *temp = avlRemove(&root,10,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)424, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)425, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node60,0,426); };

  { customTestAssertEqualNode(root->left,&node20,&node35,0,427); };

  { customTestAssertEqualNode(root->right,&node50,&node70,0,428); };

  { customTestAssertEqualNode(&node20,((void *)0),((void *)0),0,429); };

  { customTestAssertEqualNode(&node35,((void *)0),((void *)0),0,430); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,431); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,432); };

}

void test_avlRemove_remove_node10_and_given_the_bal_factor_of_node40_is_negative_1(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node20);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node10);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node35);



  int heightChange;

  Node *temp = avlRemove(&root,10,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)457, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)458, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node60,0,459); };

  { customTestAssertEqualNode(root->left,&node20,&node35,0,460); };

  { customTestAssertEqualNode(root->right,((void *)0),&node70,1,461); };

  { customTestAssertEqualNode(&node20,((void *)0),((void *)0),0,462); };

  { customTestAssertEqualNode(&node35,((void *)0),((void *)0),0,463); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,464); };

}

 void test_avlRemove_remove_node10_and_given_the_bal_factor_of_node40_is_1(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node20);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node10);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node50);



  int heightChange;

  Node *temp = avlRemove(&root,10,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)489, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)490, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node60,0,491); };

  { customTestAssertEqualNode(root->left,&node20,((void *)0),-1,492); };

  { customTestAssertEqualNode(root->right,&node50,&node70,0,493); };

  { customTestAssertEqualNode(&node20,((void *)0),((void *)0),0,494); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,495); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,496); };

}

void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node80_is_0(void){

  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node140);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node90);



  int heightChange;

  Node *temp = avlRemove(&root,140,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)525, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)526, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node60,&node100,0,527); };

  { customTestAssertEqualNode(&node100,&node90,&node130,0,528); };

  { customTestAssertEqualNode(&node60,&node40,&node70,0,529); };

  { customTestAssertEqualNode(&node40,((void *)0),((void *)0),0,530); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,531); };

  { customTestAssertEqualNode(&node90,((void *)0),((void *)0),0,532); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,533); };

}

void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node80_is_negative_1(void){

  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node140);

  cState =avlAdd(&root,&node70);



  int heightChange;

  Node *temp = avlRemove(&root,140,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)560, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)561, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node60,&node100,0,562); };

  { customTestAssertEqualNode(&node100,((void *)0),&node130,1,563); };

  { customTestAssertEqualNode(&node60,&node40,&node70,0,564); };

  { customTestAssertEqualNode(&node40,((void *)0),((void *)0),0,565); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,566); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,567); };

}

void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node80_is_1(void){

  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node140);

  cState =avlAdd(&root,&node90);



  int heightChange;

  Node *temp = avlRemove(&root,140,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)593, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)594, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node60,&node100,0,595); };

  { customTestAssertEqualNode(&node100,&node90,&node130,0,596); };

  { customTestAssertEqualNode(&node60,&node40,((void *)0),-1,597); };

  { customTestAssertEqualNode(&node40,((void *)0),((void *)0),0,598); };

  { customTestAssertEqualNode(&node90,((void *)0),((void *)0),0,599); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,600); };

}

void test_avlRemove_remove_node80_and_The_BF_of_node60_is_change_from_0_to_neg_1(void){



  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node80);



  int heightChange;

  Node *temp = avlRemove(&root,80,&heightChange);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)623, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node80)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)624, UNITY_DISPLAY_STYLE_HEX32);



  { customTestAssertEqualNode(root,&node60,&node130,-1,626); };

  { customTestAssertEqualNode(&node60,&node40,((void *)0),-1,627); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,628); };



}

 void test_avlRemove_remove_node80_and_The_BF_of_node60_is_(void){



  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node140);

  cState =avlAdd(&root,&node110);



  int heightChange;

  Node *temp = avlRemove(&root,110,&heightChange);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)651, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node110)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)652, UNITY_DISPLAY_STYLE_HEX32);



  { customTestAssertEqualNode(root,&node60,&node130,1,654); };

  { customTestAssertEqualNode(&node60,((void *)0),((void *)0),0,655); };

  { customTestAssertEqualNode(&node130,((void *)0),&node140,1,656); };



}

void test_avlGetReplace_expected_BF_of_node60_is_negative_1_and_heightChange_is_0(void){





  Node *root = &node30;

  int cState = avlAdd(&root,&node20);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node10);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node35);

  cState =avlAdd(&root,&node50);



  int heightChange;

  Node *temp = avlGetReplace( &root->right ,&heightChange);

  printf("heightChange = %d\n", heightChange);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)688, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node35)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)689, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node20,&node60,1,690); };

  { customTestAssertEqualNode(&node20,&node10,((void *)0),-1,691); };

  { customTestAssertEqualNode(&node60,&node40,&node70,-1,692); };

  { customTestAssertEqualNode(&node10,((void *)0),((void *)0),0,693); };

  { customTestAssertEqualNode(&node40,((void *)0),&node50,1,694); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,695); };

}

void xtest_avlGetReplace_expected_BF_of_node60_is_negative_1_and_heightChange_is_1(void){





  Node *root = &node30;

  int cState = avlAdd(&root,&node20);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node10);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node35);

  cState =avlAdd(&root,&node70);



  int heightChange;

  Node *temp = avlGetReplace( &root->right ,&heightChange);

  printf(" heightChange = %d\n", heightChange);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)721, UNITY_DISPLAY_STYLE_INT);

  printf("temp->data = %d",temp->data);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node35)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)723, UNITY_DISPLAY_STYLE_HEX32);



  { customTestAssertEqualNode(&node60,&node40,&node70,0,725); };

  { customTestAssertEqualNode(&node40,((void *)0),((void *)0),0,726); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,727); };

}

void test_avlGetReplace_expected_BF_of_node60_is_0(void){





  Node *root = &node30;

  int cState = avlAdd(&root,&node20);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node10);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node50);



  int heightChange;

  Node *temp = avlGetReplace( &root->right ,&heightChange);

  printf(" heightChange = %d\n", heightChange);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)756, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node40)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)757, UNITY_DISPLAY_STYLE_HEX32);



  { customTestAssertEqualNode(&node60,&node50,&node70,0,759); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,760); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,761); };

}

void test_avlGetReplace_expected_get_node45_BF_of_node60_is_0(void){



  Node *root = &node80;

  int cState = avlAdd(&root,&node50);

  cState =avlAdd(&root,&node140);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node100);

  cState =avlAdd(&root,&node150);

  cState =avlAdd(&root,&node30);

  cState =avlAdd(&root,&node90);

  cState =avlAdd(&root,&node110);

  cState =avlAdd(&root,&node160);

  cState =avlAdd(&root,&node120);





  { customTestAssertEqualNode(root,&node50,&node140,1,792); };

  { customTestAssertEqualNode(&node50,&node40,&node70,-1,793); };

  { customTestAssertEqualNode(&node40,&node30,((void *)0),-1,794); };

  { customTestAssertEqualNode(&node140,&node100,&node150,-1,795); };

  { customTestAssertEqualNode(&node90,((void *)0),((void *)0),0,796); };

  { customTestAssertEqualNode(&node110,((void *)0),&node120,1,797); };

  { customTestAssertEqualNode(&node100,&node90,&node110,1,798); };

  { customTestAssertEqualNode(&node150,((void *)0),&node160,1,799); };



  int heightChange;

  Node *temp = avlGetReplace( &root->right ,&heightChange);

  printf(" heightChange = %d\n", heightChange);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)804, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node90)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)805, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node110,&node100,&node120,0,806); };



  { customTestAssertEqualNode(&node80,&node50,&node140,1,808); };

  { customTestAssertEqualNode(&node50,&node40,&node70,-1,809); };

  { customTestAssertEqualNode(&node40,&node30,((void *)0),-1,810); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,811); };

  { customTestAssertEqualNode(&node140,&node110,&node150,0,812); };

  { customTestAssertEqualNode(&node150,((void *)0),&node160,1,813); };

}

void test_avlGetReplace_expected_get_node90_BF_of_node_is_0(void){



  Node *root = &node80;

  int cState = avlAdd(&root,&node50);

  cState =avlAdd(&root,&node140);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node70);

  cState =avlAdd(&root,&node100);

  cState =avlAdd(&root,&node150);

  cState =avlAdd(&root,&node30);

  cState =avlAdd(&root,&node90);

  cState =avlAdd(&root,&node110);

  cState =avlAdd(&root,&node160);

  cState =avlAdd(&root,&node105);

  cState =avlAdd(&root,&node120);



  { customTestAssertEqualNode(root,&node50,&node140,1,844); };

  { customTestAssertEqualNode(&node50,&node40,&node70,-1,845); };

  { customTestAssertEqualNode(&node40,&node30,((void *)0),-1,846); };

  { customTestAssertEqualNode(&node140,&node100,&node150,-1,847); };

  { customTestAssertEqualNode(&node90,((void *)0),((void *)0),0,848); };

  { customTestAssertEqualNode(&node110,&node105,&node120,0,849); };

  { customTestAssertEqualNode(&node100,&node90,&node110,1,850); };

  { customTestAssertEqualNode(&node150,((void *)0),&node160,1,851); };



  int heightChange;

  Node *temp = avlGetReplace( &root->right ,&heightChange);

  printf(" heightChange = %d\n", heightChange);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)856, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node90)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)857, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node110,&node100,&node120,-1,858); };



  { customTestAssertEqualNode(&node80,&node50,&node140,1,860); };

  { customTestAssertEqualNode(&node50,&node40,&node70,-1,861); };

  { customTestAssertEqualNode(&node40,&node30,((void *)0),-1,862); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,863); };

  { customTestAssertEqualNode(&node140,&node110,&node150,-1,864); };

  { customTestAssertEqualNode(&node150,((void *)0),&node160,1,865); };

}
