#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int middle = s.size() / 2;
    //s.size()/2 하면
    //홀수 5/2 = 2 0 1 2 3 4 print i
    //짝수 6/2 = 3 0 1 2 3 4 5 print i-1, i
    if (s.size() % 2 == 1)
    {
        answer += s[middle];
    }
    else
    {
        answer += s[middle - 1];
        answer += s[middle];
    }

    return answer;
}