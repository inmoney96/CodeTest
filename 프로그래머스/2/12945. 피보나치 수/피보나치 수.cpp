#include <string>
#include <vector>

using namespace std;

long t[100001]={0,1,};

int solution(int n) {
    for(int i = 2 ; i<=n;i++)
    {
        t[i] = (t[i-1] + t[i-2])%1234567;
    }
    return t[n];
}