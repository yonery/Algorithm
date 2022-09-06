// SWEA 1808번 지희의 고장난 계산기 (BFS)

/*

처음에 숫자와 곱하기를 번갈아가며 넘겨줬더니 9*99*999 와 같이 뒷부분에 10이상의 수가 나오는 것을 계산하지 못 함
-> X보다 작거나 같은 만들 수있는 조합의 숫자 먼저 구해주고 곱하기만 수행하기 


1. 0 ~ 9 계산기중에 만들 수 있는 수 조합을 구하고 해당 수를 만들 수 있는 계산횟수를 visit 배열에 저장
2. 해당 수들로 X를 나눠서 1이 나오는 최소 갯수 구하기

+ 중간에 visit[i] =0 으로 초기화 하고 1로만 만들어주면 01 과 1 에서 누른 계산기 횟수가 2, 1로 다른데 단순 조합은 2부터 저장시켜버림
+ visit[i] = MAXN 으로 초기화하고  작을 경우만 탐색해줬어여 
+ 나눌 수가 X보다 크면 안됨 (하지만 같을 수는 있음) 
+ 0으로 나누면 안 됨
+ 1로 나누면 무한루프 

*/

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1000001
using namespace std;
int T, arr[10], visit[MAXN], X, len, x;
vector<pair<int,int>> v;
int bfs() {
	for (int i = 0; i < v.size(); i++) {
		visit[v[i].first] = MAXN;
		if (X == v[i].first) return v[i].second + 1;
	}
	queue<pair<int,int>> q;
	q.push({ X, 0 });
	int mini = MAXN;
	while (!q.empty()) {
		int n = q.front().first, cnt = q.front().second;
		q.pop();
		if (n == 1) {
			return cnt;
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i].first == 0 || v[i].first == 1) continue;
			if (n < v[i].first) continue;
			if (n % v[i].first == 0) {
				int m = n / v[i].first;
				if ( v[i].second + cnt + 1 < visit[m]) {
					visit[m] = v[i].second + cnt + 1, q.push({ m, v[i].second + cnt + 1 });
				}
			}
		}
	}
	return -1;
}
void dfs(int cnt, int num) {
	if (cnt == len) {
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i] == 1) {
			int m = num * 10 + i;
			if (m <= X && (visit[m] > cnt + 1)) {
				visit[m] = cnt + 1;
				dfs(cnt + 1, m);
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
		}
		cin >> X;
		x = X, len = 0;
		while (x > 0) {
			x /= 10;
			len++;
		}

		for (int i = 0; i <= X; i++)
			visit[i] = MAXN;
		dfs(0, 0);
		for (int i = 0; i <= X; i++)
			if (visit[i] != MAXN) v.push_back({ i, visit[i] });

		cout << "#" << t << " "  <<bfs()<< "\n";
	}
	return 0;
}
