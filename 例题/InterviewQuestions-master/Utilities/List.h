// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���
#pragma once

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

//#define open TRUE

#ifdef open
#define isdllexport __declspec(dllexport)
#else
#define  isdllexport
#endif

isdllexport ListNode* CreateListNode(int value);
isdllexport void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
isdllexport  void PrintListNode(ListNode* pNode);
isdllexport void PrintList(ListNode* pHead);
isdllexport void DestroyList(ListNode* pHead);
isdllexport void AddToTail(ListNode** pHead, int value);
isdllexport void RemoveNode(ListNode** pHead, int value);