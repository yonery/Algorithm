// BOJ 11055번 가장 큰 증가 부분 수열 (dp)
#include<iostream>

int dp[1001] = { 0 };
int arr[1001];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	//앞의 문제와 같은 방식
	//자신보다 앞의 숫자 && 작은 숫자의 가장 큰 dp + arr[N]
	int max = 0;
	for (int i = 1; i <= N; i++) {
		int n = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (n < dp[j]) {
					n = dp[j];
				}
			}
		}
		dp[i] = n + arr[i];
		if (max < dp[i])
			max = dp[i];
	}
	printf("%d", max);

	return 0;
}
