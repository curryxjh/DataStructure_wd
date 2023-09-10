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
bool Insert(SingleList* L, int i, int x); // 在ai之后插入一个新元素
bool Print(SingleList* L); // 输出
void SelectSort(SingleList *L);

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
    SelectSort(singleList);
    Print(singleList);

    return 0;
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

void SelectSort(SingleList *L)
{
    for (Node *i = L->first; i; i = i->link)
    {
        Node *t = i;
        for (Node *j = i->link; j; j = j->link)
            if (j->element < i->element)
                t = j;
        int tmp = i->element;
        i->element = t->element;
        t->element = tmp;
    }
}