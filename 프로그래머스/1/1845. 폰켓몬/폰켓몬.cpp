#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int take = nums.size()/2;
    set<int> po;
    for(int i=0;i<nums.size();i++)
    {
        po.insert(nums[i]);
    }
    
    if(po.size()>=take)
    {
        return take;
    }else
    {
        return po.size();
    }
}