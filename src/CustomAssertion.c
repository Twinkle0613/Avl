#include "CustomAssertion.h"
#include "Node.h"




void customTestAssertEqualNode(Node* root,Node* leftNode, Node* rightNode, int balanceFactor,int lineNo){
      UNITY_TEST_ASSERT_NOT_NULL(root,lineNo,"The Node should not be NULL!");
      UNITY_TEST_ASSERT_EQUAL_INT(leftNode,root->left, lineNo,"The left child is wrong.");
      UNITY_TEST_ASSERT_EQUAL_INT(rightNode,root->right, lineNo,"The right child is wrong.");
      UNITY_TEST_ASSERT_EQUAL_INT(balanceFactor,root->balanceFactor, lineNo,"The balanceFactor is not correct."); 
}

/*     Testing List
 * 1) check the range of Balance Factor. ( BF >= 2 , -2 <= BF)
 * 2) check the value of root and the value of root child.
 *   Example.
 *   (root->left->data < root->data && root->right->data > root->data)
 * 3) verify the height of root.
 * 4) Count node and verify with the input.
 */
void customTestAssertAvlTree(Node* root, int numOfNodes, int height, int lineNo){
    
   UNITY_TEST_ASSERT_EQUAL_INT(numOfNodes,countNode(root),lineNo,"Error: The number of Node is not the same");
   checkNodeValueAndChildValue(root,lineNo);
   checkBalFactorRange(root,lineNo);  
}
void checkNodeValueAndChildValue(Node* root,int lineNo){
  if(root->left != NULL ){
   if(root->left->data > root->data){
    CUSTOM_TEST_FAIL(lineNo,"Error: Expected left-child value(%d) smaller than node value(%d).",\
    root->left->data,root->data);
   } 
   checkNodeValueAndChildValue(root->left,lineNo);
  }
  if(root->right != NULL ){
   if(root->right->data < root->data){
    CUSTOM_TEST_FAIL(lineNo,"Error: Expected right-child value(%d) larger than node value(%d).",\
    root->right->data,root->data);
   }
   checkNodeValueAndChildValue(root->right,lineNo);
  }
}


void checkBalFactorRange(Node* root,int lineNo){
  
  if(root == NULL){
    return; 
  } else if( root->balanceFactor >= 2 || root->balanceFactor <= -2){
     CUSTOM_TEST_FAIL(lineNo,"Error: The node which contain the value is %d its balance factor(%d) is out of the range.",root->data,root->balanceFactor);
  }
  checkBalFactorRange(root->left,lineNo);
  checkBalFactorRange(root->right,lineNo);
}

int countNode(Node *root){
  if(root == NULL){
    return 0;
  }else{
    return (countNode(root->left) + countNode(root->right) + 1);  
  }
  
}

// int getHeightOfTree(Node* root){
  
  // int letfHeight;
  // int rightHeight;
  
  // if( root->left){
    // letfHeight = getHeightOfTree(root->left) + 1;
  // }else{
    // letfHeight = 0;
  // }
  
  // if(root->right){
    // rightHeight = 1;
  // }else{
    // rightHeight = 0;
  // }
  
  // if( leftHeight >= rightHeight ){
   // return leftHeight;
  // }else{
   // return rightHeight;
  // } 
  
// }

