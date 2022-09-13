// BOJ 11052번 붕어빵 판매하기

#include <iostream>
using namespace std;
int dp[10001] = { 0 };
int main() {

 int N;
 scanf("%d", &N);
 int* P = new int[N+1];
 P[0] = 0;
  
 for (int i = 1; i <= N; i++)
  scanf("%d", &P[i]);

 // f(n)은 p(n-1) + p(1), p(n-2) + p(2)...
 // 즉, p(max, n-i) + P(i) 들의 최대이익
 // 하지만 p(max, n-i)가 충족되려면 1부터 n-i를 차례로 테이블을 채우며 최대값을 넣어줘야함

 for (int n = 0; n <= N; n++) {
  for (int i = 0; i <= n; i++) {
   dp[n] = dp[n - i] + P[i] > dp[n] ? dp[n - i] + P[i] : dp[n];
  }
 }
 printf("%d", dp[N]);
 return 0;

}
