/*
 * p22
 * 算法基本思想：设置两个指针，起始的时候都指向第一个节点，先将其中一个节点移动到第k个元素，
 * 然后同时移动两个指针，当另外一个指针也移动到最后一个节点的时候，便能找到倒数第k个元素
 * 时间复杂度：O(N)
 * 空间复杂度：O(1)
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
Node* Find_k(HeaderList* L, int k);
HeaderList* BuildList(int a[], int n);
int a[] = {1, 2, 3, 9, 5, 7, 3, 2, 1};

int main()
{
    HeaderList* L = BuildList(a, sizeof a / 4);
    int k;
    cin >> k;
    cout << "倒数第" << k << "个元素为： " << Find_k(L, k)->element << endl;
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

Node* Find_k(HeaderList* L, int k)
{
    Node* p = L->head->link;
    Node* q = L->head->link;
    while (k --)
        p = p->link;
    while (p)
    {
        p = p->link;
        q = q->link;
    }
    return q;
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