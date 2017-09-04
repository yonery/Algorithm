// 11053번 가장 긴 증가하는 부분 수열
#include <iostream>

int arr[1001];
int dp[1001] = { 0 };

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	//상자넣기와 비슷
	//자신보다 앞의 값 & 자신보다 작은 값의 최대 dp+1

	int max = 0;
	for (int i = 1; i <= N; i++) {
		int n = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (n < dp[j]) {
					n = dp[j];
				}
			}
		}
		dp[i] = n + 1;
		if (max < dp[i])
			max = dp[i];
	}
	

	printf("%d", max);

	return 0;
}