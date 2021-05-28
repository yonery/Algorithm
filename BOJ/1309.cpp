#include <iostream>
#define mod 9901
int dp[100001][4] = { 0 };

int main() {
	int N;
	scanf("%d", &N);

	// X X -> 이 다음에 4가지 가능(1, 2, 3, 4)
	dp[1][1] = 1;
	// O X -> 이 다음에 2가지 가능(1, 3)
	dp[1][2] = 1;
	// X O -> 이 다음에 2가지 가능 (1, 2)
	dp[1][3] = 1;
	// O O  -> 이 다음에 1가지 가능 (1)
	dp[1][4] = 1;
	
	
	for (int i = 2; i <= N; i++) {
		dp[i][1] = (dp[i-1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][2]) % mod;

	}

	int total = 0;
	for (int i = 1; i <= 3; i++)
		total = (dp[N][i] + total)%mod;

	printf("%d", total);

	return 0;
}
