#include <vector>
#include <queue>
using namespace std;
// 동서남북 탐색
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(vector<vector<int>>& maps, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    int curx, cury, runs = 1, runsbuffer = 1;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    while (!q.empty()) {
        pair<int, int> curpos = q.front();
        curx = curpos.second;
        cury = curpos.first;
        q.pop();

        // 목표 지점에 도착한 경우
        if (curx == m - 1 && cury == n - 1) {
            return runs;
        }

        // 동서남북 탐색
        for (int i = 0; i < 4; ++i) {
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && maps[newy][newx] == 1 && !visited[newy][newx]) {
                q.push(make_pair(newy, newx));
                visited[newy][newx] = true;
            }
        }

        // 이동 횟수
        --runsbuffer;
        if (runsbuffer == 0) {
            runsbuffer = q.size();
            ++runs;
        }
    }

    return -1; 
}

int solution(vector<vector<int>> maps) {
    //bfs 사용
    //2 <= n*m <= 10000
    // 1,1 / n,m
    int n = maps.size();
    int m = maps[0].size();
    return bfs(maps, n, m);
}
