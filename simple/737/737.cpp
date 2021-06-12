#include <iostream>
using namespace std;

int main()
{
    int cubes;
	while(true)
	{
		cin >> cubes;
		if (cubes == 0) break;

        int ans;
        int x, y, z, len;
		int min_x, min_y, min_z;
		int max_x, max_y, max_z;
        min_x = min_y = min_z = max_x = max_y = max_z = 0;

		for(int i = 0; i < cubes; i++)
		{
			cin >> x >> y >> z >> len;

            if(i == 0)
            {
                min_x = x;
                min_y = y;
                min_z = z;
                max_x = x + len;
                max_y = y + len;
                max_z = z + len;
                continue;
            }

			min_x = max(min_x, x);
			min_y = max(min_y, y);
			min_z = max(min_z, z);

			max_x = min(max_x, x + len);
			max_y = min(max_y, y + len);
			max_z = min(max_z, z + len);
		}

		ans = (max_x-min_x)*(max_y-min_y)*(max_z-min_z);
		(min_x >= max_x || min_y >= max_y || min_z >= max_z) ? cout << 0 << endl : cout << abs(ans) << endl;
	}
}
