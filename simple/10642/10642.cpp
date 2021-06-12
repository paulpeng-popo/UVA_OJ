#include <iostream>
using namespace std;

long magic(int a, int b)
{
    long sum = 0;
    for(int i = 1; i <= (a+b); i++)
        sum += i;
    return sum + a;
}

int main()
{
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        int s1, s2, d1, d2;
        cin >> s1 >> s2 >> d1 >> d2;
        long result = magic(d1, d2)-magic(s1, s2);
        cout << "Case " << i+1 << ": " << result << endl;
    }
}
