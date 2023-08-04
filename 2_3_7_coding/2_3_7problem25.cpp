/*
 * p25
 */

#include <iostream>
#include <cstring>
#include <cmath>
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
HeaderList* buildList(int a[], int n); //依据一个数组的元素创建链表
bool Print(HeaderList* L); // 输出
void Re_sort(HeaderList* L);
int a[] = {1, 4, 3, 6, 7, 1, 8, 3};

int main()
{
    HeaderList* L = buildList(a, sizeof a / 4);
    Print(L);
    Re_sort(L);
    Print(L);
    return 0;
}

void Re_sort(HeaderList* L)
{
    Node* p = L->head->link;
    Node* q = L->head->link;
    while (q->link)
    {
        p = p->link;
        q = q->link;
        if (q->link)
            q = q->link;
    }
    Node* l2 = p->link;
    p->link = NULL;
    while (l2)
    {
        Node* tmp = l2->link;
        l2->link = p->link;
        p->link = l2;
        l2 = tmp;
    }
    Node* l1 = L->head->link;
    q = p->link;
    p->link = NULL;
    while (q)
    {
        Node* r = q->link;
        q->link = l1->link;
        l1->link = q;
        l1 = q->link;
        q = r;
    }
}

HeaderList* buildList(int a[], int n)
{
    HeaderList* L = new HeaderList;
    Init(L);
    for (int i = 0; i < n; ++ i)
    {
        Node* node = new Node;
        node->element = a[i];
        Node* p = L->head;
        while (p->link)
            p = p->link;
        node->link = p->link;
        p->link = node;
    }
    L->length = n;
    return L;
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