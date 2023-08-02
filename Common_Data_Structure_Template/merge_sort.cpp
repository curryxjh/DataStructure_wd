/*
 * 归并排序
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */

#include <iostream>
using namespace std;
const int N = 10, M = 110;
int a[N]= {36, 78, 12, 36, 50, 2, 7, 19, 6, 99};
int q[M], tmp[M];
void merge_sort(int q[], int l, int r);
void Print(int q[], int n);

int main()
{
    merge_sort(a, 0, N - 1);
    Print(a, N);
    return 0;
}

void Print(int q[], int n)
{
    for (int i = 0; i < n; ++ i)
        cout << q[i] << " ";
}

void merge_sort(int q[], int l, int r)
{
    if(l >= r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if(q[i] <= q[j])
            tmp[k ++] = q[i ++];
        else
            tmp[k ++] = q[j ++];
    }
    while (i <= mid)
        tmp[k ++] = q[i ++];
    while (j <= r)
        tmp[k ++] = q[j ++];
    for (i = l, j = 0;i <= r; ++i, ++ j)
        q[i] = tmp[j];
}