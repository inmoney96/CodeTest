#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool bIsVisited[1001];

void dfs(const vector<vector<int>>& g, int s)
{
	bIsVisited[s] = true;
	cout << s << " ";
	for (int i = 0; i < g[s].size(); i++)
	{
		if (false == bIsVisited[g[s][i]])
		{
			dfs(g, g[s][i]);
		}
		
	}

}

void bfs(const vector<vector<int>>& g, int s)
{
	queue<int> q;
	bIsVisited[s] = true;
	q.push(s);
	while (false == q.empty())
	{
		int cur = q.front();
		cout << cur << " ";
		q.pop();
		
		for (int i = 0; i < g[cur].size(); i++)
		{
			int next = g[cur][i];
			if (false == bIsVisited[next])
			{
				bIsVisited[next] = true;
				q.push(next);
			}
		}
	}

}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	vector<vector<int>> g(1001, vector<int>());



	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		sort(g[i].begin(), g[i].end());
	}

	dfs(g,v);
	cout << endl;
	for (int i = 0; i < 1001; i++)
	{
		bIsVisited[i] = false;
	}
	bfs(g, v);

	return 0;
}