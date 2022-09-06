// SWEA 1244번 최대 상금

/*
간단한 DFS 문제인데 visit 체크를 안 해줘서 계속 틀렸던 문제.
6자리 숫자라고 하여 메모리 초과 겁을 먹고 visit를 안 만들어줬더니 계속 시간 초과 떴음;
n번의 기회 상태에서 같은 카드가 등장하면 visit 체크를 해줌
*/

#include<iostream>
#include <cmath>
using namespace std;
int T, N, ret, visit[12][1000000];
string s;

void dfs(int n, string s){
    string card = s;
    if(n==0){
        int num = 0;
        for(int i=0; i<s.length(); i++){
        	num += (int)(s[i]-'0')*pow(10, s.length()-1-i);
        }
        if(ret<num)
            ret = num;
    	return;
    }
    for(int i=0; i<s.length(); i++){
    	for(int j=0; j<s.length(); j++){
        	if(i != j){        
                char tmp = card[i];
                card[i] = card[j];
                card[j] = tmp;       
                if(visit[n][stoi(card)] == 0){
        			visit[n][stoi(card)] = 1;
                    dfs(n-1, card);            
                }
                tmp = card[i];
                card[i] = card[j];
                card[j] = tmp;
            }
        }
    }
	return;
}

int main(){
	cin>>T;
    for(int t=1; t<=T; t++){
    	cin>>s>>N;
        ret = 0;
        for(int i=0; i<=N; i++){
        	for(int j=0; j<1000000; j++)
                visit[i][j] = 0;
        }
        dfs(N, s);    
        cout<<"#"<<t<<" "<< ret<<"\n";
    }
	return 0;
}
