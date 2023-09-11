#include <iostream>
const int N = 110;
int a[14] = {7, 11, 5, 8, 9, 2, 4, 6, 23, 10, 1, 15, 44, 66};
int len = 14;
int b[N];
void countSort(int a[], int b[], int len);


int main()
{
    countSort(a, b, len);
    for (int i = 0; i < len; ++ i)
        std::cout << b[i] << "  ";
    return 0;
}

void countSort(int a[], int b[], int len)
{
    for (int i = 0; i < len; ++ i)
    {
        int cnt = 0;
        for (int j = 0; j < len; ++ j)
            if (a[j] < a[i])
                ++ cnt;
        b[cnt] = a[i];
    }
}