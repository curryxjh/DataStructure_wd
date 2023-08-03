/*
 * p17
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
void Print(HeaderList* L);
bool Init(HeaderList* L);
void Merge(HeaderList* l1, HeaderList* l2);
HeaderList* BuildList(int a[], int n);

int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
int b[] = {3, 1, 2, 3, 5};
int main()
{
    HeaderList* L1 = BuildList(a, sizeof a / 4);
    Print(L1);
    HeaderList* L2 = BuildList(b, sizeof b / 4);
    Print(L2);
    Merge(L1, L2);
    Print(L1);
    return 0;
}

void Merge(HeaderList* l1, HeaderList* l2)
{
    Node* p = l1->head->link;
    Node* q = l2->head->link;
    while (p->link != l1->head)
        p = p->link;
    while (q->link != l2->head)
        q = q->link;
    p->link = l2->head->link;
    q->link = l1->head;
}


bool Init(HeaderList* L)
{
    L->head = new Node;
    if (!L->head)
        return false;
    L->head->link = L->head;
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
        node->link = p->link;
        p->link = node;
        p = p->link;
    }
    return L;
}

void Print(HeaderList* L)
{
    Node *p = L->head->link;
    while (p != L->head)
    {
        cout << p->element << " ";
        p = p->link;
    }
    puts("");
}