#ifndef TextCode_H
#define TextCode_H


#define TEST_ASSERT_ORIGIN_TREE(head) {                           \
  TEST_ASSERT_EQUAL(60,   head->data);                            \
  TEST_ASSERT_EQUAL(30,   head->left->data);                      \
  TEST_ASSERT_EQUAL(110,  head->right->data);                     \
  TEST_ASSERT_EQUAL(20,   head->left->left->data);                \
  TEST_ASSERT_EQUAL(80,   head->right->left->data);               \
  TEST_ASSERT_EQUAL(150,  head->right->right->data);              \
  TEST_ASSERT_EQUAL(70,   head->right->left->left->data);         \
  TEST_ASSERT_EQUAL(90,   head->right->left->right->data);        \
  TEST_ASSERT_EQUAL(130,  head->right->right->left->data);        \
}


#define TEST_ASSERT_LEFT_ROTATE_TREE(head) {                      \
  TEST_ASSERT_EQUAL(110,   head->data);                           \
  TEST_ASSERT_EQUAL(60,   head->left->data);                      \
  TEST_ASSERT_EQUAL(150,  head->right->data);                     \
  TEST_ASSERT_EQUAL(30,   head->left->left->data);                \
  TEST_ASSERT_EQUAL(80,   head->left->right->data);               \
  TEST_ASSERT_EQUAL(130,  head->right->left->data);               \
  TEST_ASSERT_EQUAL(20,   head->left->left->left->data);          \
  TEST_ASSERT_EQUAL(70,   head->left->right->left->data);         \
  TEST_ASSERT_EQUAL(90,   head->left->right->right->data);        \
  TEST_ASSERT_EQUAL(100,   head->left->right->right->right->data);\
}


#define TEST_ASSERT_RIGHT_ROTATE_TREE(head) {                           \
  TEST_ASSERT_EQUAL(30,   head->data);                                  \
  TEST_ASSERT_EQUAL(20,   head->left->data);                            \
  TEST_ASSERT_EQUAL(60,   head->right->data);                           \
  TEST_ASSERT_EQUAL(110,  head->right->right->data);                    \
  TEST_ASSERT_EQUAL(80,   head->right->right->left->data);              \
  TEST_ASSERT_EQUAL(150,  head->right->right->right->data);             \
  TEST_ASSERT_EQUAL(70,   head->right->right->left->left->data);        \
  TEST_ASSERT_EQUAL(90,   head->right->right->left->right->data);       \
  TEST_ASSERT_EQUAL(130,  head->right->right->right->left->data);       \
  TEST_ASSERT_EQUAL(100,  head->right->right->left->right->right->data);\
  }
  
  
#define TEST_ASSERT_RIGHT_LEFT_ROTATE_TREE(head) {                \
  TEST_ASSERT_EQUAL(80,   head->data);                            \
  TEST_ASSERT_EQUAL(60,   head->left->data);                      \
  TEST_ASSERT_EQUAL(110,  head->right->data);                     \
  TEST_ASSERT_EQUAL(30,   head->left->left->data);                \
  TEST_ASSERT_EQUAL(70,   head->left->right->data);               \
  TEST_ASSERT_EQUAL(90,   head->right->left->data);               \
  TEST_ASSERT_EQUAL(150,  head->right->right->data);              \
  TEST_ASSERT_EQUAL(20,   head->left->left->left->data);          \
  TEST_ASSERT_EQUAL(100,  head->right->left->right->data);        \
  TEST_ASSERT_EQUAL(130,  head->right->right->left->data);        \
}


#define TEST_ASSERT_ORIGIN_TREE_FOR_LR_ROTATE(head) {              \
  TEST_ASSERT_EQUAL(150,   head->data);                            \
  TEST_ASSERT_EQUAL(80,   head->left->data);                       \
  TEST_ASSERT_EQUAL(180,  head->right->data);                      \
  TEST_ASSERT_EQUAL(50,   head->left->left->data);                 \
  TEST_ASSERT_EQUAL(100,   head->left->right->data);               \
  TEST_ASSERT_EQUAL(200,  head->right->right->data);               \
  TEST_ASSERT_EQUAL(30,   head->left->left->left->data);           \
  TEST_ASSERT_EQUAL(60,   head->left->left->right->data);          \
  TEST_ASSERT_EQUAL(110,   head->left->right->right->data);         \
}


#define TEST_ASSERT_LEFT_RIGHT_ROTATE_TREE(head) {                 \
  TEST_ASSERT_EQUAL(100,   head->data);                            \
  TEST_ASSERT_EQUAL(80,   head->left->data);                       \
  TEST_ASSERT_EQUAL(150,  head->right->data);                      \
  TEST_ASSERT_EQUAL(50,   head->left->left->data);                 \
  TEST_ASSERT_EQUAL(110,  head->right->left->data);                \
  TEST_ASSERT_EQUAL(180,  head->right->right->data);               \
  TEST_ASSERT_EQUAL(30,   head->left->left->left->data);           \
  TEST_ASSERT_EQUAL(60,   head->left->left->right->data);          \
}

#define TEST_ASSERT_EQUAL_NODE(root,leftNode,rightNode,w){             \
  TEST_ASSERT_EQUAL(root->left,leftNode);                                   \
  TEST_ASSERT_EQUAL(root->right,rightNode);                                 \
  TEST_ASSERT_EQUAL(root->balanceFactor,w);                                   \
}
#endif // TextCode_H