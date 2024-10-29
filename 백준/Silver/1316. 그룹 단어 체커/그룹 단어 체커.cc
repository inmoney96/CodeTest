#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	int n = 0;
	cin >> n;
	int ans = n;
	vector<char> group;
	for (int i = 0; i < n; i++)
	{
		string s = {};
		cin >> s;
		bool isNotGroup = false;
		group.clear();
		for (int k = 0; k < s.size(); k++)
		{
			
			if (!group.empty())
			{
				for (int j = 0; j < group.size(); j++)
				{
					if (s[k] == group[j])
					{
						ans--;
						isNotGroup = true;
						break;
					}
				}
			}
			if (isNotGroup)
			{
				isNotGroup = false;
				break;
			}
			if (s[k] != s[k + 1])
			{
				group.push_back(s[k]);
			}
					
		}
	}

	cout << ans;
	return 0;
}