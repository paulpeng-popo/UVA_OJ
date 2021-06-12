#include <iostream>
#include <string>
using namespace std;

int nodes = 0;
int rootindex = 0;
string preOrder, inOrder;

int find(char root, int start, int end)
{
    for(int i = start; i < end; i++)
    {
        if(root == inOrder[i])
            return i;
    }
    return -1;
}

void recovery(int start, int end)
{
    if(rootindex >= nodes || start == end) return;
    if(start == end-1)
    {
        cout << inOrder[start];
        rootindex += (end-start);
    }
    else
    {
        char temp = preOrder[rootindex++];
        int iroot = find(temp, start, end);
        recovery(start, iroot);
        recovery(iroot+1, end);
        cout << inOrder[iroot];
    }
}

int main()
{
    while(cin >> preOrder >> inOrder)
    {
        nodes = preOrder.length();
        rootindex = 0;
        recovery(0, nodes);
        cout << endl;
    }
}
