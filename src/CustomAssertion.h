#ifndef CustomAssertion_H
#define CustomAssertion_H

#include "unity.h"

#define TEST_ASSERT_EQUAL_NODE(root,leftNode,rightNode,balanceFactor){       \
 customTestAssertEqualNode(root,leftNode,rightNode,balanceFactor,__LINE__);  \
}


#define CUSTOM_TEST_FAIL(lineNo,msg,...)                        \
        {                                                       \
         char buffer[256];                                      \
         sprintf(buffer,msg, ## __VA_ARGS__);                   \
         UNITY_TEST_FAIL(lineNo,buffer);                        \
        }
        
        
#endif // CustomAssertion_H
