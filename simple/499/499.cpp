#include <iostream>
#include <string>
using namespace std;

void ShowMost(int asci[])
{
    int max = 0;
    for(int i = 0; i < 128; i++)
    {
        if(asci[i] > max)
            max = asci[i];
    }
    for(int i = 0; i < 128; i++)
    {
        if(asci[i] != 0 && asci[i] >= max)
            cout << (char)i;
    }
    cout << " " << max << endl;
}

void ScanChar(int asci[], string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if((str[i] <= 'Z' && str[i] >= 'A') || (str[i] <= 'z' && str[i] >= 'a'))
            asci[str[i]] += 1;
    }
}

int main()
{
    string str;
    int asci[128] = {0};
    while(getline(cin, str))
    {
        ScanChar(asci, str);
        ShowMost(asci);
        for(int i = 0; i < 128; i++)
            asci[i] = 0;
    }
}
