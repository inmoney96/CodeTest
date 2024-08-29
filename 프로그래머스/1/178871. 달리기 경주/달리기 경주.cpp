#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    answer.resize(players.size());

    map<string, unsigned short> nameKey;
    map<unsigned short, string> rankKey;
    for(int i = 0; i < players.size(); i++) {
        nameKey.insert({ players[i], i + 1 });
        rankKey.insert({ i + 1, players[i] });
    }

    map<string, unsigned short>::iterator iter;
    int rank;
    string tempcatched;
    for (int i = 0; i < callings.size(); i++) {
        //현재 calling이 몇등인지 nameKey 맵에서 확인
        iter = nameKey.find(callings[i]);
        rank = iter->second;
        iter->second -= 1; //nameKey에서 추월한 놈 등수변동

        //rankKey에서 등수 변동
        tempcatched = rankKey.find(rank-1)->second;
        rankKey.find(rank-1)->second = rankKey.find(rank)->second;
        rankKey.find(rank)->second = tempcatched;

        nameKey.find(tempcatched)->second += 1; //nameKey에서 잡힌 놈 등수변동
    }

    for (int i = 0; i < players.size(); i++) {
        answer[i] = (rankKey.find(i+1)->second);
    }

    return answer;
}