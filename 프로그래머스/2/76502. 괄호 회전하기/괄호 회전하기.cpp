#include <string>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

bool isCorrectParen(string s) {
	stack<char> st;

    for (int i = 0;i < s.size();++i)
    {
		if (!st.empty())
		{
			if (st.top() == '(' && s[i] == ')')
			{
				st.pop();
			}
			else if (st.top() == '[' && s[i] == ']')
			{
				st.pop();
			}
			else if (st.top() == '{' && s[i] == '}')
			{
				st.pop();
			}
			else
			{
				st.push(s[i]);
			}
		}
		else
		{
			st.push(s[i]);
		}
    }

	if (!st.empty()) {
		return false;
	}
	else
	{
		return true;
	}
}

int solution(string s) {
    int answer = 0;

	deque<char> dq;
	for (int i = 0; i < s.size(); ++i) {
		dq.push_back(s[i]);
	}
	
	for (int i = 0; i < s.size(); ++i) {
		if (isCorrectParen(string(dq.begin(), dq.end()))) {
			answer++;
		}
		char front = dq.front();
		dq.pop_front();
		dq.push_back(front);
	}

    return answer;
}