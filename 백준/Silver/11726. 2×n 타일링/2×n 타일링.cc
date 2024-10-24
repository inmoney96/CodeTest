#include <stdio.h>
#include <vector>
int main() {
    int n = 0;
    std::vector<int> memo;
    memo.push_back(0);
    memo.push_back(1);
    memo.push_back(2);
    scanf("%d", &n);

    for (int i = 3; i <= n; i++)
    {
        memo.push_back((memo[i - 1] + memo[i - 2]) % 10007);
    }

    printf("%d", memo[n]);

    return 0;
}