/*
 * p09
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
void Find_val(Sqlist *q, int val);

int main()
{
    int a[] = {2, 3, 5, 6, 7,8, 10, 11, 14, 15, 17, 23, 25, 29};
    int len = sizeof a / 4;
    Sqlist* sqlist = Init_sqlist(a, len);
    Print(sqlist);
    puts("");
    int x;
    cout << "请输入需要查找的值: ";
    cin >> x;
    Find_val(sqlist, x);
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

void Find_val(Sqlist *q, int val)
{
    int l = 0, r = q->length - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (q->data[mid] >= val)
            r = mid;
        else
            l = mid + 1;
    }
    if (q->data[l] == val && l != q->length - 1)
    {
        cout << "查找的元素在顺序表中" << endl;
        int tmp = q->data[l];
        q->data[l] = q->data[l + 1];
        q->data[l + 1] = tmp;
    }
    else
    {
        cout << "查找的元素不在顺序表中" << endl;
        for (int i = q->length - 1; i >= l; -- i)
            q->data[i + 1] = q->data[i];
        q->data[l] = val;
    }
}

void Print(Sqlist *q)
{
    for (int i = 0; i < q->length; ++ i)
        cout << q->data[i] << " ";
    cout << endl;
}