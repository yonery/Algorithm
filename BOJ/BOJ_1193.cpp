// 1193 분수찾기 (C++)

#include <iostream>
#include <string>
using namespace std;
int X;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> X;
	int x = 1, y = 1, d = 1, t = 1, tx = x, ty = y;
	while (t<X) {
		if (d == 1) {
			tx = x - 1, ty = y + 1;
			if (tx <= 0) {
				tx = x;
				d = 0;
			}
		}
		else {
			tx = x + 1, ty = y - 1;
			if (ty <= 0) {
				ty = y;
				d = 1;
			}
		}
		x = tx, y = ty;
		t++;
	}
	cout << x << "/"<<y << "\n";
	return 0;
}
