#include <stdio.h>

BinaryTreeNode *Construct(int *preorder, int *inorder, int length) {
  if (preorder == NULL || inorder == NULL || length <= 0) {
    return NULL;
  }
  return ConstructCore(preorder, preorder+length-1, inorder, inorder + length - 1);
}

struct BinaryTreeNode *ConstructCore )
  int *startPreorder,int *endPreorder,
  int *startInorder, int *endInorder
){
  int rootValue = startPreorder[0];
  BinaryTreeNode *root  = new BinaryTreeNode();
  root->m_nValue = rootValue;
}

int main(){
	printf("hello world\n");
	return 0;
}
