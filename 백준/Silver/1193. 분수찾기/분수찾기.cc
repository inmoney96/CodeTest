#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int dir = -1;
	int u=0, d=0;

	int i = 0, line = 0, num;
	cin >> num;
	
	while (num > i)
	{
		++line;
		i += line;
		dir *= -1;
	}

	int x = i - num;

	if (dir == -1)
	{
		u = line - x;
		d = 1 + x;

	}
	else
	{
		u = 1 + x;
		d = line - x;
	}
	cout << u << '/' << d;

}
