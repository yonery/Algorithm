// BOJ 2667번 단지번호 붙이기 (DFS)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[26][26];
int N, r, ret;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<int> v;
void makem(int x, int y, int n){
    map[x][y] = n;
    r++;
    for(int i=0; i<4; i++){
        int tx = x + dx[i], ty = y +dy[i];
        if(tx<0 || tx>=N || ty<0 || ty>=N)
            continue;
        else if(map[tx][ty]==1)
            makem(tx, ty, n);
    }
    return;
}

int main(){
    	cin>>N;
    	for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                char a;
                cin>>a;
                map[i][j] = (int)a-'0';
            }
        }
    	int ret = 2;
    	for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j]==1){
                    r = 0;
                    makem(i, j, ret);
                    v.push_back(r);
                    ret++;
                }               
            }
        }
    	ret = ret-2;
    
	sort(v.begin(), v.end());
    	cout<<ret<<"\n";
    	for(int i=0; i<v.size(); i++)
            cout<<v[i]<<"\n";
    	return 0;
}


