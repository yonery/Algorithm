// 2133번 타일채우기

#include <iostream>

int p[31] = { 0 };
int dp[31] = { 0 };

int main() {
	int N;
	scanf("%d", &N);

	p[0] = 1;
	p[2] = 3;
	dp[0] = 1;

	// 자기 자신으로 유일하게 만들 수 있는것,
	// 양쪽끝에 2x1, 가운데는 겹치게 1x2가 쌓이고, 위아래로 1x2로 받침
	for (int i = 4; i <= N; i += 2)
		p[i] = 2;

	//f(N) = f(N-2)*f(2) +  f(N-4)*f(4) + f(N-6)*f(6) ...
	//N이 홀수일 경우는 불가, 0으로 초기화. 2씩 증가.

	for (int i = 2; i <= N; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			dp[i] += dp[i - j] * p[j];
		}
	}

	printf("%d", dp[N]);


	return 0;
}
