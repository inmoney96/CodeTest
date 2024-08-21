#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    //arr idx 돌며 divisor로 나눈 값을 벡터에 넣고 sort
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] % divisor == 0)
        {
            answer.push_back(arr[i]);
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }


    return answer;
}