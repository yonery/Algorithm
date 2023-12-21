// 15683 감시 (C++)

#include <iostream>
#include <vector>
using namespace std;
int N, M, map[9][9], ret;
vector<pair<int, int>> v;

void up(int x, int y) {
	int tx = x, ty = y;
	while (map[tx][ty] != 6 && tx >= 0) {
		if (map[tx][ty] == 0) 
			map[tx][ty] = 9;
		tx--;
	}
	return;
}
void down(int x, int y) {
	int tx = x, ty = y;
	while (map[tx][ty] != 6 && tx < N) {
		if (map[tx][ty] == 0)
			map[tx][ty] = 9;
		tx++;
	}
	return;
}
void rit(int x, int y) {
	int tx = x, ty = y;
	while (map[tx][ty] != 6 && ty < M) {
		if (map[tx][ty] == 0)
			map[tx][ty] = 9;
		ty++;
	}
	return;
}
void lef(int x, int y) {
	int tx = x, ty = y;
	while (map[tx][ty] != 6 && ty >= 0) {
		if (map[tx][ty] == 0)
			map[tx][ty] = 9;
		ty--;
	}
	return;
}

void copy(int arr1[][9] , int arr2[][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
	return;
}
void dfs(int idx) {	
	if (idx == v.size()) {
		int num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					num++;
			}
		}
		if (ret > num) ret = num;
		return;
	}
	int remap[9][9];
    
	// 이전 맵 기억
	copy(remap, map);
	
	int nx = v[idx].first, ny = v[idx].second;
	if (map[nx][ny] == 1) {
		up(nx, ny);
		dfs(idx + 1);
		copy(map, remap);


		down(nx, ny);
		dfs(idx + 1);
		copy(map, remap);

		lef(nx, ny);
		dfs(idx + 1);
		copy(map, remap);

		rit(nx, ny);
		dfs(idx + 1);
		copy(map, remap);
	}
	else if (map[nx][ny] == 2) {
		up(nx, ny);
		down(nx, ny);
		dfs(idx + 1);
		copy(map, remap);

		lef(nx, ny);
		rit(nx, ny);
		dfs(idx + 1);
		copy(map, remap);
	}
	else if (map[nx][ny] == 3) {
		up(nx, ny);
		rit(nx, ny);
		dfs(idx + 1);
		copy(map, remap);

		up(nx, ny);
		lef(nx, ny);
		dfs(idx + 1);
		copy(map, remap);

		down(nx, ny);
		rit(nx, ny);
		dfs(idx + 1);
		copy(map, remap);

		down(nx, ny);
		lef(nx, ny);
		dfs(idx + 1);
		copy(map, remap);
	}
	else if (map[nx][ny] == 4) {
		up(nx, ny);
		rit(nx, ny);
		lef(nx, ny);
		dfs(idx + 1);
		copy(map, remap);

		up(nx, ny);
		rit(nx, ny);
		down(nx, ny);
		dfs(idx + 1);
		copy(map, remap);

		rit(nx, ny);
		down(nx, ny);
		lef(nx, ny);
		dfs(idx + 1);
		copy(map, remap);

		down(nx, ny);
		lef(nx, ny);
		up(nx, ny);
		dfs(idx + 1);
		copy(map, remap);
	}
	else if (map[nx][ny] == 5) {
		up(nx, ny);
		down(nx, ny);
		lef(nx, ny);
		rit(nx, ny);
		dfs(idx + 1);
		copy(map, remap);
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
			if (map[i][j] > 0 && map[i][j] < 6)
				v.push_back({ i, j });
		}
	}
	ret = 1000001;
	dfs(0);
	cout<<ret<<"\n";
	return 0;
}

