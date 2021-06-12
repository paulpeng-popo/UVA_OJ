#include <iostream>
#include <vector>
using namespace std;

typedef struct Intersection {
    Intersection(bool a, bool b, long long c)
        : from_west(a), from_south(b), ways(c) {}
    bool from_west;
    bool from_south;
    long long ways;
} Intsec;

void Initialize(vector<Intsec> *Roads, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Intsec node(true, true, 0);
            Roads[i].push_back(node);
        }
    }
}

void Set_barrier(vector<Intsec> *Roads)
{
    int W; cin >> W;
    for(int i = 0; i < W; i++)
    {
        int x, y;
        char direction;
        cin >> x >> y >> direction;
        if (direction == 'N')
        {
            y += 1;
            Roads[x][y].from_south = false;
        }
        else if (direction == 'E')
        {
            x += 1;
            Roads[x][y].from_west = false;
        }
        else if (direction == 'S')
            Roads[x][y].from_south = false;
        else if (direction == 'W')
            Roads[x][y].from_west = false;
    }
}

long long Calculate(vector<Intsec> *Roads, int startX, int startY, int endX, int endY, int size)
{
    Roads[startX][startY].ways = 1;
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            long long total = 0;
            // cout << "i: " << i << ' ' << "j: " << j << endl;
            if (Roads[i][j].from_west) total += Roads[i-1][j].ways;
            if (Roads[i][j].from_south) total += Roads[i][j-1].ways;
            Roads[i][j].ways += total;
            if (i == endX && j == endY) return total;
        }
    }
    return 0;
}

int main()
{
    int C, N;
    int startX, startY;
    int endX, endY;
    long long answer;

    cin >> C;
    for(int i = 0; i < C; i++)
    {
        cin >> N;
        cin >> startX >> startY;
        cin >> endX >> endY;

        vector<Intsec> Roads[N+1];
        Initialize(Roads, N+1);
        Set_barrier(Roads);
        answer = Calculate(Roads, startX, startY, endX, endY, N+1);
        cout << answer << endl;
        for (int i = 0; i < N+1; i++) Roads[i].clear();
    }
    return 0;
}
