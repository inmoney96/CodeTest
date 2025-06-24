#include <string>
#include <vector>

using namespace std;

long long arr[2001]={0,1,2,3,5,};

long long solution(int n) {
    //다이나믹같죠?
    // 1칸일 때 1
    // 2칸일 때 11, 2
    // 3칸일 때 111, 21, 12,
    // 4칸일 때 1111, 211, 121, 112, 22
    // 5칸일 때 11111, 2111, 1211, 1121, 221, 1112,212,122
    // n칸일 때 n-1칸에서 1칸 더감, n-2칸에서 2칸 더 감
    // n칸일 때 (n-1칸값) + (n-2칸값)
    if(n <= 4)
    {
        return arr[n];
    }
    for(int i=5;i<=n ; i++)
    {
        arr[i]=(arr[i-1]+arr[i-2])%1234567;
    }
    
    return arr[n];
}