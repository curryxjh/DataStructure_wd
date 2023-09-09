#include <iostream>
// 0 red
// 2 blue
// 1 white
int color[9] = {0, 1, 2, 2, 1, 1, 2, 0, 1};
int clen = 9;
void Sort(int a[], int l, int r);

int main()
{
    Sort(color, 0, clen - 1);
    for (int i = 0; i < clen; ++ i)
        std::cout << color[i] << " ";
    return 0;
}

void Sort(int a[], int n)
{

}

void Sort(int a[], int l, int r)
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
    Sort(a, l, j);
    Sort(a, j + 1, r);
}