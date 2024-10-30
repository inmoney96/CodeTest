#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < n; i++)
	{
		cout << nums[i] <<"\n";
	}

	return 0;
}