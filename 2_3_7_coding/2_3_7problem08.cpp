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
HeaderList* buildList(int a[], int n); //依据一个数组的元素创建链表
bool Print(HeaderList* L); // 输出
bool Destory(HeaderList* L); // 销毁单链表
Node* Common_node(HeaderList* L1, HeaderList* L2);
int a[] = {3, 4, 1, 6, 7, 8};
int b[] = {9, 1, 6, 7, 8};

int main()
{
    HeaderList* L1 = buildList(a, sizeof a / 4);
    HeaderList* L2 = buildList(b, sizeof b / 4);
    Print(L1);
    Print(L2);
    Node* node = Common_node(L1, L2);
    if (node)
        while (node)
        {
            cout << node->element << " ";
            node = node->link;
        }
    else
        puts("无公共节点");
    return 0;
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

Node* Common_node(HeaderList* L1, HeaderList* L2) {
    int dist = 0;
    int l1 = L1->length, l2 = L2->length;
    Node *longlist, *shortlist;
    if (l1 > l2) {
        longlist = L1->head->link;
        shortlist = L2->head->link;
        dist = l1 - l2;
    } else {
        longlist = L2->head->link;
        shortlist = L1->head->link;
        dist = l2 - l1;
    }
    while (dist--)
        longlist = longlist->link;
    while (longlist)
    {
        if (longlist->element == shortlist->element && longlist->link->element == shortlist->link->element)
            return longlist;
        else
        {
            longlist = longlist->link;
            shortlist = shortlist->link;
        }
    }
    return NULL;
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