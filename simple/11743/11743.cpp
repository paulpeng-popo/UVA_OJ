#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int loop = 0; loop < n; loop++)
    {
        string str, substr;
        int sum = 0;
        for(int h = 0; h < 4; h++)
        {
            cin >> substr;
            str += substr;
        }
        for(int i = 0; i < 16; i++)
        {
            if(i%2)
                sum += (str[i]-'0');
            else
            {
                int temp = (str[i]-'0')*2;
                while(temp > 0)
                {
                    sum += (temp%10);
                    temp /= 10;
                }
            }
        }

        if(sum%10)
            cout << "Invalid" << endl;
        else
            cout << "Valid" << endl;
    }
}
