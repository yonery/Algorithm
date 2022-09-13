// BOJ 1600번 말이 되고픈 원숭이 (BFS)

/*
단순 bfs지만 말로서 움직일 수 있는 기회에 따라 visit값을 변화주어야한다는 점에서 한 번 더 생각할 필요가 있던 문제였습니다.
단순히 visit 배열의 true, false로 표시해준다면 기회에 따라 도착할 수 있는 순간이 여러번인데 그것을 다 카운트하지 못 하게 됩니다.

1. 원숭이가 말로서 갈 수 있는 기회  + 현재 좌표를 큐에 push
2. visit 배열로 기회의 횟수를 비교해서 방문 체크
3. bfs 최단거리 구하기
*/

#include <iostream>
#include <queue>
using namespace std;
int K, W, H, map[201][201], visit[201][201][31];
int hx[] = { -1, -2, -2, -1, 1, 2, 2, 1};
int hy[] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dx[] = { 1, -1, 0 , 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs() {
	int ret = 1;
	queue<pair<int, pair<int,int>>> q;
	q.push({ K, { 0,0 } });
	visit[0][0][K] = 1;
	while (!q.empty()) {
		int qn = q.size();
		for (int k = 0; k < qn; k++) {
			int nk = q.front().first, nx = q.front().second.first, ny = q.front().second.second;
			q.pop();
			if (nk > 0) {
				for (int j = 0; j < 8; j++) {
					int thx = nx + hx[j], thy = ny + hy[j];
					if (thx < 0 || thx >= H || thy < 0 || thy >= W) continue;
					if (thx == H - 1 && thy == W - 1) return ret;
					if (visit[thx][thy][nk-1] == 0 && map[thx][thy]==0) {
						q.push({ nk - 1, {thx, thy} });
						visit[thx][thy][nk-1] = 1;
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				int tx = nx + dx[i], ty = ny + dy[i];
				if (tx < 0 || tx >= H || ty < 0 || ty >= W) continue;
				if (tx == H - 1 && ty == W - 1) return ret;
				if (visit[tx][ty][nk] == 0 && map[tx][ty]==0) {
					q.push({ nk, { tx,ty } });
					visit[tx][ty][nk] = 1;
				}
			}
		}
		ret++;
	}

	return -1;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	cout << bfs() << "\n";
	return 0;
}
