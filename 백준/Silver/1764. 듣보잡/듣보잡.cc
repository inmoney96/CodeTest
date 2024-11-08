#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v1;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v1.push_back(tmp);
	}
	sort(v1.begin(), v1.end());
	vector<string> v2;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (binary_search(v1.begin(), v1.end(), tmp))
		{
			v2.push_back(tmp);
		}
	}
	sort(v2.begin(), v2.end());
	cout << v2.size() << "\n";
	for (auto i : v2)
	{
		cout << i << "\n";
	}

	return 0;
}