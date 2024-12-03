#include "iostream"
#include "vector"
#include "queue"
using namespace std;

#define MAX 105

bool visited[MAX];

int find_infected(int start, vector<vector<int>>& graph) {
	int num = 0;
	queue<int> q;
	q.push(start);
	visited[start]= true;

	while (!q.empty())
	{
		int cn = q.front();
		q.pop();
		num++;
		
		for (int i = 0; i < graph[cn].size(); i++)
		{
			if (!visited[graph[cn][i]])
			{
				q.push(graph[cn][i]);
				visited[graph[cn][i]] = true;
			}
		}
	}

	num--;
	return num;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph(n+1, vector<int>());
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << find_infected(1,graph);
	return 0;
}