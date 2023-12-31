/*
 * p17
 */

#include <iostream>
using namespace std;
struct Node
{
    int element;
    Node* pre, * ne;
};
struct HeaderList
{
    Node* head;
    int length;
};
void Print(HeaderList* L);
bool Init(HeaderList* L);
HeaderList* BuildList(int a[], int n);
bool is_symmetric(HeaderList* L);
int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};

int main()
{
    HeaderList* L = BuildList(a, sizeof a / 4);
    Print(L);
    if (is_symmetric(L))
        puts("YES");
    else
        puts("NO");
    return 0;
}

bool is_symmetric(HeaderList* L)
{
    Node* p = L->head->ne;
    Node* q = L->head->pre;
    while (p != q)
    {
        if (p->element != q->element)
            return false;
        p = p->ne;
        q = q->pre;
    }
    return true;
}

bool Init(HeaderList* L)
{
    L->head = new Node;
    if (!L->head)
        return false;
    L->head->ne = L->head;
    L->head->pre = L->head;
    L->length = 0;
    return true;
}

HeaderList* BuildList(int a[], int n)
{
    HeaderList* L = new HeaderList;
    Init(L);
    Node* p = L->head;
    for (int i = 0; i < n; ++ i)
    {
        Node* node = new Node;
        node->element = a[i];
        node->ne = p->ne;
        node->pre = p;
        p->ne = node;
        p = p->ne;
        L->head->pre = node;
    }
    return L;
}

void Print(HeaderList* L)
{
    Node *p = L->head->ne;
    while (p != L->head)
    {
        cout << p->element << " ";
        p = p->ne;
    }
    puts("");
}