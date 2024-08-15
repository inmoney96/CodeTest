#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;
    string a = to_string(n);
    string temp;
    for (int i = 0; i < a.length(); i++) {
        temp = a[i];
        answer += stoi(temp);
    }
    
    return answer;
}