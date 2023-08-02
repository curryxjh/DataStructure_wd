/*
 * p15
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
bool Intersection(HeaderList*& L1, HeaderList*& L2);
int a[] = {1, 4, 7, 8, 9,11};
int b[] = {2, 4, 5, 6, 7, 8};

int main()
{
    HeaderList* l1 = buildList(a, sizeof a / 4);
    HeaderList* l2 = buildList(b, sizeof b / 4);
    Print(l1);
    Print(l2);
    Intersection(l1, l2);
    Print(l1);
    return 0;
}

bool Intersection(HeaderList*& L1, HeaderList*& L2)
{
    Node* p = L1->head;
    Node* q = L2->head;
    while (p->link && q->link)
    {
        if (p->link->element == q->link->element)
        {
            p = p->link;
            Node* tmp = q->link;
            q->link = tmp->link;
            free(tmp);
        }
        else if (p->link->element < q->link->element)
        {
            Node* tmp = p->link;
            p->link = tmp->link;
            free(tmp);
        }
        else
        {
            Node* tmp = q->link;
            q->link = tmp->link;
            free(tmp);
        }
    }
    while (p->link)
    {
        Node* tmp = p->link;
        p->link = tmp->link;
        free(tmp);
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
    return true;
}