/*
 * p05
 */
#include <iostream>
using namespace std;
typedef int ElemType;

struct SqStack
{
    int top[3];
    int MaxSize;
    ElemType *data;
};
void Init(SqStack &s, int maxsize);
bool IsEmpty(SqStack &s, int i);
bool GetTop(SqStack &s, int i, ElemType &x);
bool Push(SqStack &s, int i, ElemType x);
bool Pop(SqStack &s, int i, ElemType &x);

int main()
{
    SqStack s;
    Init(s, 20);
    Push(s, 1, 2);
    Push(s, 1, 8);
    Push(s, 2, 4);
    int x;
    GetTop(s, 1, x);
    cout << x << endl;
    return 0;
}

void Init(SqStack &s, int maxsize)
{
    s.top[1] = -1;
    s.top[2] = maxsize;
    s.data = new ElemType[maxsize];
    s.MaxSize = maxsize;
}

bool IsEmpty(SqStack &s, int i)
{
    switch (i) {
        case 1:
            if (s.top[1] + 1 != s.top[2])
                return false;
            else
                return true;
        case 2:
            if (s.top[2] - 1 == s.top[1])
                return true;
            else
                return false;
    }
}

bool GetTop(SqStack &s, int i, ElemType &x)
{
    switch(i){
        case 1:
            if (s.top[1] != -1)
            {
                x = s.data[s.top[1]];
                return true;
            }
            else
                return false;
        case 2:
            if (s.top[2] != s.MaxSize)
            {
                x = s.data[s.top[2]];
                return true;
            }
            else
                return false;
    }
}

bool Push(SqStack &s, int i, ElemType x)
{
    if (i < 0 || i > 2)
        return false;
    if (s.top[1] + 1 == s.top[2])
    {
        puts("Õ»Âú");
        return false;
    }
    switch(i) {
        case 1:
            s.data[++ s.top[1]] = x;
            return true;
            break;
        case 2:
            s.data[-- s.top[2]] = x;
            return true;
            break;
    }
}

bool Pop(SqStack &s, int i, ElemType &x)
{
    if (i < 0 || i > 2)
        return false;
    switch(i) {
        case 1:
            if (s.top[1] == -1)
            {
                puts("Õ»¿Õ");
                return false;
            }
            else
            {
                x = s.data[s.top[1] --];
                return true;
            }
        case 2:
            if (s.top[2] == s.MaxSize)
            {
                puts("Õ»¿Õ");
                return false;
            }
            else
            {
                x = s.data[s.top[2] ++];
                return true;
            }
    }
}