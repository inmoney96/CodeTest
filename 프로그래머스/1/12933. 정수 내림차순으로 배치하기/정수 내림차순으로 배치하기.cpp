#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string a = to_string(n);
    vector<int> b;
    for (auto i : a) {
        b.push_back(i-'0');
    }
    sort(b.rbegin(), b.rend());

    for (auto k : b) {
        answer = answer * 10 + k;
    }
    return answer;
}