#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> graph;
bool visited[100001] = {};
int ans[100001] = {};
int cnt = 0;

void dfs(int r) {
	visited[r] = true;;
	cnt++;
	ans[r] = cnt;

	for (int i = 0; i < graph[r].size(); i++) 
	{
		if (visited[graph[r][i]] == false)
		{
			dfs(graph[r][i]);
		}
	}

}

int main() {
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i <= n; i++)
	{
		vector<int> v;
		graph.push_back(v);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < graph.size(); i++)
	{
		sort(graph[i].begin(), graph[i].end(), greater<>());
	}

	dfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}