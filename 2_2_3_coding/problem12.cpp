/*
 * p12
 * 算法基本思想：这道题题目简化的意思就是有一半的数是相等的，则这个数就是该序列的主元，否则就没有主元
 * 第一个想法：统计序列中所有元素的出现此处，找到出现次数最大的
 * 第二个想法：选取第一个元素为候选主元，然后遍历整个序列，当遇上该候选元素时+1，不是该元素-1
 * 若变成0了则更换候选主元。
 * 源代码如下：
 * 时间复杂度：O(n) 空间复杂度：O(1)
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
        cout << "不存在主元" << endl;
    else
        cout << "主元为：" << x << endl;
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