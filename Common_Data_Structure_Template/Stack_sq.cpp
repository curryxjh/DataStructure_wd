/*
 * À≥–Ú’ª
 */
#include <iostream>
using namespace std;
typedef int ElemType;

struct SqStack
{
    int top;
    int MaxSize;
    ElemType *data;
};
void Init(SqStack &s, int maxsize);
void Destory(SqStack &s);
bool IsEmpty(SqStack &s);
bool IsFull(SqStack &s);
bool GetTop(SqStack &s, ElemType &x);
bool Push(SqStack &s, ElemType x);
bool Pop(SqStack &s, ElemType &x);

int main()
{
    SqStack s;
    Init(s, 10);
    if (IsEmpty(s))
        cout << "’ªø’" << endl;
    Push(s, 10);
    Push(s, 5);
    Push(s, 25);
    int x;
    GetTop(s, x);
    cout << "’ª∂•‘™ÀÿŒ™£∫" << x << endl;
    Pop(s, x);
    cout << "µØ≥ˆ’ª∂•‘™ÀÿŒ™£∫" << x << endl;
    GetTop(s, x);
    cout << "’ª∂•‘™ÀÿŒ™£∫" << x << endl;
    return 0;
}

void Init(SqStack &s, int maxsize)
{
    s.data = new ElemType [maxsize];
    s.MaxSize = maxsize;
    s.top = -1;
}

void Destory(SqStack &s)
{
    s.MaxSize = -1;
    free(s.data);
    s.top = -1;
}

bool IsEmpty(SqStack &s)
{
    return s.top == -1;
}

bool IsFull(SqStack &s)
{
    return s.top == s.MaxSize - 1;
}

bool GetTop(SqStack &s, ElemType &x)
{
    if (IsEmpty(s))
        return false;
    x = s.data[s.top];
    return true;
}

bool Push(SqStack &s, ElemType x)
{
    if (IsFull(s))
        return false;
    s.data[++ s.top] = x;
    return true;
}

bool Pop(SqStack &s, ElemType &x)
{
    if (IsEmpty(s))
        return false;
    x = s.data[s.top --];
    return true;
}
