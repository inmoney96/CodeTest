#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int last = attacks.size()-1;
    int seq = 0, perAttack=0;

    for (int t=1; t <= attacks[last][0]; t++) {

        if (t == attacks[perAttack][0]) {
            answer -= attacks[perAttack][1];
            if (answer <= 0) {
                answer = -1;
                break;
            }

            perAttack++;
            seq = 0;
            continue;
        }

        answer += bandage[1];
        seq++;

        if (seq >= bandage[0]) {
            answer += bandage[2];
            seq = 0;
        }
        if (answer>health) {
            answer = health;
        }
    }

    return answer;
}