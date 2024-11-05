#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans = 0;
int main() {
	int n, l;

	cin >> n >> l;
	vector<pair<int, int>> pud;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		pud.push_back({ a,b });
	}

	sort(pud.begin(), pud.end());
	int placed = 0;

	for (int i = 0; i < n; i++)
	{
		while (placed < pud[i].second)
		{
			if (placed < pud[i].first)
			{
				placed = pud[i].first + l;
				ans++;
			}
			if (placed < pud[i].second)
			{
				int multiPlace = (pud[i].second - placed) / l;
				placed += multiPlace*l;
				ans += multiPlace;
				if (placed < pud[i].second)
				{
					placed += l;
					ans++;
				}
			}
		}
		

	}

	cout << ans;
	return 0;
}
