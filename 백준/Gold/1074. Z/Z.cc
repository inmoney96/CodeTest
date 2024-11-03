#include <stdio.h>
#include <math.h>

using namespace std;

int n = 0, r = 0, c = 0;
int idx = 0;

void zSearch(int y, int x, int size) {
	if (y == r && x == c)
	{
		printf("%d", idx);
		return;
	}

	if (r < y + size && c < x + size && r >= y && c >= x)
	{
		int h = size / 2;
		zSearch(y, x, h);
		zSearch(y, x + h, h);
		zSearch(y + h, x, h);
		zSearch(y + h, x + h, h);
	}
	else
	{
		idx += size * size;
	}
	

	return;
}

int main() {

	scanf("%d %d %d", &n,&r,&c);

	zSearch(0,0,pow(2,n));


	return 0;
}