/*
 * p10
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
HeaderList* buildList(int a[], int n); //依据一个数组的元素创建链表
bool Print(HeaderList* L); // 输出
bool Destory(HeaderList* L); // 销毁单链表
void disCreate(HeaderList* L, HeaderList*& L1, HeaderList*& L2);
int a[] = {3, 4, 1, 6, 7, 8};

int main()
{
    HeaderList* L = buildList(a, sizeof a / 4);
    Print(L);
    HeaderList* l1, * l2;
    disCreate(L, l1, l2);
    Print(l1);
    Print(l2);
    return 0;
}

void disCreate(HeaderList* L, HeaderList*& L1, HeaderList*& L2)
{
    L1 = new HeaderList;
    Init(L1);
    L2 = new HeaderList;
    Init(L2);
    Node* r1 = L1->head;
    Node* r2 = L2->head;
    int idx = 1;
    Node *p = L->head->link;
    while(p)
    {
        Node* tmp = p;
        p = p->link;
        tmp->link = NULL;
        if (idx % 2)
        {
            r1->link = tmp;
            r1 = tmp;
        }
        else
        {
            r2->link = tmp;
            r2 = tmp;
        }
        ++ idx;
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