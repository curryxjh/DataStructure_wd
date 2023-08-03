/*
 * p20
 */

#include <iostream>
using namespace std;
struct Node
{
    int element;
    Node* pre, * ne;
    int freq;
};
struct HeaderList
{
    Node* head;
    int length;
};
void Print(HeaderList* L);
bool Init(HeaderList* L);
HeaderList* BuildList(int a[], int n);
Node* Locate(HeaderList* L, int x);
int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};

int main()
{
    HeaderList* L = BuildList(a, sizeof a / 4);
    Print(L);
    Node* k = Locate(L, 2);
    if (k)
        puts("Locat success");
    Print(L);
    return 0;
}

Node* Locate(HeaderList* L, int x) {
    Node *p = L->head->ne;
    while (p && p->element != x)
        p = p->ne;
    if (!p)
        return NULL;
    else
    {
        ++ p->freq;
        p->pre->ne = p->ne;
        p->ne->pre = p->pre;
        p->ne = p->pre = NULL;
        Node* q = L->head->ne;
        while (q && q->freq > p->freq)
            q = q->ne;
        p->ne = q;
        p->pre = q->pre;
        q->pre->ne = p;
        q->pre = p;
    }
    return p;
}

bool Init(HeaderList* L)
{
    L->head = new Node;
    if (!L->head)
        return false;
    L->head->ne = NULL;
    L->head->pre = NULL;
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
        node->freq = 0;
        node->ne = p->ne;
        node->pre = p;
        p->ne = node;
        p = p->ne;
    }
    return L;
}

void Print(HeaderList* L)
{
    Node *p = L->head->ne;
    while (p)
    {
        cout << p->element << " ";
        p = p->ne;
    }
    puts("");
}