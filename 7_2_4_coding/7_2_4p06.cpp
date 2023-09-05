#include <iostream>
typedef int ElemType;
const int N = 110;
struct SqList
{
    ElemType data[N];
    int length;
};

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
bool Insert(SingleList* L, int i, int x); // 在ai之后插入一个新元素
bool Print(SingleList* L); // 输出

bool Search_reverse(SqList &sqList, ElemType k);
bool Search_reverse(SingleList &slist, ElemType k);

int alen = 9;
int a[9] = {1 , 4, 9, 10, 5, 7, 3, 2, 12};

int main()
{
    SqList sqlist;
    for (int i = 0; i < alen; ++ i)
        sqlist.data[i] = a[i];
    sqlist.length = alen;
    SingleList slist;
    Init(&slist);
    for (int i = 0; i < alen; ++ i)
        Insert(&slist, i - 1, a[i]);

    Search_reverse(sqlist, 3);
    Search_reverse(slist, 7);

    std::cout << "origin:  ";
    for (int i = 0; i < alen; ++ i)
        std::cout << a[i] << " ";
    puts("");
    std::cout << "sqlist:  ";
    for(int i = 0; i < sqlist.length; ++ i)
        std::cout << sqlist.data[i] << " ";
    puts("");
    std::cout << "singlelist: ";
    Print(&slist);
    return 0;
}

bool Init(SingleList* L)
{
    L->first = NULL;
    L->length = 0;
    return true;
}

bool Insert(SingleList* L, int i, int x)
{
    if (i < -1 || i > L->length - 1)
        return false;

    Node* p = L->first;
    for (int j = 0; j < i; ++ j)
        p = p->link;
    Node* q = new Node;
    q->element = x;
    if (i > -1)
    {
        q->link = p->link;
        p->link = q;
    }
    else
    {
        q->link = L->first;
        L->first = q;
    }
    ++ L->length;
    return true;
}


bool Print(SingleList* L)
{
    Node* p;
    if (!L->length)
        return false;
    p = L->first;
    while(p)
    {
        std::cout << p->element << " ";
        p = p->link;
    }
    puts("");
    return true;
}

bool Search_reverse(SqList &sqList, ElemType k)
{
    int idx = 0;
    while (sqList.data[idx] != k && idx < sqList.length)
        ++ idx;
    if (idx < sqList.length && idx > 0)
    {
        ElemType tmp = sqList.data[idx];
        sqList.data[idx] = sqList.data[idx - 1];
        sqList.data[idx - 1] = tmp;
        return true;
    }
    return false;
}

bool Search_reverse(SingleList &slist, ElemType k)
{
    Node *p = slist.first;
    Node *q = slist.first;
    if (p->element != k)
        p = p->link;
    while(p->element != k && p)
    {
        p = p->link;
        q = q->link;
    }
    if (p)
    {
        ElemType tmp = p->element;
        p->element = q->element;
        q->element = tmp;
        return true;
    }
    return false;
}