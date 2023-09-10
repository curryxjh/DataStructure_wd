#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int a[11]= { 0, 36, 78, 12, 36, 50, 2, 7, 19, 6, 99};
int h[N],n = 10,m = 10, s = 10;
void down(int x);
bool isMinHeap(int a[], int len);


int main()
{
    for(int i=1;i<=n;++i)
        h[i] = a[i];
    for (int i = 1; i <= n; ++ i)
        cout << h[i] << " ";
    puts("");
    for(int i=n/2;i;--i)
        down(i);
    for (int i = 1; i <= n; ++ i)
        cout << h[i] << " ";
    puts("");

    if (isMinHeap(h, n))
        puts("YES");
    else
        puts("NO");
    return 0;
}

void down(int x)
{
    int t=x;
    if(2*x<=s&&h[2*x]<h[t])
        t=2*x;
    if(2*x+1<=s&&h[2*x+1]<h[t])
        t=2*x+1;
    if(t!=x)
    {
        swap(h[t],h[x]);
        down(t);
    }
}

bool isMinHeap(int a[], int len)
{
    if (len % 2)
    {
        if (a[len / 2] > a[len])
            return false;
        for (int i = len / 2 - 1; i >= 1; -- i)
            if ((a[i] > a[i * 2] || a[i] > a[2 * i + 1]) && (i * 2 <= len && i * 2 + 1 <= len))
                return false;
    }
    else
    {
        for (int i = len / 2; i >= 1; -- i)
            if ((a[i] > a[i * 2] || a[i] > a[2 * i + 1]) && (i * 2 <= len && i * 2 + 1 <= len))
                return false;
    }
    return true;
}