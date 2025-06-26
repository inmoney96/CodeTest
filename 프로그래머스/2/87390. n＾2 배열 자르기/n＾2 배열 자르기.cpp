#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1 , 0);

    long long a = left / n;
    long long b = left % n;
    long long x = 0;
    int k = a;
    for (long long i = a; i < n; i++)
    {
        k++;
        for (long long j = 1; j <= n; j++)
        {
            
            if (i == a && j <= b)
                continue;
            
            if (j >= k)
            {
                answer[x] = j;
            }
            else 
            {
                answer[x] = k;
            }
            x++;
            if (x >= right - left + 1)
            {
                return answer;
            }
        }
    }
}