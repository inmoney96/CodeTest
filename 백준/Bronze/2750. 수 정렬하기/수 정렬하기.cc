#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> a;
	int n;
	int tmp;

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}

	sort(a.begin(), a.end());

	for (const int& i : a)
	{
		cout << i << endl;
	}

	return 0;
}