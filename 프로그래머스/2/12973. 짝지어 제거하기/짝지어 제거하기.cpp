#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<char> a;
    a.push(s[0]);
    for (int i = 1;i < s.size();i++)
    {
        if (a.empty() || a.top() != s[i])
        {
            a.push(s[i]);
        }
        else
        {
            a.pop();
        }
    }
    return a.empty();
}