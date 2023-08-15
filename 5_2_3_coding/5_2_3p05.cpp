/*
 * p05
 */

#include <iostream>
using namespace std;
struct SqTree
{
    int tree[12] = {-1, 1, 2, 3, -1, 4, -1, 5, -1, -1, 6, -1};
};
int Comm_ancestor(SqTree &t, int i, int j);

int main()
{
    SqTree s;
    int x, y;
    cin >> x >> y;
    cout << Comm_ancestor(s, x, y) << endl;
    return 0;
}

int Comm_ancestor(SqTree &t, int i, int j)
{
    if (t.tree[i] != -1 && t.tree[j] != -1)
    {
        while (i != j)
        {
            if (i > j)
                i /= 2;
            else
                j /= 2;
        }
        return t.tree[i];
    }
    return -1;
}