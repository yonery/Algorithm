// BOJ 16197번 두 동전 

#include <iostream>
#include <queue>
using namespace std;
int N, M, ax, ay, bx, by;
char map[20][20];

int dx[] = { 0,0, 1, -1 };
int dy[] = { 1, -1,0, 0 };
int disc[20][20][20][20] = { 0 };

int bfs() {
	int ret = 0;
	int res = 0;
	queue <pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {ax, ay}, {bx, by} });
	while (ret<10) {
		if (ret > 10)
			return - 1;
		ret++;
		int qs = q.size();
		while (qs--) {
			auto now = q.front();
			ax = now.first.first, ay = now.first.second,
				bx = now.second.first, by = now.second.second;
			disc[ax][ay][bx][by] = 1;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int n = 0;
				int tx1 = ax + dx[i], ty1 = ay + dy[i];
				int tx2 = bx + dx[i], ty2 = by + dy[i];
				if (tx1<0 || tx1==N || ty1<0 || ty1==M) {
					n++;
				}
				if (tx2 < 0 || tx2 == N || ty2 < 0 || ty2 == M) {
					n++;
				}
				if (n != 0) {
					if (n == 1)
						return ret;
					continue;
				}
				else{
					if (map[tx1][ty1] != '.')
						tx1 = ax, ty1 = ay;
					if (map[tx2][ty2] != '.')
						tx2 = bx, ty2 = by;
					//같은 위치
					if (tx1 == tx2 && ty1 == ty2) {
						tx1 = ax, ty1 = ay,
							tx2 = bx, ty2 = by;
					}
					if(disc[tx1][ty1][tx2][ty2]==0)
						q.push({ {tx1, ty1},{tx2, ty2} });
				}

			}

		}	
		
	}
	return -1;
}


int main()
{
	cin >> N >> M;
	ax = -1, ay = -1, bx = -1, by = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') {
				if (ax < 0) {
					ax = i, ay = j;
					map[i][j] = '.';
				}
				else {
					bx = i, by = j;
					map[i][j] = '.';
				}
			}
		}
	}
	cout << bfs();
	return 0;
}
