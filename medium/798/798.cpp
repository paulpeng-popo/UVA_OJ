#include <iostream>
#include <cstring>
using namespace std;

int groups, width, height, ways;
int m[10], w[10], h[10];
bool tiles[100][100];

bool isValid(int x, int y, int p, int q)
{
    // after placing tile(p, q) whether it exceeds the limit
	if (x + p > height || y + q > width)
        return false;
    // check if tile(p, q) can place into the blank place include location(x, y)
	for (int i = 0; i < p; i++)
    {
		for (int j = 0; j < q; j++)
        {
            // the blank it needs had been occupied
			if (tiles[x + i][y + j])
                return false;
		}
	}
	return true;
}

void placeTile(int x, int y, int p, int q, bool occupy)
{
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < q; j++)
			tiles[x + i][y + j] = occupy;
	}
}

void depth_first(int x, int y)
{
	if (y >= width)
    {
		x += 1;
		y = 0;
	}

	if (x >= height)
    {
		ways += 1;
        return;
	}

    // if tiles[x][y] is a blank
	if (!tiles[x][y])
    {
		for (int i = 0; i < groups; i++)
        {
            if (m[i] > 0) // still have tiles in that group
            {
    			if (isValid(x, y, h[i], w[i]))
                {
    				placeTile(x, y, h[i], w[i], true);
                    m[i] -= 1; // use one tile
    				depth_first(x, y + 1); // go next blank
    				placeTile(x, y, h[i], w[i], false);
                    m[i] += 1; // return one tile
    			}
                // exchange width and height of the tile --> rotate
    			if (h[i] != w[i] && isValid(x, y, w[i], h[i]))
                {
    				placeTile(x, y, w[i], h[i], true);
                    m[i] -= 1; // use one tile
    				depth_first(x, y + 1); // go next blank
    				placeTile(x, y, w[i], h[i], false);
                    m[i] += 1; // return one tile
    			}
    		}
        }
	} else depth_first(x, y + 1); // tiles[x][y] had been occupied, and go next blank
}

int main()
{
	while (cin >> width >> height >> groups)
    {
        ways = 0;
    	memset(tiles, false, sizeof(tiles)); // reset tiles
    	for (int i = 0; i < groups; i++)
            cin >> m[i] >> w[i] >> h[i];
		depth_first(0, 0); // start from location (0, 0)
		cout << ways << endl;
	}
	return 0;
}
