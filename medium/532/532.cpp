#include <iostream>
#include <queue>
using namespace std;

// case size
int L, R, C;

// check if the location is in range
bool Qualified(int x, int y, int z)
{
    bool qualified = (x >= 0 && x < L && y >= 0 && y < R && z >= 0 && z < C);
    return qualified;
}

// structure of Location
struct Loc {
    Loc(int x, int y, int z)
        : x(x), y(y), z(z) {}
    int x, y, z;
};

// records the steps that every location should take
int bestMoves[35][35][35];
int max_steps;

// make sure the go_through direction in 6 ways
const int directions[6][3] = {
    {0, -1, 0},
    {0, 1, 0},
    {-1, 0, 0},
    {1, 0, 0},
    {0, 0, -1},
    {0, 0, 1}
};

// get infos from the maze
void getMaze(int& curri, int& currj, int& currk, int& exiti, int& exitj, int& exitk)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {
            string LineOfMaze;
            cin >> LineOfMaze;
            for (int k = 0; k < C; k++)
            {
                if (LineOfMaze[k] == 'S')
                {
                    curri = i;
                    currj = j;
                    currk = k;
                    // block if the location cannot arrive
                    bestMoves[i][j][k] = 0;
                }
                else if (LineOfMaze[k] == 'E')
                {
                    exiti = i;
                    exitj = j;
                    exitk = k;
                    // bigger int if the location can arrive
                    // but not the min_steps
                    bestMoves[i][j][k] = max_steps;
                }
                else if (LineOfMaze[k] == '.')
                    bestMoves[i][j][k] = max_steps;
                else
                    bestMoves[i][j][k] = 0;
            }
        }
    }
}



int bfs(int curri, int currj, int currk, Loc exit)
{
    queue<Loc> walkthrough;
    // add the start location in queue
    walkthrough.push(Loc(curri, currj, currk));

    // there are other possible ways can go
    while(!walkthrough.empty())
    {
        // retrieve the location now arriving
        Loc current = walkthrough.front();
        walkthrough.pop();

        // calculate the next steps based on the current location
        int nextSteps = bestMoves[current.x][current.y][current.z] + 1;
        for (int i = 0; i < 6; i++)
        {
            int x = current.x + directions[i][0];
            int y = current.y + directions[i][1];
            int z = current.z + directions[i][2];
            // if the x, y, z is in range and its stpes lower than the min_steps
            if (Qualified(x, y, z) && nextSteps < bestMoves[x][y][z])
            {
                // find the finish location
                if (x == exit.x && y == exit.y && z == exit.z)
                    return nextSteps;
                // not yet, but renew the min_steps in bestMoves
                bestMoves[x][y][z] = nextSteps;
                // add new location in queue
                walkthrough.push(Loc(x, y, z));
            }
        }
    }
    return -1;
}

int main()
{
    while(cin >> L >> R >> C)
    {
        if (L == 0) break;
        max_steps = L*R*C+10;
        int curri = -1, currj = -1, currk = -1;
        int exiti = -1, exitj = -1, exitk = -1;
        getMaze(curri, currj, currk, exiti, exitj, exitk);
        int min_steps = bfs(curri, currj, currk, Loc(exiti, exitj, exitk));
        (min_steps != -1) ? cout << "Escaped in " << min_steps << " minute(s)." : cout << "Trapped!";
        cout << endl;
    }
    return 0;
}
