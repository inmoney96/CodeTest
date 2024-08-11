#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmpVec;
    int start, end, cut;
    //commands 나누기
    for (int i = 0; i < commands.size(); ++i)
    {
        start = commands[i][0]-1;
        end = commands[i][1];
        cut = commands[i][2]-1;
        
        for (int k = start; k < end; ++k)
        {
            tmpVec.push_back(array[k]);
        }

        sort(tmpVec.begin(),tmpVec.end());

        answer.push_back(tmpVec[cut]);
        tmpVec.clear();

    }

    return answer;
}