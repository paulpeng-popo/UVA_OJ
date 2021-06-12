#include <iostream>
#include <vector>
using namespace std;

void Build(vector<vector<int>>& map, int n)
{
    vector<int> temp;
    map.assign(n+1, temp);
    for(int i = 0; i < n-1; i++)
    {
        int row, col;
        cin >> row >> col;
        map[row].push_back(col);
        map[col].push_back(row);
    }
}

bool Play(vector<vector<int>> map, int s, int d, vector<int>& path, int p)
{
    path.push_back(s);
    if(s == d) return true;
    int len = map[s].size();
    for(int i = 0; i < len; i++)
    {
        int temp = map[s][i];
        if(p == temp) continue;
        if(Play(map, temp, d, path, s)) return true;
    }
    path.pop_back();
    return false;
}

int main()
{
    int n, cases;
    while((cin >> n) && n)
    {
        vector<vector<int>> map;
        Build(map, n);
        cin >> cases;
        for(int i = 0; i < cases; i++)
        {
            int s, d;
            vector<int> path;
            cin >> s >> d;
            Play(map, s, d, path, -1);
            int length = path.size();
            if(length % 2)
                cout << "The fleas meet at " << path[length/2] << '.' << endl;
            else
            {
                int a = min(path[length/2], path[length/2-1]);
                int b = max(path[length/2], path[length/2-1]);
                cout << "The fleas jump forever between " << a << " and " << b << '.' << endl;
            }
        }
    }
}
