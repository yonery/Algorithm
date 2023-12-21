// 1110 더하기 사이클 (C++)
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int pre = N, cnt = 1, n = N / 10 + N % 10;
	while (1) {
		pre = (pre % 10) * 10 + n % 10;
		if (pre == N) break;
		n = pre / 10 + pre % 10;
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}
