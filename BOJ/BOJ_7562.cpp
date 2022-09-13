// BOJ 7562번 나이트의 이동 (BFS)

#include <iostream>
#include <queue>
using namespace std;
int T, I, sx, sy, ex, ey, visit[301][301];
int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int bfs() {
	int ret = 0;
	if (sx == ex && sy == ey) return 0;
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visit[sx][sy] = 1;
	while (!q.empty()) {
		int qn = q.size();
		for (int k = 0; k < qn; k++) {
			int nx = q.front().first, ny = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int tx = nx + dx[i], ty = ny + dy[i];
				if (tx < 0 || tx >= I || ty < 0 || ty >= I)continue;
				if (tx == ex && ty == ey) return ret + 1;
				if (visit[tx][ty] == 0) {
					visit[tx][ty] = 1;
					q.push({ tx, ty });
				}
			}
		}
		ret++;
	}
	return -1;
}
int main(void)
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> I;
		cin >> sx >> sy;
		cin >> ex >> ey;
		for (int i = 0; i < I; i++)
			for (int j = 0; j < I; j++)
				visit[i][j] = 0;
		cout << bfs() << "\n";
	}

	return 0;
}
