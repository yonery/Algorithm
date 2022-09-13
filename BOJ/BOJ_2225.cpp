// BOJ 2225번 합분해

#include <iostream>
using namespace std;
#define mod 1000000000
int dp[201][201] = {};

int main() {
 int N, K;
 scanf("%d %d", &N, &K);
  
 //f(n, k) = f(n-i, k-1)의 합. (i =0~n)
 //예를 들어 f(2, 3) = f(2, 2) + f(1, 2) + f(0,2)
 //왜냐하면 f(2,3) = 0 + f(2,2) / 1 + f(1,2) / 2 + f(0, 2)

 for (int i = 0; i <= N; i++)
  dp[i][1] = 1;
 for (int i = 1; i <= K; i++)
  dp[0][i] = 1;

 for (int n = 1; n <= N; n++) {
  for (int k = 2; k <= K; k++) {
   for (int i = 0; i <= n; i++) {
    dp[n][k] = (dp[n][k] + dp[n - i][k - 1])%mod;
   }
  }
 }


 printf("%d", dp[N][K]);

 return 0;

}
