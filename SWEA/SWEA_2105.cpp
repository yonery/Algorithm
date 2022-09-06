// SWEA 2105번 디저트카페 (DFS)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int res, N, sx, sy;
int map[21][21];

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, -1, 1};

void dfs(int x, int y, int dir, int now, vector<int> q) {
	vector<int> tq;
	for (int i = 0; i < q.size(); i++)
		tq.push_back(q[i]);

	if (dir == 4 && x == sx && y == sy) {
		res = res > now ? res : now;
		return;
	}

	for (int i = 1; i < N; i++) {
		int tx = x + (i*dx[dir]), ty = y + (i*dy[dir]);
		if (tx<1 || tx>N || ty<1 || ty>N)
			return;
		int item = map[tx][ty];

		if (tx == sx && ty == sy) {
			dfs(sx, sy, dir + 1, now + i, tq);
			return;
		}
		if (tq.end() != find(tq.begin(), tq.end(), item))
			return;
		
		tq.push_back(item);
        if(dir<3)
			dfs(tx, ty, dir + 1, now + i, tq);

	}
	return;
}
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for(int i=0; i<=N; i++)
            for(int j=1; j<=N; j++)
                map[i][j] =0;
		res = -1;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		vector <int> q;
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				int item = map[i][j];
				q.push_back(item);
				sx = i, sy = j;
				dfs(i, j, 0, 0, q);
				q.pop_back();
			}
		}



		cout << "#" << t << " " << res << "\n";
	}
	return 0;
}
