#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string solution(string s) {
    vector<int> nums;

    string tmp;
    for (int i = 0;i < s.size();i++)
    {
        if(s[i] != ' ')
        {
            tmp = tmp + s[i];
        }
        else
        {
            int tmpnum = stoi(tmp);
            nums.push_back(tmpnum);
            tmp.clear();
        }
    }
    int tmpnum = stoi(tmp);
    nums.push_back(tmpnum);
    sort(nums.begin(), nums.end());

    return to_string(nums.front()) + " " + to_string(nums.back());
}