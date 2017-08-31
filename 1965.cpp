//1965�� ���ڳֱ�
#include <iostream>
using namespace std;

int dp[1001] = { 0 };
int p[1001] = { 0 };

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &p[i]);

	dp[1] = 1;
	//N��° ���ڴ� N���� ���̸� �ڱ⺸�� ���� ���� �ִ������ �� + 1
	for (int i = 2; i <= N; i++) {
		int m = 0;
		for (int j = 1; j < i; j++) {
			if (p[j]<p[i])
				m = max(m, dp[j]);
		}
		dp[i] = m + 1;
	}

	int m = 0;
	for (int i = 1; i <= N; i++)
		m = max(m, dp[i]);

	printf("%d", m);

	return 0;
}