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

//*************************ǰ�Ṧ��**************************
PNode AddNode(DataType data);        //���ӽ��
void SListPushBack(PNode *pHead, DataType data); // β��
PNode SListFind(PNode pHead, DataType data); // �������в���ֵΪdata��Ԫ�أ��ҵ��󷵻�ֵΪdata�Ľ�� 
//**************************************************************

PNode IsListWithCircle(PNode pHead1);   // �жϵ������Ƿ���������������㡣
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode);    // ��ȡ������ڵ�
int GetCircleLen(PNode pMeetNode);  // ��ȡ���ĳ���
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2); // �ж����������Ƿ��ཻ��������ܴ���
PNode CopyComplexList(PNode pHead);   // ����������
void UnionSet(Node* l1,Node* l2);   //��������������������ͬ�����ݡ�