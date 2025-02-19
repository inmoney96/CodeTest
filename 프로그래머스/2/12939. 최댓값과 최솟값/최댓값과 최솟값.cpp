#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string t;
    vector<int> a;
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] != ' ')
        {
            t += s[i];
        }
        else
        {
            a.push_back(stoi(t));
            t.clear();
        }
    }
    a.push_back(stoi(t));
    t.clear();

    sort(a.begin(), a.end());
    t = to_string(a.front()) + " " + to_string(a.back());
    return t;
}