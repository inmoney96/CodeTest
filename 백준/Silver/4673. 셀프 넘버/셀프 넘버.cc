#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isNotSelf[10001]{};

int main() {
	int n = 1;
	string s;

	int t;
	while (n < 10000)
	{
		if (!isNotSelf[n])
		{
			t = n;
			while (t < 10000)
			{

				s = to_string(t);
				for (int i = 0;i < s.size();i++)
				{
					t += s[i] - '0';
				}
				isNotSelf[t] = true;

				s.clear();
			}
		}
		n++;
	}

	for (int i = 1;i < 10001;i++)
	{
		if (!isNotSelf[i])
		{
			cout << i << endl;
		}
	}



	return 0;
}