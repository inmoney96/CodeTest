#include <iostream>

int main() {
	int n; std::cin >> n;
	int ans = 0;
	for (int i = 1; i <= n;)
	{
		ans += n-i+1;
		i *= 10;
	}

	std::cout << ans;
	return 0;
}