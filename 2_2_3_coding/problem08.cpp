/*
 * p08
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
void Reverse_list(Sqlist *q, int l, int r);

int main()
{
    int a[] = {2, 9, 12, 3, 4,8, 23, 1, 34, 11, 7, 3, 5, 19};
    int m = 6, n = 8;
    Sqlist* sqlist = Init_sqlist(a, sizeof (a) / 4);
    cout << "原顺序表为：";
    Print(sqlist);
    Reverse_list(sqlist, 0, m + n - 1);
    Print(sqlist);
    Reverse_list(sqlist, 0, n - 1);
    Print(sqlist);
    Reverse_list(sqlist, n, m + n - 1);
    cout << "转换后的顺序表为：";
    Print(sqlist);
    return 0;
}

void Print(Sqlist *q)
{
    for (int i = 0; i < q->length; ++ i)
        cout << q->data[i] << " ";
    cout << endl;
}


Sqlist* Init_sqlist(int a[], int l)
{
    Sqlist* sqlist = new Sqlist;
    for (int i = 0; i < l; ++ i)
        sqlist->data[i] = a[i];
    sqlist->length = l;
    return sqlist;
}

void Reverse_list(Sqlist *q, int l, int r)
{
    for (int i = l; i <= (l + r) / 2; ++ i)
    {
        int tmp = q->data[i];
        q->data[i] = q->data[l + r - i];
        q->data[l + r - i] = tmp;
    }
}