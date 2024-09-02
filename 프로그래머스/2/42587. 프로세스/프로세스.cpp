#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	//priorities의 max값 저장
	queue<int> q;
	priority_queue<int> pq;

	for (int i = 0; i < priorities.size(); ++i)
	{
		q.push(priorities[i]);
		pq.push(priorities[i]);
	}

	int answer = 1;

	while (1)
	{
		if (q.front() == pq.top() && location == 0)
		{
			return answer;
		}
		else if (q.front() == pq.top()) 
		{
			q.pop();
			pq.pop();
			++answer;
		}
		else
		{
			q.push(q.front());
			q.pop();
		}

		if (location == 0) {
			location = q.size() -1;
		}
		else
		{
			--location;
		}
	}
}