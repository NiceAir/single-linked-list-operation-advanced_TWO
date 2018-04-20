#include "index.h"
int main()
{
    PNode pHead = NULL;
    
//*****************test_IsListWithCircle***************
    //PNode pRes = NULL;
    //SListPushBack(&pHead, 1);
    //SListPushBack(&pHead, 2);
    //SListPushBack(&pHead, 3);
    //SListPushBack(&pHead, 4);
    //SListPushBack(&pHead, 5);
    //SListPushBack(&pHead, 6);
    //SListFind(pHead, 6)->next = SListFind(pHead, 1);
    //pRes = IsListWithCircle(pHead);
    //printf("len = %d\n", GetCircleLen(pRes));
    //pRes = GetCircleEnter(pHead, pRes);

//******************test_UnionSet*********************
    PNode pHead2 = NULL;
    SListPushBack(&pHead, 2);
    SListPushBack(&pHead, 4);
    SListPushBack(&pHead, 5);
    SListPushBack(&pHead, 5);
    SListPushBack(&pHead, 5);
    SListPushBack(&pHead, 8);
    SListPushBack(&pHead, 9);

    SListPushBack(&pHead2, 1);
    SListPushBack(&pHead2, 3);
    SListPushBack(&pHead2, 4);
    SListPushBack(&pHead2, 5);
    SListPushBack(&pHead2, 6);
    SListPushBack(&pHead2, 8);
    SListPushBack(&pHead2, 8);
    SListPushBack(&pHead2, 9);




    UnionSet(pHead, pHead2);


    return 0;
}