#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),-1);
    stack<int> s;

    for (int i = numbers.size() - 1;i >= 0;i--)
    {
        while (!s.empty())
        {
            if (numbers[i] < s.top())
            {
                answer[i] = s.top();
                break;
            }
            else {
                s.pop();
            }
        }
        s.push(numbers[i]);
        
    }
    

    return answer;
}
