//
// p01
//
#include <iostream>
#define MaxSize 10
using namespace std;
typedef int ElemType;
struct SqQueue
{
    int front, rear;
    ElemType *data;
    bool tag;
};
void Init(SqQueue &q);
bool IsEmpty(SqQueue &q);
bool EnQueue(SqQueue &q, ElemType x);
bool DeQueue(SqQueue &q, ElemType &x);

int main()
{
    SqQueue q;
    Init(q);
    if (!IsEmpty(q))
        puts("���зǿ�");
    EnQueue(q, 10);
    EnQueue(q, 20);
    EnQueue(q, 30);

    int x;
    puts("����");
    DeQueue(q, x);
    cout << x << endl;
    DeQueue(q, x);
    cout << x << endl;
    DeQueue(q, x);
    cout << x << endl;
    if (IsEmpty(q))
        puts("���п�");
    return 0;
}

void Init(SqQueue &q)
{
    q.data = new ElemType[MaxSize];
    q.front = q.rear = 0;
    q.tag = 0;
}

bool IsEmpty(SqQueue &q)
{
    if (q.front == q.rear && q.tag == 0)
        return true;
    return false;
}

bool EnQueue(SqQueue &q, ElemType x) {
    if (q.front == q.rear && q.tag == 1)
    {
        puts("������");
        return false;
    }
    q.data[q.rear] = x;
    q.rear = (q.rear + 1 + MaxSize) % MaxSize;
    if (q.front == q.rear)
        q.tag = 1;
    return true;
}

bool DeQueue(SqQueue &q, ElemType &x)
{
    if (IsEmpty(q))
        return false;
    x = q.data[q.front];
    q.front = (q.front + 1 + MaxSize) % MaxSize;
    if (q.front == q.rear)
        q.tag = 0;
    return true;
}
