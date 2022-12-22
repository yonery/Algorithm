// BOJ 1065 한수 (C++)

#include <iostream>
using namespace std;
int result, N;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	if (N < 100) {
		printf("%d", N);
	}
	else{
		result = 99;
		for (int i = 10; i <= 99; i++) {
			int a = i / 10, b = i % 10;
			if (i * 10 > N) break;
			else {
				int c;
				if (a <= b) {
					c = b - a;
					if (b + c < 10 && (10 * i + c + b) <= N) {
						result++;
					}
				}
				else {
					c = a - b;
					if (b - c >= 0 && (10 * i + b - c) <= N) {
						result++;
					}
				}
			}

		}
		printf("%d", result);

	}
	return 0;
}
