#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>());
	vector<vector<bool>> cf(n, vector<bool>(n, false));
	vector<bool> isChecekd(10, false);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int tmp;
			cin >> tmp;
			a[i].push_back(tmp);
		}
	}

		for (int g = 0; g < 5; ++g)
		{
			for (int s = 0; s < n-1; ++s)
			{
				
					for (int ts = s + 1; ts < n; ++ts)
					{
						if (a[s][g] == a[ts][g])
						{
							cf[s][ts] = true;
							cf[ts][s] = true;
							isChecekd[a[s][g]] = true;
						}
					}
							
				
			}
			fill(isChecekd.begin(), isChecekd.end(), false);
		}
	
	vector<int> c(n, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int s = 0; s < n; ++s)
		{
			if (cf[i][s])
			{
				c[i]++;
			}
		}
	}

	vector<pair<int, int>> cs;
	for (int s = 0;s < n;++s)
	{
		cs.push_back(make_pair(c[s], s + 1));
	}

	sort(cs.begin(), cs.end(), compare);
	cout << cs.front().second;




	return 0;
}
