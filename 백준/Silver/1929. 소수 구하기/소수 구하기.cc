#include <iostream>
using namespace std;

int a[1000001] = { 0,1 };

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 2; i <= m; i++)
	{
		for (int j = 2; i * j <= m; j++)
		{
			a[i * j] = 1;
		}
	}

	for (int i = n; i <= m; i++)
		if (!a[i]) cout << i << '\n';


	return 0;
}