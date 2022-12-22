// 1018 체스판 다시 칠하기 (C++)

#include <iostream>
using namespace std;
int N, M, dp[51][51], dp2[51][51];
char map[51][51];
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int num1 = 0, num2 = 0;
			for (int k = 0; k < 8; k++) {
				if ((j + k) % 2 == 0) {
					if (i % 2 == 0) {
						if (map[i][j + k] == 'B') num1++;
						else num2++;
					}
					else {
						if (map[i][j + k] == 'W') num1++;
						else num2++;
					}
				}
				else {
					if (i% 2 == 0) {
						if (map[i][j + k] == 'W') num1++;
						else num2++;
					}
					else{
						if (map[i][j + k] == 'B') num1++;
						else num2++;
					}

				}
			}
			dp[i][j] = num1, dp2[i][j] = num2;
		}
	}

	int ret = 1000001;
	for (int j = 0; j <= M - 8; j++) {
		for (int i = 0; i <= N - 8; i++) {
			int num1 = 0, num2 = 0;
			for (int k = 0; k < 8; k++) {
				num1 += dp[i + k][j];
				num2 += dp2[i + k][j];
			}
			if (ret > num1) ret = num1;
			if (ret > num2) ret = num2;
		}
	}
	

	cout << ret << "\n"; 
	
	return 0;
}

