/*
 * p09
 */

#include <iostream>
using namespace std;
struct Node
{
    int element;
    Node* link;
};
struct HeaderList
{
    Node* head;
    int length;
};

bool Init(HeaderList* L); // 初始化单链表
bool Insert(HeaderList* L, int i, int x); // 在ai之后插入一个新元素
void Sort_Print(HeaderList* L);
bool Print(HeaderList* L); // 输出

int main()
{
    HeaderList* headerList = new HeaderList;
    Init(headerList);
    Insert(headerList, -1, 2);
    Insert(headerList, -1, 27);
    Insert(headerList, -1, 1);
    Insert(headerList, -1, 3);
    Insert(headerList, -1, 4);
    Insert(headerList, -1, 5);
    Print(headerList);
    Sort_Print(headerList);
    return 0;
}


bool Init(HeaderList* L)
{
    L->head = new Node;
    if (!L->head)
        return false;
    L->head->link = NULL;
    L->length = 0;
    return true;
}

bool Insert(HeaderList* L, int i, int x)
{
    if (i < -1 || i > L->length - 1)
        return false;
    Node* p = L->head;
    for (int j = 0; j <= i; ++ j)
        p = p->link;
    Node* q = new Node;
    q->element = x;
    q->link = p->link;
    p->link = q;
    ++ L->length;
    return true;
}

void Sort_Print(HeaderList* L)
{
    while (L->head->link)
    {
        Node *p = L->head->link;
        Node *pre = L->head;
        Node *del;
        int idx = 1;
        while (p->link)
        {
            if (pre->link->element > p->link->element)
                pre = p;
            p = p->link;
        }
        cout << pre->link->element << " ";
        del = pre->link;
        pre->link = del->link;
        free(del);
    }
    free(L->head);
}


bool Print(HeaderList* L)
{
    Node* p;
    if (!L->length)
        return false;
    p = L->head->link;
    while(p)
    {
        cout << p->element << " ";
        p = p->link;
    }
    puts("");
    return true;
}