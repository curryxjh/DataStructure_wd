/*
 * p02
 */
#include <iostream>
#define MaxSize 100
using namespace std;
typedef int ElemType;
struct SqQueue
{
    int front, rear;
    ElemType *data;
};
void Init(SqQueue &q);
bool IsEmpty(SqQueue &q);
bool EnQueue(SqQueue &q, ElemType x);
bool DeQueue(SqQueue &q, ElemType &x);


struct SqStack
{
    int top;
    int Maxsize;
    ElemType *data;
};
void Initstack(SqStack &s, int maxsize);
void Destory(SqStack &s);
bool IsEmpty(SqStack &s);
bool IsFull(SqStack &s);
bool GetTop(SqStack &s, ElemType &x);
bool Push(SqStack &s, ElemType x);
bool Pop(SqStack &s, ElemType &x);


int main()
{
    SqQueue q;
    Init(q);
    SqStack s;
    Initstack(s, MaxSize);
    puts("队列元素为：");
    for (int i = 1; i < 10; ++ i)
    {
        cout << i << " ";
        EnQueue(q, i);
    }
    puts("");
    while (!IsEmpty(q))
    {
        int x;
        DeQueue(q, x);
        Push(s, x);
    }
    while (!IsEmpty(s))
    {
        int x;
        Pop(s, x);
        cout << x << " ";
    }
    return 0;
}

void Init(SqQueue &q)
{
    q.front = q.front = 0;
    q.data = new ElemType[MaxSize];
}

bool IsEmpty(SqQueue &q)
{
    if (q.front == q.rear)
        return true;
    return false;
}

bool EnQueue(SqQueue &q, ElemType x)
{
    if (q.rear == MaxSize)
        return false;
    q.data[q.rear ++] = x;
    return true;
}

bool DeQueue(SqQueue &q, ElemType &x)
{
    if (IsEmpty(q))
        return false;
    x = q.data[q.front ++];
    return true;
}

void Initstack(SqStack &s, int maxsize)
{
    s.data = new ElemType [maxsize];
    s.Maxsize = maxsize;
    s.top = -1;
}

void Destory(SqStack &s)
{
    s.Maxsize = -1;
    free(s.data);
    s.top = -1;
}

bool IsEmpty(SqStack &s)
{
    return s.top == -1;
}

bool IsFull(SqStack &s)
{
    return s.top == s.Maxsize - 1;
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
