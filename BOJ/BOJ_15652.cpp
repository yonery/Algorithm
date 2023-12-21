// 15652 N과 M (4) (C++)

#include <iostream>
int n, m;
using namespace std;
void dfs(int idx, int cnt, int* arr) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = idx; i <= n; i++) {
		arr[cnt] = i;
		dfs(i, cnt + 1, arr);
	}
}
int main() {
	cin >> n >> m;
	int* arr = new int[m];
	dfs(1, 0, arr);
	return 0;
}
