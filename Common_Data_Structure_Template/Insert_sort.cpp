/*
 * 算法空间复杂度：O(1)
 * 算法最优时间复杂度：O(n)
 * 算法最坏时间复杂度：O(n^2)
 * 算法平均复杂度：O(n^2)
 */
#include <iostream>
using namespace std;
const int N = 10;
int a[N]= {36, 78, 12, 36, 50, 2, 7, 19, 6, 99};
void InsertSort(int arr[], int n);
void Print(int arr[], int n);

int main() {
    InsertSort(a, N);
    Print(a, N);

    return 0;
}

void InsertSort(int arr[], int n)
{
    for (int i = 1; i < n; ++ i)
    {
        int tmp;
        if(a[i] < a[i - 1])
        {
            tmp = a[i];
            int j;
            for (j = i - 1; j >= 0 && a[j] > tmp; --j)
                a[j + 1] = a[j];
            a[j + 1] = tmp;
        }
    }
}

void Print(int arr[], int n)
{
    for (int i = 0; i < n; ++ i)
        cout << arr[i] << " ";
}