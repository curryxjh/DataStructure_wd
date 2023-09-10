#include <iostream>
using namespace std;
const int N = 11;
int q[N];
int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
int n = 5, m = 5;
void Merge(int a[], int n, int m);

int main()
{
    Merge(a, n, m);
    for (int i = 0; i < m + n; ++ i)
        cout << a[i] << " ";
    return 0;
}

void Merge(int a[], int n, int m)
{
    int k = 0, i = 0, j = n;
    while (i <= n - 1 && j <= n + m - 1)
    {
        if (a[i] < a[j])
            q[k ++] = a[i ++];
        else
            q[k ++] = a[j ++];
    }
    while (i < n)
        q[k ++] = a[i ++];
    while (j < n + m)
        q[k ++] = a[j ++];
    for (int i = 0; i < n + m; ++ i)
        a[i] = q[i];
}