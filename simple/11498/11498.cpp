#include <iostream>
using namespace std;

int main()
{
    while(true)
    {
        int k, n, m, x, y;
        cin >> k;
        if(k == 0) break;
        cin >> n >> m;
        for(int i = 0; i < k; i++)
        {
            cin >> x >> y;
            if(x == n || y == m)
                cout << "divisa" << endl;
            else if(x > n && y > m)
                cout << "NE" << endl;
            else if(x > n && y < m)
                cout << "SE" << endl;
            else if(x < n && y > m)
                cout << "NO" << endl;
            else if(x < n && y < m)
                cout << "SO" << endl;
        }
    }
}
