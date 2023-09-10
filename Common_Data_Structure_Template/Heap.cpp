/*
 * 堆排序
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(1)
 * 建立堆的复杂度：O(n)
 */

#include <iostream>
using namespace std;
const int N = 1010, M = 10;
int a[M]= {36, 78, 12, 36, 50, 2, 7, 19, 6, 99};
int h[N], g[N], n, s;
void swap(int &a, int &b);
void HeadAdjust(int arr, int k, int len);
void BuildMaxHeap(int arr[], int len);
void down(int x);


int main()
{

    return 0;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void down(int x)
{
    int t = x;
    if (2 * x <= s && h[2 * x] < h[t])
        t = 2 * x;
    if (2 * x + 1 <= s && h[2 * x + 1] < h[t])
        t = 2 * x + 1;
    if (t != x)
    {
        swap(h[t], h[x]);
        down(t);
    }
}

void HeadAdjust(int arr[], int k, int len)
{
    arr[0] = arr[k];
    for (int i = 2 * k; i <= len; i *= 2)
    {
        if (i <= len && arr[i] < arr[i + 1])
            ++i;
        if (arr[0] >= arr[i])
            break;
        else
        {
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0];
}

void BuildMaxHeap(int arr[], int len)
{
    for (int i = len / 2; i; -- i)
        HeadAdjust(arr, i , len);
}
