#include "stdio.h"
#include <set>
using namespace std;

int main() {
	int N,M, tmp;
	set<int> arrn;
	int arrm[100001];

	scanf("%d", &N);

	for (int i=0; i < N; i++) {
		scanf("%d", &tmp);
		arrn.insert(tmp);
	}

	scanf("%d", &M);

	for (int i=0; i < M; i++) {
		scanf("%d",&arrm[i]);
		if (arrn.end() != arrn.find(arrm[i])) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

	return 0;
}