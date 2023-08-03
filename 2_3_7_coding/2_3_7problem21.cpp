/*
 * p21
 * 算法设计基本思想，遍历整个链表，并记录遍历的节点个数，若节点个数超过链表长度则有环，否则没有
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
struct SingleList
{
    Node* first;
    int length;
};
bool Init(SingleList* L); // 初始化单链表
bool Print(SingleList* L); // 输出
SingleList* BuildList(int a[], int n);
bool Is_loop(SingleList* L);
int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};

int main()
{
    SingleList* singleList = BuildList(a, sizeof a / 4);
    Print(singleList);
//    Node* p = singleList->first;
//    while (p->link)
//        p = p->link;
//    p->link = singleList->first;
    if (Is_loop(singleList))
        puts("YES");
    else
        puts("NO");
    return 0;
}

bool Init(SingleList* L)
{
    L->first = NULL;
    L->length = 0;
    return true;
}
bool Is_loop(SingleList* L)
{
    Node* p = L->first;
    int num = 0;
    while (p)
    {
        ++num;
        p = p->link;
        if (num > L->length)
            return true;
    }
    return false;
}
SingleList* BuildList(int a[], int n)
{
    SingleList* L = new SingleList;
    Init(L);
    Node* p;
    for (int i = 0; i < n; ++ i)
    {
        Node *node = new Node;
        node->element = a[i];
        node->link = NULL;
        if (i == 0)
        {
            L->first = node;
           p = L->first;
        }
        else
        {
            node->link = p->link;
            p->link = node;
            p = p->link;
        }
    }
    L->length = n;
    return L;
}

bool Print(SingleList* L)
{
    Node* p;
    if (!L->length)
        return false;
    p = L->first;
    while(p)
    {
        cout << p->element << " ";
        p = p->link;
    }
    puts("");
    return true;
}