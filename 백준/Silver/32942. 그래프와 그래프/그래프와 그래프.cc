#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g(11, vector<int>());

int main() {
	int a, b, c; cin >> a >> b >> c;
	int y;

	if (b == 0)
	{
		if (c % a == 0)
		{
			y = c / a;
			for (int x = 1;x < 11;++x)
			{
				g[y].push_back(x);
			}
		}

	}
	else
	{
		for (int x = 1;x < 11;++x)
		{
			if ((c - (a * x)) % b == 0)
			{
				y = (c - (a * x)) / b;
				if (y > 0 && y <= 10)
				{
					g[x].push_back(y);
				}
			}
			

		}
	}

	

	for (int x = 1;x < 11;++x)
	{
		if (g[x].empty()) {
			cout << 0;
		}
		else
		{
			for (int i = 0; i < g[x].size();++i)
			{
				cout << g[x][i] << ' ';
			}
		}

		cout << endl;
	}

	return 0;
}