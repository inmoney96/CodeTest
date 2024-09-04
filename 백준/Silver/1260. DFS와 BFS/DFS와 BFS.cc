#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[10001];
vector<int> node;
bool visited_dfs[1001];
bool visited_bfs[1001];

void dfs(int x) {

	printf("%d ", x);
	visited_dfs[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited_dfs[y]) {
			dfs(y);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited_bfs[x] = true;

	while (!q.empty()) {
		int dx = q.front();
		printf("%d ", dx);
		q.pop();

		for (int i = 0; i < graph[dx].size(); i++) {
			int dy = graph[dx][i];
			if (!visited_bfs[dy]) {
				visited_bfs[dy] = true;
				q.push(dy);
			}
		}
	}
}

int main() {
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	//for (int i = 0; i <= N; i++) {
	//	graph.push_back(node);
	//}

	for (int i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(),graph[i].end());
	}
	dfs(V);
	printf("\n");
	bfs(V);

	return 0;
}