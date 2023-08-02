/*
 * p11
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
HeaderList* Merge_Decline(HeaderList*& L1, HeaderList*& L2);
int a[] = {1, 4, 7, 8, 9,11};
int b[] = {2, 4, 5, 6, 7, 8};

int main()
{
    HeaderList* l1 = buildList(a, sizeof a / 4);
    HeaderList* l2 = buildList(b, sizeof b / 4);
    Print(l1);
    Print(l2);
    HeaderList* ans = Merge_Decline(l1, l2);
    Print(ans);
    return 0;
}

HeaderList* Merge_Decline(HeaderList*& L1, HeaderList*& L2)
{
    HeaderList* L = new HeaderList;
    Init(L);
    Node* p = L1->head->link;
    Node* q = L2->head->link;
    while (p && q)
    {
        Node* pne = p->link, *qne = q->link;
        if (p->element < q->element)
        {
            p->link = L->head->link;
            L->head->link = p;
            p = pne;
        }
        else
        {
            q->link = L->head->link;
            L->head->link = q;
            q = qne;
        }
    }
    while (p)
    {
        Node* tmp = p;
        p = p->link;
        tmp->link = L->head->link;
        L->head->link = tmp;
    }
    while (q)
    {
        Node* tmp = q;
        q = q->link;
        tmp->link = L->head->link;
        L->head->link = tmp;
    }
    return L;
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