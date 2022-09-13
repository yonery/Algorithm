// BOJ 10026번 적록색약 (DFS)

#include <iostream>
using namespace std;
int N;
char map[100][100];
int visit[100][100];
int dx[] = { 0, 0, -1, 1};
int dy[] = { 1, -1, 0, 0};

void print(){
	for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
        	cout<<visit[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}
int chk(char mark){
	if(mark=='R')
        return 1;
    else if(mark=='B')
        return 2;
    else
    	return 3;
}
void dfs(int x, int y, char mark){
	for(int i=0; i<4; i++){
        int tx = x +dx[i], ty = y +dy[i];
        if(tx<0 || tx>=N || ty<0 || ty>=N)
            continue;
        if(visit[tx][ty] == 0 && map[tx][ty]==mark){
        	visit[tx][ty] = chk(mark);
            dfs(tx, ty, mark);
        }
    }
    return;
}

int main(){
	cin>>N;
    for(int i=0; i<N; i++){
    	for(int j=0;j<N;j++){
        	cin>>map[i][j];
        }
    }
    int x = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
        	if(visit[i][j] ==0){
                dfs(i, j, map[i][j]);
                x++;
            }
        }
    }
    //print();
    
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visit[i][j] = 0;
            if(map[i][j] == 'G')
                map[i][j] = 'R';
        }
    }
   int y = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
        	if(visit[i][j] ==0){
                dfs(i, j, map[i][j]);
                y++;
            }
        }
    }
    cout<<x-1<<" "<<y-1<<"\n";    
    return 0;
}
​
