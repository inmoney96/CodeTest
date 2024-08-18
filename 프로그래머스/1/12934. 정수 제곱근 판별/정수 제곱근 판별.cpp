#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = -1;

    if (n < 2250000000000) {
        for (long long i = 1; i * i <= n; i++) {
            if (n / i == i&&n%i==0) {
                answer = i+1;
                return answer * answer;
            }
        }
    }else if (n < 9000000000000) {
        for (long long i = 1499999; i * i <= n; i++) {
            if (n / i == i&&n%i==0) {
                answer = i + 1;
                return answer * answer;
            }
        }
    }
    else if (n < 20250000000000) {
        for (long long i = 2999999; i * i <= n; i++) {
            if (n / i == i&&n%i==0) {
                answer = i + 1;
                return answer * answer;
            }
        }
    }
    else if (n < 36000000000000) {
        for (long long i = 4499999; i * i <= n; i++) {
            if (n / i == i&&n%i==0) {
                answer = i+1;
                return answer * answer;
            }
        }
    }
    else {
        for (long long i = 5999999; i * i <= n; i++) {
            if (n / i == i&&n%i==0) {
                answer = i + 1;
                return answer * answer;
            }
        }
    }

    return answer;
}