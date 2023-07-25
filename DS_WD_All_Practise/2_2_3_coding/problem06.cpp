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
void Del_val(SqlList *s);

int main()
{
    SqlList * slist = new SqlList;
    Insert_Val(slist, 1, 4);
    Insert_Val(slist, 2, 5);
    Insert_Val(slist, 3, 20);
    Insert_Val(slist, 4, 4);
    Insert_Val(slist, 5, 13);
    Insert_Val(slist, 6, 4);
    Insert_Val(slist, 7, 2);
    Insert_Val(slist, 8, 4);
    Insert_Val(slist, 9, 31);
    Insert_Val(slist, 10, 13);
    for (int i = 0; i < slist->length; ++ i)
        cout << slist->data[i] << " ";
    puts("");
    int l, r;
    cout << "请输入需要删除元素的区间范围：";
    cin >> l >> r;
    Del_val(slist);
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

void Del_val(SqlList *s)
{
    for (int i = 0, j = 0; )
}
