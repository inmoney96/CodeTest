#include "iostream"
using namespace std;

int main() {

	int n; cin >> n;
	long long g = 0;
	for (int i = 1; i <= n; i++) {
		g += (n / i)*i;	
	}
	cout << g;



	return 0;
}