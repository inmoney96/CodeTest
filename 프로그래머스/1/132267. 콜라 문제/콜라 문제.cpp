#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int nowCoke = n;

    //n/a의 몫(을 다 더하면 받을 수 있는 콜라[답]) * b 를 n%a 에 더함을 총 개수 < a 때까지
    
    while (nowCoke >= a)
    {
        answer += (nowCoke / a)*b;
        nowCoke = (nowCoke / a) * b + (nowCoke % a);
    }

    return answer;
}