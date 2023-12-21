// 15684 사다리 조작 (C++)

#include <iostream>
#include <vector>
using namespace std;
int N, M, H, a, b, map[32][12], ret, tmp[32][12];
bool result = false;
vector<pair<int, int>> v;

bool chk() {
	for (int j = 1; j <= N; j++) {
		int x = 0, y = j;
		while (x <= H) {
			x++;
			if (map[x][y]) {
				y++;
			}
			else if (map[x][y - 1]) {
				y--;
			}
		}
		if (j != y) return false;
	}
	return true;
}
void dfs(int x, int y, int cnt, int total) {
	if (result) return;
	if (cnt == total) {
		result = chk();
		return;
	}
    for(int i=x; i<=H; i++){
        for(int j=1; j<N; j++){
            if(i==x && j==y) continue;
            if(map[i][j-1]||map[i][j]||map[i][j+1]) continue;
            map[i][j] =1;
            dfs(i, j, cnt+1, total);
            map[i][j] = 0;
        }
    }	
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio("false");
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}

	if (M == 0) {
		cout << "0\n";
	}
	else {

		int num = 0;
		for (num = 0; num <= 3; num++) {
			dfs(1, 1, 0, num);
			if (result) break;
		}
		if (result) cout << num << "\n";
		else cout << "-1\n";

	}
	return 0;
}
