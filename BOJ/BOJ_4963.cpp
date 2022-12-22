// BOJ 4963 섬의 개수 (C++)

#include <iostream>
using namespace std;
int w, h, map[52][52];
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
void dfs(int x, int y, int n) {
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < 0 || tx >= h || ty < 0 || ty >= w) continue;
		if (map[tx][ty] == 1) {
			map[tx][ty] = n;
			dfs(tx, ty, n);
		}
	}
	return;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio("false");
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		int n = 2;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					map[i][j] = n;
					dfs(i, j, n);
					n++;
				}
			}
		}
		cout << n - 2 << "\n";
	}
	return 0;
}
