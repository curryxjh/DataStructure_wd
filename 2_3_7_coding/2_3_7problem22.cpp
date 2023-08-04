/*
 * p22
 * �㷨����˼�룺��������ָ�룬��ʼ��ʱ��ָ���һ���ڵ㣬�Ƚ�����һ���ڵ��ƶ�����k��Ԫ�أ�
 * Ȼ��ͬʱ�ƶ�����ָ�룬������һ��ָ��Ҳ�ƶ������һ���ڵ��ʱ�򣬱����ҵ�������k��Ԫ��
 * ʱ�临�Ӷȣ�O(N)
 * �ռ临�Ӷȣ�O(1)
 */

#include <iostream>
using namespace std;
struct Node
{
    int element;
    Node* link;
};
struct HeaderList
{
    Node* head;
    int length;
};
void Print(HeaderList* L);
bool Init(HeaderList* L);
Node* Find_k(HeaderList* L, int k);
HeaderList* BuildList(int a[], int n);
int a[] = {1, 2, 3, 9, 5, 7, 3, 2, 1};

int main()
{
    HeaderList* L = BuildList(a, sizeof a / 4);
    int k;
    cin >> k;
    cout << "������" << k << "��Ԫ��Ϊ�� " << Find_k(L, k)->element << endl;
    return 0;
}


bool Init(HeaderList* L)
{
    L->head = new Node;
    if (!L->head)
        return false;
    L->head->link = NULL;
    L->length = 0;
    return true;
}

Node* Find_k(HeaderList* L, int k)
{
    Node* p = L->head->link;
    Node* q = L->head->link;
    while (k --)
        p = p->link;
    while (p)
    {
        p = p->link;
        q = q->link;
    }
    return q;
}

HeaderList* BuildList(int a[], int n)
{
    HeaderList* L = new HeaderList;
    Init(L);
    Node* p = L->head;
    for (int i = 0; i < n; ++ i)
    {
        Node* node = new Node;
        node->element = a[i];
        node->link = p->link;
        p->link = node;
        p = p->link;
    }
    return L;
}

void Print(HeaderList* L)
{
    Node *p = L->head->link;
    while (p != L->head)
    {
        cout << p->element << " ";
        p = p->link;
    }
    puts("");
}