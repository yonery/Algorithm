// SWEA 1266번 소수 완제품 확률 (DP, 에라토스테네스의 체)

/*
전형적인 Dp 문제 유형같아서 확률 더하기로 풀었습니다.

1. A, B 모두 90분동안 최대 18개의 완제품을 생산할 수 있음 (90/5)
2. dp[시간][완제품수] 로 구성하여 
 (i번째의 j개를 만들 확률)*(1개의 완제품을 만들 수 있는 확률) = (i+1번째의 j+1개를 만들 확률)
 (i번째의  j개를 만들 확률)*(1 - 1개의 완제품을 만들 수 있는 확률) = (i+1번쨰의 j개를 만들 확률)

3. A가 소수를 만들 확률 + B가 소수를 만들 확률 - A도 B도 모두 소수를 만들 확률


에라토스테네스의 체 참고
https://ledgku.tistory.com/61


*/

#include <iostream>
#include <cmath>
#define swap(a, b) { int t = a, a = b, b = t; }
using namespace std;
int T;
double A, B, skiA, skiB, dp[19][20], dp2[19][20], prime[19];
bool chk(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) return false;
	}
	return true;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
    cout << fixed;
	cout.precision(6);
	for (int i = 1; i <= 18; i++) {
		if (chk(i)) prime[i] = 1;
	}

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> skiA >> skiB;
		A = skiA / 100.0;
		B = skiB / 100.0;
		for (int i = 1; i <= 18; i++)
			for (int j = 0; j <= 18; j++)
				dp[i][j] = dp2[i][j] = 0;
        dp[1][0] = (1-A);
        dp[1][1] = A;
        dp2[1][0] = (1-B);
        dp2[1][1] = B;
		for (int i = 1; i < 18; i++) {
			for (int j = 0; j <= 18; j++) {
                if(dp[i][j] > 0){
                	dp[i+1][j] += dp[i][j]*(1-A);               	
                	dp[i+1][j+1] += dp[i][j]*A;            	 	            
                }
                if(dp2[i][j] >0){
                	dp2[i+1][j] += dp2[i][j]*(1-B);
                    dp2[i+1][j+1] += dp2[i][j]*B;      
                }
            }
		}
		double a = 0, b = 0;
		for (int i = 2; i <= 18; i++) {
			if (prime[i]){
                a += dp[18][i], b += dp2[18][i];
            }
		}
		cout << "#" << t << " " <<(a+b)- (a*b)<<"\n";
	}
	return 0;
}
