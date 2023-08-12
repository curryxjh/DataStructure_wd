/*
 * p02
 */
/*
 * p01
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef char ElemType;

struct SqStack
{
    int top;
    int MaxSize;
    ElemType *data;
};
void Init(SqStack &s, int maxsize);
void Destory(SqStack &s);
bool IsEmpty(SqStack &s);
bool IsFull(SqStack &s);
bool GetTop(SqStack &s, ElemType &x);
bool Push(SqStack &s, ElemType x);
bool Pop(SqStack &s, ElemType &x);
void modify_train(char *str);

int main()
{
    char str[100];
    gets(str);
    modify_train(str);
    return 0;
}

void modify_train(char *str)
{
    SqStack s;
    Init(s, 100);
    char ans[100];
    int i = 0;
    int idx = 0;
    while (str[idx] != '\0')
    {
        if (str[idx] == 'S')
        {
            ans[i ++] = str[idx ++];
            continue;
        }
        else if (str[idx] == 'H')
        {
            Push(s, str[idx]);
            ++idx;
        }
    }
    while (!IsEmpty(s))
        Pop(s, ans[i ++]);
    for (int j = 0; j < i; ++ j)
        cout << ans[j];
}

void Init(SqStack &s, int maxsize)
{
    s.data = new ElemType [maxsize];
    s.MaxSize = maxsize;
    s.top = -1;
}

void Destory(SqStack &s)
{
    s.MaxSize = -1;
    free(s.data);
    s.top = -1;
}

bool IsEmpty(SqStack &s)
{
    return s.top == -1;
}

bool IsFull(SqStack &s)
{
    return s.top == s.MaxSize - 1;
}

bool GetTop(SqStack &s, ElemType &x)
{
    if (IsEmpty(s))
        return false;
    x = s.data[s.top];
    return true;
}

bool Push(SqStack &s, ElemType x)
{
    if (IsFull(s))
        return false;
    s.data[++ s.top] = x;
    return true;
}

bool Pop(SqStack &s, ElemType &x)
{
    if (IsEmpty(s))
        return false;
    x = s.data[s.top --];
    return true;
}
