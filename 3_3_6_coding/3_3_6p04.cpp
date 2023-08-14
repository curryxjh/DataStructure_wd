/*
 * p04
 */
#include <iostream>
#define MaxSize 100
using namespace std;
typedef char ElemType;
struct SqQueue
{
    int front, rear;
    ElemType *data;
};
void Init(SqQueue &q);
bool IsEmpty(SqQueue &q);
bool EnQueue(SqQueue &q, ElemType x);
bool DeQueue(SqQueue &q, ElemType &x);
bool manager(SqQueue &q1, SqQueue &q2);

int main()
{
    SqQueue q1, q2;
    Init(q1);
    Init(q2);
    for (int i = 0; i < 5; ++ i)
        EnQueue(q1, 'H');
    for (int j = 0; j < 5; ++ j)
        EnQueue(q2, 'K');



    manager(q1, q2);

    return 0;
}

bool manager(SqQueue &q1, SqQueue &q2)
{
    // q2 客车 q1 货车
    SqQueue ans;
    Init(ans);
    int num = 0, idx = 0;
    while (num < 10)
    {
        if (!IsEmpty(q2) && idx < 4)
        {
            ElemType x;
            DeQueue(q2, x);
            EnQueue(ans, x);
            ++ idx;
            ++ num;
        }
        else if (idx == 4 && !IsEmpty(q1))
        {
            ElemType x;
            DeQueue(q1, x);
            EnQueue(ans, x);
            ++ num;
            idx = 0;
        }
        else
        {
            while (num < 10 && idx < 4 && !IsEmpty(q1))
            {
                ElemType x;
                DeQueue(q1, x);
                EnQueue(ans ,x);
                ++ num;
                ++ idx;
            }
            idx = 0;
        }
        if (IsEmpty(q1) && IsEmpty(q1))
            break;
    }
    while (!IsEmpty(ans))
    {
        ElemType x;
        DeQueue(ans, x);
        cout << x << " ";
    }
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
