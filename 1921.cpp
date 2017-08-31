// 1921�� ������
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

	// N��°���� N-1���� ���� �ְ����� arr[N]�� ũ�� ���� arr[N]���� ����,
	// ������ ������ ���ϴ� ������ ��� ����.
	for (int i = 1; i <= N; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
	}
	int re = dp[1];
	for (int i = 2; i <= N; i++)
		re = max(re, dp[i]);

	printf("%d", re);

	return 0;
}