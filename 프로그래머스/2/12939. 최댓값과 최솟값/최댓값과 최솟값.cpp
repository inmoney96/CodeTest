#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string tmp = "";
    int min = 0, max = 0;
    int a = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        tmp.push_back(s[i]);
        if (s[i] == ' ')
        {
            a = stoi(tmp);
            tmp.clear();
            min = a;
            max = a;
            break;
        }
    }

    for (int i = 0; i < s.size(); ++i)
    {
        tmp.push_back(s[i]);
        if (s[i] == ' ')
        {
            a = stoi(tmp);
            tmp.clear();
            if (a < min) {
                min = a;
            }
            if (a > max) {
                max = a;
            }
        }
    }

    a = stoi(tmp);
    if (a < min) {
        min = a;
    }
    if (a > max) {
        max = a;
    }
    tmp.clear();
    tmp += to_string(min);
    tmp += " ";
    tmp += to_string(max);
    return tmp;

}