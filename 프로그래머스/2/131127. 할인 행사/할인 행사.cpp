#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> list;

    for (int i = 0;i < want.size();++i)
    {
        list.insert(make_pair(want[i], number[i]));
    }

    int answer = 0;

    for (int j = 0; j < 10; ++j)
    {
        auto it = list.find(discount[j]);
        if (it != list.end())
        {
            it->second--;
        }
    }

    for (int i = 0; i < discount.size() - 10;++i)
    {        
        auto it = list.begin();
        bool canSave = true;
        while (it != list.end())
        {
            if (it->second > 0)
            {
                canSave = false;
                break;
            }
            it++;
        }
        if (canSave)
        {
            answer++;
        }

        it = list.find(discount[i]);
        if (it != list.end())
        {
            it->second++;
        }
        it = list.find(discount[i+10]);
        if (it != list.end())
        {
            it->second--;
        }
    }

    auto it = list.begin();
    bool canSave = true;
    while (it != list.end())
    {
        if (it->second > 0)
        {
            canSave = false;
            break;
        }
        it++;
    }
    if (canSave)
    {
        answer++;
    }

    return answer;
}