#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool isVisited[8];

void dfs(const vector<vector<int>> &dungeon, int d, int e){
    if (d > answer)
        answer = d;

    for (int i = 0; i < dungeon.size(); i++)
    {
        if (!isVisited[i] && dungeon[i][0] <= e)
        {
            isVisited[i] = true;
            dfs(dungeon, d + 1, e - dungeon[i][1]);
            isVisited[i] = false;
        }
    }

}

int solution(int k, vector<vector<int>> dungeons) {

    dfs(dungeons, 0, k);

    return answer;
}