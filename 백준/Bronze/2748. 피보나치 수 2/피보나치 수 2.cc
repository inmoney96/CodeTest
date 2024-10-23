#include <stdio.h>

long long fibo[92] = {0,1,1,2,};

int main() {
	int n = 0;
	scanf("%d", &n);

	if (n == 0)
	{
		printf("0\n");
	}
	else if (n == 1)
	{
		printf("1\n");
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			fibo[i] = fibo[i - 1] + fibo[i - 2];
		}
        printf("%lld\n", fibo[n]);
	}

	return 0;
}