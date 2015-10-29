#include "TestCode.h"
#include "Node.h"
#include "unity.h"
void setUp(void){}



void tearDown(void){}



void test_Node_list(void){

  UnityIgnore( ("Ignore test_Node_list"), (_U_UINT)9);;

  Node *head;

  head = createNode(60);

  initializeTree(head);

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->right->left->data)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((head->right->left->left->data)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((head->right->left->right->data)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((130)), (_U_SINT)((head->right->right->left->data)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT); };

}





void test_initializeTreeForLRrotateTest(void){

  UnityIgnore( ("Ignore initializeTreeForLRrotateTest"), (_U_UINT)19);;

  Node *head;

  head = createNode(150);

  initializeTreeForLRrotateTest(head);

  InorderNode(head);

  { UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((head->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((head->left->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((180)), (_U_SINT)((head->right->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((head->left->left->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((head->left->right->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((200)), (_U_SINT)((head->right->right->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((head->left->left->left->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((head->left->left->right->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((head->left->right->right->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT); };

}
