// 16917 양념 반 후라이드 반 (C++)

#include <iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (a + b > 2 * c) {
		if (x > y) {
			if (a > 2 * c) cout << 2 * c * x << "\n";
			else cout << (x - y)*a + 2 * y * c << "\n";
		}
		else {
			if (b > 2 * c) cout << 2 * c * y << "\n";
			else cout << (y - x)*b + 2 * x * c << "\n";
		}
	}
	else {
		if (a > 2 * c) cout << 2 * c*x + b * y << "\n";
		else if (b > 2 * c) cout << a * x + 2 * c*y << "\n";
		else cout << a * x + b * y << "\n";
	}

	return 0;
}
