// BOJ 17136번 색종이 붙이기 

#include <iostream>
#include <vector>
using namespace std;
int result, n, ori[10][10], arr[5];
vector<pair<int, int>> v;
bool chk(int n, int x, int y, int (*map)[10]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tx = x + i, ty = y + j;
			if (tx < 0 || tx >= 10 || ty < 0 || ty >= 10 || map[tx][ty] == 0) return false;
		}
	}
	return true;
}
void copy(int(*arr1)[10], int(*arr2)[10]) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			arr1[i][j] = arr2[i][j];
}
void dfs(int idx, int cnt, int room, int (*tmp)[10]) {
    if(cnt > result) return;
	if (room == 0) {
		//cout << "--- " << result << " " << cnt << "\n";
		if (cnt < result) result = cnt;
		return;
	}
	if (idx == v.size()) return;
	int nx = v[idx].first, ny = v[idx].second;
	if (tmp[nx][ny] == 0) {
		dfs(idx + 1, cnt, room, tmp);
	}
	else{
		int map[10][10];
		copy(map, tmp);
		if (arr[4] < 5 && chk(5, nx, ny, map)) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					map[nx + i][ny + j] = 0;
				}
			}
			arr[4]++;
			dfs(idx + 1, cnt + 1, room - (5*5), map);
			arr[4]--;
		}
		copy(map, tmp);
		if (arr[3]<5 && chk(4, nx, ny, map)) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map[nx + i][ny + j] = 0;
				}
			}
			arr[3]++;
			dfs(idx + 1, cnt + 1, room - (4 * 4), map);
			arr[3]--;
		}
		copy(map, tmp);
		if (arr[2]<5 && chk(3, nx, ny, map)) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					map[nx + i][ny + j] = 0;
				}
			}
			arr[2]++;
			dfs(idx + 1, cnt + 1, room - (3 * 3), map);
			arr[2]--;
		}
		copy(map, tmp);
		if (arr[1] < 5 && chk(2, nx, ny, map)) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					map[nx + i][ny + j] = 0;
				}
			}
			arr[1]++;
			dfs(idx + 1, cnt + 1, room - (2 * 2), map);
			arr[1]--;
		}
		copy(map, tmp);
		if (arr[0] < 5) {
			map[nx][ny] = 0;
			arr[0]++;
			dfs(idx + 1, cnt + 1, room - (1 * 1), map);
			arr[0]--;
		}
	}
	return;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	n = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> ori[i][j];
			if (ori[i][j] == 1) {
				v.push_back({ i, j });
				n++;
			}
		}
	}

	if (v.size() == 0) result = 0;
	else {
		result = 100000;
		dfs(0, 0, n, ori);
		if (result == 100000) result = -1;
	}
	cout << result << "\n";
	return 0;
}
