#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    char tmp = ' ';
    bool isFirst = true;
    for (int i = 0; i < s.size(); ++i)
    {

        if (97 <= s[i] && s[i] <= 122 && isFirst)
        {
            tmp = s[i] - 32;
        }
        else if (65 <= s[i] && s[i] <= 90 && !isFirst)
        {
            tmp = s[i] + 32;
        } else
        {
            tmp = s[i];
        }

        answer.push_back(tmp);

        isFirst = false;

        if (s[i] == ' ')
        {
            isFirst = true;
        }

    }

    return answer;
}