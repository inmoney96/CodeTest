#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N, M;
int graph[101][101];
bool isOutGraph(int nx, int ny) {
	if (nx > N || ny > M || nx < 0 || ny < 0) {
		return true;
	}
	else {
		return false;
	}
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isOutGraph(ny, nx)) continue;

			if (graph[ny][nx] == 1)
			{
				q.push(make_pair(ny, nx));
				graph[ny][nx] = graph[y][x] + 1;
			}
		}
	}
	return graph[N - 1][M - 1];
}

int main() {
	cin >> N >> M;
	//붙어서 주어지므로 M개의 입력을 받고 N개로 쪼개야 함
	for (int i = 0; i < N; ++i)
	{
		string tmp;
		cin >> tmp;

		for (int k = 0; k < M; ++k)
		{
			graph[i][k] = tmp[k] -'0';
		}
	}

	cout << bfs();

	return 0;
}