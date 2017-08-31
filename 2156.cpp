// 2156�� ������ �ý�
#include <iostream>
#include <math.h>
using namespace std;


int dp[10001] = { 0 };
int arr[10001] = { 0 };

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	// * ���� 3���� ���� �� ���� :
	// 1) P[i] + P[i-1] + dp[i-3]
	// 2) P[i] + dp[i-2]
	// 3) dp[i-1] => i��°�� ������ ����.
	// 3���� ��� ��

	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	printf("%d", dp[N]);

	return 0;
}