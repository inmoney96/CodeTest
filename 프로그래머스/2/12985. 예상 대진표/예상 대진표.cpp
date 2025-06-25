#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int ans = log2(n);
    int min = 1, max = n, cur;
    while (true)
    {
        cur = (max + min) / 2;

        if (a > cur && b > cur)
        {
            min = cur + 1;
        }
        else if (a <= cur && b <= cur)
        {
            max = cur;
        }
        else
        {
            break;
        }
        ans--;
    }

    return ans;
}