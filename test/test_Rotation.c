#include "unity.h"
#include "Rotation.h"
#include "Node.h"
#include "TestCode.h"
void setUp(void){}

void tearDown(void){}

// The diagram about the concept of left rotation can be find in Avl/diagram/Rotation.pdf

void test_leftRotate(void){
  TEST_IGNORE_MESSAGE("Ignore test_leftRotate_and_rightRotate");
  node *head;
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

// The diagram about the concept of right rotation can be find in Avl/diagram/Rotation.pdf

void test_rightRotate(void){
  TEST_IGNORE_MESSAGE("Ignore test_rightRotate");
  node *head;
  head = createNode(60);
  initializeTree(head);
  TEST_ASSERT_ORIGIN_TREE(head);
  InorderNode(head);
  rightRotate(&head);
  printf("\n");
  InorderNode(head);
  TEST_ASSERT_RIGHT_ROTATE_TREE(head);
  
}

// The diagram about the concept of right-left rotation can be find in Avl/diagram/Rotation.pdf

void test_rightLeftRotate(void){
 TEST_IGNORE_MESSAGE("Ignore test_rightLeftRotate");
  node *head;
  head = createNode(60);
  initializeTree(head);
  TEST_ASSERT_ORIGIN_TREE(head);
  InorderNode(head);
  rightLeftRotate(&head);
  printf("\n");
  InorderNode(head);
  TEST_ASSERT_RIGHT_LEFT_ROTATE_TREE(head);
}
// The diagram about the concept of left-right rotation can be find in Avl/diagram/Rotation.pdf

void test_leftRightRotate(void){
 // TEST_IGNORE_MESSAGE("Ignore test_leftRightRotate");
  node *head;
  head = createNode(150);
  initializeTreeForLRrotateTest(head);
  TEST_ASSERT_ORIGIN_TREE_FOR_LR_ROTATE(head);
  InorderNode(head);
  leftRightRotate(&head);
  printf("\n");
  InorderNode(head);
  TEST_ASSERT_LEFT_RIGHT_ROTATE_TREE(head);
}

