/*
 * p12
 * �㷨����˼�룺�������Ŀ�򻯵���˼������һ���������ȵģ�����������Ǹ����е���Ԫ�������û����Ԫ
 * ��һ���뷨��ͳ������������Ԫ�صĳ��ִ˴����ҵ����ִ�������
 * �ڶ����뷨��ѡȡ��һ��Ԫ��Ϊ��ѡ��Ԫ��Ȼ������������У������ϸú�ѡԪ��ʱ+1�����Ǹ�Ԫ��-1
 * �����0���������ѡ��Ԫ��
 * Դ�������£�
 * ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(1)
 */
#include <iostream>
using namespace std;
const int N = 110;
int A[] = {0, 5, 5, 3, 5, 7, 5, 5};
int find_main(int a[], int n);

int main()
{
    int n = sizeof A / 4;
    int x = find_main(A, n);
    if (x == -1)
        cout << "��������Ԫ" << endl;
    else
        cout << "��ԪΪ��" << x << endl;
    return 0;
}

int find_main(int a[], int n)
{
    int v = a[0], cnt = 1;
    for (int i = 1; i < n; ++ i)
    {
        if (a[i] == v)
            ++ cnt;
        else
        {
            -- cnt;
            if (!cnt)
            {
                v = a[i];
                cnt = 1;
            }
        }
        int count = 0;
        if (cnt)
        {
            for (int i = 0; i < n; ++ i)
                if(a[i] == v)
                    ++ count;
        }
        if (count > n/2)
            return v;
        else
            return -1;
    }
}