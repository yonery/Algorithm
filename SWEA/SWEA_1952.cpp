// SWEA 1952번 수영장

/*
다이나믹 프로그래밍입니다... 하지만 실전에 나온다면 dp로 풀지 않으리...ㅎ..... 
1시간 주고 스터디원들이랑 풀었는데 dfs로 조합하신분들이 더 빠르게 푸시더군요...
요즘 하도 시뮬레이션 문제만 풀어서 dp가 생소했습니다...

앞에서부터 해당 날짜만큼 이용하는데 가장 적게 드는 비용을 구해서 비교했습니다. 
*/

#include <iostream>
using namespace std;

int my[4];
int mth[13];
int dp[13];
int res;
int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		res = 0;
		my[4] = { 0 };
		mth[4] = { 0 };
		dp[13] = { 0 };
		for (int i = 0; i < 4; i++)
			cin >> my[i];
		for (int i = 1; i <= 12; i++) {
			cin >> mth[i];
			if (mth[i] != 0) {
				mth[i] = (mth[i] * my[0]) < my[1] ? (mth[i] * my[0]) : my[1];
			}
		}

		dp[1] = mth[1];
		dp[2] = mth[1] + mth[2];

		for (int i = 3; i <= 12; i++) {
			if (mth[i] == 0){
				dp[i] = dp[i - 1];
				continue;
			}
			dp[i] = mth[i] + dp[i - 1];
			dp[i] = dp[i] < (dp[i - 3] + my[2]) ? dp[i] : (dp[i - 3] + my[2]);
			
		}
		int res = dp[12] < my[3] ? dp[12] : my[3];
		cout << "#" << t << " " << res << endl;

	}
	return 0;
}
