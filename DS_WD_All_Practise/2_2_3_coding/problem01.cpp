/*
 * p01
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
bool Del_Min(SqlList *s, int &val);

int main()
{
    SqlList * slist = new SqlList;
    Insert_Val(slist, 1, 4);
    Insert_Val(slist, 2, 5);
    Insert_Val(slist, 3, 20);
    Insert_Val(slist, 4, 1);
    Insert_Val(slist, 5, 9);
    for (int i = 0; i < slist->length; ++ i)
        cout << slist->data[i] << " ";
    puts("");
    int val;
    bool flag = Del_Min(slist, val);
    if(flag)
    {
        cout << "最小值为：" << val << endl;
        cout << "删除后的顺序表为： ";
        for (int i = 0; i < slist->length; ++i)
            cout << slist->data[i] << " ";
    }
    else
        puts("删除失败");
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

bool Del_Min(SqlList * s, int &val)
{
    if(!s->length)
        return false;

    int id = 0;
    val = s->data[id];
    for (int i = 1; i < s->length; ++ i)
        if(s->data[i] < val)
        {
            id = i;
            val = s->data[i];
        }
    s->data[id] = s->data[s->length - 1];
    -- s->length;
    return true;
}
