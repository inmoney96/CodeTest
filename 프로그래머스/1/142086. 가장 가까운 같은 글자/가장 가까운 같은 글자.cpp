#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> lastPop;

    for (int i = 97; i <= 122; ++i)
    {
        lastPop.insert(make_pair(i, -1));
    }

    for (int i = 0; i < s.size(); ++i)
    {
        if (lastPop.find(s[i])->second == -1) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(i - lastPop.find(s[i])->second);
        }
        
        
        lastPop.find(s[i])->second = i;
        
       

    }

    return answer;
}