#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#pragma once

typedef int DataType;

typedef struct PNode{
    DataType data;
    struct PNode *next;
    struct PNode *random;
}*PNode, Node;

//*************************前提功能**************************
PNode AddNode(DataType data);        //增加结点
void SListPushBack(PNode *pHead, DataType data); // 尾插
PNode SListFind(PNode pHead, DataType data); // 在链表中查找值为data的元素，找到后返回值为data的结点 
//**************************************************************

PNode IsListWithCircle(PNode pHead1);   // 判断单链表是否带环，返回相遇点。
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode);    // 获取环的入口点
int GetCircleLen(PNode pMeetNode);  // 获取环的长度
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2); // 判断两个链表是否相交，链表可能带环
PNode CopyComplexList(PNode pHead);   // 复杂链表复制
void UnionSet(Node* l1,Node* l2);   //求两个已排序单链表中相同的数据。