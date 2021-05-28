// 1921번 연속합
#include <iostream>
#include <math.h>
using namespace std;


int dp[100001] = { 0 };
int arr[100001] = { 0 };

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	// N번째에서 N-1까지 더한 최고값보다 arr[N]이 크면 끊고 arr[N]부터 시작,
	// 작으면 이전에 더하던 값에서 계속 더함.
	for (int i = 1; i <= N; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
	}
	int re = dp[1];
	for (int i = 2; i <= N; i++)
		re = max(re, dp[i]);

	printf("%d", re);

	return 0;
}
