#include "Node.h"
#include "Rotation.h"
#include "unity.h"
void setUp(void){}



void tearDown(void){}



void test_rigithRotate(void){

  node *head;

  head = createNode(60);

  initializeHead(head);

  preorderNode(head);

  rightRotate(head);

  printf("\n");

  preorderNode(head);

}
