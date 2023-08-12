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
bool BracketCheck(char *str);

int main()
{
    char str[100];
    gets(str);
    if (BracketCheck(str))
        puts("∆•≈‰");
    else
        puts("≤ª∆•≈‰");
    return 0;
}
bool BracketCheck(char *str)
{
    SqStack s;
    Init(s, 100);
    int idx = 0;
    while (str[idx] != '\0')
    {
        if (str[idx] == '(' || str[idx] == '[' || str[idx] == '{')
        {
            Push(s, str[idx]);
            ++ idx;
        }
        else if (str[idx] == ')')
        {
            char ch;
            Pop(s, ch);
            if (ch != '(')
                return false;
            ++ idx;
        }
        else if (str[idx] == ']')
        {
            char ch;
            Pop(s, ch);
            if (ch != '[')
                return false;
            ++ idx;
        }
        else if (str[idx] == '}')
        {
            char ch;
            Pop(s, ch);
            if (ch != '{')
                return false;
            ++ idx;
        }
    }
    if (IsEmpty(s))
        return true;
    return false;
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
