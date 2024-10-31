#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

int dist[1000001] = {};
bool isKExist = false;

void dijkstra(int start, int n, const vector<vector<pair<int, int>>>& graph) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    priority_queue<pair<int, int>> pq;
    dist[start] = 0; // 시작 노드의 거리는 0
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if (cur_dist > dist[cur_node]) {
            continue;
        }

        for (int i = 0; i < graph[cur_node].size(); i++) {
            int nxt_node = graph[cur_node][i].first;
            int nxt_dist = cur_dist + graph[cur_node][i].second;

            if (nxt_dist < dist[nxt_node]) {
                dist[nxt_node] = nxt_dist;
                pq.push({ -nxt_dist, nxt_node });
            }
        }
    }
}

int main() {
    int n = 0, m = 0, k = 0, x = 0;
    scanf("%d %d %d %d", &n, &m, &k, &x);
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back({ b, 1 }); // 모든 거리는 1
    }

    dijkstra(x, n, graph);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            printf("%d\n", i);
            isKExist = true;
        }
    }

    if (!isKExist) {
        printf("-1");
    }

    return 0;
}
