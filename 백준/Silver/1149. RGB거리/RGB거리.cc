#include "iostream"
#include "algorithm"
using namespace std;

int r[1001];
int g[1001];
int b[1001];

int price[3] = { 0,0,0 };
int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> r[i] >> g[i] >> b[i];
	}

	price[0] = r[0];
	price[1] = g[0];
	price[2] = b[0];

	for (int i = 1; i < N; ++i)
	{
		int tr = min(price[1], price[2]) + r[i];
		int tg = min(price[0], price[2]) + g[i];
		int tb = min(price[0], price[1]) + b[i];

		price[0] = tr;
		price[1] = tg;
		price[2] = tb;
	}

	std::cout << min({price[0], price[1], price[2]});

	return 0;
}