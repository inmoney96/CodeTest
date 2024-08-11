#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int su1 = 0, su2 = 0, su3 = 0;
    int su1arr[5] = { 1, 2, 3, 4, 5 };
    int su2arr[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int su3arr[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int idx1 = 0, idx2 = 0, idx3 = 0;
    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == su1arr[idx1]) {
            ++su1;
        }
        if (answers[i] == su2arr[idx2]) {
            ++su2;
        }
        if (answers[i] == su3arr[idx3]) {
            ++su3;
        }

        ++idx1;
        ++idx2;
        ++idx3;

        if (idx1 >= 5) {
            idx1 = 0;
        }
        if (idx2 >= 8) {
            idx2 = 0;
        }
        if (idx3 >= 10) {
            idx3 = 0;
        }
    }

    vector<int> rank;

    if (su1 >= su2) {
        rank.push_back(1);
    }
    else {
        rank.push_back(2);
    }

    if (su1 == su2) {
        rank.push_back(2);
    }

    if (su3 > su1 && su3 > su2) {
        rank.clear();
        rank.push_back(3);
    }
    else if (su3 >= su1 && su3 >= su2) {
        rank.push_back(3);
    }

    return rank;
}