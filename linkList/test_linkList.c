#include "linkList.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void myPrint(int elem)
{
    printf("%d ", elem);
}

int main(int argc, char const *argv[])
{
    LinkList L;
    srand(time(NULL)); // 初始化随机数

    printf("init ....\n");
    InitList(&L);

    if (ListEmpty(L))
        printf("List is empty\n");
    else
        printf("List is not empty\n");

    for (int i = 0; i < 5; i++)
    {
        ListInsertHead(L, rand() % 100);
    }

    printf("Now has %d elements\n", ListLength(L));

    LNode *p = ListGetElem(L, 4);
    if (p)
    {
        printf("get element 1 is %d\n", p->data);
    }
    else
    {
        printf("get element ERROR\n");
    }

    ListVisit(L, myPrint);
    printf("\nVisit end\n");

    ClearList(L);
    if (ListEmpty(L))
        printf("List is empty\n");
    else
        printf("List is not empty\n");

    for (int i = 0; i < 10; i++)
    {
        ListInsertTail(L, rand() % 100);
    }

    printf("Now has %d elements\n", ListLength(L));
    ListVisit(L, myPrint);
    printf("\nVisit end\n");

    int data;
    if (ListDelete(L, 10, &data))
    {
        printf("Delete the 10th element: %d\n",data);
        printf("Now has %d elements\n", ListLength(L));
    } else {
        printf("Delete ERROR\n");
    }
    

    return 0;
}
