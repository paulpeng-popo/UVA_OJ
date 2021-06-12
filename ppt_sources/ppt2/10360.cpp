#include <iostream>
#include <cstring>
using namespace std;

int road[1025][1025];
int main()
{
	int scenarios;
	cin >> scenarios;
	for(; scenarios > 0; scenarios--)
	{
		memset(road, 0, sizeof(road));
		int strength, group;
		int row = 0, col = 0, kills = 0;
		cin >> strength >> group;
		for(int line = 0; line < group; line++)
		{
			int x, y, num;
			cin >> x >> y >> num;
			for(int i = x - strength; i <= x + strength; i++)
			{
				for(int j = y - strength; j <= y + strength; j++)
				{
					if(i >= 0 && i < 1025 && j >= 0 && j < 1025)
					{
						road[i][j] += num;
						if(road[i][j] > kills)
						{
							kills = road[i][j];
							row = i;
							col = j;
						}
					}
				}
			}
		}
		cout << row << " " << col << " " << kills << endl;
	}
	return 0;
}
