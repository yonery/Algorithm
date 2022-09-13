// BOJ 2206번 벽 부수고 이동하기 (BFS)
/*
*시간먹는 예외발견 : 같은 자리에 도달했을 때, 
벽을 안 부신 애가 지나갈 경우 더 많은 경로 이용 가능한데,  
visit 체크로 풀면 벽을 부신 애가 선점해서 안 부신 애가 접근하지를 않음. 
그래서 visit 0 ,1 , 2로 상태를 나눠서 안 부신 애는 부신 애보다 우선순위를 두어 처리 .
*/



#include <iostream>
#include <queue>
using namespace std;
int N, M;
int map[1001][1001], visit[1001][1001];
int dx[] = { 0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0};

int bfs(){
    int ret = 1;
    queue<pair<pair<int,int>, int>>  q;
    q.push({{1,1}, 2});
    visit[1][1] = ret;
    while(!q.empty()){
        int qn = q.size();
        for(int k=0; k<qn; k++){
            int nx = q.front().first.first, ny = q.front().first.second, nk = q.front().second;
            q.pop();
           // cout<<nx<<" "<<ny<<"->";
            if(nx ==N && ny==M)
                return ret;
            for(int i=0; i<4; i++){
                int tx = nx + dx[i], ty = ny + dy[i];
                if(tx<=0 || tx>N || ty<=0 || ty> M)
                    continue;
                if(map[tx][ty] == 0){
                    if(visit[tx][ty] == 0){
                    	visit[tx][ty] = nk;
                        q.push({{tx, ty}, nk});
                    }
                    else if (nk==2 && visit[tx][ty] ==1){
                        visit[tx][ty] = nk;
                        q.push({{tx,ty}, nk});
                    }
                }
                else if(nk ==2){
                    visit[tx][ty] = 1;
                    q.push({{tx,ty}, 1});
                }

                    // 벽을 부시지 않았는데 도달하는 경우가 우선순위
                    // 0 : 안 지나감, 1 : 부신애가 지나감, 2 :  안 부신애가 지나감
      				//error : 이미 벽을 부신애가 지나간 자리를 안 부신 애가 접근하지 않음.. visit에 변화된 값주기      
            }
        }
        ret++;
    }
    return -1;
}

int main(){
	cin>>N>>M;
    for(int i=1; i<=N; i++){
    	for(int j=1; j<=M; j++){
        	char a;
            cin>>a;
            map[i][j] = (int)(a-'0');
        }
    }
    cout<<bfs()<<"\n";
    return 0;
}
