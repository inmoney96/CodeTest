#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isPword(const string& s, int l, int r) {

		while (l <= r)
		{
			if (s[l] == s[r])
			{
				l++, r--;
			}
			else
			{
				return false;
			}
		}
		return true;
}

int main() {
	int n = 0;
	cin >> n;
	vector<string> words;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		int isP = 0;
		int l = 0, r = words[i].size() - 1;
		string tmp = words[i];

		while (l <= r)
		{
			if (tmp[l] == tmp[r])
			{
				l++, r--;
			}
			else
			{
				if (isPword(tmp, l + 1, r) || isPword(tmp, l, r - 1)) {
					isP = 1;
				}
				else {
					isP = 2;
				}
				break;
			}
		}
		cout << isP << "\n";
	}

	return 0;
}