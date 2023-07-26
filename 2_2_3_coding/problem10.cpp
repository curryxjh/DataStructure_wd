/*
 * p10
 * (1) 算法基本思想:参照p08的思路,把数组堪称两部分ab，a即为需要左移的部分，b为不需要左移的部分，
 * 原顺序为ab，现在左移后需要得到顺序为ba，那么只要调换这两段字符的位置即可，但需要注意ab的长度不相同，
 * 所以不可以直接以中间位置为抽对换，参照线性代数的类似点(a逆b逆)逆=ba
 *
 * (2) 源码如下
 * (3) 时间复杂度：O(n) 空间复杂度：O(1)
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
    cout << "请输入需要左移动的位数: ";
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
