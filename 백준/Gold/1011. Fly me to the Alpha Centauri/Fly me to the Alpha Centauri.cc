#include <iostream>
#include <vector>
using namespace std;

int warp(long long x, long long y) {
	long long max = 0;

	while (max * max <= y - x)
	{
		max++;
	}
	max--;
	long long rem = y - x - (max * max);
	int move = 2*max -1 + rem / max;
	if (rem % max)
	{
		move++;
	}
	return move;
}

int main() {
	vector<int> answer;
	long long t, x, y;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> x >> y;
		answer.push_back(warp(x, y));
	}

	for (int i = 0; i < t; ++i)
	{
		cout << answer[i] << endl;
	}
		
}
