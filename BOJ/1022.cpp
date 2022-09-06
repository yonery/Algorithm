// 1022번 소용돌이 예쁘게 출력하기
// https://www.acmicpc.net/problem/1022

#include <iostream>
#include <cmath>
using namespace std;
int map[50][50];
int len(int lmx) {
	int n = 1;
	while (lmx > 9) {
		lmx /= 10;
		n++;
	}
	return n;
}
int num(int r, int c) {
	int n = abs(r) > abs(c) ? abs(r) : abs(c);
	int num = (2 * n + 1)*(2 * n + 1);
	if (r > 0 && r == c) return num;
	if (r < 0 && r == c) return num -= 4 * n;
	if (r >= c) {
		if (n == r) {
			num -= (n - c);
		}
		else {
			num -= 2 * n;
			num -= (n - r);
		}

	}
	else {
		num -= 4 * n;
		if (n == abs(r)) {
			num -= (n + c);
		}
		else {
			num -= 2 * n;
			num -= (n + r);
		}


	}
	return num;
}

int main() {
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			map[i][j] = num(r1 + i, c1 + j);
		}
	}
	
	int lmx = 0;
	for (int j = 0; j <= c2 - c1; j++) {
		for (int i = 0; i <= r2 - r1; i++) {
			if (lmx < len(map[i][j])) lmx = len(map[i][j]);
		}
	}

	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2-c1; j++) {
			for (int k = 0; k < lmx - len(map[i][j]); k++) cout << " ";
			cout << map[i][j] << " ";

		}
		cout << "\n";
	}

	return 0;
}
