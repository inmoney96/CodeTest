#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 51;

int arr[MAX][MAX] = {};
bool visited[MAX][MAX] = {};
int t, m, n, k;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool isIn(int y, int x) {
	if (y >= 0 && x >= 0 && y < n && x < m) return true;
	else return false;
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (isIn(ny, nx) && !visited[ny][nx] && arr[ny][nx] == 1)
			{
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}

}

int main() {
	vector<int> ans;
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && !visited[i][j])
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		ans.push_back(cnt);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		
		cnt = 0;
	}

	for (int i=0;i<ans.size();i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}