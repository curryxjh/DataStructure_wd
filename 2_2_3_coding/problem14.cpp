/*
 * p14
 * (1) ��Ŀ��һ�µ���˼���Ǵ������������ѡ����һ�������Ԫ�飬������Ԫ���������СΪ���١�
 * (2) Դ������
 * (3) ʱ�临�Ӷȣ�O(n)  �ռ临�Ӷȣ�O(1)
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 110, INF = 0x3f3f3f3f;
int A[] = {-1, 0, 9};
int B[] = {-25, -10, 10, 11};
int C[] = {2, 9, 17, 30, 41};
int dist(int a[], int b[], int c[], int l1, int l2, int l3);

int main()
{
    cout << dist(A, B, C, sizeof A / 4, sizeof B / 4, sizeof C / 4) << endl;
    return 0;
}

int dist(int a[], int b[], int c[], int l1, int l2, int l3)
{
    int min_v = INF;
    for (int i = 0, j = 0, k = 0; i< l1 && j < l3 && k < l3;)
    {
        int d = abs(a[i] - b[j]) + abs(a[i] - c[k]) + abs(b[j] - c[k]);
        if (d < min_v)
            min_v = d;
        if (min(a[i], min(b[j], c[k])) == a[i])
            ++ i;
        else if (min(b[j], min(a[i], c[k])) == b[j])
            ++ j;
        else if (min(c[k], min(a[i], b[j])) == c[k])
            ++ k;
    }
    return min_v;
}