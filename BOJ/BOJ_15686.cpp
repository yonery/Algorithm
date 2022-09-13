// BOJ 15686번 치킨 배달 (DFS)

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define INF 987654321
int map[51][51];
vector <pair<int, int>> h;
vector <pair<int, int>> c;
vector <int> cnt;
int result;
int len, siz, N, M;

void check() {
	int mini = 0, hx, hy, cx, cy;
	for (int i = 0; i < siz; i++) {
		hx = h[i].first; hy = h[i].second;
		int num = INF;
		for (int j = 0; j < len; j++) {
			int a;
			cx = c[j].first, cy = c[j].second;
			if (map[cx][cy] == 2) {
				a = abs(hx - cx) + abs(hy - cy);
				num = num < a ? num : a;

			}
		}
		mini += num;
	}
	result = result < mini ? result : mini;
	
	return;
}

void dfs(int cnt, int total, int idx) {

	//치킨 거리 계산
	if (cnt >= total) {
		check();
		return;
	}
	
	//치킨집 제거
	for (int r = idx + 1; r < len; r++) {
		int x = c[r].first, y = c[r].second;
		map[x][y] = 0;
		dfs(cnt + 1, total, r);
		map[x][y] = 2;
	}

}

int main()
{
	cin >> N >> M;
	result = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				h.push_back({ i, j });
			else if (map[i][j] == 2)
				c.push_back({ i,j });
		}
	}
	siz = h.size();
	len = c.size();

	dfs(0, len-M, -1);
	
	cout << result;
	
    return 0;
}
