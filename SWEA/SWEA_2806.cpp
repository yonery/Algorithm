// SWEA 2806 번 N-Queen (Back Tracking)

/*
* 이차원 배열로 풀면 마지막 테스트 케이스에서 제한시간 초과가 이뤄진다​

1. 대각선 왼쪽아래 방향은 (y+x) 값이 일정
2. 대각선 오른쪽아래 방향은 (y-x)값이 일정 
3. 행 배열 arr에 0이 아닌 수가 있다면 불가
4. for문을 통해 열에 올 수 있는 경우 확인 (열을 통한 백트래킹)
5. 각각 대각선의 종류는 총 2n-1 개 -> y-x의 경우 음수가 나오기에 그만큼 인덱스 증가시킴

*/

#include <iostream>
using namespace std;
int T, N, arr[11], d1[21], d2[21], ret;
void solve(int y){
	if(y==N)
		ret++;
    for(int i=0; i<N; i++){
    	if(arr[i]) continue;
        if(d1[y+i] || d2[N + (y-i)]) continue;
        arr[i] = d1[y+i] = d2[N + (y-i)] = 1;
        solve(y+1);
        arr[i] = d1[y+i] = d2[N + (y-i)] = 0;
    }
}
int main(){
    cin>>T;
    for(int t=1; t<=T; t++){
    	cin>>N;
        ret = 0;
        for(int i=0; i<N; i++)
            arr[i] = d1[i] = d2[i] = 0;
        solve(0);
        cout<<"#"<<t<<" "<<ret<<"\n";
    }
	return 0;
}
