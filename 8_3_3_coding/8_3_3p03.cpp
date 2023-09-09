#include <iostream>
int a[11] = {9, 7, 11, 3, 23, 2, 6, 34, 99, 1, 4};
int alen = 11;
void Sort(int a[], int n);


int main()
{
    Sort(a, alen);
    for (int i = 0; i < alen; ++ i)
        std::cout << a[i] << " ";
    return 0;
}

void Sort(int a[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (i < j && a[i] % 2 != 0)
            ++ i;
        while (i < j && a[j] % 2 == 0)
            -- j;
        if (i < j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        ++ i;
        -- j;
    }
}