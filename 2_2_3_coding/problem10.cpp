/*
 * p10
 * (1) �㷨����˼��:����p08��˼·,�����鿰��������ab��a��Ϊ��Ҫ���ƵĲ��֣�bΪ����Ҫ���ƵĲ��֣�
 * ԭ˳��Ϊab���������ƺ���Ҫ�õ�˳��Ϊba����ôֻҪ�����������ַ���λ�ü��ɣ�����Ҫע��ab�ĳ��Ȳ���ͬ��
 * ���Բ�����ֱ�����м�λ��Ϊ��Ի����������Դ��������Ƶ�(a��b��)��=ba
 *
 * (2) Դ������
 * (3) ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(1)
 */

#include <iostream>
using namespace std;
const int N = 110;
struct Sqlist
{
    int data[N];
    int length;
};
void Print(Sqlist *q);
Sqlist* Init_sqlist(int a[], int l);
void exchange(Sqlist *q, int l, int r);
void remove_left(Sqlist *q, int pos);

int main()
{
    int a[] = {2, 3, 5, 6, 7,8, 10, 11, 14, 15, 17, 23, 25, 29};
    int len = sizeof a / 4;
    Sqlist* sqlist = Init_sqlist(a, len);
    Print(sqlist);
    puts("");
    int x;
    cout << "��������Ҫ���ƶ���λ��: ";
    cin >> x;
    remove_left(sqlist, x);
    Print(sqlist);
    return 0;
}


Sqlist* Init_sqlist(int a[], int l)
{
    Sqlist* sqlist = new Sqlist;
    for (int i = 0; i < l; ++ i)
        sqlist->data[i] = a[i];
    sqlist->length = l;
    return sqlist;
}

void exchange(Sqlist *q, int l, int r)
{
    for (int i = l; i <= (l + r) / 2; ++ i)
    {
        int tmp = q->data[i];
        q->data[i] = q->data[l + r - i];
        q->data[l + r - i] = tmp;
    }
}

void remove_left(Sqlist *q, int pos)
{
    exchange(q, 0, pos - 1);
    exchange(q, pos, q->length - 1);
    exchange(q, 0, q->length - 1);
}

void Print(Sqlist *q)
{
    for (int i = 0; i < q->length; ++ i)
        cout << q->data[i] << " ";
    cout << endl;
}
