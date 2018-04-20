#include "index.h"

//*************************ǰ�Ṧ��**************************
PNode AddNode(DataType data)        //���ӽ��
{
    PNode p = (PNode)malloc(sizeof(Node));
    if (p != NULL)
    {
        p->data = data;
        p->next = NULL;
        return p;
    }
    assert(p);
    return NULL;
}
 
void SListPushBack(PNode *pHead, DataType data) // β��
{
    assert(pHead);
    if (*pHead == NULL) //����Ϊ������,��ֱ������һ�����
    {
        *pHead = AddNode(data);
    }
    else    
    {
        PNode p = *pHead;
        while (p->next)
        {
            p = p->next;
        }
        p->next = AddNode(data);
    }
}

PNode SListFind(PNode pHead, DataType data) // �������в���ֵΪdata��Ԫ�أ��ҵ��󷵻�ֵΪdata�Ľ�� 
{ 
    if (pHead == NULL) //������Ϊ�գ��򷵻�NULL
    {
        return NULL;         
    }
    else
    {
        PNode pCur = pHead;
        while(pCur)
        {
            if (pCur->data == data)
            {
                return pCur;
            }
            pCur = pCur->next;
        }
        return NULL;
    }
}

int IsSListCross(PNode pHead1, PNode pHead2)    //�ж����������������Ƿ��ཻ
{   
    PNode pTail1 = NULL;
    PNode pTail2 = NULL;
    if (pHead1 == NULL || pHead2 == NULL)   //������һ������Ϊ�գ������
    {
        return -1;
    }
    pTail1 = pHead1;
    pTail2 = pHead2;
    while(pTail1)       //�ҵ���һ���������β��
    {
        pTail1 = pTail1->next;
    }
    while(pTail2)       //�ҵ��ڶ����������β��
    {
        pTail2 = pTail2->next;
    }
    if (pTail1 == pTail2)   //�Ƚ����������β���Ƿ���ͬ
    {
        return 1;
    }
    return 0;
}
//****************************ǰ�Ṧ��********************************




PNode IsListWithCircle(PNode pHead1)  // �жϵ������Ƿ���������������㡣
{
    PNode pFas = NULL;
    PNode pSlo = NULL;
    if (pHead1 == NULL)
    {
        return NULL;
    }
    pFas = pHead1;
    pSlo = pHead1;
    while(pFas && pFas->next)
    {
        pSlo = pSlo->next;
        pFas = pFas->next->next;
        if (pFas == pSlo)
        {
            return pFas;
        }
    }
    return NULL;
}

PNode GetCircleEnter(PNode pHead1, PNode pMeetNode)    // ��ȡ������ڵ�
{
    PNode pHea = pHead1;
    PNode pMee = pMeetNode;
    if(pMeetNode == NULL)
        return NULL;
    while(1)
    {
        if (pHea == pMee)
        {
            return pHea;
        }
        pHea = pHea->next;
        pMee = pMee->next;
    }
}

int GetCircleLen(PNode pMeetNode)  // ��ȡ���ĳ���
{
    PNode pWait = pMeetNode;
    PNode pMove = pMeetNode->next;
    int len = 1;
    while(1)
    {
        if (pWait == pMove)
        {
            return len;
        }
        pMove = pMove->next;
        len++;
    }
}

int IsSListCrossWithCircle(PNode pHead1, PNode pHead2) // �ж����������Ƿ��ཻ��������ܴ���
{
    PNode p1 =  IsListWithCircle(pHead1);
    PNode p2 =  IsListWithCircle(pHead2);
    if (p1 == NULL && p2 == NULL)   //������������
    {
        return IsSListCross(p1, p2);
    }
    if (p1 && p2)   //����������
    {
        int n = GetCircleLen(pHead1);   
        while(n--)
        {
            if (p1 == p2)
            {
                return 1;
            }
            p1 = p1->next;
        }
    }
    return -1;
}

PNode MeetingNodeWithCircle(PNode pHead1, PNode pHead2) //�����������ཻ�㣨��֪�ཻ��
{
    PNode pC1 = GetCircleEnter(pHead1, IsListWithCircle(pHead1));  //�õ�����1�Ļ���ڵ�
    PNode pC2 = GetCircleEnter(pHead2, IsListWithCircle(pHead2));  //�õ�����2�Ļ���ڵ�
    PNode pH1 = pHead1;
    PNode pH2 = pHead2;
    int len1 = 1;
    int len2 = 1;
    int SubLen = 0;
    if (pC1 != pC2)   //��Ӧͼ�������
    {
        return pC1;
    }
    while(pH1 != pC1)   //�����һ�������ͷ������ڵ�ĳ���
    {
        len1++;
        pH1 = pH1->next;
    }
    while(pH2 != pC1)   //����ڶ��������ͷ������ڵ�ĳ���
    {
        len2++;
        pH2 = pH2->next;
    }
    pH1 = pHead1;
    pH2 = pHead2;
    if (len1 >= len2)   //�ó��Ƚϳ��Ķ�Ӧ��ָ������SubLen��
    {
        SubLen = len1-len2;
        while(SubLen--)
        {
            pH1 = pH1->next;
        }
    }
    else
    {
        SubLen = len2-len1;
        while(SubLen--)
        {
            pH2 = pH2->next;
        }
    }
    while(pH1 != pH2)   //��ָ��һ���ߣ�������һ����ͬ�Ľ���ͣ����
    {
        pH1 = pH1->next;
        pH2 = pH2->next;
    }
    return pH1; //���ص�һ�������� 
}




PNode CopyComplexList(PNode pHead)   // ����������
{
    PNode pHead2 = NULL;
    PNode pNext = NULL; //ԭ����ĵ�ǰ���
    PNode pCur = NULL;  //ԭ����ǰ������һ�����
    if (pHead == NULL)
    {
        return NULL;
    }

//��ԭ����ÿ���������ֵ��ͬ���½�� 
    pCur = pHead;
    pNext = pHead->next;    
    while(pNext)
    {
        pCur->next = AddNode(pCur->data);   //�ڵ�ǰ�������ֵ��ͬ���½��
        pCur->next->next = pNext;           //�޸��½���nextָ�룬ʹ��ָ��ԭ����ǰ������һ�����
        pCur = pNext;                       //�ƶ�pCurָ��
        pNext = pNext->next;                //�ƶ�pNextָ��
    }
    pCur->next = AddNode(pCur->data);       //�������һ����㣬��nextΪNULL���赥������
    pCur->next->next = pNext;
 
//���²���������ָ����ֵ
    pCur = pHead;
    pNext = pHead->next;
    while(pNext->next)  //����ԭ������ǰn-1������randomָ��ָ��
    {
        if (pCur->random == NULL)
        {
            pNext->random = NULL;
        }
        else
        {
            pNext->random = pCur->random->next;
            pCur = pNext->next;
            pNext = pCur->next;
        }    
    }
    if (pCur->random == NULL)   //�����һ����㣬���⴦��
        pNext->random = NULL;
    else
        pNext->random = pCur->random->next;

//���½���ԭ���������²�����
    pCur = pHead;
    pNext = pHead->next;
    pHead2 = pHead->next;
    while(pNext->next)  //��ԭ�����е�ǰn-1����������
    {
        pCur->next = pNext->next;
        pNext->next = pCur->next->next;
        pCur = pCur->next;
        pNext = pNext->next;
    }
     pCur->next = pNext->next;  //���һ��������⴦��

     return pHead2;
}

void UnionSet(PNode pHead1, PNode pHead2)   //��������������������ͬ�����ݡ�
{
    PNode p1 = pHead1;
    PNode p2 = pHead2;
    int flag = 0;
    if (pHead1 == NULL || pHead2 == NULL)
    {
        return;
    }
    while(p1&&p2)
    {   
        if ((p1->data == p2->data) && (flag == 0) )
        {   
            printf("%d ", p1->data);
            flag = 1;
            p1 = p1->next;
            continue;
        }
        if((p1->data == p2->data) && (flag == 1))
        {
            p1 = p1->next;
            continue;
        }
        flag = 0;
        if (p1->data < p2->data)
            p1 = p1->next;
        else
            p2 = p2->next;
    }
}