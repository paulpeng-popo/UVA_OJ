#include <iostream>
using namespace std;

bool isPrime(int num)
{
    for(int i = 2; i*i <= num; i++)
        if(!(num%i)) return false;
    return true;
}

int main()
{
    int num = 0;
    int min, max;
    while(cin >> num)
    {
        if(num == 0) break;
        min = max = num;
        for(;;min--)
            if(isPrime(min)) break;
        for(;;max++)
            if(isPrime(max)) break;
        cout << max - min << endl;
    }
}
