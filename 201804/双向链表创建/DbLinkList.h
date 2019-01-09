#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
	int data;
	struct Node *pNext;
	struct Node *pPre;
}NODE,*pNODE;

//create
pNODE CreateDbLinkList(void);

//printf node list
void TraverseDbLinkList(pNODE pHead);

int IsEmptyDbLinkList(pNODE pHead);

int GetLengthDbLinkList(pNODE pHead);

int InsertEleDbLinkList(pNODE pHead, int pos, int data);

int DeleteEleDbLinkList (pNODE pHead, int pos);

//delete free memory
void FreeMemory(pNODE *ppHead);

#endif
