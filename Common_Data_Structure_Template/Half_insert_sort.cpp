/*
 * 算法时间复杂度：O(n^2)
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
        int tmp = a[i];
        int l = 0, r = i - 1;

        while (l <= r)
        {
            int mid = l + r >> 1;
            if (a[mid] > tmp)
                r = mid - 1;
            else
                l = mid + 1;
        }
        for (int j = i - 1; j >= r + 1; -- j)
            a[j + 1] = a[j];
        a[r + 1] = tmp;
    }
}

void Print(int arr[], int n)
{
    for (int i = 0; i < n; ++ i)
        cout << arr[i] << " ";
}