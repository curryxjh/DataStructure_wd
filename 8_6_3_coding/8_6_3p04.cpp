#include <iostream>
int a[14] = {7, 11, 5, 8, 79, 2, 4, 6, 23, 10, 1, 15, 44, 13};
int len = 14;
int Sort(int a[], int len);

int main()
{
    int idx = Sort(a, len);
    std::cout << idx << std::endl;
    for (int i = 0; i  < len; ++ i)
        std::cout << a[i] << "  ";
    return 0;
}

int Sort(int a[], int len)
{
    int i = 0, j = len - 1;
    int x = a[len - 1];
    while (i < j)
    {
        do
            ++ i;
        while (a[i] < x);
        do
            -- j;
        while (a[j] > x);
        if (i < j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    int tmp = a[i];
    a[i] = a[len - 1];
    a[len - 1] = tmp;
    return i;
}