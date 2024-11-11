#include <iostream>
#include <string>
using namespace std;

char s [105];

int main() {
	cin >> s;

	int a=0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		switch (s[i])
		{
		case 'c':
		{
			if (s[i + 1] == '=' || s[i + 1] == '-')
			{
				i++;
			}
			break;
		}
		case 'd':
			if (s[i + 1] == '-')
			{
				i++;
			}
			else if (s[i + 1] == 'z' && s[i + 2] == '=')
			{
				i += 2;
			}
			break;
		case 'l':
			if (s[i + 1] == 'j')
			{
				i++;
			}
			break;
		case 'n':
			if (s[i + 1] == 'j')
			{
				i++;
			}
			break;
		case 's':
			if (s[i + 1] == '=')
			{
				i++;
			}
			break;
		case 'z':
			if (s[i + 1] == '=')
			{
				i++;
			}
			break;

		default:
			break;
		}
		a++;
	}

	cout << a;

	return 0;
}