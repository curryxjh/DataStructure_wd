/*
 * p24
 */

#include <iostream>
#include <cstring>
#include <cmath>
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
void Del_list_abs_val(HeaderList* L, int n);
int a[] = {-3, 4, -1, 6, 7, 1, 8, 3};

int main()
{
    HeaderList* L = buildList(a, sizeof a / 4);
    Print(L);
    int x;
    cin >> x;
    Del_list_abs_val(L, x);
    Print(L);
    return 0;
}

void Del_list_abs_val(HeaderList* L, int n)
{
    int *cnt = new int[n + 1];
    memset(cnt, 0, (sizeof(int)) * (n + 1));
    Node* p = L->head->link;
    Node* pre = L->head;
    while (p)
    {
        if (! cnt[abs(p->element)])
        {
            ++ cnt[abs(p->element)];
            pre = p;
            p = p->link;
        }
        else
        {
            Node* tmp = p;
            pre->link = tmp->link;
            p = tmp->link;
            free(tmp);
        }
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