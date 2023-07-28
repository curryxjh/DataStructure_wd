/*
 * p04
 */
#include <iostream>
#include <algorithm>
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
bool Del_val(SqlList *s, int l, int r);

int main()
{
    SqlList * slist = new SqlList;
    Insert_Val(slist, 1, 4);
    Insert_Val(slist, 2, 5);
    Insert_Val(slist, 3, 6);
    Insert_Val(slist, 4, 7);
    Insert_Val(slist, 5, 8);
    Insert_Val(slist, 6, 9);
    Insert_Val(slist, 7, 10);
    Insert_Val(slist, 8, 11);
    Insert_Val(slist, 9, 12);
    Insert_Val(slist, 10, 13);
    for (int i = 0; i < slist->length; ++ i)
        cout << slist->data[i] << " ";
    puts("");
    int l, r;
    cout << "请输入需要删除元素的区间范围：";
    cin >> l >> r;
    bool t = Del_val(slist, l, r);
    if(!t)
    {
        cout << "顺序表为空或输入不合法" << endl;
        return 0;
    }
    cout << "删除后的顺序表为：";
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

bool Del_val(SqlList *s, int l, int r)
{
    if ((l > r) || !s->length)
        return false;
    int head_max = 0, head_less = 0;
    for (head_max; s->data[head_max] < l; ++ head_max);
    if (head_max > s->length)
        return false;
    for (head_less = head_max; head_less < s->length && s->data[head_less] <= r; ++ head_less);
    for (; head_less < s->length; ++ head_less)
        s->data[head_max++] = s->data[head_less];
    s->length = head_max;
    return true;
}