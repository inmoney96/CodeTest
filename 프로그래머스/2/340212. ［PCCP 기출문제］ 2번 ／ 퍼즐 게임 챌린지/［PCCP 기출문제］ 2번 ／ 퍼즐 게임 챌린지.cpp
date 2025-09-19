#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int level = 0;

    for (int i : diffs)
    {
        level = level > i ? level : i;
    }

    int min = 1;
    int max = level;
    int prevlevel = 0;
    while (true)
    {
        long long record = 0;

        for (int i = 0; i < diffs.size(); i++)
        {
            if (level < diffs[i])
            {
                record += (times[i - 1]+times[i]) * (diffs[i] - level);
            }
            record += times[i];
        }

        if (record == limit)
            return level;

        if (record < limit)
        {
            max = level;
        }
        else
        {
            if (level + 1 == max)
                return max;
            min = level;
        }
        level = (min + max) / 2;

        if (level == max)
            break;

        prevlevel = level;
    }

    return prevlevel;
}