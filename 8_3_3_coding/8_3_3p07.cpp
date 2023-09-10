#include <iostream>
int a[11] = {9, 7, 11, 3, 23, 2, 6, 34, 99, 1, 4};
int alen = 11;
void Quick_sort(int a[], int l, int r);
int split(int a[], int n);

int main()
{
    Quick_sort(a, 0, alen - 1);

    for (int i = 0; i < alen; ++ i)
        std::cout << a[i] << " ";
    puts("");
    std::cout << split(a, alen);
    return 0;
}


void Quick_sort(int a[], int l, int r)
{
    if (l >= r)
        return ;
    int val = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            ++ i;
        while (a[i] < val);
        do
            -- j;
        while(a[j] > val);
        if (i < j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    Quick_sort(a, l, j);
    Quick_sort(a, j + 1, r);
}

int split(int a[], int n)
{
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n / 2; ++ i)
        s1 += a[i];
    for (int j = n/2 + 1; j < n; ++ j)
        s2 += a[j];
    return abs(s1 - s2);
}