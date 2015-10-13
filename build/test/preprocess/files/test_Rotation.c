#include "TestCode.h"
#include "Node.h"
#include "Rotation.h"
#include "unity.h"
void setUp(void){}



void tearDown(void){}







void test_leftRotate(void){

  UnityIgnore( ("Ignore test_leftRotate_and_rightRotate"), (_U_UINT)12);;

  node *head;

  head = createNode(60);

  initializeTree(head);

  { UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->right->left->left->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->left->right->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT); };

  InorderNode(head);

  leftRotate(&head);

  printf("\n");

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->left->right->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->left->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->left->right->left->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->left->right->right->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->left->right->right->right->data)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);};



  printf("\n-------------------------------------------------------\n");

}







void test_rightRotate(void){

  UnityIgnore( ("Ignore test_rightRotate"), (_U_UINT)29);;

  node *head;

  head = createNode(60);

  initializeTree(head);

  { UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->right->left->left->data)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->left->right->data)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT); };

  InorderNode(head);

  rightRotate(&head);

  printf("\n");

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->right->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->right->right->left->left->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->right->left->right->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->right->left->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->right->right->left->right->right->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT); };



}







void test_rightLeftRotate(void){

 UnityIgnore( ("Ignore test_rightLeftRotate"), (_U_UINT)45);;

  node *head;

  head = createNode(60);

  initializeTree(head);

  { UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->right->left->left->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->left->right->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT); };

  InorderNode(head);

  rightLeftRotate(&head);

  printf("\n");

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->left->right->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->right->left->right->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT); };

}





void test_leftRightRotate(void){



  node *head;

  head = createNode(150);

  initializeTreeForLRrotateTest(head);

  { UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((180)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->left->right->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((200)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->left->left->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->left->left->right->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->left->right->right->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT); };

  InorderNode(head);

  leftRightRotate(&head);

  printf("\n");

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((180)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->left->left->data)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->left->left->right->data)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT); };

}
