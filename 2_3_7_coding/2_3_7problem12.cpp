/*
 * p12
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
bool Del_same_val(HeaderList* L);
bool Print(HeaderList* L); // 输出

int main()
{
    HeaderList* headerList = new HeaderList;
    Init(headerList);
    Insert(headerList, -1, 9);
    Insert(headerList, -1, 9);
    Insert(headerList, -1, 7);
    Insert(headerList, -1, 6);
    Insert(headerList, -1, 5);
    Insert(headerList, -1, 2);
    Insert(headerList, -1, 2);
    Insert(headerList, -1, 2);
    Print(headerList);
    Del_same_val(headerList);
    Print(headerList);
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

bool Del_same_val(HeaderList* L)
{
    if (! L->length)
        return false;
    Node* p = L->head->link;
    while (p->link)
    {
        if (p->element == p->link->element)
        {
            Node* tmp = p->link;
            p->link = tmp->link;
            free(tmp);
        }
        else
            p = p->link;
    }
    return true;
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