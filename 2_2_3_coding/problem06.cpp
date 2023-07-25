/*
 * p06
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
bool Del_val(SqlList *s);

int main()
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
    Insert_Val(slist, 9, 31);
    Insert_Val(slist, 10, 54);
    for (int i = 0; i < slist->length; ++ i)
        cout << slist->data[i] << " ";
    puts("");

    bool t = Del_val(slist);
    if (!t)
    {
        cout << "顺序表为空，不需要进行删除" << endl;
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

bool Del_val(SqlList *s)
{
    if (!s->length)
        return false;
    int i, j;
    for (i = 0, j = 1; j < s->length; ++ j)
    {
        if (s->data[i] != s->data[j])
            s->data[++ i] = s->data[j];
    }
    s->length = i + 1;
    return true;
}
