#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i : scoville)
    {
        pq.push(i);
    }
     
    while (pq.top() < K)
    {
        if(pq.size()<=1)return -1;
        int amaiest = pq.top();
        pq.pop();
        int amai = pq.top();
        pq.pop();
        int mix = amaiest + amai * 2;
        pq.push(mix);
        answer++;
           
    }

    return answer;
}

