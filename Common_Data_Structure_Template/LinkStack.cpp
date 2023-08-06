/*
 * Á´Õ»
 */

#include <iostream>
using namespace std;
typedef int ElemType;
struct Node
{
    ElemType data;
    Node *link;
};
struct LinkStack
{
    Node *linkStack;
    int lenght;
};
void Init(LinkStack &s);
bool IsEmpty(LinkStack &s);
bool GetTop(LinkStack &s, ElemType &x);
bool Pop(LinkStack &s, ElemType &x);
bool Push(LinkStack &s, ElemType x);

int main()
{
    LinkStack s;
    Init(s);
    if (IsEmpty(s))
        cout << "Õ»¿Õ" << endl;
    Push(s, 10);
    Push(s, 2);
    Push(s, 19);
    int x;
    GetTop(s, x);
    cout << "Õ»¶¥ÔªËØÎª: " << x << endl;
    Pop(s, x);
    cout << "±»µ¯³öµÄÕ»¶¥ÔªËØÎª£º" << x << endl;
    GetTop(s, x);
    cout << "Õ»¶¥ÔªËØÎª: " << x << endl;
    return 0;
}

void Init(LinkStack &s)
{
    s.linkStack = NULL;
    s.lenght = 0;
}

bool IsEmpty(LinkStack &s)
{
    return s.linkStack == NULL;
}

bool GetTop(LinkStack &s, ElemType &x)
{
    if (IsEmpty(s))
        return false;
    x = s.linkStack->data;
    return true;
}

bool Pop(LinkStack &s, ElemType &x)
{
    if (IsEmpty(s))
        return false;
    x = s.linkStack->data;
    Node* tmp = s.linkStack;
    s.linkStack = s.linkStack->link;
    free(tmp);
    return true;
}

bool Push(LinkStack &s, ElemType x)
{
    Node *node = new Node;
    node->data = x;
    node->link = s.linkStack;
    s.linkStack = node;
    return true;
}