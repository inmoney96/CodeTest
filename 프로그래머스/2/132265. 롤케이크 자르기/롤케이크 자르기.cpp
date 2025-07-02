#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int l = 0, r = 0;
    map<int,int> setA;
    map<int,int> setB;
    for(const auto v : topping)
    {
        if(setB[v] == 0)
        {
            r++;
        }
        setB[v]++;
    }

    for(const auto v : topping)
    {
        if(setA[v] == 0)
        {
            l++;
        }
        setA[v]++;
        setB[v]--;
        if(setB[v] == 0)
        {
            r--;
        }

        if(l == r)
        {
            answer++;
        }
    }

    return answer;
}