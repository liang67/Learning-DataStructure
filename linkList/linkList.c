#include "linkList.h"

/// @brief 初始化链表，创建一个空的头检点指针
/// @param L
/// @return 成功返回True
bool InitList(LinkList *L)
{
    *L = malloc(sizeof(LNode));
    if (*L)
    {
        (*L)->next = NULL;
        return true;
    }
    else
    {
        return false;
    }
}
/// @brief 从头指针开始遍历
/// @param L
/// @return
bool DestroyList(LinkList *L)
{
    LNode *tmp;
    tmp = *L; // 指向头节点
    while (tmp != NULL)
    {
        tmp = (*L)->next; // 非空时tmp指向头节点->next
        free(*L);         // free头节点
        (*L) = tmp;       // 重新设置头节点
    }
    *L = NULL; // 把头指针FREE

    return true;
}

bool ClearList(LinkList L)
{
    LNode *p, *tmp;
    p = L->next; // 首元
    while (p != NULL)
    {
        tmp = p;     // 先保存临时变量，方便后面FREE
        p = p->next; // 指向下一个节点
        free(tmp);   // FREE掉刚才保存的节点
    }
    L->next = NULL; // 把头节点next置空
    return true;
}

/// @brief 判断链表是否为空
/// @param L
/// @return 空返回true，否则返回false
bool ListEmpty(LinkList L)
{ // 仅头节点时代表链表为空
    if (L != NULL && L->next == NULL)
        return true;
    return false;
}

int ListLength(LinkList L)
{
    LNode *p;
    int i = 0;
    p = L->next;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

// 在单链表中查找编号为i的LNode,i从1开始
LNode *ListGetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next; // p指向首元节点
    while (p && j < i)  // p不为空或者j小于i
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return NULL;
    return p;
}

// 在第i位插入元素elem，i从0开始，即i=0；
bool ListInsert(LinkList L, int i, int elem)
{
    return false;
}

// 头插法
bool ListInsertHead(LinkList L, int elem)
{

    LNode *p = malloc(sizeof(LNode)); // new node;
    if (!p)
        return false;  // p为NULL返回失败
    p->data = elem;    // 设置新节点的数据位
    p->next = L->next; // 把原来的首元结点指向新节点的next
    L->next = p;       // 把头节点的next指向new node

    return true;
}

// 尾插法
bool ListInsertTail(LinkList L, int elem)
{
    LNode *p = malloc(sizeof(LNode)); // new node;
    if (!p)
        return false; // p为NULL返回失败
    p->data = elem;   // 设置新节点的数据位
    p->next = NULL;   // 新节点的next指向NULL

    // 遍历链表
    LNode *tmp = L;   // tmp指向头节点
    while (tmp->next) // 遍历链表
    {
        tmp = tmp->next;
    }
    tmp->next = p; // 尾结点next指向新节点p

    return true;
}

// 删除第i个节点；i从1开始，返回值用指针返回
bool ListDelete(LinkList L, int i, int *data)
{
    int j = 0;
    LNode *p = L; // p指向头节点
    while (j < i - 1 && p)
    {
        p = p->next;
        j++;
    }
    if (j > i - 1 || !p)
        return false;

    // 删除第i个元素
    LNode *tmp = p->next; // tmp为待删除结点
    p->next = tmp->next;  // 把p的next执行待删除结点的next
    *data = tmp->data;
    free(tmp);
    return true;
}

// 使用回调函数来访问链表
void ListVisit(LinkList L, void (*visit)(int))
{
    LNode *p;
    p = L->next;
    while (p != NULL)
    {
        visit(p->data);
        p = p->next;
    }
}
