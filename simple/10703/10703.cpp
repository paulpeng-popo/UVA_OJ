#include <iostream>
#include <set>
using namespace std;

class Position
{
public:
    int x;
    int y;
    Position(): x(0), y(0) {}
    Position(int i, int j) { x = i; y = j; }
    bool operator <(const Position& p) const
    {
        if(this->x == p.x)
            return (this->y < p.y);
        return (this->x < p.x);
    }
    friend ostream& operator <<(ostream& out, const Position& pos);
};

ostream& operator <<(ostream& out, const Position& pos)
{
    out << "( " << pos.x << ", " << pos.y << " )" << endl;
    return out;
}

void SpotSet(Position s, Position d, set<Position>& myset)
{
    for(int i = min(s.x, d.x); i <= max(s.x, d.x); i++)
    {
        for(int j = min(s.y, d.y); j <= max(s.y, d.y); j++)
            myset.insert(Position(i, j));
    }
}

int main()
{
    int W, H, N;
    int x1, y1, x2, y2;
    int total_spots = 0;

    cin >> W >> H >> N;
    while(W != 0 || H != 0 || N != 0)
    {
        set<Position> myset;
        total_spots = W*H;
        //cout << total_spots << endl;
        for(int c = 0; c < N; c++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            Position s(x1, y1);
            Position d(x2, y2);
            SpotSet(s, d, myset);
            // for(const auto &s : myset)
            //     cout << s;
        }
        int left = total_spots - myset.size();
        if(left == 0)
            cout << "There is no empty spots." << endl;
        else if(left == 1)
            cout << "There is one empty spot." << endl;
        else
            cout << "There are " << left << " empty spots." << endl;

        cin >> W >> H >> N;
    }
}
