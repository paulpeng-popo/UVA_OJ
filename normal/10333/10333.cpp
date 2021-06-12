#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> seq;

void make_seq(vector<int>& arr)
{
    int total;
    seq.push_back(0);
    for (int i = 1; i <= 32; i++)
    {
        total = i*(i+1)/2;
        seq.push_back(total);
    }
}

void make_leftpart(set<int>& temp, int height, int& level)
{
    int tail;
    for (tail = 0; tail < 32; tail++)
        if (seq[tail+1] > height) break;
    level = tail;
    int h = 1;
    while (tail-- > 0)
    {
        if (tail == 0 && height - h > 0)
            h = height;
        temp.insert(h);
        height -= h;
        h++;
    }
}

void draw_one_level_tower(int stars, bool left, bool right)
{
    left ? cout << "#**" : cout << '#';
    for (int i = 0; i < stars; i++) cout << '.';
    right ? cout << "**#" << endl : cout << "#" << endl;
}

void draw_picture(set<int> left, int height, int level)
{
    int layer = 1;
    for (const auto &s : left)
    {
        for (int i = 0; i < s; i++)
        {
            for (int j = 1; j < (level-(s-1))*2-1; j++)
                cout << ' ';
            if (i == 0)
            {
                if (layer >= level) draw_one_level_tower(layer*4-4, true, false);
                else draw_one_level_tower(layer*4-4, true, true);
            }
            else
            {
                if (layer >= level) draw_one_level_tower(layer*4-2, false, false);
                else draw_one_level_tower(layer*4, false, false);
            }
        }
        layer += 1;
    }
    cout << endl;
}

int main()
{
    int level;
    int height;
    int number = 1;
    set<int> left;
    make_seq(seq);

    while(cin >> height)
    {
        cout << "Tower #" << number++ << endl;
        make_leftpart(left, height, level);
        draw_picture(left, height, level);
        left.clear();
    }
    return 0;
}
