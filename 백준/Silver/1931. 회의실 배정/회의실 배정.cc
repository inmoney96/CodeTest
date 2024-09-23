#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
	int n;
	vector<pair<int,int>> c;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int s, e;
		cin >> s >> e;
		c.push_back(make_pair(e, s));
	}
	sort(c.begin(), c.end());
	
	int answer = 0;
	int last = 0;
	for (int i = 0; i < c.size(); ++i)
	{
		if (c[i].second >= last)
		{
			answer++;
			last = c[i].first;
		}
	}
	cout << answer;

	return 0;
}