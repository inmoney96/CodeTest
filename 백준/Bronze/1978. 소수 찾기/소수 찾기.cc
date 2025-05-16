#include <iostream>
using namespace std;

int arr[100]{};
bool isPrime[1001]{};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    fill(isPrime, isPrime + 1001, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= 1000; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 1000; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime[arr[i]]) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}
