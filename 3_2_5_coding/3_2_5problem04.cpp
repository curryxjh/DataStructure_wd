/*
 * p04
 * 其实就是利用循环链表去实现队列
 */

#include <iostream>
using namespace std;
typedef int ElemType;
struct Node
{
    ElemType data;
    Node* link;
};
struct Queue
{
    Node* front, *rear;
};
bool Init(Queue &q);
bool IsEmpty(Queue &q);
bool IsFull(Queue &q);
bool EnQueue(Queue &q, ElemType x);
bool DeQueue(Queue &q, ElemType  &x);

int main()
{
    Queue q;
    Init(q);
    if (IsEmpty(q))
        puts("空");
    else
        puts("非空");
    EnQueue(q, 10);
    EnQueue(q, 20);
    EnQueue(q, 30);
    ElemType x;
    if (IsFull(q))
        puts("YES");
    else
        puts("NO");
    DeQueue(q, x);
    cout << x << endl;
    DeQueue(q, x);
    cout << x << endl;
    if (IsEmpty(q))
        puts("空");
    else
        puts("非空");

    return 0;
}

bool Init(Queue &q)
{
    q.front = new Node;
    q.rear = q.front;
    q.rear->link = q.front;
}

bool IsEmpty(Queue &q)
{
    if (q.rear == q.front)
        return true;
    return false;
}

bool IsFull(Queue &q)
{
    if (q.rear->link == q.front)
        return true;
    return false;
}

bool EnQueue(Queue &q, ElemType x)
{
    if (q.rear->link == q.front)
    {
        Node *node = new Node;
        node->data = x;
        q.rear->link = node;
        q.rear = node;
        q.rear->link = q.front;
        return true;
    }
    else
    {
        q.rear->link->data = x;
        q.rear = q.rear->link;
        return true;
    }
}

bool DeQueue(Queue &q, ElemType  &x)
{
    if (q.rear == q.front)
        return false;
    x = q.front->link->data;
    q.front = q.front->link;
    return true;
}