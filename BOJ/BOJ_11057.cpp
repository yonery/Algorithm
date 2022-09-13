// BOJ 11057번 오르막 수 (

#include <iostream>
#define mod 10007
using namespace std;

int main() {
	//이전 수에 따라 다음에 올 수 있는 경우의 수가 달라짐
	//0 -> 0~9, 1 -> 1~9, 2->2~9, 3->3~9 ...
	
	//점화식부터 세우기
	//dp[N][L] = dp[N-1][L] + dp[N-1][L-1] +...+dp[N-1][0]
	
	int N;
	cin >> N;
	int dp[1001][10] = { 0, };



	//수의 길이는 0이 될 수 없으며, N=1일 경우 0~9는 한번만 올 수 있는 경우를 채움.
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	
	//2부터 N까지의 자리수
	for (int i = 2; i <= N; i++) 
		//N의 각 자리에 들어갈 수 있는 0~9
		for (int j = 0; j < 10; j++) 
			for (int k = j; k < 10; k++) 
				dp[i][j] = (dp[i][j]+dp[i - 1][k])%mod;

	// DP의 기초는 테이블 채우기!
	
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum+dp[N][i]) % mod;

	printf("%d", sum);

	
	return 0;
}
