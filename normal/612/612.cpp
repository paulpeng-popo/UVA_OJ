#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class DNA {
public:
    DNA(): len(0), seq(""), order(0) {}
    void getinfo(int length)
    {
        cin >> seq;
        len = length;
        order = 0;
        for(int i = 0; i < len; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(seq[i] > seq[j])
                    order++;
            }
        }
    }
    void getseq() { cout << seq << endl; }
    int getorder() { return order; }
private:
    int len;
    string seq;
    int order;
};

bool compare(DNA x, DNA y)
{
    return x.getorder() < y.getorder();
}

int main()
{
    int datasets;
    cin >> datasets;
    while (datasets-- > 0)
    {
        int length, max;
        cin >> length >> max;
        DNA list[max];
        for (int i = 0; i < max; i++)
        {
            list[i].getinfo(length);
        }
        stable_sort(list , list + max , compare);
        for (int i = 0; i < max; i++)
            list[i].getseq();
        if (datasets != 0) cout << endl;
    }
    return 0;
}
