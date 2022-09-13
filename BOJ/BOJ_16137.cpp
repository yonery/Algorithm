// BOJ 16137번 견우외 직녀 (BFS)
// https://www.acmicpc.net/problem/16137


/* 
처음에 개복치나 열쇠 문제처럼 시작점부터 이동 거리를 돌렸다가 시간초과남... 
갈 수 있는 곳에서부터 이전 단계로의 경우 시간 확장이 옳은 것 (경우 확장 아님)

1. 오작교를 1개 지을 수 있으니 지을 수 있는 칸을 골라 짓는다
2. bfs로 갈 수 있는 최단 시간 구하기 
3. 오작교 부수고 다른 경우의 수에 오작짓고 다시 bfs로 최단시간 구하기 
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, map[11][11], visit[11][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<pair<int, int>> b;
int Min(int a, int b){
    return a < b ? a : b;
}
bool inter(int x, int y) {
	bool hori = true, vert = true;
	if (x + 1 < N && map[x + 1][y] != 1) vert = false;
	if (x - 1 >= 0 && map[x - 1][y] != 1) vert = false;
	if (y + 1 < N && map[x][y + 1] != 1) hori = false;
	if (y - 1 >= 0 && map[x][y - 1] != 1) hori = false;
	return hori | vert;
}

int bfs() {
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			visit[i][j] = 100000;
	
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = 0;
	while (!q.empty()) {
		int nx = q.front().first, ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i], ty = ny + dy[i];
			if (tx < 0 || tx >= N || ty < 0 || ty >= N) continue;
			if (visit[tx][ty] > visit[nx][ny] + 1) {
				if (map[tx][ty] == 1) {
					visit[tx][ty] = visit[nx][ny] + 1;
					q.push({ tx, ty });
				}
				else if (map[tx][ty] > 1 && map[nx][ny] == 1) {
					visit[tx][ty] = map[tx][ty] * (visit[nx][ny] / map[tx][ty] + 1);
					q.push({ tx, ty });
				}
			}
		}
	}
	return visit[N - 1][N - 1];
}
int bridge() {
	int min = 1000000;
	for (int i = 0; i < b.size(); i++) {
		int bx = b[i].first, by = b[i].second;
		if (inter(bx, by)) {
			map[bx][by] = M;
            min = Min(min, bfs());
			map[bx][by] = 0;
		}
	}
	return min;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visit[i][j] = 100000;
			if (map[i][j] == 0)
				b.push_back({ i, j });
		}
	}
	cout << bridge() << "\n";
	return 0;
}
