/*
 * p3
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef struct {
    int val, idx;
}ElemType;

struct SqStack
{
    int top;
    int MaxSize;
    ElemType *data;
};
void Init(SqStack &s, int maxsize);
bool IsEmpty(SqStack &s);
bool IsFull(SqStack &s);
bool GetTop(SqStack &s, ElemType &x);
bool Push(SqStack &s, ElemType x);
bool Pop(SqStack &s, ElemType &x);
int P_n(double x, int n);

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << P_n(x, n) << endl;
    return 0;
}

int P_n(double x, int n)
{
    SqStack s;
    Init(s, 100);
    double v1 = 1, v2 = 2 * x;
    for (int i = n; i >= 2; --i)
        Push(s, {0, i});
    while (!IsEmpty(s))
    {
        ElemType node;
        GetTop(s, node);
        node.val = 2 * x * v2 - 2 * (node.idx - 1) * v1;
        v1 = v2;
        v2 = node.val;
        Pop(s, node);
    }
    if (n == 0)
        return v1;
    return v2;
}
void Init(SqStack &s, int maxsize)
{
    s.data = new ElemType [maxsize];
    s.MaxSize = maxsize;
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
