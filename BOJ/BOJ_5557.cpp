// BOJ 5557번 1학년 (dp)

/*
 1. 매 횟수마다 나오는수는 0~ 20으로 짧은 구간임
 2. i번째에서 j (0<=j<=20) 가 나오는 경우의 수를 저장 (메모이제이션)
*/
#include <iostream>
using namespace std;
int N, num[101];
long long dp[101][21];
int main(){
	cin>>N;
    for(int i=0; i<N; i++) cin>>num[i];
    dp[0][num[0]] = 1;
    for(int i=1; i<N-1; i++){
     for(int j=0; j<21; j++){
         if(dp[i-1][j] !=0){
             if(j + num[i] <=20) dp[i][j + num[i]] += dp[i-1][j];             
             if(j- num[i] >=0) dp[i][j - num[i]] += dp[i-1][j];                
            }
        }
    }
    cout<<dp[N-2][num[N-1]]<<"\n";
    return 0;
}
