#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> box;
    sort(score.begin(), score.end(),greater<>());

    //answer += m*lower

    for (int i = 1; i <= score.size(); ++i)
    {
        box.push_back(score[i-1]);
        if (i % m == 0)
        {
            answer += box[m-1] * m;
            box.clear();
        }
    }

    return answer;
}

int main() {
    solution(3, 4, { 1, 2, 3, 1, 2, 3, 1 });
}