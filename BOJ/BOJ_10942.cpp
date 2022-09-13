// 10942번 팰린드롬 (dp)
#include <iostream>
using namespace std;


int p[2001] = { 0 };
int dp[2001][2001] = { 0 };

int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d ", &p[i]);

	//한자리의 경우 1
	//두자리의 경우에도 뒤와 같으면 같으면 1
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
		if (p[i] == p[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	//n이 검사할 길이, i가 시작점
	//i와 j 사이가 팰린드롬이고, i번째와 j번째가 같으면 f(i,j)도 팰린드롬 = 1
	//즉, f(i+1, j-1)을 비교하여 팰린드롬 비교
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
