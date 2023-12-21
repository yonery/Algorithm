// 14889 스타트와 링크 (C++)
#include <iostream>
#include <vector>
using namespace std;
#define MX 1000001
int map[20][20];
int N, res;

int chk(int vit) {
	int a = 0, b = 0;
	vector<int> at;
	vector<int> bt;
	for (int i = 0; i <N; i++) {
		if ((vit&(1 << i)) > 0) {
			at.push_back(i);
		}
		else {
			bt.push_back(i);
		}
	}
	
	if (at.size() > 0) {

		for (int i = 0; i < at.size(); i++) {
			for (int j = i + 1; j < at.size(); j++) {
				a += map[at[i]][at[j]];
				a += map[at[j]][at[i]];
			}
		}
		//cout << a << "\n";
	}

	if (bt.size() > 0) {

		for (int i = 0; i < bt.size(); i++) {
			for (int j = i + 1; j < at.size(); j++) {
				b += map[bt[i]][bt[j]];
				b += map[bt[j]][bt[i]];
			}
		}
		//cout << b << "\n";
	}
	
	
	return abs(a - b);
}

void dfs(int idx, int visit) {
	if (idx == N) {
		int k = 0;
		for (int i = 0; i < N; i++) {
			if ((visit&(1 << i)) > 0)
				k++;
		}

		if (k == (N / 2)) {
			res = res < chk(visit) ? res : chk(visit);
		}
		return;
	}

	dfs(idx + 1, (visit | (1 << idx)));
	dfs(idx + 1, visit);
	
	return;
}
int main()
{

	cin >> N;
	res = MX;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 0);

	cout << res << "\n";
	return 0;
}
