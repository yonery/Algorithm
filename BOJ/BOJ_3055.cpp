// BOJ 3055번 탈출 (BFS)

/*
 -> BFS 최단거리를 구해주되, 물이 확장되는 상태를 계속 적용시켜줘야함
 -> 고슴도치가 물이 다음 시간에 확장되는 곳은 이동하지 못 하므로 물을 먼저 확장시켜주면 고슴도치 경로 확인 
 -> 간단한 시뮬레이션에 대한 이해를 넣은 BFS.... ??
*/

#include <iostream>
#include <queue>
using namespace std;
int R, C, sx, sy, visit[51][51];
char map[51][51];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
queue<pair<int, int>> w;
int bfs() {
	int ret = 0;
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visit[sx][sy] = 1;
	while (!q.empty()) {
		int wn = w.size();
		for (int k = 0; k < wn; k++) {
			int wx = w.front().first, wy = w.front().second;
			w.pop();
			for (int i = 0; i < 4; i++) {
				int tx = wx + dx[i], ty = wy + dy[i];
				if (tx < 0 || tx >= R || ty < 0 || ty >= C) continue;
				if (map[tx][ty] == '.') {
					map[tx][ty] = '*';
					w.push({ tx, ty });
				}
			}
		}
		int qn = q.size();
		for (int k = 0; k < qn; k++) {
			int nx = q.front().first, ny = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nx + dx[i], ty = ny + dy[i];
				if (tx < 0 || tx >= R || ty < 0 || ty >= C) continue;
				if (map[tx][ty] == 'D') return ret+1;
				if (map[tx][ty] == '.' && visit[tx][ty] == 0) {
					visit[tx][ty] = 1;
					q.push({ tx, ty });
				}
			}
		}
		ret++;
	}

	return 0;
}

int main(){
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				sx = i, sy = j;
				map[i][j] = '.';
			}
			if (map[i][j] == '*') {
				w.push({ i, j });
			}
		}
	}
	int ret = bfs();
	if (ret == 0) 
		cout << "KAKTUS\n";
	else {
		cout << ret << "\n";
	}

	return 0;
}
