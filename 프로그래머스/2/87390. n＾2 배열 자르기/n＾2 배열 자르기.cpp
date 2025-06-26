#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    long long x = 1;
	long long start = -1;
	bool isRight = false;

	for (long long i = 0; i < n; i++) {
		for (long long j = 1; j <= n; j++) {
			start++;
			if (start < left)
				continue;
			if (start > right)
			{
				isRight = true;
				break;
			}

			if (j < x)
			{
				answer.push_back(x);
			}
			else
			{
				answer.push_back(j);
			}
		}
		if (isRight)
		{
			break;
		}
		x++;
	}

	return answer;
}