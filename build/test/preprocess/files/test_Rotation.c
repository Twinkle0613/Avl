#include "TestCode.h"
#include "Node.h"
#include "Rotation.h"
#include "unity.h"
Node node20;

Node node30;

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

}



void setUp(void){

  resetNode(&node20,20);

  resetNode(&node30,30);

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



void tearDown(void){}







void test_leftRotate(void){



  Node *head;

  head = createNode(60);

  initializeTree(head);

  { UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->right->left->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->left->right->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); };

  InorderNode(head);

  leftRotate(&head);

  printf("\n");

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->left->right->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->left->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->left->right->left->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->left->right->right->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->left->right->right->right->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);};



  printf("\n-------------------------------------------------------\n");

}





void test_rightRotate(void){



  Node *head;

  head = createNode(60);

  initializeTree(head);

  { UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->right->left->left->data)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->left->right->data)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT); };

  InorderNode(head);

  rightRotate(&head);

  printf("\n");

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->right->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->right->right->left->left->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->right->left->right->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->right->left->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->right->right->left->right->right->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT); };



}





void test_rightLeftRotate(void){



  Node *head;

  head = createNode(60);

  initializeTree(head);

  { UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->right->left->left->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->left->right->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); };

  InorderNode(head);

  rightLeftRotate(&head);

  printf("\n");

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->left->right->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->left->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->right->left->right->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT); };

}



void test_leftRightRotate(void){



  Node *head;

  head = createNode(150);

  initializeTreeForLRrotateTest(head);

  { UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((180)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->left->right->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((200)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->left->left->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->left->left->right->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->left->right->right->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT); };

  InorderNode(head);

  leftRightRotate(&head);

  printf("\n");

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((180)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->left->left->data)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->left->left->right->data)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT); };

}
