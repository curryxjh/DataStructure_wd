/*
 * 带头结点的单链表
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
bool Find(HeaderList* L, int i, int &x); // 查找下标为i的元素
bool Find(HeaderList* L, int val); // 寻找单链表中第一个值为x的元素
bool Insert(HeaderList* L, int i, int x); // 在ai之后插入一个新元素
bool Delete(HeaderList* L, int i); // 删除ai这个元素
bool Delete(HeaderList* L, Node* node); // 删除对应指针指向的节点
bool Print(HeaderList* L); // 输出
bool Destory(HeaderList* L); // 销毁单链表

int main()
{
    HeaderList* headerList = new HeaderList;
    Init(headerList);
    Insert(headerList, -1, 2);
    Insert(headerList, -1, 27);
    Insert(headerList, -1, 3);
    Insert(headerList, -1, 4);
    Insert(headerList, -1, 5);
    Print(headerList);
    Delete(headerList, 1);
    Delete(headerList, 3);
    Print(headerList);
    int val;
    if (Find(headerList, 2, val))
        cout << val << endl;
    Delete(headerList, headerList->head->link);
    Print(headerList);
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

bool Find(HeaderList* L, int i, int &x)
{
    if (! L->length)
        return false;
    if (i < 0 || i > L->length - 1)
        return false;
    Node* p = L->head->link;
    for (int j = 0; j < i; ++ j)
        p = p->link;
    x = p->element;
    return true;
}

bool Find(HeaderList* L, int val)
{
    Node* p = L->head->link;
    while(p)
    {
        if (p->element == val)
            return true;
        p = p->link;
    }
    return false;
}

bool Insert(HeaderList* L, int i, int x)
{
    if (i < -1 || i > L->length - 1)
        return false;
    Node* p = L->head;
    for (int j = 0; j <= i; ++ j)
        p = p->link;
    Node* q = new Node;
    q->element = x;
    q->link = p->link;
    p->link = q;
    ++ L->length;
    return true;
}

bool Delete(HeaderList* L, int i)
{
    if (! L->length)
        return false;
    if (i< 0 || i > L->length - 1)
        return false;
    Node* p = L->head;
    Node* tmp;
    for (int j = 0; j <= i - 1; ++ j)
        p = p->link;
    tmp = p->link;
    p->link = tmp->link;
    free(tmp);
    -- L->length;
    return true;
}

bool Delete(HeaderList* L, Node* node)
{
    Node* p = L->head;
    bool flag = false;
    Node* tmp;
    while (p->link != node)
        p = p->link;
    if (p)
    {
        tmp = p->link;
        p->link = tmp->link;
        flag = true;
    }
    free(tmp);
    return flag;
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