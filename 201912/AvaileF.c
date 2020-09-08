#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Heap
{
    char data[10000];
    int top;
};

int pushHeap(struct  Heap *heap,char x)
{
    heap->top=heap->top+1;
    heap->data[heap->top]=x;
    return 1;
};

int pullHeap(struct Heap *heap)
{
    heap->top = heap->top-1;
    return 1;
};

bool isValid(char* s){
    struct Heap *p = (struct Heap *)malloc(sizeof(struct Heap));
    p->top = 0;
    if (strlen(s) == 0) 
    {
        return true;
    }
    pushHeap(p,s[0]);
    for (int i = 1; i < strlen(s); i++)
    {
        if (p->data[p->top]=='[')
        {
            if (s[i]==']')
            {
                pullHeap(p);
            }else
            {
                pushHeap(p,s[i]);
            }
        }else if (p->data[p->top]=='{')
        {
            if (s[i]=='}')
            {
                pullHeap(p);
            }else
            {
                pushHeap(p,s[i]);
            }
        }else if (p->data[p->top]=='(')
        {
            if (s[i]==')')
            {
                pullHeap(p);
            }else
            {
                pushHeap(p,s[i]);
            }
        }else
        {
            pushHeap(p,s[i]);
        }
    }
    if (p->top == 0)
    {
        return true;
    }else
    {
        return false;
    }
    
    
    
    
}

int compare(char *list, int length){
    
    return 0;
}

int main(){
    char *s=((char*)malloc(sizeof(char*)*10000));
    s="[(])]";
    bool i=isValid(s);
    printf("%d\n",i);
    return 0;
}