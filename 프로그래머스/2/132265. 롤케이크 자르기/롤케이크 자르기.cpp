#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
	int l = 0, r = 0;
    vector<stack<int>> LTopping(10001);
    vector<stack<int>> RTopping(10001);

    for (int i = 0; i < topping.size(); i++) {
		if (RTopping[topping[i]].empty()) {
			r++;
		}
        RTopping[topping[i]].push(topping[i]);
    }

	for (int i = 0; i < topping.size(); i++) {
		RTopping[topping[i]].pop();
		if (RTopping[topping[i]].empty()) {
			r--;
		}
		if (LTopping[topping[i]].empty()) {
			l++;
		}
		LTopping[topping[i]].push(topping[i]);
		if (l == r) {
			answer++;
		}
	}
    return answer;
}