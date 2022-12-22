// BOJ 1941 소문난 칠공주 (C++)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
char map[5][5];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<int> v;


void dfs(int cnt, int yy, int visit) {
	if (yy > 3)
		return;
	if (cnt == 7) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == visit)
				return;
		}
		v.push_back(visit);
		return;
	}
	for (int k = 0; k < 25; k++) {
		if ((visit&(1 << k)) > 0) {
			int nx = k / 5, ny = k % 5;

			for (int i = 0; i < 4; i++) {
				int tx = nx + dx[i], ty = ny + dy[i];
				int idx = (5 * tx) + ty;
				if (tx < 0 || tx == 5 || ty < 0 || ty == 5)
					continue;
				if ((visit&(1 << idx)) == 0) {
					if (map[tx][ty] == 'Y')
						dfs(cnt + 1, yy + 1, visit | (1 << idx));
					else
						dfs(cnt + 1, yy, visit | (1 << idx));

				}
			}

		}
	}
	
	return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio("false");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (map[i][j] == 'S') {
				int idx = (5 * i) + j;
				dfs(1, 0, (1<<idx));
			}
		}
	}
	cout << v.size() << "\n";
	return 0;
}
