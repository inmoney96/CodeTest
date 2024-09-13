#include <iostream>

using namespace std;

int main() {
	int T, N, M;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> N >> M;
		int noc = 1;

		for (int k = 0; k < N; ++k)
		{
			noc *= M - k;
			noc /= 1 + k;
		}
		cout << noc << endl;
	}

	return 0;
}