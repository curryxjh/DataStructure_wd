/*
 * 快速排序
 * 最优时间复杂度：O(nlogn)
 * 最坏时间复杂度：O(n^2)
 * 最优空间复杂度：O(logn)
 * 最坏空间复杂度：O(n)
 */

#include <iostream>
using namespace std;
const int N = 10;
int a[N]= {36, 78, 12, 36, 50, 2, 7, 19, 6, 99};
void Quick_Sort_v1(int arr[], int l, int r); //以中间元素为枢纽
void Quick_Sort_v2(int arr[], int l, int r); //以第一个元素为枢纽
int Partition(int arr[], int l, int r); // 根据枢纽划分表元素
void Print(int arr[], int n);
void swap(int &a, int &b);

int main()
{
    Quick_Sort_v1(a, 0, N - 1);
    Print(a, N);
    puts("");
    Quick_Sort_v2(a, 0, N - 1);
    Print(a, N);
    return 0;
}

void Quick_Sort_v1(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int x = arr[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            ++ i;
        while(arr[i] < x);
        do
            -- j;
        while(arr[j] > x);
        if (i < j)
            swap(arr[i], arr[j]);
    }
    Quick_Sort_v1(arr, l, j);
    Quick_Sort_v1(arr, j + 1, r);
}

void Quick_Sort_v2(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivotpos = Partition(arr, l, r);
        Quick_Sort_v2(arr, l, pivotpos - 1);
        Quick_Sort_v2(arr, pivotpos + 1, r);
    }
}
int Partition(int arr[], int l, int r)
{
    int piv = arr[l];
    while (l < r)
    {
        while(l < r && arr[r] >= piv)
            -- r;
        arr[l] = a[r];
        while(l < r && arr[l] <= piv)
            ++ l;
        arr[r] = arr[l];
    }
    arr[l] = piv;
    return l;
}

void Print(int arr[], int n)
{
    for (int i = 0; i < n; ++ i)
        cout << arr[i] << " ";
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}