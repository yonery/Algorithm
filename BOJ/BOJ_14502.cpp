// 14502 연구소 (C++)

#include <iostream>
#include <vector>
using namespace std;
int N, M, map[9][9], ret, remap[9][9], visit[9][9];
vector<pair<int, int>> v;
vector<pair<int, int>> w;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < 0 || tx >= N || ty < 0 || ty >= M || remap[tx][ty]==1) continue;
		if (remap[tx][ty] == 0) {
			remap[tx][ty] = 2;
			virus(tx, ty);
		}
	}
	return;
}
int chk() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			remap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < v.size(); i++) {
		virus(v[i].first, v[i].second);
	}
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (remap[i][j] == 0)
				num++;
		}
	}
	return num;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		int num = chk();
		if (ret < num) ret = num;
		return;
	}
	if (idx == w.size()) return;
	else {
		map[w[idx].first][w[idx].second] = 1;
		dfs(idx + 1, cnt + 1);
		map[w[idx].first][w[idx].second] = 0;
		dfs(idx + 1, cnt);
	}
	return;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio("false");
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i, j });
			}
			else if (map[i][j] == 0) {
				w.push_back({ i, j });
			}
		}
	}

	dfs(0, 0);
	cout << ret << "\n";
	return 0;
}

