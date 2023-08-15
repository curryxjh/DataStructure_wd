/*
 * 队列
 */
#include <iostream>
#define MaxSize 1000
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

int main()
{
    SqQueue q;
    Init(q);

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
