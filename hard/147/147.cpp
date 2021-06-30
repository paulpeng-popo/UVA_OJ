#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int coin[] {
    10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5
};

long long dp[30001] = {1};

long long bank(string temp)
{
    return dp[stoi(temp)];
}

int main()
{
    string change;
    long long ways = 0;

    for(int i = 10; i >= 0; i--)
        for(int j = coin[i]; j <= 30000; j += 5)
            dp[j] += dp[j-coin[i]];

    cin >> change;
    while(change != "0.00")
    {
        string temp;
        for(int i = 0; i < change.length(); i++)
            if(change[i] != '.') temp += change[i];
        ways = bank(temp);
        cout << fixed << setprecision(2);
        cout << setw(6) << change;
        cout << setw(17) << ways << endl;
        cin >> change;
    }
}
