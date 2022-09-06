// SWEA 2112번 보호 필름

#include <iostream>
using namespace std;
int D, W, K;
int map[13][20];
bool res;
int max(int a, int b) {
	return a >= b ? a : b;
}
bool chk() {
	for (int j = 0; j < W; j++) {
		int n = 1, m = map[0][j], num = 0;
		for (int i = 1; i < D; i++) {
			if (m == map[i][j]) {
				n++;
				if (i == (D - 1))
					num = max(num, n);
			}
			else {
				num = max(num, n);
				n = 1;
				m = map[i][j];
			}
		}
		if (num < K)
			return false;
	}

	return true;
}

void dfs(int tot, int cnt, int idx, int visit) {
	if (tot == cnt) {
		if(!res)
			res = chk();
		return;
	}

	if (!res) {
		int a[20];
		for (int i = idx; i < D; i++) {
			if ((visit&(1 << i)) == 0) {
                for (int j = 0; j < W; j++){
                    a[j] = map[i][j];
                    map[i][j] =0;
                }
				dfs(tot, cnt + 1, i+1, visit | (1 << i));
				for (int j = 0; j < W; j++)
					map[i][j] = 1;
				dfs(tot, cnt + 1, i+1, visit | (1 << i));
                for(int j=0; j<W; j++)
                    map[i][j] = a[j];
			}
		}
	}
	return;
}


//backtracking
int play() {
	int ret = 0;
	res = chk();
	if (res == true)
		return ret;

	while (!res) {
		ret++;
		dfs(ret, 0, 0, 0);
		if (res == true)
			return ret;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> D >> W >> K;
		res = false;
		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				map[i][j] = 0;

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		cout << "#" << t << " " << play() << "\n";

	}
	return 0;
}
