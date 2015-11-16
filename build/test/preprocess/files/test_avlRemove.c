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

void test_avlRemove_remove_node60_in_tree(void){

    Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  { customTestAssertEqualNode(&node30,&node10,&node60,0,92); };

  int heightChange;

  Node *temp = avlRemove(&root,10,&heightChange);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node30,((void *)0),&node60,1,96); };



}

void test_avlRemove_remove_node10_in_tree(void){

    Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  { customTestAssertEqualNode(&node30,&node10,&node60,0,112); };

  int heightChange;

  Node *temp = avlRemove(&root,60,&heightChange);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node60)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node30,&node10,((void *)0),-1,116); };

}

 void test_avlRemove_remove_node5_in_tree(void){

    Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node5);

  int heightChange;

  Node *temp = avlRemove(&root,5,&heightChange);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(&node30,&node10,&node60,0,136); };

}

void test_avlRemove_remove_node5_and_given_the_bal_factor_of_node60_is_0(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node50);

  cState =avlAdd(&root,&node70);



  int heightChange;

  Node *temp = avlRemove(&root,10,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node70,-1,160); };

  { customTestAssertEqualNode(&node30,((void *)0),&node50,1,161); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,162); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,163); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)190, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node70,0,191); };

  { customTestAssertEqualNode(&node30,&node10,&node50,0,192); };

  { customTestAssertEqualNode(&node70,((void *)0),&node80,1,193); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,194); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,195); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node70,0,224); };

  { customTestAssertEqualNode(&node30,&node10,&node50,0,225); };

  { customTestAssertEqualNode(&node70,&node65,((void *)0),-1,226); };

  { customTestAssertEqualNode(&node65,((void *)0),((void *)0),0,227); };

  { customTestAssertEqualNode(&node10,((void *)0),((void *)0),0,228); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,229); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)258, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node5)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node70,0,260); };

  { customTestAssertEqualNode(&node30,&node10,&node50,0,261); };

  { customTestAssertEqualNode(&node70,&node65,&node80,0,262); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,263); };

  { customTestAssertEqualNode(&node65,((void *)0),((void *)0),0,264); };

  { customTestAssertEqualNode(&node10,((void *)0),((void *)0),0,265); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,266); };

}

void test_avlRemove_remove_node130_and_given_the_bal_factor_of_node60_is_0(void){

  Node *root = &node100;

  int cState = avlAdd(&root,&node60);

  cState =avlAdd(&root,&node130);

  cState =avlAdd(&root,&node40);

  cState =avlAdd(&root,&node80);



  int heightChange;

  Node *temp = avlRemove(&root,130,&heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)291, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node130)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)292, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node40,&node100,1,293); };

  { customTestAssertEqualNode(&node100,&node80,((void *)0),-1,294); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,295); };

  { customTestAssertEqualNode(&node40,((void *)0),((void *)0),0,296); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)321, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)322, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node40,&node100,0,323); };

  { customTestAssertEqualNode(&node100,&node80,&node130,0,324); };

  { customTestAssertEqualNode(&node40,((void *)0),&node50,1,325); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,326); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,327); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,328); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)351, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)352, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node40,&node100,0,353); };

  { customTestAssertEqualNode(&node100,&node80,&node130,0,354); };

  { customTestAssertEqualNode(&node40,&node30,((void *)0),-1,355); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,356); };

  { customTestAssertEqualNode(&node30,((void *)0),((void *)0),0,357); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,358); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)384, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)385, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node40,&node100,0,386); };

  { customTestAssertEqualNode(&node100,&node80,&node130,0,387); };

  { customTestAssertEqualNode(&node40,&node30,&node50,0,388); };

  { customTestAssertEqualNode(&node80,((void *)0),((void *)0),0,389); };

  { customTestAssertEqualNode(&node30,((void *)0),((void *)0),0,390); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,391); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)418, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)419, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node60,0,420); };

  { customTestAssertEqualNode(root->left,&node20,&node35,0,421); };

  { customTestAssertEqualNode(root->right,&node50,&node70,0,422); };

  { customTestAssertEqualNode(&node20,((void *)0),((void *)0),0,423); };

  { customTestAssertEqualNode(&node35,((void *)0),((void *)0),0,424); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,425); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,426); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)451, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)452, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node60,0,453); };

  { customTestAssertEqualNode(root->left,&node20,&node35,0,454); };

  { customTestAssertEqualNode(root->right,((void *)0),&node70,1,455); };

  { customTestAssertEqualNode(&node20,((void *)0),((void *)0),0,456); };

  { customTestAssertEqualNode(&node35,((void *)0),((void *)0),0,457); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,458); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)483, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node10)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)484, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node30,&node60,0,485); };

  { customTestAssertEqualNode(root->left,&node20,((void *)0),-1,486); };

  { customTestAssertEqualNode(root->right,&node50,&node70,0,487); };

  { customTestAssertEqualNode(&node20,((void *)0),((void *)0),0,488); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,489); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,490); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)519, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)520, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node60,&node100,0,521); };

  { customTestAssertEqualNode(&node100,&node90,&node130,0,522); };

  { customTestAssertEqualNode(&node60,&node40,&node70,0,523); };

  { customTestAssertEqualNode(&node40,((void *)0),((void *)0),0,524); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,525); };

  { customTestAssertEqualNode(&node90,((void *)0),((void *)0),0,526); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,527); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)554, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)555, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node60,&node100,0,556); };

  { customTestAssertEqualNode(&node100,((void *)0),&node130,1,557); };

  { customTestAssertEqualNode(&node60,&node40,&node70,0,558); };

  { customTestAssertEqualNode(&node40,((void *)0),((void *)0),0,559); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,560); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,561); };

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



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((heightChange)), (((void *)0)), (_U_UINT)587, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&node140)), (_U_SINT)(_UP)((temp)), (((void *)0)), (_U_UINT)588, UNITY_DISPLAY_STYLE_HEX32);

  { customTestAssertEqualNode(root,&node60,&node100,0,589); };

  { customTestAssertEqualNode(&node100,&node90,&node130,0,590); };

  { customTestAssertEqualNode(&node60,&node40,((void *)0),-1,591); };

  { customTestAssertEqualNode(&node40,((void *)0),((void *)0),0,592); };

  { customTestAssertEqualNode(&node90,((void *)0),((void *)0),0,593); };

  { customTestAssertEqualNode(&node130,((void *)0),((void *)0),0,594); };

}
