// 16198 에너지 모으기 (C++)

#include <iostream>
#include <vector>
using namespace std;
int N, res;

int max(int a, int b) {
	return a >= b ? a : b;
}

void dfs(int now, vector<int> e) {
	if (e.size() == 2) {
		res = max(res, now);
		return;
	}
	
	int es = e.size() - 2;
	for (int i = es; i > 0; i--) {
		vector<int> b = e;
		int num = e[i + 1] * e[i - 1];
		b.erase(b.begin() + i);
		dfs(now + num, b);
	}

	return;
}

int main()
{
	cin >> N;
	res = 0; 
	vector<int> e;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		e.push_back(a);
	}

	dfs(0, e);
	cout << res << "\n";
	return 0;
}
