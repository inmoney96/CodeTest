#include "stdio.h"
#include <algorithm>

int a[51];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0;i < n;++i)
	{
		scanf("%d", a+i);
	}
	std::sort(a, a+n);
	printf("%d", a[0] * a[n - 1]);

	return 0;
}