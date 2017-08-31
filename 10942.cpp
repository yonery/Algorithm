// 10942�� �Ӹ����
#include <iostream>
using namespace std;


int p[2001] = { 0 };
int dp[2001][2001] = { 0 };

int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d ", &p[i]);

	//���ڸ��� ��� 1
	//���ڸ��� ��쿡�� �ڿ� ������ ������ 1
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
		if (p[i] == p[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	//n�� �˻��� ����, i�� ������
	//i�� j ���̰� �Ӹ�����̰�, i��°�� j��°�� ������ f(i,j)�� �Ӹ���� = 1
	//��, f(i+1, j-1)�� ���Ͽ� �Ӹ���� ��
	for (int n = 1; n < N; n++)
		for (int i = 1; i <= N - n; i++)
			if (p[i] == p[i + n] && dp[i + 1][i + n - 1] == 1)
				dp[i][i + n] = 1;

	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[s][e]);
	}


	return 0;
}