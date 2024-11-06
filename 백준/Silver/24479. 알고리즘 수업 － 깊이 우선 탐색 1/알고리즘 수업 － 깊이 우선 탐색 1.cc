#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100001] = {};
int ans[100001];
int cnt = 0;

void dfs(const vector<vector<int>> &graph, int r) {
	visited[r] = true;
	cnt++;
	ans[r] = cnt;
	for (int i = 0; i < graph[r].size(); i++)
	{
		if (visited[graph[r][i]] == false)
		{
			dfs(graph, graph[r][i]);
		}
	}
}

int main() {
	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> graph(n+1, vector<int>());
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

    for(int i=0;i<graph.size();i++)
        {
            sort(graph[i].begin(), graph[i].end());
        }
	
	dfs(graph, r);

	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}