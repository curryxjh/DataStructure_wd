/*
 * 希尔排序
 * 算法空间复杂度：O(1)
 * 算法最坏时间复杂度：O(n^2)
 * 算法时间平均复杂度：O(N^1.3)
 */
#include <iostream>
using namespace std;
const int N = 10;
int a[N]= {36, 78, 12, 36, 50, 2, 7, 19, 6, 99};
void SellSort(int arr[], int n);
void Print(int arr[], int n);

int main()
{
    SellSort(a, N);
    Print(a, N);
    return 0;
}

void SellSort(int arr[], int n)
{
    for (int d = n / 2; d >= 1; d /= 2)
    {
        for (int i = d; i < n; ++ i)
        {
            if(arr[i] < arr[i - d])
            {
                int tmp = arr[i];
                int j;
                for (j = i - d; j >= 0 && arr[j] > tmp; j -= d)
                    arr[j + d] = arr[j];
                arr[j + d] = tmp;
            }
        }
    }
}


void Print(int arr[], int n)
{
    for (int i = 0; i < n; ++ i)
        cout << arr[i] << " ";
}