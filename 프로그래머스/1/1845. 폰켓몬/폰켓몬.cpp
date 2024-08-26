#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i)
    {
        map.insert({ nums[i], 1 });
    }
    if (map.size() > (nums.size() / 2))
    {
        return nums.size() / 2;
    }
    else
    {
        return map.size();
    }
}