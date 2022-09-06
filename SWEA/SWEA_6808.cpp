// SWEA 6808번 규영이와 인영이의 카드게임 (DFS, BitMask)

/*

1. 규영이의 패를 입력받으면서 인영이가 낼 수 있는 카드패 배열을 만든다.
2. 인영이가 이미 냈던 카드패를 비트마스크로 저장해주고, 매 회 인영이가 낼 수 있는 카드를 조합하여
   마지막에 규영이와 인영이중 누가 이길지 점수를 비교

+ next_permutation으로 했다가 시간초과남... 

*/

#include <iostream>
using namespace std;
int T, num[9], visit[19], win, lose, num2[9];
void dfs(int idx, int cnt, int cnt2, int vit){
	if(idx==9){
        if(cnt>cnt2) win++;
        else lose++;
    	return;
    }
    for(int i=0; i<9; i++){
    	if((vit&(1<<i)) ==0){
        	if(num[idx] > num2[i]) dfs(idx+1, cnt+num[idx]+num2[i], cnt2, vit|(1<<i));
            else dfs(idx+1, cnt, cnt2+num[idx]+num2[i], vit|(1<<i));
        }
    }
    return;
}
int main(){
	cin>>T;
    for(int t=1; t<=T; t++){
        for(int i=1; i<=18; i++)
            visit[i] = 0;
        win = 0, lose = 0;
        for(int i=0; i<9; i++){
            cin>>num[i];
            visit[num[i]] = 1;
        }
        int k = 0;
        for(int i=1; i<=18; i++){
            if(visit[i]==0){
                num2[k++] = i;
            }
        }
        dfs(0, 0, 0, 0);
        cout<<"#"<<t<<" "<<win<<" "<<lose<<"\n";
    }
	return 0;
}
