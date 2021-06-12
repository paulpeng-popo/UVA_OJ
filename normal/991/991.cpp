#include <iostream>
using namespace std;

int main()
{
    int func[11] = {1, 1};
    for (int i = 2; i < 11; i++)
    {
    	for (int j = 0; j < i; j++)
    	    func[i] += func[j] * func[i-j-1];
    }
    int n, flag = 0;
    while ( cin >> n )
    {
        if(flag)
            cout << endl;
        flag = 1;
        cout << func[n] << endl;
    }
    return 0;
}
