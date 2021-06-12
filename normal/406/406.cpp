#include <iostream>
#include <vector>
using namespace std;

vector<bool> Prime_table(1001, true);
vector<int> Prime_count;

void Show()
{
    int size = Prime_count.size();
    for(int i = 0; i < size; i++)
    {
        cout << Prime_count[i] << '\t' << i << endl;
    }
}

void Count()
{
    for(int i = 1; i < 1001; i++)
    {
        if(Prime_table[i])
            Prime_count.push_back(i);
    }
}

void Build()
{
    Prime_table[0] = false;
    for(int i = 2; i*i <= 1001; i++)
    {
        if(Prime_table[i])
        {
            int prime = i*i;
            while(prime <= 1001)
            {
                Prime_table[prime] = false;
                prime += i;
            }
        }
    }
    Count();
}

void Input()
{
    int n, c;
    while(cin >> n >> c)
    {
        int loc = 0, len = c*2-1;
        int size = Prime_count.size();
        while(Prime_count[loc++] <= n && loc < size+1);
        if(loc-len-1 < 0)
            len = 0;
        else
            len = (loc-len-1) / 2;
        // cout << "loc: " << loc << ' ' << "len: " << len << endl;
        cout << n << ' ' << c << ": ";
        for(int i = len; i < loc-len-1 && i < size; i++)
        {
            if(i != loc-len-2 && i != size-1)
                cout << Prime_count[i] << " ";
            else
                cout << Prime_count[i];
        }
        cout << endl << endl;
    }
}

int main()
{
    Build();
    // Show();
    Input();
}
