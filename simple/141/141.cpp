#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool **rotate(bool **seq, int size)
{
    bool **temp = new bool*[size];
    for(int i = 0; i < size; i++)
        temp[i] = new bool[size];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            temp[i][j] = seq[size-j-1][i];
    }
    return temp;
}

bool check(bool **seq, vector<bool**> log, int size)
{
    vector<bool**>::iterator it_i;
    for(it_i = log.begin(); it_i != log.end(); it_i++)
    {
        bool result = true;
        bool **temp = *it_i;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                result = result && (seq[i][j] == temp[i][j]);
        }
        if(result) return result;
    }
    return false;
}

int main()
{
    int size;
    cin >> size;
    vector<bool**> log;
    while(size != 0)
    {
        bool stop = false;
        bool **seq = new bool*[size];
        for(int i = 0; i < size; i++)
            seq[i] = new bool[size];
        for(int i = 0; i < size*2; i++)
        {
            char op;
            int x, y;
            cin >> x >> y >> op;
            if(!stop)
            {
                if(op == '+')
                    seq[x-1][y-1] = true;
                else
                    seq[x-1][y-1] = false;

                bool **temp = seq;
                bool result = false;
                result = result || check(temp, log, size);
                for(int j = 0; j < 3; j++)
                {
                    temp = rotate(temp, size);
                    result = result || check(temp, log, size);
                }
                stop = result;
                if(result) cout << "Player " << ((i+1)%2+1) << " wins on move " << i+1 << endl;
                log.push_back(temp);
            }
        }
        if(!stop) cout << "Draw" << endl;
        log.clear();
        cin >> size;
    }
}
