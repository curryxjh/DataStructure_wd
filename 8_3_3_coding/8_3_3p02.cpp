#include <iostream>
int a[11] = {9, 7, 11, 3, 23, 2, 6, 34, 99, 1, 4};
int alen = 11;
void BubbleSort(int a[], int n);

int main()
{
    BubbleSort(a, alen);
    for (int i = 0; i < alen; ++ i)
        std::cout << a[i] << " ";
    return 0;
}

void BubbleSort(int a[], int n)
{
    int l = 0, r = n - 1;
    bool flag = true;
    while (l < r && flag)
    {
        flag = false;
        for (int i = l; i < r; ++ i)
        {
            if (a[i] > a[i + 1])
            {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                flag = true;
            }
        }
        -- r;
        for (int i = r; i > l; -- i)
        {
            if (a[i] < a[i - 1])
            {
                int tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                flag = true;
            }
        }
        ++ l;
    }
}