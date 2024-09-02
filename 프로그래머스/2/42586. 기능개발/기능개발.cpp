#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    //progresses의 i = 0 번이 100 이상이 되면, ++i 하며 100 미만이 나올때까지 전부 배포
    //day는 front가 100 이상이 될 떄마다 초기화

    //grogresses의 각 요소는 day가 1 증가할 때마다 speeds만큼 증가
    vector<int> answer;
    int released = 0;
    int dayrelease = 0;

    while (released < progresses.size())
    {
        //1일 경과
        for (int i = released; i < progresses.size(); ++i)
        {
            progresses[i] += speeds[i];
        }

        //하루의 끝에 배포


        while (progresses[released] >= 100)
        {
            ++released;
            ++dayrelease;
            if (released >= progresses.size())
                break;
        }

        if (dayrelease > 0)
        {
            answer.push_back(dayrelease);
            dayrelease = 0;
        }

    }

    return answer;
}