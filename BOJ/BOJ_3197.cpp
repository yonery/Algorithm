// BOJ 3197번 백조의 호수 (BFS)

/*
백조만 가지고 계속 맵 바꿔가면서 BFS 했더니 시간 초과~~~ 
물의 경계면에서 백조를 출발시켰줬더니 메모리 초과~~~


1. 물을 확장시켜줌 -> wit으로 이미 퍼진 물 자리는 가지 않음
2. 백조가 갈 수 있는 거리를 visit 로 매 시간마다 기록
3. 다른 백조가 있는 자리에 도달하면 끝남

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int R, C, sx, sy, ex, ey;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char map[1501][1501];
int visit[1501][1501], wit[1501][1501];
queue<pair<int, int>> w, q, tq;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");

	cin >> R >> C;
	sx = sy = ex = ey = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'L') {
				map[i][j] = '.';
				if (sx == -1) {
					sx = i, sy = j;
				}
				else {
					ex = i, ey = j;
				}
			}
			if (map[i][j] == '.') {
				w.push({ i, j });
				wit[i][j] = 1;
			}
		}
	}
	q.push({ sx, sy });
	visit[sx][sy] = 1;
	int ans = 0;
	while (!visit[ex][ey]) {
		while (!q.empty()) {
			tq.push(q.front());
			q.pop();
		}
		int tn = w.size();
		for (int k = 0; k < tn; k++) {
			int nx = w.front().first, ny = w.front().second;
			w.pop();
			map[nx][ny] = '.';
			for (int i = 0; i < 4; i++) {
				int tx = nx + dx[i], ty = ny + dy[i];
				if (tx < 0 || tx >= R || ty < 0 || ty >= C || wit[tx][ty]) continue;
				wit[tx][ty] = 1;
				w.push({ tx, ty });
			}
		}
		while (!tq.empty()) {
			int nx = tq.front().first, ny = tq.front().second;
			tq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nx + dx[i], ty = ny + dy[i];
				if (tx < 0 || tx >= R || ty < 0 || ty >= C || visit[tx][ty]) continue;
				visit[tx][ty] = 1;
				if (map[tx][ty] == 'X') {
					q.push({ tx, ty });
				}
				else if (map[tx][ty] == '.') {
					tq.push({ tx, ty });
				}
			}
		}
		ans++;
	}
	cout << ans -1 << "\n";
	return 0;
}
