/*
 * p02
 * ˫ָ�뷨Ҳ�ɣ�����ı�Ԫ�ص����λ��,���ڲ�һ��
 */
// todo ˫ָ��ⷨ
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef int ElemType;
const int MaxSize = 110;
struct SqlList
{
    ElemType data[MaxSize];
    int length;
};
bool Insert_Val(SqlList *s, int i, int val);
void del_val_x_v1(SqlList *s, int x);
void del_val_x_v2(SqlList *s, int x);

int main()
{
    SqlList * slist = new SqlList;
    Insert_Val(slist, 1, 4);
    Insert_Val(slist, 2, 5);
    Insert_Val(slist, 3, 20);
    Insert_Val(slist, 4, 1);
    Insert_Val(slist, 5, 9);
    Insert_Val(slist, 2, 9);
    Insert_Val(slist, 2, 9);
    for (int i = 0; i < slist->length; ++ i)
        cout << slist->data[i] << " ";
    cout << endl << "������Ҫɾ��Ԫ�أ�";
    int x;
    cin >> x;
    del_val_x_v1(slist, x);
    cout << "ɾ��Ԫ�غ��˳���Ϊ��";
    for (int i = 0; i < slist->length; ++ i)
        cout << slist->data[i] << " ";
    cout << endl << "������Ҫɾ���ĵڶ���Ԫ�أ�";
    int y;
    cin >> y;
    del_val_x_v2(slist, y);
    cout << "ɾ��Ԫ�غ��˳���Ϊ��";
    for (int i = 0; i < slist->length; ++ i)
        cout << slist->data[i] << " ";
    return 0;
}

bool Insert_Val(SqlList *s, int i, int val)
{
    if (i < 1 || i > s->length + 1)
        return false;
    if (s->length >= MaxSize)
        return false;
    for (int j = s->length; j >= i; -- j)
        s->data[j] = s->data[j - 1];
    s->data[i - 1] = val;
    ++ s->length;
    return true;
}

void del_val_x_v1(SqlList *s, int x)
{
    int num = 0;
    for (int i = 0; i < s->length; ++ i)
        if (s->data[i] != x)
        {
            s->data[num] = s->data[i];
            ++ num;
        }
    s->length = num;
}

void del_val_x_v2(SqlList *s, int x)
{
    int num = 0;
    for (int i = 0; i < s->length; ++ i)
    {
        if (s->data[i] == x)
            ++ num;
        else
            s->data[i - num] = s->data[i];
    }
    s->length -= num;
}