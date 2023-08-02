/*
 * 冒泡排序
 * 算法最优时间复杂度：O(n) 表有序
 * 算法最差时间复杂度：O(n^2) 表逆序
 * 算法平均时间复杂度：O(n^2)
 * 算法空间复杂度：O(1)
 */
#include <iostream>
using namespace std;
const int N = 10;
int a[N]= {36, 78, 12, 36, 50, 2, 7, 19, 6, 99};
void BubbleSort(int arr[], int n);
void swap(int &a, int &b);
void Print(int arr[], int n);

int main()
{
    BubbleSort(a, N);
    Print(a, N);
    return 0;
}

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++ i)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; ++ j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            return;
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Print(int arr[], int n)
{
    for (int i = 0; i < n; ++ i)
        cout << arr[i] << " ";
}