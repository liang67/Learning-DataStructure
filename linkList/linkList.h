#if !defined(__LINKLIST_H)
#define __LINKLIST_H


#include <stdlib.h>
#include <stdbool.h>

/*实现一个带头结点的单链表*/

struct nodeType
{
    int data;              // 数据域
    struct nodeType *next; // 指针域
};
typedef struct nodeType LNode, *LinkList;

// 初始化链表，生成一个空节点作为头节点，二级指针
// 因为需要对传入的一级指针进行修改，所以需要二级指针
// 按道理，这里不要二级指针？后面测试下
bool InitList(LinkList *L);

bool DestroyList(LinkList *L);

bool ClearList(LinkList L);

bool ListEmpty(LinkList L);

int ListLength(LinkList L);

LNode* ListGetElem(LinkList L, int i);

bool ListInsert(LinkList L, int i, int elem);

bool ListInsertHead(LinkList L, int elem);

bool ListInsertTail(LinkList L, int elem);

bool ListDelete(LinkList L, int i, int *data);

void ListVisit(LinkList L, void (*visit)(int));

#endif // __LINKLIST_H
