#include <iostream>
#include <vector>
using namespace std;

#define NODE 5005
vector<int> edges[NODE];
int path[NODE] = {0};
int path_len = 0;

void Build_edges(int n)
{
    for(int i = 1; i <= n; i++) edges[i].clear();
    for(int i = 1; i < n; i++)
    {
        int row, col;
        cin >> row >> col;
        edges[row].push_back(col);
        edges[col].push_back(row);
    }
}

bool Play(int s, int d, int p)
{
    path[path_len++] = s;
    if(s == d) return true;
    int len = edges[s].size();
    for(int i = 0; i < len; i++)
    {
        int temp = edges[s][i];
        if(p == temp) continue;
        if(Play(temp, d, s)) return true;
    }
    path_len -= 1;
    return false;
}

int main()
{
    int n, cases;
    while((cin >> n) && n)
    {
        Build_edges(n);
        cin >> cases;
        for(int loop = 0; loop < cases; loop++)
        {
            int s, d;
            path_len = 0;
            cin >> s >> d;
            Play(s, d, -1);
            if(path_len & 1)
                cout << "The fleas meet at " << path[path_len/2] << '.' << endl;
            else
            {
                int a = min(path[path_len/2], path[path_len/2-1]);
                int b = max(path[path_len/2], path[path_len/2-1]);
                cout << "The fleas jump forever between " << a << " and " << b << '.' << endl;
            }
        }
    }
}
