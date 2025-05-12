#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T[12] {};

int main() {
	T[1] = 1;
	T[2] = 2; 
	T[3] = 4; 
	T[4] = 7;

	for (int i = 5;i <= 11;i++)
	{
		T[i] = T[i - 1] + T[i - 2] + T[i - 3];
	}
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << T[n] << endl;
	}
	return 0;
}