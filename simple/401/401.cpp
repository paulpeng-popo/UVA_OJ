#include <iostream>
#include <string>
#include <map>
using namespace std;

void Initial(map<char, char>& table)
{
    string keys = "AEHIJLMOSTUVWXYZ12358";
    string vals = "A3HILJMO2TUVWXY51SEZ8";
    int size = keys.size();
    for(int i = 0; i < size; i++)
        table[keys[i]] = vals[i];
}

int main()
{
    string str;
    map<char, char> table;
    Initial(table);
    while(cin >> str)
    {
        string test;
        bool mirror = true;
        int size = str.size();
        int middle = (size+1)/2;
        for(int i = size-1; i >= 0; i--)
            test += str[i];
        for(int i = 0; i < middle; i++)
            mirror = mirror && (str[size-(i+1)] == table[str[i]]);
        if(str == test && mirror)
            cout << str << " -- is a mirrored palindrome.\n" << endl;
        else if(str == test)
            cout << str << " -- is a regular palindrome.\n" << endl;
        else if(mirror)
            cout << str << " -- is a mirrored string.\n" << endl;
        else
            cout << str << " -- is not a palindrome.\n" << endl;
    }
}
