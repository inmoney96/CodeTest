#include <iostream>
using namespace std;

struct Point {
	int x, y;
};

int CCW(Point p1, Point p2, Point p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) -(p3.x-p1.x)* (p2.y - p1.y);
}

int main() {
	Point p1, p2, p3;

	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;

	int result = CCW(p1, p2, p3);

	if (result > 0) {
		cout << 1;
	}
	else if (result < 0) {
		cout << -1;
	}
	else {
		cout << 0;
	}

	return 0;
}