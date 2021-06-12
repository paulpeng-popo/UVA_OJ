#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <set>
using namespace std;

// auto cmp = [](char a, char b) { return a > b; };
// set<char, decltype(cmp)> alpha(cmp);

void Show_intersection(set<char> (*temp))
{
    for (int j = 0; j < 5; j++)
    {
        for (auto it = temp[j].begin(); it != temp[j].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

void Make_intersection(set<char> (*first), set<char> (*second), set<char> (*final))
{
    for (int j = 0; j < 5; j++)
    {
        set_intersection(first[j].begin(), first[j].end(),
                         second[j].begin(), second[j].end(),
                         inserter(final[j], final[j].begin()));
    }
}

void Fill_in(set<char> (*temp))
{
    string line;
    for (int i = 0; i < 6; i++)
    {
        cin >> line;
        for (int j = 0; j < 5; j++)
            temp[j].insert(line[j]);
    }
}

void Combination(int pos, set<char> (*temp), vector<string>& arr, string str)
{
    for (auto it = temp[pos].begin(); it != temp[pos].end(); it++)
    {
        string new_str = str + (*it);
        if (pos == 4) arr.push_back(new_str);
        else Combination(pos+1, temp, arr, new_str);
    }
}

int main()
{
    int cases;
    set<char> alpha[5];
    set<char> beta[5];
    set<char> Iwant[5];
    vector<string> List;

    cin >> cases;
    while (cases-- > 0)
    {
        int k;
        string line;
        cin >> k;

        Fill_in(alpha);
        Fill_in(beta);
        Make_intersection(alpha, beta, Iwant);
        // Show_intersection(Iwant);
        Combination(0, Iwant, List, "");
        int size = List.size();
        if (k > size) cout << "NO" << endl;
        else cout << List[k-1] << endl;

        for (int j = 0; j < 5; j++)
        {
            alpha[j].clear();
            beta[j].clear();
            Iwant[j].clear();
        }
        List.clear();
    }
    return 0;
}
