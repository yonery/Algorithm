// 10844번 쉬운 계단 수
#include <iostream>
using namespace std;
#define mod 1000000000
int dp[101][10];

int main() {
	int N;
	scanf("%d", &N);

	//N번째 수는 N-1번째 수에 의해 결정됨.
	//N번째 수 i가 0이면 N-1의 i는 1, 9이면 N-1의 i는 8밖에 올 수 없음.
	//N이 나머지 범위늬 i는  N-1은 i-1과  i+1이 올 수 있음.

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int n = 2; n <= N; n++) {
		for (int i = 0; i < 10; i++) {
			if (i == 0)
				dp[n][i] = dp[n - 1][1] % mod;
			else if (i == 9)
				dp[n][i] = dp[n - 1][8] % mod;
			else
				dp[n][i] = (dp[n - 1][i - 1] + dp[n - 1][i + 1]) % mod;
		}
	}
	int sum = 0;
	for (int i = 1; i < 10; i++)
		sum = (sum + dp[N][i]) % mod;

	printf("%d", sum%mod);
	return 0;
}
