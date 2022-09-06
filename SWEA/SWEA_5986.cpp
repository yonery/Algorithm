// SWEA 5986번 새샘이의 세 소수

/*
소수들을 먼저 구해준 뒤, 중복있는 3가지 조합으로 N이 되는지 확인

1. 테스트케이스 전에 999전의 소수를 배열에 넣어줌
2. 3가지를 고르고 해당 수가 되는지 확인
3. 고르는 중에 나머지보다 큰 수이면 뒤를 검사 안 해주고 return

*/

#include <iostream>
#include <vector>
using namespace std;
int T, N, ret;
vector<int> v;
bool chk(int n) {
	for (int i = 2; i < n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
void dfs(int idx, int cnt, int num) {	
	if (cnt == 3) {
		if (num == 0) ret++;
		return;
	}
	if (v[idx] > num) return;
	dfs(idx, cnt + 1, num - v[idx]);
	dfs(idx + 1, cnt, num);
    return;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");

	for (int i = 2; i < 998; i++) {
		if (chk(i)) v.push_back(i);
	}
    cin >> T;
	for (int t = 1; t <= T; t++) {

		cin >> N;
		ret = 0;
		dfs(0, 0, N);

		cout << "#" << t << " " << ret << "\n";

	}
	return 0;
}
