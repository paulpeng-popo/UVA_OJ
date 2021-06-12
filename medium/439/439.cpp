#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int direction[8][2] = {
    { 1, 2 },
    { 2, 1 },
    { 2, -1 },
    { 1, -2 },
    { -1, -2 },
    { -2, -1 },
    { -2, 1 },
    { -1, 2 }
};

class LOC
{
public:
    LOC() : x(0), y(0), steps(0) {}
    LOC(int a, int b) : x(a), y(b), steps(0) {}
    int x, y;
    int steps;
};

int TKP(LOC src, const LOC dst)
{
    if (src.x == dst.x && src.y == dst.y)
        return src.steps;

    bool isVisited[8][8] = { false };
    queue<LOC> que;
    que.push(src);

    while (!que.empty())
    {
        LOC curr = que.front();
        isVisited[curr.x][curr.y] = true;
        que.pop();

        // try all direction from the current point
        LOC next;
        for (int i = 0; i < 8; i++)
        {
            next.x = curr.x + direction[i][0];
            next.y = curr.y + direction[i][1];
            next.steps = curr.steps + 1;

            if ((next.x >= 0 && next.x < 8) && (next.y >= 0 && next.y < 8) && !isVisited[next.x][next.y])
            // the position is valid and haven't been visited
            {
                isVisited[next.x][next.y] = true;
                if (next.x == dst.x && next.y == dst.y) // arrive destination
                    return next.steps;
                que.push(next); // add a node to queue
            }
        }
    }
    return 0;
}

int main()
{
    string src, dst;
    while(cin >> src >> dst)
    {
        LOC p1(src[0]-'a', src[1]-'1'), p2(dst[0]-'a', dst[1]-'1');
        int moves = TKP(p1, p2);
        cout << "To get from " << src
             << " to " << dst << " takes "
             << moves << " knight moves." << endl;
    }
    return 0;
}
