/*
 * p03
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
bool IsEmpty(SqStack &s);
bool IsFull(SqStack &s);
bool Push(SqStack &s, ElemType x);
bool Pop(SqStack &s, ElemType &x);
bool EnQueue(SqStack &s1, SqStack &s2, ElemType x);
bool DeQueue(SqStack &s1, SqStack &s2, ElemType &x);
bool QueueEmpty(SqStack &s1, SqStack &s2);

int main()
{
    SqStack s1, s2;
    Init(s1, 10);
    Init(s2, 10);
    EnQueue(s1, s2, 4);
    EnQueue(s1, s2, 10);
    EnQueue(s1, s2, 100);
    int x;
    DeQueue(s1, s2, x);
    cout << x << endl;
    cout << QueueEmpty(s1, s2) << endl;

    return 0;
}

bool EnQueue(SqStack &s1, SqStack &s2, ElemType x)
{
    if (!IsFull(s1))
    {
        Push(s1, x);
        return true;
    }
    if (IsFull(s1) && !IsEmpty(s2))
    {
        puts("队列满");
        return false;
    }
    if (IsFull(s1) && IsEmpty(s2))
    {
        while (!IsEmpty(s1))
        {
            int x;
            Pop(s1, x);
            Push(s2, x);
        }
    }
    Push(s1, x);
    return true;

}

bool DeQueue(SqStack &s1, SqStack &s2, ElemType &x)
{
    if (!IsEmpty(s2))
    {
        Pop(s2, x);
        return true;
    }
    else if (IsEmpty(s1))
    {
        printf("队列为空");
        return false;
    }
    else
    {
        while (!IsEmpty(s1))
        {
            int y;
            Pop(s1, y);
            Push(s2, y);
        }
        Pop(s2, x);
        return true;
    }
}

bool QueueEmpty(SqStack &s1, SqStack &s2)
{
    if (IsEmpty(s1) && IsEmpty(s2))
        return true;
    return false;
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
