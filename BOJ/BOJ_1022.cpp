// BOJ 1022번 소용돌이 예쁘게 출력하기
// https://www.acmicpc.net/problem/1022

/* 
-  좌표를 기준으로 소용돌이 따라 구현하면 메모리 초과가 남 (범위가 -5000~5000이라)
-  각 좌표에 들어가는 숫자는 수학적 규칙이 있음

 1. 원점(0,0)을 기준으로 대각선 가장 오른쪽 아래는 (2*n+1)의 제곱으로 증가하는 규칙이 있음
 2. (r, c) 중 가장 큰 절대값으로 구현할 map 잡기 
 3.  n =  (r, c 중 가장 큰 절대값) 이며 (r, c)는 n이 형성하는 가장 바깥 외곽선에 위치함
 4. abs(r)==n 일 경우 수평으로 가장 위거나 가장 아래에 위치 / 
    abs(c)==n 일 경우 수직으로 가장 왼쪽이거나 오른쪽에 위치
 5. 음수와 양수의 경우를 나눠서 각 위치가 (2*n+1)*(2+n+1)에서 숫자 줄이기

 - 출력 길이가 같아야함
  1.  저장된 맵을 10으로 계속 나누면서 가장 큰 자릿수 확인
  2.  출력할 숫자의 길이에서 가장 큰 길이(lx)를 뺀 만큼 공백을 출력하여 길이 맞추기

+ 전체 숫자 길이 같은게 아니라 수직인 축 길이만 같으면 되는줄 알고 한참 틀림... 문제 똑바로 읽기... 
*/



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
