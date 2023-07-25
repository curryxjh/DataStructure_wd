/*
 * p07
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
SqlList* Create_list_1();
SqlList* Create_list_2();
bool merge_list(SqlList *s, SqlList *t, SqlList *c);

int main()
{
    SqlList *l1 = Create_list_1();
    SqlList *l2 = Create_list_2();
    cout << "两个有序表为：" << endl;
    for (int i = 0; i < l1->length; ++ i)
        cout << l1->data[i] << " ";
    puts("");
    for (int i = 0; i < l2->length; ++ i)
        cout << l2->data[i] << " ";
    puts("");
    cout << "合并后的有序表为：" << endl;
    SqlList *ans = new SqlList;
    bool t = merge_list(l1, l2, ans);
    if (!t)
    {
        cout << "有误" << endl;
        return 0;
    }
    for (int i = 0; i < ans->length; ++ i)
        cout << ans->data[i] << " ";

    return 0;
}

SqlList* Create_list_1()
{
    SqlList * slist = new SqlList;
    Insert_Val(slist, 1, 4);
    Insert_Val(slist, 2, 4);
    Insert_Val(slist, 3, 5);
    Insert_Val(slist, 4, 5);
    Insert_Val(slist, 5, 5);
    Insert_Val(slist, 6, 7);
    Insert_Val(slist, 7, 12);
    Insert_Val(slist, 8, 12);
    return slist;
}

SqlList* Create_list_2()
{
    SqlList * slist = new SqlList;
    Insert_Val(slist, 1, 1);
    Insert_Val(slist, 2, 2);
    Insert_Val(slist, 3, 3);
    Insert_Val(slist, 4, 5);
    Insert_Val(slist, 5, 9);
    Insert_Val(slist, 6, 11);
    Insert_Val(slist, 7, 17);
    Insert_Val(slist, 8, 23);
    Insert_Val(slist, 9, 31);
    Insert_Val(slist, 10, 99);
    return slist;
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

bool merge_list(SqlList *s, SqlList * t, SqlList *c)
{
    if (s->length + t->length > MaxSize)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < s->length && j < t->length)
    {
        if (s->data[i] < t->data[j])
            c->data[k ++] = s->data[i ++];
        else
            c->data[k ++] = t->data[j ++];
    }
    cout << "here" << endl;
    while (i < s->length)
        c->data[k ++] = s->data[i ++];
    while (j < t->length)
        c->data[k ++] = t->data[j ++];
    c->length = k;
    return true;
}