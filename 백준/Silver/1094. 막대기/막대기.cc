#include <iostream>

using namespace std;

int main() {
	int len = 64, ea = 1, want, keep = 0;
	cin >> want;

	while (true)
	{
		if (len+keep == want) break;
		//자른다
		len /= 2;
		//맞으면 끝
		//작으면 반 버리고 반복
		//크면 반 놔두고 (ea++) 반복
		if (len+keep < want)
		{
			keep += len;
			ea++;
		}	}

	cout << ea;

	return 0;
}