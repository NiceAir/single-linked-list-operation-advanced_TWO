#include "index.h"

//*************************前提功能**************************
PNode AddNode(DataType data)        //增加结点
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
 
void SListPushBack(PNode *pHead, DataType data) // 尾插
{
    assert(pHead);
    if (*pHead == NULL) //链表为空链表,则直接增加一个结点
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

PNode SListFind(PNode pHead, DataType data) // 在链表中查找值为data的元素，找到后返回值为data的结点 
{ 
    if (pHead == NULL) //若链表为空，则返回NULL
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

int IsSListCross(PNode pHead1, PNode pHead2)    //判断两不带环单链表是否相交
{   
    PNode pTail1 = NULL;
    PNode pTail2 = NULL;
    if (pHead1 == NULL || pHead2 == NULL)   //若其中一个链表为空，则错误
    {
        return -1;
    }
    pTail1 = pHead1;
    pTail2 = pHead2;
    while(pTail1)       //找到第一个单链表的尾部
    {
        pTail1 = pTail1->next;
    }
    while(pTail2)       //找到第二个单链表的尾部
    {
        pTail2 = pTail2->next;
    }
    if (pTail1 == pTail2)   //比较两个链表的尾部是否相同
    {
        return 1;
    }
    return 0;
}
//****************************前提功能********************************




PNode IsListWithCircle(PNode pHead1)  // 判断单链表是否带环，返回相遇点。
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

PNode GetCircleEnter(PNode pHead1, PNode pMeetNode)    // 获取环的入口点
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

int GetCircleLen(PNode pMeetNode)  // 获取环的长度
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

int IsSListCrossWithCircle(PNode pHead1, PNode pHead2) // 判断两个链表是否相交，链表可能带环
{
    PNode p1 =  IsListWithCircle(pHead1);
    PNode p2 =  IsListWithCircle(pHead2);
    if (p1 == NULL && p2 == NULL)   //两链表都不带环
    {
        return IsSListCross(p1, p2);
    }
    if (p1 && p2)   //两链表都带环
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

PNode MeetingNodeWithCircle(PNode pHead1, PNode pHead2) //求带环链表的相交点（已知相交）
{
    PNode pC1 = GetCircleEnter(pHead1, IsListWithCircle(pHead1));  //得到链表1的环入口点
    PNode pC2 = GetCircleEnter(pHead2, IsListWithCircle(pHead2));  //得到链表2的环入口点
    PNode pH1 = pHead1;
    PNode pH2 = pHead2;
    int len1 = 1;
    int len2 = 1;
    int SubLen = 0;
    if (pC1 != pC2)   //对应图二的情况
    {
        return pC1;
    }
    while(pH1 != pC1)   //求出第一条链表从头到环入口点的长度
    {
        len1++;
        pH1 = pH1->next;
    }
    while(pH2 != pC1)   //求出第二条链表从头到环入口点的长度
    {
        len2++;
        pH2 = pH2->next;
    }
    pH1 = pHead1;
    pH2 = pHead2;
    if (len1 >= len2)   //让长度较长的对应的指针先走SubLen步
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
    while(pH1 != pH2)   //两指针一起走，遇到第一个相同的结点就停下来
    {
        pH1 = pH1->next;
        pH2 = pH2->next;
    }
    return pH1; //返回第一次相遇点 
}




PNode CopyComplexList(PNode pHead)   // 复杂链表复制
{
    PNode pHead2 = NULL;
    PNode pNext = NULL; //原链表的当前结点
    PNode pCur = NULL;  //原链表当前结点的下一个结点
    if (pHead == NULL)
    {
        return NULL;
    }

//给原链表每个结点后插入值相同的新结点 
    pCur = pHead;
    pNext = pHead->next;    
    while(pNext)
    {
        pCur->next = AddNode(pCur->data);   //在当前结点后插入值相同的新结点
        pCur->next->next = pNext;           //修改新结点的next指针，使其指向原链表当前结点的下一个结点
        pCur = pNext;                       //移动pCur指针
        pNext = pNext->next;                //移动pNext指针
    }
    pCur->next = AddNode(pCur->data);       //对于最后一个结点，其next为NULL。需单独处理
    pCur->next->next = pNext;
 
//给新插入结点的随机指针域赋值
    pCur = pHead;
    pNext = pHead->next;
    while(pNext->next)  //复制原链表中前n-1个结点的random指针指向
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
    if (pCur->random == NULL)   //对最后一个结点，特殊处理
        pNext->random = NULL;
    else
        pNext->random = pCur->random->next;

//将新结点从原来表上重新拆下来
    pCur = pHead;
    pNext = pHead->next;
    pHead2 = pHead->next;
    while(pNext->next)  //将原链表中的前n-1个结点拆下来
    {
        pCur->next = pNext->next;
        pNext->next = pCur->next->next;
        pCur = pCur->next;
        pNext = pNext->next;
    }
     pCur->next = pNext->next;  //最后一个结点特殊处理

     return pHead2;
}

void UnionSet(PNode pHead1, PNode pHead2)   //求两个已排序单链表中相同的数据。
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