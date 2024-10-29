#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int total=0, s3=0, s5 = 0;

	while (s5 * 5 < n)
	{
		s5++;
	}

	while (n != (s5 * 5) + (s3 * 3))
	{
		s5--;
		s3 = 0;

		while ((s5 * 5) + (s3*3) < n) s3++;

		if (s5 < 0)
		{
			cout << -1;
			return 0;
		}
	}

	cout << s3 + s5;

	return 0;
}