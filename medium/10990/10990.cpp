#include <iostream>
#include <cstring>
#define N 2000000
using namespace std;

int phi[N + 1];
int dep[N + 1];

void phi_1_to_n()
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= N; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2 * i; j <= N; j += i)
              phi[j] -= phi[i];
    }
}

int Find_depth(int n)
{
    if(dep[n] != -1)
        return dep[n];
    else
        dep[n] = 1 + Find_depth(phi[n]);
    return dep[n];
}

int main()
{
    phi_1_to_n();
    memset(dep, -1, sizeof(dep));
    dep[0] = 0;
    dep[1] = 0;
    dep[2] = 1;

    int T;
    cin >> T;
    for(int loop = 0; loop < T; loop++)
    {
        int m, n, sum = 0;
        cin >> m >> n;
        for(int i = m; i <= n; i++)
        {
            if(dep[i] != -1)
                sum += dep[i];
            else
                sum += Find_depth(i);
        }
        cout << sum << endl;
    }
    return 0;
}
