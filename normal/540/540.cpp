#include <iostream>
#include <map>
#include <queue>
#include <string>
using  namespace std;

int main()
{
    int num, scene = 0;
    string instruction;
    cin >> num;
    while(num > 0)
    {
        int length, element;
        map<int, int> tag;
        for(int i = 0; i < num; i++)
        {
            cin >> length;
            for(int j = 0; j < length; j++)
            {
                cin >> element;
                tag[element] = i;
            }
        }
        cout << "Scenario #" << ++scene << endl;
        cin >> instruction;
        queue<int> teams_order;
        queue<int> a_team[num];
        while(instruction != "STOP")
        {
            if(instruction == "ENQUEUE")
            {
                int n;
                cin >> n;
                int head = tag[n];
                if(a_team[head].empty())
                {
                    teams_order.push(head);
                }
                a_team[head].push(n);
            }
            else
            {
                int head = teams_order.front();
                while(a_team[head].empty())
                {
                    teams_order.pop();
                    head = teams_order.front();
                }
                cout << a_team[head].front() << endl;
                a_team[head].pop();
                if(a_team[head].empty())
                {
                    teams_order.pop();
                }
            }
            cin >> instruction;
        }
        cout << endl;
        cin >> num;
    }
}
