#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	queue<int> deck;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		deck.push(i);
	}
	while (deck.size() != 1) {
		deck.pop();
		deck.push(deck.front());
		deck.pop();
	}

	printf("%d", deck.front());
	return 0;
}