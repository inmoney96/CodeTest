#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    //clothes[i][] i 별 항목+1(안입은경우) 를 모두 곱하고 -1(아무것도 안입음)

    //map에 키 [i][1], 값 1 추가, 이미 있으면 값 ++
    map<string, int> cmap;
    for (int i = 0; i < clothes.size(); ++i)
    {
        if (cmap.find(clothes[i][1]) == cmap.end())
        {
            cmap.insert({ clothes[i][1], 2});
        }
        else
        {
            cmap.find(clothes[i][1])->second++;
        }
    }

    int answer = 1;

    for (auto iter:cmap)
    {
        answer *= iter.second;
    }

    return answer-1;
}
