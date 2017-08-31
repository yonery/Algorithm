// 2579번 계단 오르기
#include <iostream>
using namespace std;


int dp[301] = { 0 };
int arr[301] = { 0 };

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	// * 조건 : 1or2칸을 밟아야함. 
	// * i번째를 밟을 경우: i-1을 밟거나 안 밟거나
	// 1) P[i] + dp[i-2] 
	// 2) P[i] + P[i-1] + dp[i-3]

	dp[1] = arr[1];
	dp[2] = arr[2] + dp[1];

	for (int i = 3; i <= N; i++)
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);


	printf("%d", dp[N]);

	return 0;
}