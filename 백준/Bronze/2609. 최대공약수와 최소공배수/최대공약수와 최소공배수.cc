#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	int a = min(n, m);
	int b = max(n, m);
	long long int c = 2;
	vector<int> divisor;
	while (c <= a)
	{
		if (a % c == 0 && b % c == 0)
		{
			a = a / c;
			b = b / c;
			divisor.push_back(c);
			c = 2;
		}
		else
		{
			c++;
		}
	}
	if (divisor.empty())
	{
		cout << 1 <<endl;
		cout << a * b;
		return 0;
	}
	else
	{
		c = 1;
		for (int i = 0;i < divisor.size();i++)
		{
			c = c * divisor[i];
		}
		cout << c <<endl;
		cout << c * a * b;
		return 0;
	}


}