/*
 * 单链表
 */

#include <iostream>
using namespace std;
struct Node
{
    int element;
    Node* link;
};
struct SingleList
{
    Node* first;
    int length;
};
bool Init(SingleList* L); // 初始化单链表
bool Find(SingleList* L, int i, int &x); // 查找下标为i的元素
bool Find(SingleList* L, int val); // 寻找单链表中第一个值为x的元素
bool Insert(SingleList* L, int i, int x); // 在ai之后插入一个新元素
bool Delete(SingleList* L, int i); // 删除ai这个元素
bool Delete(SingleList* L, Node* node); // 删除对应指针指向的节点
bool Print(SingleList* L); // 输出
bool Destory(SingleList* L); // 销毁单链表

int main()
{
    SingleList* singleList = new SingleList;
    Init(singleList);
    Insert(singleList, -1, 2);
    Insert(singleList, -1, 27);
    Insert(singleList, -1, 3);
    Insert(singleList, -1, 4);
    Insert(singleList, -1, 5);
    Print(singleList);
    Delete(singleList, 1);
    Delete(singleList, 3);
    Print(singleList);
    int val;
    if (Find(singleList, 2, val))
        cout << val << endl;
    return 0;
}

bool Init(SingleList* L)
{
    L->first = NULL;
    L->length = 0;
    return true;
}

bool Find(SingleList* L, int i, int &x)
{
    if (! L->length)
        return false;
    if (i < 0 || i > L->length - 1)
        return false;
    Node* p = L->first;
    for (int j = 0; j < i; ++ j)
        p = p->link;
    x = p->element;
    return true;
}

bool Find(SingleList* L, int val)
{
    Node* p = L->first;
    while(p)
    {
        if (p->element == val)
            return true;
        p = p->link;
    }
    return false;
}

bool Insert(SingleList* L, int i, int x)
{
    if (i < -1 || i > L->length - 1)
        return false;
    Node* p = L->first;
    for (int j = 0; j < i; ++ j)
        p = p->link;
    Node* q = new Node;
    q->element = x;
    if (i > -1)
    {
        q->link = p->link;
        p->link = q;
    }
    else
    {
        q->link = L->first;
        L->first = q;
    }
    ++ L->length;
    return true;
}

bool Delete(SingleList* L, int i)
{
    if (! L->length)
        return false;
    if (i< 0 || i > L->length - 1)
        return false;
    Node* p = L->first;
    Node* tmp;
    for (int j = 0; j < i - 1; ++ j)
        p = p->link;
    if (i == 0)
    {
        tmp = L->first;
        L->first = L->first->link;
    }
    else
    {
        tmp = p->link;
        p->link = tmp->link;
    }
    free(tmp);
    -- L->length;
    return true;
}

bool Delete(SingleList* L, Node* node)
{
    Node* p = L->first;
    bool flag = false;
    Node* tmp;
    if (p == node)
    {
        tmp = L->first;
        L->first = p->link;
        flag = true;
    }
    else
    {
        while (p->link != node)
            p = p->link;
        if (p) {
            tmp = p->link;
            p->link = tmp->link;
            flag = true;
        }
    }
    free(tmp);
    return flag;
}

bool Print(SingleList* L)
{
    Node* p;
    if (!L->length)
        return false;
    p = L->first;
    while(p)
    {
        cout << p->element << " ";
        p = p->link;
    }
    puts("");
    return true;
}

bool Destory(SingleList* L)
{
    Node* p;
    while (L->first)
    {
        p = L->first->link;
        free(L->first);
        L->first = p;
    }
}