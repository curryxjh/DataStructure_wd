/*
 * p11
 * (1)�㷨����˼�룺��һ���뷨����������ֱ�Ӻϲ���һ���������У�Ȼ��ֱ��ȡ��λ����
 * �˴�����Ҫ��ĺϲ�������ָ�벻��ȥ�Ƚϣ�Ȼ���ж��Ѿ��ó��������еĸ������������г��Ⱥ͵�/2��ȡ�����ɡ�
 * ������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
 * �ڶ����뷨(��������)��ȥ�Ƚ��������е���λ��������ȣ���ϲ�֮���������λ��ҲΪ�������
 * �������(aΪ��һ�����е���λ����bΪ�ڶ������е���λ��)
 * a>b����ô��a�ұߵ�һ���������Լ���b��ߵ�һ������������Ч��
 * a<b����ô��a���һ���������Լ�b�ұ�һ������������Ч��
 * (2)Դ��������
 * (3)ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(1)
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