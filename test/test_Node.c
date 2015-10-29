#include "unity.h"
#include "Node.h"
#include "TestCode.h"
void setUp(void){}

void tearDown(void){}

void test_Node_list(void){
  TEST_IGNORE_MESSAGE("Ignore test_Node_list");
  Node *head;
  head = createNode(60);
  initializeTree(head);
  InorderNode(head);
  TEST_ASSERT_ORIGIN_TREE(head);
}


void test_initializeTreeForLRrotateTest(void){
  TEST_IGNORE_MESSAGE("Ignore initializeTreeForLRrotateTest");
  Node *head;
  head = createNode(150);
  initializeTreeForLRrotateTest(head);
  InorderNode(head);
  TEST_ASSERT_ORIGIN_TREE_FOR_LR_ROTATE(head);
}
