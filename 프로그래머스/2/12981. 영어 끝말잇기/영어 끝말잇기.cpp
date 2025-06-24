#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> p(n+1, 0);
    int pt = 0;
    int t = -1;
    bool isBreak = false;
    while (true)
    {
        t++;
        if (t >= words.size())
            break;
        pt++;
        p[pt]++;
        if (t!=0)
        {
            if (words[t][0] != words[t - 1][words[t - 1].size() - 1])
            {
                isBreak = true;
                break;
            }
            for (int i = 0;i < t;i++)
            {
                if (words[i] == words[t])
                {
                    isBreak = true;
                    break;
                }
                    
            }

            if (isBreak)
                break;
        }
        if (pt == n)
            pt = 0;

    }

    vector<int> ans;
    if (!isBreak)
    {
        ans.push_back(0);
        ans.push_back(0);
        return ans;
    }

    ans.push_back(pt);
    ans.push_back(p[pt]);
    return ans;
}

int main()
{
    solution(3, {"abc", "cbd", "ddd", "ddd", "dbc", "cbd" });
    return 0;
}