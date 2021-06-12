#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int d[maxn], ans[20], num[20], a[20][20];

int main()
{
    int s; // capacity of posts
    while ((cin >> s) && s != 0)
    {
        int n;
        cin >> n; // how many sets of postage
        // calculate the max coverage of the test case
        for (int i = 1; i <= n; i++)
        {
            cin >> num[i]; // how many postages in the set
            for (int j = 1; j <= num[i]; j++) cin >> a[i][j]; // store postages
            memset(d, 63, sizeof(d)); // initialize each d[] in 63s
            d[0] = 0;
            for (int j = 1; j < maxn; j++) // j indicates the range of coverage
            {
                for (int k = 1; k <= num[i] && j-a[i][k] >= 0; k++)
                    // decide d[j] should add one new postage or add one postage from previous postage
                    d[j] = min(d[j], d[j-a[i][k]]+1);
                // if number of posts greater than capacity, then minus one and store to answer and break
                if (d[j] > s) { ans[i] = j-1; break; }
            }
        }
        // figure out which set of postage produce the max coverage with fewest cost
        int best = -1, pos = 0;
        for(int i = 1; i <= n; i++)
        {
            if (ans[i] > best) best = ans[i], pos = i;
            else if (ans[i] == best)
            {
                if (num[i] < num[pos]) pos = i;
                else if (num[i] == num[pos])
                {
                    bool ok = false;
                    for (int j = num[i]; j > 0; j--)
                        if (a[i][j] != a[pos][j])
                        {
                            ok = a[i][j] < a[pos][j];
                            break;
                        }
                    if (ok) pos = i;
                }
            }
        }
        printf("max coverage =%4d :", ans[pos]);
        for (int i = 1; i <= num[pos]; i++)
            printf("%3d",a[pos][i]);
        printf("\n");
    }
    return 0;
}
