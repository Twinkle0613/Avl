#include "unity.h"
#include "Rotation.h"
#include "Node.h"
#include "TestCode.h"
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
  node->left = NULL;
  node->right = NULL;
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
  //TEST_IGNORE_MESSAGE("Ignore test_leftRotate_and_rightRotate");
  Node *head;
  head = createNode(60);
  initializeTree(head);
  TEST_ASSERT_ORIGIN_TREE(head);
  InorderNode(head);
  leftRotate(&head);
  printf("\n");
  InorderNode(head);
  TEST_ASSERT_LEFT_ROTATE_TREE(head);

  printf("\n-------------------------------------------------------\n");
}


void test_rightRotate(void){
  //TEST_IGNORE_MESSAGE("Ignore test_rightRotate");
  Node *head;
  head = createNode(60);
  initializeTree(head);
  TEST_ASSERT_ORIGIN_TREE(head);
  InorderNode(head);
  rightRotate(&head);
  printf("\n");
  InorderNode(head);
  TEST_ASSERT_RIGHT_ROTATE_TREE(head);
  
}


void test_rightLeftRotate(void){
 //TEST_IGNORE_MESSAGE("Ignore test_rightLeftRotate");
  Node *head;
  head = createNode(60);
  initializeTree(head);
  TEST_ASSERT_ORIGIN_TREE(head);
  InorderNode(head);
  rightLeftRotate(&head);
  printf("\n");
  InorderNode(head);
  TEST_ASSERT_RIGHT_LEFT_ROTATE_TREE(head);
}

void test_leftRightRotate(void){
 // TEST_IGNORE_MESSAGE("Ignore test_leftRightRotate");
  Node *head;
  head = createNode(150);
  initializeTreeForLRrotateTest(head);
  TEST_ASSERT_ORIGIN_TREE_FOR_LR_ROTATE(head);
  InorderNode(head);
  leftRightRotate(&head);
  printf("\n");
  InorderNode(head);
  TEST_ASSERT_LEFT_RIGHT_ROTATE_TREE(head);
}

