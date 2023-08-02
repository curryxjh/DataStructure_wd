/*
 * 选择排序
 * 空间复杂度：O(1)
 * 时间复杂度：O(n^2)
 */
#include <iostream>
using namespace std;
const int N = 10;
int a[N]= {36, 78, 12, 36, 50, 2, 7, 19, 6, 99};
void Select_Sort(int arr[], int n);
void Print(int arr[], int n);
void swap(int &a, int &b);

int main()
{
    Select_Sort(a, N);
    Print(a, N);
    return 0;
}

void Select_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++ i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++ j)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            swap(arr[i], arr[min]);
    }
}

void Print(int arr[], int n)
{
    for (int i = 0; i < n; ++ i)
        cout << arr[i] << " ";
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}