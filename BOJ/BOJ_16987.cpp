// 16987 계란으로 계란치기 (C++)
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int N, a, b, arr[8], ret;

void dfs(int idx) {
	if (idx == N) {
		int num = 0;
		for (int i = 0; i < N; i++) 
            if (arr[i] <= 0) num++;
		if (ret < num) ret = num;
		return;
	}
	if (arr[idx] <= 0) dfs(idx + 1);
	else {
		bool chk = true;
		for (int i = 0; i < N; i++) {
			if (idx != i && arr[i] > 0) {
				chk = false;
				arr[idx] -= v[i].second;
				arr[i] -= v[idx].second;

				dfs(idx + 1);

				arr[idx] += v[i].second;
				arr[i] += v[idx].second;
			}
		}
		if (chk)
			dfs(N);
	}

	return;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
		arr[i] = a;
	}
	ret = 0;
	if (N <= 1) cout << "0\n";
	else {
		dfs(0);
		cout << ret << "\n";
	}
	return 0;
}
