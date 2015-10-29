/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_avlAdd(void);
extern void test_avlAdd_add_rightNode(void);
extern void test_avlAdd_add_rightNode_and_then_add_leftNode(void);
extern void test_avlAdd_add_node80_into_node30Tree(void);
extern void test_avlAdd_add_node5_into_node30Tree(void);
extern void test_avlAdd_add_node50_into_node30Tree(void);
extern void test_avlAdd_add_2node5_into_node30Tree(void);
extern void test_avlAdd_add_node20_into_node30Tree(void);
extern void test_avlAdd_add_node90_into_node30Tree(void);
extern void test_avlAdd_add_node70_into_node30Tree(void);
extern void test_avlAdd_add_node25_into_node30Tree(void);
extern void test_avlAdd_add_node8_into_node30Tree(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin("test_Avl.c");
  RUN_TEST(test_avlAdd, 87);
  RUN_TEST(test_avlAdd_add_rightNode, 99);
  RUN_TEST(test_avlAdd_add_rightNode_and_then_add_leftNode, 115);
  RUN_TEST(test_avlAdd_add_node80_into_node30Tree, 133);
  RUN_TEST(test_avlAdd_add_node5_into_node30Tree, 155);
  RUN_TEST(test_avlAdd_add_node50_into_node30Tree, 178);
  RUN_TEST(test_avlAdd_add_2node5_into_node30Tree, 202);
  RUN_TEST(test_avlAdd_add_node20_into_node30Tree, 225);
  RUN_TEST(test_avlAdd_add_node90_into_node30Tree, 249);
  RUN_TEST(test_avlAdd_add_node70_into_node30Tree, 276);
  RUN_TEST(test_avlAdd_add_node25_into_node30Tree, 305);
  RUN_TEST(test_avlAdd_add_node8_into_node30Tree, 332);

  return (UnityEnd());
}
