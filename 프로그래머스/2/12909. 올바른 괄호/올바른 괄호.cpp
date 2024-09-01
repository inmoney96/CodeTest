#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    int n = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(') {
            n++;
        }
        if (s[i] == ')') {
            n--;
        }
        if (n < 0) {
            return false;
        }
    }

    if(n != 0){
        return false;
    }

    return answer;
}