// 16988 Baaaaaaaaaduk2 (Easy) (C++)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, map[21][21], visit[21][21], ret;
vector<pair<int, int>> vv;
vector<pair<int, int>> v;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int count(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[x][y] = 1;
	int num = 1;
	bool chk = true;
	while (!q.empty()) {
		int nx = q.front().first, ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i], ty = ny + dy[i];
			if (tx < 0 || tx >= N || ty < 0 || ty >= M) continue;
			if (map[tx][ty] == 0) {
				chk = false;
			}
			if (map[tx][ty] == 2 && visit[tx][ty] == 0) {
				visit[tx][ty] = 1;
				num++;
				q.push({ tx, ty });
			}
		}

	}
	if (chk) return num;
	else return 0;
}
int check() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visit[i][j] = 0;
	int ss = 0;
	for (int i = 0; i < vv.size(); i++) {
		int nx = vv[i].first, ny = vv[i].second;
		if (visit[nx][ny]==0) {
			ss += count(nx, ny);
		}
	}

	return ss;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio("false");
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				v.push_back({ i, j });
			}
			else if (map[i][j] == 2) {
				vv.push_back({ i, j });
			}
		}
	}
	
	ret = 0;
	for (int i = 0; i < v.size()-1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			map[v[i].first][v[i].second] = 1;
			map[v[j].first][v[j].second] = 1;

			int n = check();
			if (ret < n) ret = n;

			map[v[i].first][v[i].second] = 0;
			map[v[j].first][v[j].second] = 0;
		}
	}
	cout << ret << "\n";
	return 0;
}
