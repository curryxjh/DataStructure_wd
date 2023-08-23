/*
 * p15
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MasSize = 110;
void pre_to_post(char pre[], int l1, int r1, char post[], int l2, int r2);
char pre[MasSize], post[MasSize];

int main()
{
    cin.getline(pre, '\n');
    int len = strlen(pre);
    cout << len << endl;
    pre_to_post(pre, 0, len - 1, post, 0, len - 1);
    cout << "ÏÈÐò£º" << pre << endl;
    cout << "ºóÐò£º" << post << endl;
    return 0;
}

void pre_to_post(char pre[], int l1, int r1, char post[], int l2, int r2)
{
    int mid;
    if (r1 >= l1)
    {
        post[r2] = pre[l1];
        mid = (r1 - l1) / 2;
        pre_to_post(pre, l1 + 1, l1 + mid, post, l2, l2 + mid - 1);
        pre_to_post(pre, l1 + mid + 1, r1, post, l2 + mid, r2 - 1);
    }
}