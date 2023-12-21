// 1158 요세푸스 문제 (C++)

#include <iostream>
using namespace std;
int N, M, num[5001];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> N >> M;
	int idx = M, n = 0, cnt = M;
	cout << "<";
	while (n<N) {
		if (cnt==M) {
			cout << idx;
			num[idx] = 1;
			n++;
			if (n < N) cout << ", ";
			cnt = 0;
		}

		idx++;
		if (idx > N) idx -= N;
		if (num[idx] == 0) cnt++;

	}
	cout << ">\n";
	return 0;
}
