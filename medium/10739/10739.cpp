#include <iostream>
#include <cstring>
using namespace std;

int dp[1000][1000];

int palindrome(string str, int a, int b)
{
    if (a >= b) return 0;
    if (dp[a][b] == -1)
    {
        if (str[a] == str[b])
        {
            dp[a][b] = palindrome(str, a+1, b-1);
        }
        else if (str[a] != str[b])
        {
            dp[a][b] = 1+palindrome(str, a+1, b-1);
            int left = 1+palindrome(str, a, b-1);
            int down = 1+palindrome(str, a+1, b);
            if (dp[a][b] > left) dp[a][b] = left;
            if (dp[a][b] > down) dp[a][b] = down;
        }
    }
    return dp[a][b];
}

int main()
{
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        memset(dp, -1, sizeof(dp));
        cin >> str;
        int size = str.length();
        int ans = palindrome(str, 0, size-1);
        cout << "Case " << i+1 << ": " << ans << endl;
    }
    return 0;
}
