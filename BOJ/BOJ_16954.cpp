// BOJ 16954번 움직이는 미로 탈출 (BFS, Simulation)

/*
벽 배열이 쌓이는게 위에 부터라는걸 생각 못 해서 틀린 문제.... 
벽의 이동을 위부터 해주면 당연히 '.' 으로 도배될텐데.... 아래부터 이동시켜줘서 PASS 했습니다.

1. 현재 위치에서 다음 시간에 욱제가 갈 수 있는 곳을 큐에 넣어줌
2. 벽을 아래부터 이동시킴
3. 큐를 꺼낼 때 욱제가 시작하는 위치가 벽이면 continue (벽 이동에 의해 갈 수 없던 곳이므로)
4. 같은 시간대에 욱제가 가는 곳을 여러 번 큐에 넣어주지 않으려고 해당 시간대에 욱제가 있을 수 있는 위치를 맵에 O로 표시해줌
 -> 1부터 반복
5.  큐 사이즈 = 0 은 욱제가 갈 수 있는 곳이 없으므로 false 
6. 큐 사이즈가 0이 아니고 벽의 갯수가 0개가 되면 욱제는 현재 미로판에 살아있지만 벽이 하나도 없는 상태이므로 당연히 목적지에 갈 수 있음 true
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char map[8][8];
int sx, sy, ex, ey, w;
int dx[] = { 0, 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 0, 1, -1, 1, -1, -1, 1 };
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	vector<pair<int, int>> v;
	w = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				w++;
				v.push_back({ i, j });
			}
		}
	}

	sx = 7, sy = 0, ex = 0, ey = 7;
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	map[sx][sy] = 'O';
	bool chk = false;
	while (1) {
		int qn = q.size();
		for (int k = 0; k < qn; k++) {
			int nx = q.front().first, ny = q.front().second;
			q.pop();
			if (map[nx][ny] == '#') continue;
			if (nx == ex && ny == ey) {
				chk = true;
				break;
			}
			map[nx][ny] = '.';
			for (int i = 0; i < 9; i++) {
				int tx = nx + dx[i], ty = ny + dy[i];
				if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8) continue;
				if(map[tx][ty] == '.'){
					q.push({ tx, ty });
					map[tx][ty] = 'O';
				}
			}
		}
		if (chk) break;
		if (q.size() == 0) {
			chk = false;
			break;
		}
		else if (w == 0) {
			chk = true;
			break;
		}
		else {
			for (int i = v.size()-1; i >= 0; i--) {
				if (v[i].first != -1 ) {
					map[v[i].first][v[i].second] = '.';
					v[i].first+=1;
					if (v[i].first < 8) {
						map[v[i].first][v[i].second] = '#';
					}
					else{
						v[i].first = v[i].second = -1;
						w--;
					}
				}
			}
		}
	}
	if (chk) cout << "1\n";
	else cout << "0\n";
	
	return 0;
}
