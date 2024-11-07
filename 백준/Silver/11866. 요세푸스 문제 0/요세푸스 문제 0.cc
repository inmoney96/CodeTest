#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> c;
	for (int i = 1; i <= n; i++)
	{
		c.push_back(i);
	}
	int idx = 0;

	printf("<");
	while (n--)
	{
		idx += k - 1;
		while (idx >= c.size())
		{
			idx = idx - c.size();
		}
		printf("%d", c[idx]);
		c.erase(c.begin()+idx);
		if (!c.empty())
		{
			printf(", ");
		}
	}
	printf(">");

	return 0;
}