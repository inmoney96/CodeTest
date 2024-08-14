#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0; 
    int w = 0, h = 0, wM = 0, hM = 0;
    // w긴것 중 제일 긴것 x h짧은것 중 제일 긴것
    for(int i =0 ; i< sizes.size(); ++i)
    {
        if(sizes[i][0] >= sizes[i][1])
        {
            w = sizes[i][0];
            h = sizes[i][1];
        }
        else
        {
            h = sizes[i][0];
            w = sizes[i][1];
        }
        
        if(w > wM)
        {
            wM = w;
        }
        if(h >hM)
        {
            hM = h;
        }
    }
    answer = wM*hM;
    return answer;
}