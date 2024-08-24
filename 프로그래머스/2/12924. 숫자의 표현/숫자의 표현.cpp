#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int sum = 0;
    int min = 1;
    
    //연속한 자연수, 1부터 ++ 하며 나온 값이 n 이면 ++answer;
    //n보다 작으면 다음 숫자 추가
    //n보다 크면 작은숫자 하나 제거
    //숫자가 n/2보다크면 종료
    
    if(n==1 || n ==2){
        return 1;
    }
    
    for(int i = 1; i <= n/2+1 ; ++i)
    {
        sum += i;
        
        if(sum == n)
        {
            ++answer;
        } 
        else if (sum > n)
        {
            while(sum > n)
            {
                sum -= min;
                ++min;
            }
            if(sum == n)
            {
                ++answer;
            }
        }
    }
    
    return answer;
}