#include <string>
#include <vector>
#include <queue>

using namespace std;
// 1<=n<=200
int visited[201]={};
//연결이 0개일 때 네트워크는 n개
//visited 로 체크하면서 지나온 수 x만큼 네트워크 n-x개

void bfs(int start, int n, vector<vector<int>> computers){
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        visited[q.front()] = 1;
        int now = q.front(); 
        q.pop();
        
        for(int i = 0 ; i < n ; i++)
        {
            if(computers[now][i] ==1 && !visited[i])
            {
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
        bfs(i, n, computers);
        answer++;
        }
    }
        
    return answer;
}