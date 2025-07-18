#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    for (int i = 1; i < land.size();++i)
    {
        for (int j = 0;j < 4;++j)
        {
            int temp = -1;
            for (int k = 0;k < 4;++k)
            {
                if (j == k) continue;

                temp = max(temp, land[i][j] + land[i - 1][k]);
            }
            land[i][j] = temp;
        }
    }


    int ans = -1;
    for (int j = 0;j < 4;++j)
    {
        ans = max(ans, land[land.size() - 1][j]);
    }
    return ans;
}