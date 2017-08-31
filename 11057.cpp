#include <iostream>
#define mod 10007
using namespace std;

int main() {
	//���� ���� ���� ������ �� �� �ִ� ����� ���� �޶���
	//0 -> 0~9, 1 -> 1~9, 2->2~9, 3->3~9 ...
	
	//��ȭ�ĺ��� �����
	//dp[N][L] = dp[N-1][L] + dp[N-1][L-1] +...+dp[N-1][0]
	
	int N;
	cin >> N;
	int dp[1001][10] = { 0, };



	//���� ���̴� 0�� �� �� ������, N=1�� ��� 0~9�� �ѹ��� �� �� �ִ� ��츦 ä��.
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	
	//2���� N������ �ڸ���
	for (int i = 2; i <= N; i++) 
		//N�� �� �ڸ��� �� �� �ִ� 0~9
		for (int j = 0; j < 10; j++) 
			for (int k = j; k < 10; k++) 
				dp[i][j] = (dp[i][j]+dp[i - 1][k])%mod;

	// DP�� ���ʴ� ���̺� ä���!
	
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum+dp[N][i]) % mod;

	printf("%d", sum);

	
	return 0;
}