// BOJ 17135번 캐슬 디펜스

/*
자꾸 맵 백업하는거 까먹어서 시간 까먹은 문제.

1. 궁수가 올 수 있는 3자리 조합 맞추기
2. 3명의 궁수가 쏠수 있는 적중에 가장 가깝고 가장 왼쪽인 적 쏘기
3. 쏜 적 만큼 남은 적 줄이기
4. 맵 이동해서 사라진 적만큼 남은 적 수 줄이기
5. 맵에 남아있는 적의 수가 0이 될때까지 반복 


=> 재채점해서 틀렸는데 배열 범위 수정해줘서 맞았습니다.... 진리의 맞왜틀.... 
 런타임 에러 안 나서 설마했는데 배열 범위 문제였어요 ㅠㅠ
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N, M, D, map[17][16], tmp[17][16], n, ret;
vector<pair<int, int>> vec, v;
int chg() {
	int num = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i].first != -1) {
			map[v[i].first][v[i].second] = 0;
			v[i].first++;
			if (v[i].first == N) {
				v[i].first = v[i].second = -1;
				num++;
			}
			else
				map[v[i].first][v[i].second] = 1;
		}
	}
	return num;
}
int chk(int visit) {
	int arrow[3], target[3];
	int adx = 0, enemy = n, remove = 0;
	for (int i = 0; i < M; i++) {
		if ((visit&(1 << i)) > 0)
			arrow[adx++] = i;
	}
    v = vec;
	while (enemy > 0) {
		for (int a = 0; a < 3; a++) {
			int ay = arrow[a], ax = N;
			// 적들을 모두 검색하여 제일 가까운애
			int bx = 100, by = 100, bidx = -1, min = 10000;
			for (int i = 0; i < v.size(); i++) {
				if (v[i].first != -1) {
					int d = abs(ax - v[i].first) + abs(ay - v[i].second);
					if (d <= D && d <= min) {
						if (d == min) {
							if (v[i].second < by) {
								bx = v[i].first, by = v[i].second, bidx = i;
							}
						}
						else {
							min = d, bx = v[i].first, by = v[i].second, bidx = i;
						}
					}
				}
			}
			target[a] = bidx;
		}
		for (int a = 0; a < 3; a++) {
			if (target[a] != -1) {				
				if (map[v[target[a]].first][v[target[a]].second] == 1) {
					map[v[target[a]].first][v[target[a]].second] = 0;
					remove++;
					enemy--;
				}
				v[target[a]].first = v[target[a]].second = -1;
			}
		}
		enemy -= chg();
	}
	return remove;
}
void copy(int(*arr1)[16], int(*arr2)[16]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			arr1[i][j] = arr2[i][j];
	}
	return;
}
void dfs(int idx, int cnt, int vit) {
	if (cnt == 3) {
		copy(map, tmp);
		int m = chk(vit);
		if (ret < m) ret = m;
		return;
	}
	if (idx == M) return;
	dfs(idx + 1, cnt + 1, vit | (1 << idx));
	dfs(idx + 1, cnt, vit);
	return;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> N >> M >> D;
	n = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp[i][j];
			if (tmp[i][j] == 1) {
				vec.push_back({ i, j });
				n++;
			}
		}
	}
	ret = 0;
	dfs(0, 0, 0);
	cout << ret << "\n";
	return 0;
}
