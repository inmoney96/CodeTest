#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.push_back(numbers[0] + numbers[1]);

    for (int i = 0; i < numbers.size()-1; ++i)
    {
        for (int k = i + 1; k < numbers.size(); ++k)
        {
            if (find(answer.begin(), answer.end(), numbers[i] + numbers[k]) == answer.end()) {
                answer.push_back(numbers[i] + numbers[k]);
            }
                
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}