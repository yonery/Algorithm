// BOJ 2468번 안전 영역 (DFS)

#include <iostream>
using namespace std;
int N, map[100][100], mx, visit[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void dfs(int x, int y, int n, int k){
	for(int i=0; i<4; i++){
    	int tx = x+dx[i], ty = y +dy[i];
        if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
        if(visit[tx][ty] ==0 && map[tx][ty] > k){
        	visit[tx][ty] = n;
            dfs(tx, ty, n, k);
        }
    }
	return;
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
        	cin>>map[i][j];
            if(mx<map[i][j]) mx = map[i][j];
        }
    }
    int ret = 0;
    for(int k=0; k<=mx; k++){
        int n=1;
        for(int i=0; i<N; i++){
        	for(int j=0; j<N; j++){
            	if(visit[i][j] ==0 && map[i][j] >k){
                    visit[i][j] = n;
                	dfs(i, j, n, k);
                    n++;
                }
            }
        }
        n--;
        if(ret<n) ret = n;
    	for(int i=0; i<N; i++){
        	for(int j=0; j<N; j++){
            	visit[i][j] = 0;
            }
        }
    }
    cout<<ret<<"\n";
	return 0;
}
