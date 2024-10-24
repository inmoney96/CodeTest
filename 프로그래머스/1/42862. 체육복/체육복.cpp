#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> cloth;
    int answer = 0;
    for(int i =0;i<=n+1;i++)//0번,n+1번 배열 초과 방지용
    {
        cloth.push_back(1);
    }
    
    for(int i =0;i<lost.size();i++)
    {
        cloth[lost[i]] -= 1;
    }
    
    for(int i =0;i<reserve.size();i++)
    {
        cloth[reserve[i]] += 1;
    }
    
    for(int i =1;i<=n;i++)
    {
        if(cloth[i] ==0)
        {
            if(cloth[i-1]==2)
            {
                cloth[i-1] = 1;
                cloth[i] = 1;
            }else if(cloth[i+1]==2)
            {
                cloth[i] = 1;
                cloth[i+1] = 1;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(cloth[i] >= 1)
        {
            answer++;
        }
    }
    
    return answer;
}