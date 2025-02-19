#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool isFirst = true;
    for(int i =0;i<s.size();i++)
    {
        if(isFirst)
        {
            isFirst = false;
            if(s[i] >= 97)
            {
                s[i] -= 32;
            }
        }
        else
        {
            if(s[i] >= 65 && s[i] <= 90)
            {
            s[i] += 32;
            }
        }
        
        if(s[i] == ' ')
        {
            isFirst = true;
        }
    }
    return s;
}