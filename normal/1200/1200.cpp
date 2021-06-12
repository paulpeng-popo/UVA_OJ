#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int size = 0;
    int problems;
    int param[4];

    cin >> problems;
    while (problems-- > 0)
    {
        string expr;
        cin >> expr;
        size = expr.length();
        param[0] = param[1] = param[2] = param[3] = 0;

        int loc = 0;
        bool flag = true;
        int number = 0;
        for (int i = 0; i <= size; i++)
        {
            if (i == size)
            {
                flag ? param[loc+1] += number : param[loc+1] -= number;
                break;
            }
            if (47 < expr[i] && expr[i] < 58)
                number = number*10 + expr[i]-'0';
            else if (expr[i] == '=')
            {
                flag ? param[loc+1] += number : param[loc+1] -= number;
                number = 0;
                flag = true;
                loc += 2;
            }
            else if (expr[i] == 'x')
            {
                if (i == 0 || expr[i-1] == '+' || expr[i-1] == '=' || expr[i-1] == '-')
                    number = 1;
                flag ? param[loc] += number : param[loc] -= number;
                number = 0;
            }
            else if (expr[i] == '+')
            {
                flag ? param[loc+1] += number : param[loc+1] -= number;
                number = 0;
                flag = true;
            }
            else if (expr[i] == '-')
            {
                flag ? param[loc+1] += number : param[loc+1] -= number;
                number = 0;
                flag = false;
            }
        }
        // cout << param[0] << "x + " << param[1] << " = ";
        // cout << param[2] << "x + " << param[3] << endl;
        int x = param[1]-param[3];
        int y = param[2]-param[0];
        if (y == 0 && x == 0) cout << "IDENTITY" << endl;
        else if (y == 0 && x != 0) cout << "IMPOSSIBLE" << endl;
        else
        {
            double temp = float(x) / y;
            if (temp == 0)
                cout << 0 << endl;
            else
                cout << floor(temp) << endl;

        }
    }
    return 0;
}
