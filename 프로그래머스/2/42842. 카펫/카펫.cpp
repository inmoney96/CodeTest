#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    //노란색이 직사각형이 되어야 함 노란색과 갈색 사이의 공식은?
    //노란카펫 가로=x, 세로=y 일 때, 2(x+y) + 4 = 갈색 총 개수
    //전체카펫 = 노란 카펫 가로+2 세로+2
    int x = yellow, y = 1, i = 1;
    vector<int> answer;

    while (true)
    {
        if (2 * (x + y) + 4 == brown)
        {
            answer.push_back(x + 2);
            answer.push_back(y + 2);
            return answer;
        }
        
        while (true)
        {
            ++i;
            if (yellow % i == 0)
            {
                x = yellow / i;
                y = i;
                break;
            }
        }
    }

}