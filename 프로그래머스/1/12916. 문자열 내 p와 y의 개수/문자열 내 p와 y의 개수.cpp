#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p=0,y=0;
    int c=0;
    
    while(s[c]){
        if(s[c]==80||s[c]==112)
            p +=1;
        if(s[c]==89||s[c]==121)
            y +=1;
        
        c++;
    }
    if(p!=y)
        answer = false;
    
    return answer;
}