// 11055�� ���� ū ���� �κ� ����
#include<iostream>

int dp[1001] = { 0 };
int arr[1001];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	//���� ������ ���� ���
	//�ڽź��� ���� ���� && ���� ������ ���� ū dp + arr[N]
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