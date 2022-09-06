// SWEA 3289번 서로소 집합 (Union Find)

#include <iostream>
#define swap(a, b) { int t = a, a = b, b = t; }
using namespace std;
int T, n, m, x, y, z, parent[1000001], level[1000001];
int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (level[x] > level[y]) swap(x, y);
	parent[x] = y;
	if (level[x] == level[y])
		++level[y];
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> T;
	for (int t = 1; t <= T; t++) {	
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			parent[i] = i, level[i] = 1;
		cout<<"#"<<t<<" ";
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> z;
			if (x == 0) {
				Union(y, z);
				
			}
			else if (x == 1) {
				y = Find(y);
				z = Find(z);
				if (y == z) cout << "1";
				else cout << "0";
			}
		}
        cout<<"\n";
	}
	return 0;
}
