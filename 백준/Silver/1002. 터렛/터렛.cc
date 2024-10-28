#include <iostream>
#include <vector>
using namespace std;

struct pos {
    int y, x, r;
};

int main() {
    int n;
    cin >> n;

    pos t1, t2;

    for (int i = 0; i < n; i++) {
        cin >> t1.x >> t1.y >> t1.r >> t2.x >> t2.y >> t2.r;

        int lenSq = (t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y);
        int outRSq = (t1.r + t2.r) * (t1.r + t2.r);
        int inRSq = (t1.r - t2.r) * (t1.r - t2.r);

        if (lenSq == 0 && t1.r == t2.r) {
            cout << -1 << endl; // 무한대 상태로 겹침
        }
        else if (lenSq == outRSq || lenSq == inRSq) {
            cout << 1 << endl;  // 외접 또는 내접
        }
        else if (lenSq > inRSq && lenSq < outRSq) {
            cout << 2 << endl;  // 두 원이 겹침
        }
        else {
            cout << 0 << endl;  // 두 원이 떨어져 있음
        }
    }

    return 0;
}
