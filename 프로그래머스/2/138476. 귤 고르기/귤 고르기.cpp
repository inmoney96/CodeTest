#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int tangerineNum[10000001] = {};

int solution(int k, vector<int> tangerine) {
    for (int i = 0;i < tangerine.size(); i++)
    {
        tangerineNum[tangerine[i]]++;
    }

    sort(tangerineNum, tangerineNum+10000001,greater<int>());

    int answer = 0;
    int tangerineSum = 0;
    while (k > tangerineSum)
    {
        tangerineSum += tangerineNum[answer];
        answer++;
    }
    return answer;
}