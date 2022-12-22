// 1012 유기농 배추 (C++)

#include <iostream>
using namespace std;
int map[51][51] = { 0 };

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int M, N, K;

void dfs(int x, int y) {
	map[x][y] = 2;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < 0 || tx >= N || ty < 0 || ty >= M)
			continue;
		else if (map[tx][ty] == 1)
			dfs(tx, ty);
	}
	return;
}
void chk() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> M >> N >> K;

		for (int i = 0; i <= N; i++) 
			for (int j = 0; j <= M; j++)
				map[i][j] = 0;
		

		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> b >> a;
			map[a][b] = 1;
		}

		int res = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					res++;
					dfs(i, j);
				}
			}
		}


		cout << res << endl;
	}
	return 0;
}
