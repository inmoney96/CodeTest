#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int x = 0;
    while(x <500)
    {
       if (num == 1)
        {
            return answer;
        }
       ++answer;    
       if( num%2==0)
       {
           num = num/2;
       } else if (num%2==1){
           num = num*3 +1;
       }
        
        
        
        ++x;
    }
    
    return -1;
    
}