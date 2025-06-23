#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    vector<int> nums;
    string tmp;
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] != ' ')
        {
            tmp += s[i];
        }
        else
        {
            nums.push_back(stoi(tmp));
            tmp.clear();
        }
    }
    nums.push_back(stoi(tmp));

    sort(nums.begin(), nums.end());

    string a = to_string(nums.front());
    string b = to_string(nums.back());
    string answer = a +" " + b;
    return answer;
}


int main() {
    solution("1 2 3 4");
    return 0;
}
