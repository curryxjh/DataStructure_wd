/*
 * p13
 * (1) 新开一个数组用来存储原数组中出现的正整数，然后扫描一下新开的数组，第一个为0的就是最小正整数
 * (2) 源代码如下
 * (3) 时间复杂度：O(n) 空间复杂度：O(n)
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;
int A[] = {1, 2, 3, 4, 5, 7, 5, 5};
int find_min_num(int a[], int n);

int main()
{
    int n = sizeof A / 4;
    cout << find_min_num(A, n) << endl;

    return 0;
}

int find_min_num(int a[], int n)
{
    int *b = new int[N];
    memset(b, 0, sizeof b * n);
    for (int i = 0; i < n; ++ i)
        if (a[i] > 0 && a[i] <= n)
            ++b[a[i]];
    for (int i = 1; i < n; ++ i)
        if (!b[i])
            return i;
}