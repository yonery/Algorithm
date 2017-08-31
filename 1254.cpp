//1254번 팰린드롬 만들기

#include <iostream>
#include <string.h>
using namespace std;


char S[1009];
int dp[1009][1009] = { 0 };

int main() {
	scanf("%s", &S);
	int N = strlen(S);

	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j < N; j++) {
			if (i == j)
				dp[i][j] = 1;
			else if (i == j - 1 && S[i] == S[j])
				dp[i][j] = 1;
			else if (dp[i + 1][j - 1] == 1 && S[i] == S[j])
				dp[i][j] = 1;
		}
	}
	int num;
	for (int i = N - 1; i >= 0; i--)
		if (dp[i][N - 1])
			num = i;

	printf("%d", N + num);

	return 0;
}