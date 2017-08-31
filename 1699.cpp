//1699�� �������� ��
#include <iostream>
#include <math.h>
using namespace std;


int dp[100001] = { 0 };

int min(int a, int b) {
	return a <= b ? a : b;
}

int main() {
	int N;
	scanf("%d", &N);



	// N = a^2 + b �� ���� �� ����.
	//f(N) �� f(b) + 1�� f(N-1) +1�� ���ؼ� ���� ��

	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		int num = sqrt(i);
		for (int j = num; j >= 1; j--) {
			dp[i] = min(dp[i - (j*j)] + 1, dp[i]);
		}
	}

	printf("%d", dp[N]);


	return 0;
}