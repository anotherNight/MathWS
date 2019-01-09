#include <stdio.h>

void PrintListReversingly_Iteratively(ListNode* pHead){
  std::stack<ListNode*> nodes;
  ListNode* pNode = pHead;
  while(pNode != NULL){
    nodes.push(pNode);
    pNode = pNode->m_pNext;
  }
  while (!nodes.empty()) {
    pNode = nodes.top();
    printf("%d\t",pNode->m_nValue);
    nodes.pop();
  }
}

Node * create(){
   node *head=NULL;//表头指针，一开始没有任何结点，所以为NULL
   node *pEnd=head;//表为指针，一开始没有任何结点，所以指向表头
   node *pS;//创建新结点时使用的指针
   char temp;//用于存放从键盘输入的字符
   cout <<"Please input a string end with '#':" <<endl;
   do//循环至少运行一次
   {
      cin >>temp;
      if (temp!='#')//如果输入的字符不是结尾符#，则建立新结点
      {
         pS=new node;//创建新结点
         pS->data=temp;//新结点的数据为temp
         pS->next=NULL;//新结点将成为表尾，所以next为NULL
         if (head==NULL)//如果链表还没有任何结点存在
         {
            head=pS;//则表头指针指向这个新结点
         }
         else//否则
         {
            pEnd->next=pS;//把这个新结点连接在表尾
         }
         pEnd=pS;//这个新结点成为了新的表尾
      }
   }
   while (temp!='#');//一旦输入了结尾符，则跳出循环
   return head;//返回表头指针
}
int int main(int argc, char const *argv[]) {
  Node *pNext
  return 0;
}
