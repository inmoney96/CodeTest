#include <iostream>
#include <algorithm>
using namespace std;
int d[9];
int main() {

	for (int i = 0;i < 9;++i)
	{
		cin >> d[i];
	}
	sort(d, d + 9);

	int ff = 8, f = 7;
	int add = 0;
	while (true)
	{
		add = 0;
		for (int i = 0;i < 9;i++)
		{
			if (i == f || i == ff)
				continue;
			add += d[i];
		}
		if (add == 100)
			break;
		f--;
		if (f == 0)
		{
			ff--;
			f = ff - 1;
		}
	}
	for (int i = 0;i < 9;i++)
	{
		if (i == f || i == ff)
			continue;
		cout << d[i] << endl;
	}
}