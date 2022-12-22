// 1010 다리놓기 (C++)

#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;
		if (N == 0 || M == 0 || N > M)
			cout << 0 << endl;
		else {
			
			// 조합 공식 이용
			long long num = 1, mum = 1;
			N = N <= M - N ? N : M - N;
			for (int i = (M - N + 1); i <= M; i++) {
				num *= i;
			}
			for (int i = 1; i <= N; i++) {
				mum *= i;
			}
			cout << num/mum << endl;

		}
	}

	return 0;
}
