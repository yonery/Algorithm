// BOJ 2178번 미로 탐색 (BFS)

#include <iostream>
#include <queue>
using namespace std;
int map[101][101];
int visit[101][101];
int N, M;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int bfs(){
    queue <pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()){
        int qn = q.size();
        for(int k=0; k<qn; k++){
            int nx = q.front().first, ny = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int tx = nx + dx[i], ty = ny + dy[i];
                if(tx<=0 || tx>N || ty<=0 || ty>M)
                    continue;
                else if(map[tx][ty]==1 && visit[tx][ty]==0){
                    visit[tx][ty] = visit[nx][ny] +1;
                    q.push({tx,ty});
                }
            }
        }
    }
    return visit[N][M];
}
int main(){
    	cin>>N>>M;
    	for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                char a;
                cin>>a;
                map[i][j] = (int)a-'0';
            }
        }
    	visit[1][1] = 1;
    	cout<<bfs()<<"\n";
    
    	return 0;
}
