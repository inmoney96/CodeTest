#include <string>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<int, vector<int>> tmp;
    //ext val_ext
    //data를 탐색하면서 ext가 val_ext 보다 작은 값만 answer에 삽입
    //sort_by에 따라 정렬해야 하고 sort_by는 중복되지 않으니 map 활용

    //sort_by 변수화
    int sort=0;
    if (sort_by == "code")
    {
        sort = 0;
    }
    else if (sort_by == "date")
    {
        sort = 1;
    }
    else if (sort_by == "maximum")
    {
        sort = 2;
    }
    else if (sort_by == "remain")
    {
        sort = 3;
    }

    // ext 변수화
    int filter=0;
    if (ext == "code")
    {
        filter = 0;
    }
    else if (ext == "date")
    {
        filter = 1;
    }
    else if (ext == "maximum")
    {
        filter = 2;
    }
    else if (ext == "remain")
    {
        filter = 3;
    }

        // val_ext보다 작은 것만 삽입
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i][filter] < val_ext)
        {
            tmp.insert(make_pair(data[i][sort], data[i]));
        }
    }

    for (auto iter = tmp.begin(); iter != tmp.end(); ++iter)
    {
        answer.push_back(iter->second);
    }
   

    return answer;
}
