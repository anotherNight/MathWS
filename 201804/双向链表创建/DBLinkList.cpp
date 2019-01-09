#include <stdio.h>
#include <stdlib.h>
#include "DbLinkList.h"

pNode CreateDbLinkList (void) {
  int i,length = 0,data = 0;
  pNode pTail = NULL, p_new = NULL:
  pNode pHead = (pNODE)malloc(sizeof(NODE));

  if (pHead == NULL) {
    printf("malloc error\n");
    exit(EXIT_FAILURE);
  }

  pHead->data = 0;
  pHead->pPre = NULL;
  pHead->pNext = NULL;
  pTail = pHead;

  printf("enter list length\n");
  scanf("%d\n",&length );

  for ( i = 0; i < length+1; i++) {
    p_new = (pNODE)malloc(sizeof(NODE));

    if (p_new == NULL) {
      printf("p_new malloc fail\n");
      exit(EXIT_FAILURE);
    }

    printf("please enter the %d element:\n", i);
    scanf("%d\n", &data);

    p_new->data = data;
    p_new->pNext = NULL;
    p_new->pPre = pTail;
    pTail->pNext = p_new;
    pTail = p_new;
  }
  return pHead;
}


void TraverseDbLinkList(pNODE pHead) {
  pNODE pt = pHead->pNext;

  printf("the node list :\n");
  while (pt != NULL) {
    printf("%d\n", pt->data);
    pt = pt->pNext;
  }
  putchar('\n');
}

int IsEmptyDbLinkList(pNODE pHead) {
  pNODE pt = pHead->pNext;

  if (p == NULL) {
    return 1;
  }else {
    return 0;
  }
}

int GetLengthDbLinkList (pNODE pHead) {
  int length = 0;
  pNODE pt = pHead->pNext;

  while (pt != NULL) {
    length ++;
    pt = pt->pNext;
  }
  return length;
}

int InsertEleDbLinkList (pNODE pHead, int pos, int data){
  pNODE pt = NULL, p_new = NULL;
  if (pos > 0 && pos < GetLengthDbLinkList(pHead)+2) {
    p_new = (pNODE)malloc(sizeof(NODE));

    if (p_new == NULL) {
      printf("malloc fail\n");
      exit(EXIT_FAILURE);
    }

    while (1) {
      pos --;
      if (pos == 0) {
        break;
      }
      pHead = pHead->pNext;
    }

    pt = pHead->pNext;
    p_new->data = data;
    p_new->pNext = pt;
    if (pt != NULL) {
      pt->pPre = p_new;
    }
    p_new->pPre = pHead;
    pHead->pNext = p_new;

    return 1;
  }else
    return 0;
}

int DeleteEleDbLinkList(pNODE pHead, int pos){
  pNODE pt = NULL;

  if (pos > 0 && pos < GetLengthDbLinkList(pHead) + 1) {
    while (1) {
      pos --;
      if (pos == 0) {
        break;
      }
      pHead = pHead->pNext;
    }

    pt = pHead->pNext->pNext;
    free(pHead->pNext);
    pHead->pNext = pt;
    if (pt != NULL) {
      pt->pPre = pHead;
    }

    return 1;
  }else {
    return 0;
  }
}

void FreeMemory(pNODE *ppHead) {
  pNODE pt = NULL:

  while (*ppHead != NULL) {
    pt = (*ppHead)->pNext;
    free(*ppHead);
    if (pt != NULL) {
      pt->pPre = NULL;
    }
    *ppHead = pt;
  }
}
