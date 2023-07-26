/*
 * p11
 * (1)算法基本思想：第一个想法将两个序列直接合并成一个有序序列，然后直接取中位数，
 * 此处不需要真的合并，两个指针不断去比较，然后判断已经得出有序序列的个数和两个序列长度和的/2上取整即可。
 * 这样做时间复杂度为O(n)，空间复杂度为O(1)
 * 第二个想法(王道正解)，去比较两个序列的中位数，若相等，则合并之后的序列中位数也为这个数字
 * 若不想等(a为第一个序列的中位数，b为第二个序列的中位数)
 * a>b：那么在a右边的一部分数字以及在b左边的一部分数字是无效的
 * a<b：那么在a左边一部分数字以及b右边一部分数字是无效的
 * (2)源代码如下
 * (3)时间复杂度：O(n) 空间复杂度：O(1)
 */
#include <iostream>
using namespace std;
const int N = 110;
struct Sqlist
{
    int data[N];
    int length;
};
void Print(Sqlist *q);
Sqlist* Init_sqlist(int a[], int l);
int find_middle(Sqlist *p, Sqlist *q);

int main()
{
    int a[] = {2, 3, 9, 11, 17,18, 20};
    int b[] = {3, 3, 5, 8, 9, 14, 19};
    int len1 = sizeof a / 4;
    int len2 = sizeof b / 4;
    Sqlist* sqlistA = Init_sqlist(a, len1);
    Sqlist* sqlistB = Init_sqlist(b,len2);
    Print(sqlistA);
    Print(sqlistB);
    puts("");
    int middle = find_middle(sqlistA, sqlistB);
    cout << middle << endl;
    return 0;
}


Sqlist* Init_sqlist(int a[], int l)
{
    Sqlist* sqlist = new Sqlist;
    for (int i = 0; i < l; ++ i)
        sqlist->data[i] = a[i];
    sqlist->length = l;
    return sqlist;
}

int find_middle(Sqlist *p, Sqlist *q)
{
    int i = 0, j = 0;
    int pos = (p->length + q->length - 1) / 2;
    int middle = 0;
    while (i < p->length && j < q->length)
    {
        if(p->data[i] <= q->data[j])
        {
            ++ middle;
            if (middle == pos + 1)
                return p->data[i];
            ++ i;
        }
        else
        {
            ++ middle;
            if (middle == pos + 1)
                return q->data[j];
            ++ j;
        }
    }
}

void Print(Sqlist *q)
{
    for (int i = 0; i < q->length; ++ i)
        cout << q->data[i] << " ";
    cout << endl;
}