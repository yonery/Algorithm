// SWEA 7227번 사랑의 카운슬러 

/*
고등학교 수학의 기하벡터 내용을 응용하여 해결함


1. 지렁이가 위치한 벡터의 모든 값을 더 함
2. 그 중 1/2를 선택하여 2번 빼줌 
  A->B 로 향하는 벡터  =   원점(0,0)에서 A벡터의 반대방향 + 원점(0,0)에서의 B벡터 

3. 그 중 가장 작은 값을 비교
4. 이동 벡터의 가장 큰 값이 200,000이라 벡터의 합을 낼때 제곱을 해줘야하므로 int형으로는 범위가 안 되서 long long으로 비교해줌

*/

#include <iostream>
#include <vector>
using namespace std;
int T, N, a, b;
long long ret;
vector<pair<int, int>> v;
void dfs(int idx, int cnt, int x, int y) {
	if (cnt == N / 2) {
		long long xx = x, yy = y;
		xx *= xx, yy *= yy;
		if (xx + yy < ret) ret = xx + yy;
		return;
	}
	if (idx == N) return;
	dfs(idx+1, cnt+1,  x-(2*v[idx].first), y-(2*v[idx].second));
	dfs(idx+1, cnt,  x, y);

	if (idx == N) return;
	
}
int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		v.clear();
		ret = 1000000000000000000;
		int n = 0, m = 0;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			v.push_back({ a, b });
			n += a, m += b;
		}
		dfs(0, 0, n, m);
		cout << "#" << t << " " <<ret<< "\n";
	}
	return 0;
}
