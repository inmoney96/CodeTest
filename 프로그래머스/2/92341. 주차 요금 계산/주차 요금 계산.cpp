#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    
    vector<string> input;
    map<string, int> parking;
    map<string, int> answer;

    for (int i = 0; i < records.size(); i++)
    {
        //시간 차번 입출로 나눠
        string tmp;
        for (int j = 0; j < records[i].size(); j++)
        {
            if (records[i][j] != ' ')
            {
                tmp +=records[i][j];
            }
            else
            {
                input.push_back(tmp);
                tmp.clear();
            }
        }
        input.push_back(tmp);
        //시간을 분으로 환산해
        int min = 0;
        string h;
        h += input[0][0];
        h += input[0][1];
        string m;
        m += input[0][3]; 
        m += input[0][4];
        min += stoi(h) * 60 + stoi(m);

        //입이면 맵에 넣어
        if (input[2] == "IN")
        {
            parking.insert(make_pair(input[1], min));
        }
        else //출이면 맵에서 차번이 같은걸 찾고 시간을 빼
        {
            int inTime = parking.find(input[1])->second;
            int parkTime = min - inTime;

            //그 값을 정답 맵에 넣어
            if (answer.find(input[1]) == answer.end()) // 없으면 추가
            {
                answer.insert(make_pair(input[1], parkTime));
            }
            else // 있으면 주차한 시간을 더해
            {
                answer.find(input[1])->second += parkTime;
            }
            parking.erase(input[1]); //차 빼
        }

        input.clear();
    }

    //records가 끝났을 때 맵에 차가 남아있으면 23:59로 다 출 해
    while (!parking.empty())
    {


        int inTime = parking.begin()->second;
        int parkTime = (23*60+59) - inTime;

        //그 값을 정답 맵에 넣어
        if (answer.find(parking.begin()->first) == answer.end()) // 없으면 추가
        {
            answer.insert(make_pair(parking.begin()->first, parkTime));
        }
        else // 있으면 주차한 시간을 더해
        {
            answer.find(parking.begin()->first)->second += parkTime;
        }
        parking.erase(parking.begin()->first); //차 빼
    }
    
    //정답 맵을 오름차순으로 정렬하고 벡터로 바꿔
    vector<int> answerVec;

    map<string, int>::iterator it = answer.begin();

    while (it != answer.end())
    {
        if (it->second <= fees[0]) // 기본요금
        {
            answerVec.push_back(fees[1]);
        }
        else
        {
            int fee = 0;
            int parkTime = it->second;
            parkTime -= fees[0];
            fee += fees[1];
            while (parkTime > 0)
            {
                fee += fees[3];
                parkTime -= fees[2];
            }

            answerVec.push_back(fee);
        }
        it++;
    }

    return answerVec;
}