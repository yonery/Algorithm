// 11053�� ���� �� �����ϴ� �κ� ����
#include <iostream>

int arr[1001];
int dp[1001] = { 0 };

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	//���ڳֱ�� ���
	//�ڽź��� ���� �� & �ڽź��� ���� ���� �ִ� dp+1

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