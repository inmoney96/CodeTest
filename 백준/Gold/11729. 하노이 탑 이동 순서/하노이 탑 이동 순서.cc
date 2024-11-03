#include <stdio.h>
#include <vector>

using namespace std;

vector<pair<int, int>> mov;

void hanoi(int n, int from, int temp, int to) {
	if (n == 1)
	{
		mov.push_back({ from, to });
		return;
	}
	hanoi(n - 1, from, to, temp);
	mov.push_back({ from, to });
	hanoi(n - 1, temp, from, to);

	return;
}

int main() {
	int n = 0;
	scanf("%d", &n);

	hanoi(n,1,2,3);

	printf("%d\n", mov.size());
	for (int i = 0; i < mov.size(); i++)
	{
		printf("%d %d\n", mov[i].first, mov[i].second);
	}

	return 0;
}