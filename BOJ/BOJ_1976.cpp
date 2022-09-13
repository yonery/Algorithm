// BOJ 1976번 여행 가자 (Union find)
// 유니온 파인드로 인접 국가까리 서로소집합을 만들어주고 서로의 루트 노드를 비교해주었음 

#include <iostream>
#include <vector>
#define swap(a, b) { int t = a; a=b; b=t; }
using namespace std;
int map[201][201], parent[201], level[201];
int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (level[x] > level[y])
		swap(x, y);
	// x의 루트가 y가 되도록
	parent[x] = y;
	if (level[x] == level[y])
		++level[y];
}
int main() {
	int n, m;
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		parent[i] = i, level[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) Union(i, j);
		}
	}

	int ret = 0, a;
	bool chk = true;
	for (int i = 0; i < m; i++) {
		cin >> a;
		a = Find(a);
		if (ret == 0) {
			ret = a;
		}
		else {
			if (ret != a) chk = false;
		}
	}
	if (chk) cout << "YES";
	else cout << "NO";
	return 0;
}
