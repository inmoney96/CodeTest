#include "stdio.h"
#include <queue>
struct tomato {
	int y, x;
};

int n, m, result = 0;
int graph[1001][1001];
std::queue<tomato> s;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool isInside(int y, int x) {
	if (y >= 0 && x >= 0 && y < n && x < m) {
		return true;
	}
	else {
		return false;
	}
}

void bfs() {

	while (!s.empty())
	{
		int y = s.front().y;
		int x = s.front().x;
		s.pop();

		//탐색
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (isInside(ny, nx) && graph[ny][nx] == 0)
			{
				graph[ny][nx] = graph[y][x] + 1;
				s.push({ ny,nx });
			}
		}

	}
}

int main() {
	scanf("%d %d", &m, &n);

	//토마토상자 정의
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			scanf("%d", &graph[i][k]);
			if (graph[i][k] == 1) //익은토마토면
			{
				s.push({ i,k });
			}
		}
	}

	bfs();

	//익은 토마토 확인
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (graph[i][k] == 0) //안 익은 토마토 있으면 -1 출력 후 종료
			{
				printf("-1\n");
				return 0;
			}
			else
			{
				if (graph[i][k] > result)
				{
					result = graph[i][k];
				}
			}
		}
	}

	printf("%d", result - 1);
	return 0;
}