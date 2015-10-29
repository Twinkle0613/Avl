#include "CustomAssertion.h"
#include "Node.h"
#include "Avl.h"
#include "unity.h"


Node node0;

Node node5;

Node node8;

Node node10;

Node node20;

Node node25;

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

  node->left = ((void *)0);

  node->right = ((void *)0);

  node->balanceFactor = 0;

}



void setUp(void){

  resetNode(&node0,0);

  resetNode(&node5,5);

  resetNode(&node8,8);

  resetNode(&node10,10);

  resetNode(&node20,20);

  resetNode(&node25,25);

  resetNode(&node30,30);

  resetNode(&node40,40);

  resetNode(&node50,50);

  resetNode(&node50,55);

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

void test_avlAdd(){

  Node *root = &node30;

  int cState = avlAdd(&root,&node60);

  { customTestAssertEqualNode(root,((void *)0),&node60,1,90); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

}













void test_avlAdd_add_rightNode(){



  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  { customTestAssertEqualNode(root,&node10,((void *)0),-1,103); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);



}

void test_avlAdd_add_rightNode_and_then_add_leftNode(void){



  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  { customTestAssertEqualNode(root,&node10,((void *)0),-1,119); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

  cState = avlAdd(&root,&node60);

  { customTestAssertEqualNode(root,&node10,&node60,0,122); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);

}

 void test_avlAdd_add_node80_into_node30Tree(void){



  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node80);



  { customTestAssertEqualNode(root,&node10,&node60,1,140); };

  { customTestAssertEqualNode(root->right,((void *)0),&node80,1,141); };

  { customTestAssertEqualNode(root->left,((void *)0),((void *)0),0,142); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT);



  }

void test_avlAdd_add_node5_into_node30Tree(void){



  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node5);



  { customTestAssertEqualNode(root,&node10,&node60,0,163); };

  { customTestAssertEqualNode(root->right,((void *)0),&node80,1,164); };

  { customTestAssertEqualNode(root->left,&node5,((void *)0),-1,165); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);



  }

void test_avlAdd_add_node50_into_node30Tree(void){



  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node50);



  { customTestAssertEqualNode(root,&node10,&node60,1,186); };

  { customTestAssertEqualNode(root->right,&node50,&node80,0,187); };

  { customTestAssertEqualNode(root->left,((void *)0),((void *)0),0,188); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);



  }

void test_avlAdd_add_2node5_into_node30Tree(void){



  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node5);



  { customTestAssertEqualNode(root,&node10,&node60,-1,209); };

  { customTestAssertEqualNode(root->right,((void *)0),((void *)0),0,210); };

  { customTestAssertEqualNode(root->left,&node5,((void *)0),-1,211); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)212, UNITY_DISPLAY_STYLE_INT);



  }

void test_avlAdd_add_node20_into_node30Tree(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node20);

  cState =avlAdd(&root,&node5);



  { customTestAssertEqualNode(root,&node10,&node60,-1,232); };

  { customTestAssertEqualNode(root->right,((void *)0),((void *)0),0,233); };

  { customTestAssertEqualNode(root->left,&node5,&node20,0,234); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);



}

void test_avlAdd_add_node90_into_node30Tree(void){



  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node50);

  cState =avlAdd(&root,&node90);

  { customTestAssertEqualNode(&node60,&node30,&node80,0,257); };

  { customTestAssertEqualNode(&node30,&node10,&node50,0,258); };

  { customTestAssertEqualNode(&node80,((void *)0),&node90,1,259); };

  { customTestAssertEqualNode(&node10,((void *)0),((void *)0),0,260); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,261); };

  { customTestAssertEqualNode(&node90,((void *)0),((void *)0),0,262); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);

}

void test_avlAdd_add_node70_into_node30Tree(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node80);

  cState =avlAdd(&root,&node50);

  cState =avlAdd(&root,&node70);

  { customTestAssertEqualNode(&node60,&node30,&node80,0,283); };

  { customTestAssertEqualNode(&node30,&node10,&node50,0,284); };

  { customTestAssertEqualNode(&node80,&node70,((void *)0),-1,285); };

  { customTestAssertEqualNode(&node10,((void *)0),((void *)0),0,286); };

  { customTestAssertEqualNode(&node50,((void *)0),((void *)0),0,287); };

  { customTestAssertEqualNode(&node70,((void *)0),((void *)0),0,288); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)289, UNITY_DISPLAY_STYLE_INT);

}

 void test_avlAdd_add_node25_into_node30Tree(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node20);

  cState =avlAdd(&root,&node5);

  cState =avlAdd(&root,&node0);



  { customTestAssertEqualNode(&node10,&node5,&node30,0,313); };

  { customTestAssertEqualNode(&node5,&node0,((void *)0),-1,314); };

  { customTestAssertEqualNode(&node30,&node20,&node60,0,315); };

  { customTestAssertEqualNode(&node20,((void *)0),((void *)0),0,316); };

  { customTestAssertEqualNode(&node60,((void *)0),((void *)0),0,317); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)318, UNITY_DISPLAY_STYLE_INT);



}

 void test_avlAdd_add_node8_into_node30Tree(void){

  Node *root = &node30;

  int cState = avlAdd(&root,&node10);

  cState =avlAdd(&root,&node60);

  cState =avlAdd(&root,&node20);

  cState =avlAdd(&root,&node5);

  cState =avlAdd(&root,&node8);



  { customTestAssertEqualNode(&node10,&node5,&node30,0,340); };

  { customTestAssertEqualNode(&node5,((void *)0),&node8,1,341); };

  { customTestAssertEqualNode(&node30,&node20,&node60,0,342); };

  { customTestAssertEqualNode(&node20,((void *)0),((void *)0),0,343); };

  { customTestAssertEqualNode(&node60,((void *)0),((void *)0),0,344); };

  UnityAssertEqualNumber((_U_SINT)((cState)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)345, UNITY_DISPLAY_STYLE_INT);



}
