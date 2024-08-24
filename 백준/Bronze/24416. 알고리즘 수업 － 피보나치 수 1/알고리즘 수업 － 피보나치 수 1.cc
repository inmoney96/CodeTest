#include <iostream>

using namespace std;

int code1 = 0;
int code2 = 0;

int f[41]{0,1};


int fib(int n) {
	if (n == 1 || n == 2)
	{
		++code1;
		return 1;
	}
	else
	{
		return(fib(n - 2) + fib(n - 1));
	}
}

int fibonacci(int n) {
	for (int i = 2; i < n; ++i)
	{
		f[i] = f[i - 2] + f[i - 1];
		++code2;
	}
		return f[n];
}

int main() {
	int n;
	cin >> n;

	fib(n);
	fibonacci(n);

	cout << code1 << " " << code2;
	return 0;
}