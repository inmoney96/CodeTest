#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> allSum;

void pm(const vector<int> &numbers, int idx, int sum) {
    sum += numbers[idx];
    if (idx == numbers.size()-1) {
        allSum.push_back(sum);
    }
    else{
        pm(numbers, idx + 1, sum);
    }
    sum -= numbers[idx];
    sum -= numbers[idx];
    if (idx == numbers.size()-1) {
        allSum.push_back(sum);
    }
    else {
        pm(numbers, idx + 1, sum);
    }
    return;
}

int solution(vector<int> numbers, int target) {
    pm(numbers, 0, 0);
    return count(allSum.begin(), allSum.end(), target);
}