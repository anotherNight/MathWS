#include <stdio.h>

typedef struct BTNode{
  int data;
  struct BTNode *lChild;
  struct BTNode *rChild;
}BiTNode;

int CreateBiTree(BiTNode **T){
  int ch;
  scanf("%d\n", &ch);
  if (ch == -1) {
    *T = NULL;
    return 0;
  }else {
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    if (T == NULL) {
      printf("failed\n");
      return 0;
    }else {
      (*T)->data = ch;
      printf("input %d left node:\n", ch);
      CreateBiTree(&(*T)->lChild);
      printf("input %d right node:\n", ch);
      CreateBiTree(&(*T)->rChild);
    }
  }
  return 1;
}

void PreOrderBiTree(BiTNode *T) {
  if (T == NULL) {
    return;
  }else {
    printf("%d\n", T->data);
    PreOrderBiTree(T->lChild);
    PreOrderBiTree(T->rChild);
  }
}

void MiddleOrderBiTree(BiTNode *T) {
  if (T == NULL) {
    return;
  }else {
    MiddleOrderBiTree(T->lChild);
    printf("%d\n", T->data);
    MiddleOrderBiTree(T->rChild);
  }
}

void PostOrderBiTree(BiTNode *T) {
  if (T == NULL) {
    return;
  }else {
    PostOrderBiTree(T->lChild);
    PostOrderBiTree(T->rChild);
    printf("%d\n", T->data);
  }
}

int TreeDeep(BiTNode *T) {
  int deep = 0;
  if (T != NULL) {
    int leftdeep = TreeDeep(T->lChild);
    int rightdeep = TreeDeep(T->rChild);
    deep = leftdeep >= rightdeep?leftdeep:rightdeep;
    deep++;
  }
  return deep;
}

int LeafCount(BiTNode *T) {
  static int count;
  if (T != NULL) {
    if (T->lChild == NULL && T->rChild == NULL) {
      count++;
    }
    LeafCount(T->lChild);
    LeafCount(T->rChild);
  }
  return count;
}

int main(){
  BiTNode *T;
    int depth,leafCount = 0;
    printf("请输入第一个节点的值，-1表示没有叶节点：\n");
    CreateBiTree(&T);

    printf("先序遍历二叉树：");
    PreOrderBiTree(T);
    printf("\n");

    printf("中序遍历二叉树：");
    MiddleOrderBiTree(T);
    printf("\n");

    printf("后续遍历二叉树：");
    PostOrderBiTree(T);
    printf("\n");

    depth = TreeDeep(T);
    printf("树的深度为：%d\n",depth);

    leafCount = LeafCount(T);
    printf("叶子节点个数:%d\n",leafCount);

	return 0;
}
