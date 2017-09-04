// 11722�� ���� �� �����ϴ� �κ� ����
#include<iostream>
int dp[1001] = { 0 };
int arr[1001];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	//�ڿ��� ���� �˻�
	//�ڽź��� �۰� && �ڽ��� �ڿ� �ִ� ���� ū dp + 1
	
	int max = 0;
	for (int i = N; i > 0; i--) {
		int n = 0;
		for (int j = i+1; j <= N; j++) {
			if (arr[i] > arr[j])
				if (n < dp[j])
					n = dp[j];
		}
		dp[i] = n + 1;
		if (max < dp[i])
			max = dp[i];
	}

	printf("%d", max);

	return 0;
}