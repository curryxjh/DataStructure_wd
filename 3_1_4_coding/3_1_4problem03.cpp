/*
 * p03
 */
#include <iostream>
using namespace std;
string str[] = {"IOIIOIOO", "IOOIOIIO", "IIIOIOIO", "IIIOOIOO"};

int main()
{

    for (int i = 0; i < 4; ++ i)
    {
        int ans = 0;
        bool flag = true;
        for (int j = 0; j < str[i].size(); ++ j)
        {
            if (str[i][j] == 'I')
                ++ ans;
            else if (str[i][j] == 'O')
                -- ans;
            if (ans < 0)
                flag = false;
        }
        if (flag && !ans)
            cout << char('A' + i) << "  合格" << endl;
        else
            cout << char('A' + i) << "  不合格" << endl;
    }
    return 0;
}