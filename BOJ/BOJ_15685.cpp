// 15685 드래곤 커브 (C++)
#include <iostream>
#include <vector>
using namespace std;
#define M 100
int N;
int map[101][101];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


int check() {
	int num = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1) {
				if (map[i + 1][j] == 1 && map[i + 1][j + 1] == 1 && map[i][j + 1] == 1)
					num++;
			}
		}
	}

	return num;
}

void make_m(int x, int y, int d, int g) {
	vector<int> ds;
	ds.push_back(d);
	map[x][y] = 1;
	int tx = x, ty = y;
	for (int i = 0; i < g; i++) {
		int dss = ds.size();
		while (dss--) {
			int td = (ds[dss] - 1 + 6) % 4;
			ds.push_back(td);
		}
	}

	for (int i = 0; i < ds.size(); i++) {
		tx = tx + dx[ds[i]], ty = ty + dy[ds[i]];
		map[tx][ty] = 1;
	}


	return;
}

int main()
{
	cin >> N;
	int x, y, d, g;
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			map[i][j] = 0;
	for (int i = 0; i < N; i++) {
		cin >> y >> x >> d >> g;
		make_m(x, y, d, g);
	}

	cout << check();
	return 0;
}
