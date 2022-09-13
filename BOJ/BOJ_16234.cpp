// BOJ 16234번 인구 이동 (Simulation)


/*
간단한 구현문제, 단지번호 붙이기를 응용해서 같은 단지 내의 인구의 수를 맞춰주고 움직인 인구가 없거나, 한번에 통합되면 종료해주었습니다.

1. 현재 위치에서 인접해있는 L과 R 사이의 국가들을 같은 단지 번호를 붙여주면서 확장 
2. 확장 시키면서 획득한 총 인구수와 국가 갯수로 이어진 단지가 2개 이상이면 평균 인구로 만들어줌
3. crush==0 이라는 것은 인접한 단지중에 인구이동이 없었다는 것이기에 종료  (합쳐진 횟수를 안 세줘도 되기에 ret은 증가시키지 않음)
    / chk 를 true로 만들어준 것은 전체 인구가 한번에 통합된 것이 있었다는 것으로 종료 (합쳐진 횟수를 세줘야 하기에 ret++)
*/

#include <iostream>
#include <cmath>
using namespace std;
int N, L, R, map[51][51], visit[51][51], cnt;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int makem(int x, int y, int m) {
	int sum = map[x][y];
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < 0 || tx >= N || ty < 0 || ty >= N )continue;
		else if (visit[tx][ty]==0 && abs(map[x][y] - map[tx][ty]) >= L && abs(map[x][y] - map[tx][ty]) <= R) {
			visit[tx][ty] = m;
			cnt++;
			sum += makem(tx, ty, m);
		}
	}
	return sum;
}

void divm(int x, int y, int n, int m) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < 0 || tx >= N || ty < 0 || ty >= N ) continue;
		else if (visit[tx][ty] ==m) {
			map[tx][ty] = n;
			visit[tx][ty] = -1;
			divm(tx, ty, n, m);
		}
	}
	return;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int ret = 0;
	bool chk = false;
	while (!chk) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visit[i][j] = 0;

		int m = 0, crush = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0) {
					m++;
					cnt = 1;
					visit[i][j] = m;
					int sum = makem(i, j, m);
					if (cnt > 1) {
						crush++;
						int avg = sum / cnt;
						map[i][j] = avg;
						visit[i][j] = -1;
						divm(i, j, avg, m);
						if (cnt == N * N)
							chk = true;
					}
				}
			}
		}

		if (crush==0) break;
		else	ret++;
		if (chk) break;

	}
	cout << ret << "\n";
	return 0;
}
