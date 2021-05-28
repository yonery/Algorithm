#include <iostream>

long long dp[101] = { 1, 1, 1, 1, 2, 2, };

int main() {

	int T;
	scanf("%d", &T);

	//f(N) = f(N-1) + f(N-5)
	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}

	return 0;
}
