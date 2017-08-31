// 10844�� ���� ��� ��
#include <iostream>
using namespace std;
#define mod 1000000000
int dp[101][10];

int main() {
	int N;
	scanf("%d", &N);

	//N��° ���� N-1��° ���� ���� ������.
	//N��° �� i�� 0�̸� N-1�� i�� 1, 9�̸� N-1�� i�� 8�ۿ� �� �� ����.
	//N�� ������ ������ i��  N-1�� i-1��  i+1�� �� �� ����.

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