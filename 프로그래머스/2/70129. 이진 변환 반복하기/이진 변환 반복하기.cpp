#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> tmp;
    int tmplen = 0;
    int zero = 0;
    int changeTime = 0;

    while (s.size() > 1) {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
            {
                tmp.push_back(1);
            }
            else
            {
                ++zero;
            }
        }
        tmplen = tmp.size();
        ++changeTime;

        s.clear();
        tmp.clear();
        while (tmplen > 0)
        {
            s.insert(0, to_string(tmplen % 2));
            tmplen /= 2;
        }
    }

    answer.push_back(changeTime);
    answer.push_back(zero);

    return answer;
}