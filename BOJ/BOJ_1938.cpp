// BOJ 1938번 통나무 옮기기 (BFS)

#include <iostream>
#include <queue>
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1};
int N, bd, bx, by, ed, ex, ey, visit[2][51][51];
char map[51][51];
// dir : 0 가로 , 1 세로

int bfs(){
	int ret = 0;
    queue <pair<int, pair<int,int>>> q;
    q.push({bd, {bx, by}});
	visit[bd][bx][by] = 1;
    
	while(!q.empty()){
        int qn = q.size();
        for(int k=0; k<qn; k++){
        	int nd = q.front().first, nx = q.front().second.first, ny = q.front().second.second;
            q.pop();
            if(nd==ed && nx==ex && ny==ey)
                return ret;
            
            int tmp[3][2];
            if(nd==0){
                tmp[0][0] = nx, tmp[0][1] = ny;
                tmp[1][0] = nx, tmp[1][1] = ny + 1;
                tmp[2][0] = nx, tmp[2][1] = ny - 1;
            }
            else if (nd==1){
                tmp[0][0] = nx, tmp[0][1] = ny;
                tmp[1][0] = nx - 1, tmp[1][1] = ny;
                tmp[2][0] = nx + 1, tmp[2][1] = ny;
            }
            //4방향 검사
            for(int i=0; i<4; i++){              
                bool chk = true;
                int tx, ty;
                for(int m =0; m<3; m++){
                    tx = tmp[m][0] + dx[i], ty = tmp[m][1] + dy[i];
                    if(tx<=0 || tx>N || ty<=0 || ty>N){
                        chk = false;
                        break;
                    }
					if(map[tx][ty] =='1'){
                    	chk = false;
                        break;
                    }
                }
                tx = nx +dx[i], ty = ny + dy[i];
                if(chk==true && visit[nd][tx][ty] ==0){
                    q.push({nd,{tx, ty}});
                    visit[nd][tx][ty] = 1;
                    //cout<<nd<<nx<<ny<<"->"<<nd<<tx<<ty<<"\n";
                }              
            }
            
            //회전
            bool chk = true;            
            for(int i=0; i<8; i++){
                int tx = nx + dx[i], ty = ny + dy[i];
                if(tx <=0 || tx>N || ty<=0 || ty>N){
                    chk = false;
                    break;
                }
                if(map[tx][ty] =='1'){
                	chk = false;
                    break;
                }
            }
            int td;
            if(nd) td = 0;
            else td = 1;
            if(chk==true && visit[td][nx][ny]==0){
                q.push({td, {nx, ny}});
                visit[td][nx][ny] = 1;
                //cout<<nd<<nx<<ny<<"->"<<td<<nx<<ny<<"t\n";
            }     
            
        }
        ret++;
    }  
    return 0;
}

int main(){
	cin>>N;
    int BBB[3][2], EEE[3][2];
    int b = 0, e = 0;
    for(int i=1; i<=N; i++){
    	for(int j=1; j<=N; j++){
        	cin>>map[i][j];
            if(map[i][j]=='B'){
                bx += i, by += j;
                BBB[b][0] = i, BBB[b][1] = j;
                b++;
            }
            if(map[i][j] =='E'){               
                ex += i, ey += j;
                EEE[e][0] = i, EEE[e][1] = j;
                e++;
            }
        }
    }
    bx = bx/3, by = by/3, ex = ex/3, ey = ey/3;
    if(BBB[0][0] == BBB[1][0] && BBB[1][0] && BBB[2][0])
       bd = 0;
    else
       bd = 1;
    if(EEE[0][0] == EEE[1][0] && EEE[1][0] && EEE[2][0])
       ed = 0;
    else
       ed =1;
    //cout<<bd<<bx<<by<<ed<<ex<<ey<<"\n";
    cout<<bfs()<<"\n";
    return 0;
}
