#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

int h, k, maxval;
map<int, int> stamp;
map<int, int> maxstamp;
map<int, int> ans;
vector<bool> check;

void dfs(int cur, int index, int sum)
{
	if (cur == h)
	{
		check[sum] = true;
		return;
	}

	check[sum] = true;
	for (int i = 0; i <= index; ++i) dfs(cur + 1, index, sum + stamp[i]);
}

void search(int index)
{
	if (index == k)
	{
		if (maxstamp[index - 1] > maxval)
		{
			maxval = maxstamp[index - 1];
			ans = stamp;
		}

		return;
	}

	for (int i = stamp[index - 1] + 1; i <= maxstamp[index - 1] + 1; ++i)
	{
		check.assign(200, false);
		stamp[index] = i;

		dfs(0, index, 0);

		int j = 0, num = 0;
		while (check[++j]) ++num;
		maxstamp[index] = num;

		search(index + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> h >> k, h && k)
	{
		stamp.clear();
		maxstamp.clear();
		maxval = 0;
		stamp[0] = 1;
		maxstamp[0] = h;

		search(1);

		for (auto& [key, val] : ans) cout << setw(3) << val;
		cout << " ->" << setw(3) << maxval << "\n";
	}

	return 0;
}
