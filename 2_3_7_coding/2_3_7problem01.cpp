/*
 * p01
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
bool Insert(SingleList* L, int i, int x); // 在ai之后插入一个新元素
bool Delete(SingleList* L, Node* node);
bool Print(SingleList* L); // 输出
bool Destory(SingleList* L); // 销毁单链表
void Dele_val_x(SingleList* L, Node* LN, int x);

int main()
{
    SingleList* singleList = new SingleList;
    Init(singleList);
    Insert(singleList, -1, 5);
    Insert(singleList, -1, 2);
    Insert(singleList, -1, 27);
    Insert(singleList, -1, 3);
    Insert(singleList, -1, 5);
    Insert(singleList, -1, 4);
    Insert(singleList, -1, 5);
    Insert(singleList, -1, 1);
    Insert(singleList, -1, 5);
    Print(singleList);
    Dele_val_x(singleList, singleList->first, 5);
    Print(singleList);
    return 0;
}

void Dele_val_x(SingleList* L, Node* LN, int x)
{
    Node* p;
    if (! LN)
        return;
    if (LN->element == x)
    {
        p = LN;
        LN = LN->link;
        Delete(L, p);
        Dele_val_x(L, LN, x);
    }
    else
        Dele_val_x(L, LN->link, x);
}

bool Init(SingleList* L)
{
    L->first = NULL;
    L->length = 0;
    return true;
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