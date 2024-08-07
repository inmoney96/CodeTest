#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    bool initIter = true;
    vector<int> score;
    vector<int>::iterator iter;
    for (int i = 0; i < dartResult.size(); ++i)
    {
        
        if (dartResult[i] >= 48 && dartResult[i] <= 57)
        {
            if (dartResult[i + 1] == 48 && dartResult[i] == 49)
            {
                score.push_back(10);
                ++i;
            }
            else {
                score.push_back(dartResult[i] - '0');
            }

            iter = score.end();
            --iter;
        }
        else 
        {
            switch (dartResult[i])
            {
            case 'S':
                break;

            case 'D':
                *iter *= *iter;
                break;

            case 'T':
                *iter *= *iter * (*iter);
                break;

            case '*':
                *iter = 2 * (*iter);
                if (iter != score.begin())
                {
                    --iter;
                    *iter = 2 * (*iter);
                    ++iter;
                }

                break;

            case '#':
                *iter = -(*iter);
                break;

            default:
                break;
            }
        }
        
    }

    // 점수 계산 로직
    // 3 * (0~10)
    // S = a, D = aa, T = aaa
    // a *b = 2(a+b), #a = -a
    // *a *b = 4(a+b), #a *b = 2(-a + b)
    for (int i = 0; i < 3; ++i) {
        answer += score[i];
    }
    return answer;
}