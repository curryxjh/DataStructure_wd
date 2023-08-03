/*
 * p19
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
void Find_min(HeaderList* L);
HeaderList* BuildList(int a[], int n);

int a[] = {4, 6, 3, 9, 5, 4, 15, 2, 1};

int main()
{
    HeaderList* L1 = BuildList(a, sizeof a / 4);
    Print(L1);
    Find_min(L1);
    return 0;
}

void Find_min(HeaderList* L)
{
    Node* p = L->head->link;
    Node* pre = L->head;
    while (L->head->link != L->head)
    {
        p = L->head->link;
        pre = L->head;
        Node* minval = L->head->link;
        Node* minpre = L->head;
        while (p != L->head)
        {
            if (p->element < minval->element)
            {
                minval = p;
                minpre = pre;
            }
            pre = p;
            p = p->link;
        }
        cout << minval->element << endl;
        minpre->link = minval->link;
        free(minval);
    }
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