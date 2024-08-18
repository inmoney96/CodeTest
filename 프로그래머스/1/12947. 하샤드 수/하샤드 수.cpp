#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    string digit = to_string(x);
    int sum=0;
    for (int i = 0; i < digit.size(); ++i)
    {
        sum += digit[i] - '0';
    }

    if (x % sum != 0) {
        answer = false;
    }

    return answer;
}