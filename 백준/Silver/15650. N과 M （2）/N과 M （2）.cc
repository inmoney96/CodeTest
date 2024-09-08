#include <iostream>
#include <vector>
using namespace std;

int arr[8];

void fn(int N, int M, int d,int x) {
	
	if (d == M) {
		for (int k = 0; k < M; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
		return;
	}

	for (x; x <= N; x++) {
		arr[d] = x;
		fn(N,M,d+1,x+1);
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	fn(N, M, 0, 1);
    return 0;
}