/*
 * p07
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
bool Print(HeaderList* L); // 输出
bool Destory(HeaderList* L); // 销毁单链表
bool Delete_val(HeaderList* L, int l, int r);

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
    int l, r;
    cout << "删除元素区间范围: ";
    cin >> l >> r;
    Delete_val(headerList, l, r);
    Print(headerList);
    return 0;
}

bool Delete_val(HeaderList* L, int l, int r)
{
    if (! L->length)
        return false;
    Node* p = L->head->link;
    Node* q = L->head;
    while (p)
    {
        if (p->element >= l && p->element <= r)
        {
            Node* tmp = p;
            q->link = p->link;
            p = q->link;
            free(tmp);
        }
        else
        {
            q = p;
            p = p->link;
        }
    }
    return true;
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

bool Destory(HeaderList* L)
{
    Node* p;
    while (L->head)
    {
        p = L->head->link;
        free(L->head);
        L->head = p;
    }
}