#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    int ascii;
    int count;
};

bool mycompare(Node n1, Node n2)
{
    if(n1.count != n2.count)
        return n1.count < n2.count;
    else
        return n1.ascii > n2.ascii;
}

int main()
{
    string str;
    Node list[128];
    list[0].count = 10001;
    while(getline(cin, str))
    {
        if(list[0].count != 10001) cout << endl;
        int size = str.length();
        for(int i = 0; i < 128; i++)
        {
            list[i].ascii = 0;
            list[i].count = 0;
        }
        for(int i = 0; i < size; i++)
        {
            int ascii = int(str[i]);
            if(ascii < 32) continue;
            list[ascii].ascii = ascii;
            list[ascii].count += 1;
        }
        sort(list, list+128, mycompare);
        for(int i = 0; i < 128; i++)
        {
            if(list[i].count == 0) continue;
            cout << list[i].ascii << " " << list[i].count << endl;
        }
    }
    return 0;
}
