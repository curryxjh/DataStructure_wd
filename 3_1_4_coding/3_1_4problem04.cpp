/*
 * p04
 */

#include <iostream>
using namespace std;
typedef char ElemType;
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
bool Is_symmetry(string str);

int main()
{
    string str;
    cin >> str;
    if (Is_symmetry(str))
        puts("¶Ô³Æ");
    else
        puts("²»¶Ô³Æ");
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

bool Is_symmetry(string str)
{
    LinkStack s;
    Init(s);
    for (int i = 0; i < str.size(); ++ i)
        Push(s, str[i]);
    int idx = 0;
    while (!IsEmpty(s))
    {
        char x;
        Pop(s, x);
        if (x != str[idx ++])
            return false;
    }
    return true;
}