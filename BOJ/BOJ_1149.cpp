// BOJ 1149 RGB거리 (DP)

/*
간단한 dp문제입니다. 


현재 빨간 집을 칠할 수 있는 경우 = 이전에 초록 or 파랑
현재 초록 집을 칠할 수 있는 경우 = 이전에 빨강 or 파랑
현재 파랑 집을 칠할 수 있는 경우 = 이전에 빨강 or 초록

해서 두 가지 경우중에 최소 비용을 선택해서 확장시켜 나갑니다.
그리고 마지막 집이 빨강/초록/파랑 일 경우 중 가장 작은 비용이 총 최소 비용 입니다.
*/

#include <iostream>
using namespace std;
int N, dp[1001][3], r, g, b;
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");

	cin >> N;
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	for (int i = 1; i < N; i++) {
		cin >> r >> g >> b;
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b;
	}

	int ret = min(dp[N - 1][0], dp[N - 1][1]);
	ret = min(ret, dp[N - 1][2]);
	cout << ret << "\n";

	return 0;
}
